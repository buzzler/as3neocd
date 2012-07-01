package
{
	import flash.display.Bitmap;
	import flash.display.BitmapData;
	import flash.events.Event;
	import flash.utils.ByteArray;
	import flash.utils.getTimer;
	
	import vdisk.VDisk;
	
	public class NeocdCore extends Bitmap
	{
		/**
		 * CUSTOM VARIABLE
		 */
		public	var title	:String;
		public	var disk	:VDisk;
		public	var loading	:BitmapData;
		
		/**
		 * HEADER
		 */
		private	const FPS				:Number = 60;
		private	const REFRESHTIME		:Number = 1000/FPS;
		private	const MC68K_VBL_CYCLES	:Number = 12000000/FPS;
//		private	const Z80_VBL_CYCLES	:Number = 4000000/FPS;
		private	const Z80_VBL_CYCLES	:Number = 100000;
		private	const SAMPLE_RATE		:Number = 22050;

		include "cdaudio/cdaudio.as"
		include "cdrom/cdrom.as"
		include "mc68000/m68k.as"
		include "memory/memory.as"
		include "video/video.as"
		include "input/input.as"
		include "z80/z80intrf.as"
		include "sound/sound.as"
		include "sound/streams.as"
		include "sound/2610intf.as"
		include "sound/timer.as"
		include "pd4990a.as"

		private	const VERSION1			:String = "NeoCD/SDL 0.3.1";
		private	const VERSION2			:String	= "Compiled on: 20120616";

		public	var global_error		:String;
		public	var neogeo_rom_memory	:Vector.<uint>;
		public	var neogeo_prg_memory	:Vector.<uint>;
		public	var neogeo_fix_memory	:Vector.<uint>;
		public	var neogeo_spr_memory	:Vector.<uint>;
		public	var neogeo_pcm_memory	:Vector.<uint>;
		public	var neogeo_memorycard	:Vector.<uint>;
		public	var neogeo_ipl_done		:Boolean;
		public	var neocd_time			:uint;

		/**
		 * IMPLEMENTATION
		 */
		private	const REGION_JAPAN		:uint = 0;
		private const REGION_USA		:uint = 1;
		private	const REGION_EUROPE		:uint = 2;
		private	const REGION			:uint = REGION_USA;

		private	var	neocd_wm_title		:String;
		private	var neogeo_prio_mode	:int;
		private	var neogeo_region		:uint;
		private	var config_game_name	:String;
		private	var mame_debug			:int;
		private	var previouspc			:int;
		private	var ophw				:int;
		private	var cur_mrhard			:int;
		
		public function NeocdCore(bitmap:Bitmap = null):void
		{
			super(new BitmapData(320, 224, false, 0x0), "auto", false);
			title	= "";
			disk	= new VDisk();
			loading	= (bitmapData==null) ? new BitmapData(320, 224, false, 0x0):bitmap.bitmapData.clone();
			
			init_m68k();
		}
		
		public	function power():void
		{
			neogeo_rom_memory	= null;
			neogeo_prg_memory	= null;
			neogeo_fix_memory	= null;
			neogeo_spr_memory	= null;
			neogeo_pcm_memory	= null;
			config_game_name	= "";
			neogeo_memorycard	= new Vector.<uint>(8192, true);
			neogeo_region		= REGION;
			neogeo_prio_mode	= 0;
			neogeo_ipl_done		= false;
			neocd_time			= 0;
			neocd_wm_title		= VERSION1;
			global_error		= "";
			mame_debug			= 0;
			previouspc			= 0;
			ophw				= 0;
			cur_mrhard			= 0;
			
			trace(VERSION1);
			trace(VERSION2);
			
			neogeo_prg_memory = Util.calloc(1,0x200000);
			neogeo_spr_memory = Util.calloc(1,0x400000);
			neogeo_rom_memory = Util.calloc(1,0x80000);
			neogeo_fix_memory = Util.calloc(1,0x20000);
			neogeo_pcm_memory = Util.calloc(1,0x100000);
			
			initialize_memmap();
			
			var fp:ByteArray;
			fp = disk.openFile("memcard.bin");
			if (fp!=null)
			{
				disk.readFile(neogeo_memorycard, 0, 1, 8192, fp);
				disk.closeFile(fp);
			}
			
			if (video_init()!=true)
			{
				video_mode = 0;
				trace(global_error);
				return;
			}
			
			fp =  disk.openFile("neocd.bin");
			if (fp==null)
			{
				trace("Fatal Error: Could not load NEOCD.BIN\n");
				return;
			}
			disk.readFile(neogeo_rom_memory, 0, 1, 0x80000, fp);
			disk.closeFile(fp);
			
			var fixtmp:Vector.<uint> = Util.calloc(1, 65536, 0);
			Util.memcpy(fixtmp, 0, neogeo_rom_memory, 458752, 65536);
			fix_conv(fixtmp,0,neogeo_rom_memory,458752,65536,rom_fix_usage);
			fixtmp = null;
			
			fp = disk.openFile("startup.bin");
			if (fp==null)
			{
				trace("Fatal Error: Could not load STARTUP.BIN");
				return;
			}
			disk.readFile(neogeo_prg_memory, 0x10F300, 1, 3328, fp);
			disk.closeFile(fp);
			Util.swab(neogeo_prg_memory, 0x10F300, neogeo_prg_memory, 0x10F300, 3328);
			
			if (neogeo_rom_memory[0xA822]!=0xF9 || neogeo_rom_memory[0xA823]!=0x4B)
			{
				trace(neogeo_rom_memory[0xA822].toString(16), neogeo_rom_memory[0xA823].toString(16)  );
				trace("Fatal Error: Invalid BIOS file.");
				return;
			}
			
			neogeo_rom_memory[0x552]	= 0xBF;
			neogeo_rom_memory[0x553]	= 0xFA;
			
			neogeo_rom_memory[0x554]	= 0x75;
			neogeo_rom_memory[0x555]	= 0x4E;
			
			neogeo_rom_memory[0x564]	= 0xC0;
			neogeo_rom_memory[0x565]	= 0xFA;
			
			neogeo_rom_memory[0x566]	= 0x75;
			neogeo_rom_memory[0x567]	= 0x4E;
			
			neogeo_rom_memory[0xB040]	= 0x71;
			neogeo_rom_memory[0xB041]	= 0x4E;
			
			neogeo_rom_memory[0xB042]	= 0x71;
			neogeo_rom_memory[0xB043]	= 0x4E;
			
			neogeo_rom_memory[0x546]	= 0xC1;
			neogeo_rom_memory[0x547]	= 0xFA;
			
			neogeo_rom_memory[0x548]	= 0x75;
			neogeo_rom_memory[0x549]	= 0x4E;
			
			neogeo_rom_memory[0x56A]	= 0xC3;
			neogeo_rom_memory[0x56B]	= 0xFA;
			
			neogeo_rom_memory[0x56C]	= 0x75;
			neogeo_rom_memory[0x56D]	= 0x4E;
			
			neogeo_rom_memory[0xA87A]	= 0x39;
			neogeo_rom_memory[0xA87B]	= 0x42;
			
			neogeo_rom_memory[0xA87C]	= 0x10;
			neogeo_rom_memory[0xA87D]	= 0x00;
			
			neogeo_rom_memory[0xA87E]	= 0xAE;
			neogeo_rom_memory[0xA87F]	= 0xFD;
			
			neogeo_rom_memory[0xA5B6]	= 0xFC;
			neogeo_rom_memory[0xA5B7]	= 0x4A;
			
			
			input_init();
			
			cdrom_init1();
			cdda_current_drive=cdrom_current_drive;
			cdda_init();
			
			init_sdl_audio();
			
			neogeo_init();
			pd4990a_init();
			neogeo_run();
		}
		
		private	function neogeo_init():void
		{
			m68k_pulse_reset();
		}
		
		private	function neogeo_reset():void
		{
			neogeo_read_gamename();
			if (config_game_name=="TEST PROGRAM USA")
			{
				config_game_name = "SAMURAI SPIRITS RPG";

				var fp:ByteArray = disk.openFile("patch.prg");
				if (fp==null || fp.length==0)
				{
					throw new Error("Fatal Error: Couldnt open patch.prg.");
				}
				
				disk.readFile(neogeo_prg_memory, 0x132000, 1, 112, fp);
				disk.closeFile(fp);
				Util.swab(neogeo_prg_memory, 0x132000, neogeo_prg_memory, 0x132000, 112);
			}

			neocd_wm_title += " - ";
			neocd_wm_title += config_game_name;
			this.title = neocd_wm_title;
			
			m68k_pulse_reset();
			m68k_set_reg(M68K_REG_PC,0xc0a822);
			m68k_set_reg(M68K_REG_SR,0x2700);
			m68k_set_reg(M68K_REG_A7,0x10F300);
			m68k_set_reg(M68K_REG_ISP,0x10F300);
			m68k_set_reg(M68K_REG_USP,0x10F300);
			
			m68k_write_memory_32(0x10F6EE, m68k_read_memory_32(0x68));
			
			if (m68k_read_memory_8(0x107)&0x7E)
			{
				if (m68k_read_memory_16(0x13A))
				{
					m68k_write_memory_32(0x10F6EA, (m68k_read_memory_16(0x13A)<<1) + 0xE00000);
				}
				else
				{
					m68k_write_memory_32(0x10F6EA, 0);
					m68k_write_memory_8(0x00013B, 0x01);
				}
			}
			else
				m68k_write_memory_32(0x10F6EA, 0xE1FDF0);
			
			m68k_write_memory_8(0x10FD83,neogeo_region);
			
			cdda_current_track = 0;
			cdda_get_disk_info();
			
			z80_init();
		}
		
		private	function neogeo_hreset():void
		{
			m68k_pulse_reset();
			m68k_set_reg(M68K_REG_PC,0x122);
			m68k_set_reg(M68K_REG_SR,0x2700);
			m68k_set_reg(M68K_REG_A7,0x10F300);
			m68k_set_reg(M68K_REG_ISP,0x10F300);
			m68k_set_reg(M68K_REG_USP,0x10F300);
			
			m68k_write_memory_8(0x10FD80, 0x82);
			m68k_write_memory_8(0x10FDAF, 0x01);
			m68k_write_memory_8(0x10FEE1, 0x0A);
			m68k_write_memory_8(0x10F675, 0x01);
			m68k_write_memory_8(0x10FEBF, 0x00);
			m68k_write_memory_32(0x10FDB6, 0);
			m68k_write_memory_32(0x10FDBA, 0);
			
			m68k_write_memory_8(0x10FD83,neogeo_region);
			
			cdda_current_track = 0;
			z80_init();
		}
		
		private	function neogeo_shutdown():void
		{
			cdda_shutdown();
			cdrom_shutdown();
			sound_shutdown();
			input_shutdown();
			video_shutdown();
			
			trace("NEOGEO: System Shutdown.");
			
			var fp:ByteArray = disk.openFile("memcard.bin");
			if (fp==null || fp.length==0)
			{
				disk.writeFile(neogeo_memorycard, 0, 1, 8192, fp);
				disk.closeFile(fp);
			}
			else
			{
				trace("Error: Couldn't open memcard.bin for writing.");
			}
			
			neogeo_prg_memory = null;
			neogeo_rom_memory = null;
			neogeo_spr_memory = null;
			neogeo_fix_memory = null;
			neogeo_pcm_memory = null;
			
			removeEventListener(Event.ENTER_FRAME, neogeo_on_vbl);
		}
		
		
		private	function neogeo_exception():void
		{
			throw new Error("NEOGEO: Exception Trapped at " + previouspc.toString(16) + " !");
		}
		
		private	function MC68000_Cause_Interrupt(level:int):void
		{
			m68k_set_irq(level);
		}
		
		private	function neogeo_exit():void
		{
			removeEventListener(Event.ENTER_FRAME, neogeo_on_vbl);
			trace("NEOGEO: Exit requested by software...");
		}
		
		private	function neogeo_run():void
		{
			var now:uint;
			var i:int;
			
			if (neogeo_ipl_done!=true)
			{
				cdrom_load_title();
				if (cdrom_process_ipl()!=true)
				{
					trace("Error: Error while processing IPL.TXT");
					return;
				}
				
				neogeo_ipl_done = true;
				neogeo_hreset();
			}
			
			neocd_time = flash.utils.getTimer()+REFRESHTIME;
			
			my_timer();
			z80_cycles = Z80_VBL_CYCLES/256;
			
			addEventListener(Event.ENTER_FRAME, neogeo_on_vbl, false, int.MAX_VALUE);
		}
		
		private	function neogeo_on_vbl(event:Event):void
		{
			/**
			 * Z80
			 */
			mz80int(0);
//			if (SDL_GetAudioStatus()==SDL_AUDIO_PLAYING) {
			for (var i:uint = 0; i < 256; i++) {
				if (z80_cycles>0) {
					mz80exec(z80_cycles);
					z80_cycles=0;
					my_timer();
				}
				z80_cycles += Z80_VBL_CYCLES/256;
			}
//			}
			
			/**
			 * MC68000
			 */
			m68k_execute(MC68K_VBL_CYCLES);
			m68k_set_irq(2);
			
			/**
			 * PD4990A
			 */
			pd4990a_addretrace();
			
			if (watchdog_counter > 0)
			{
				if (--watchdog_counter == 0)
				{
					neogeo_reset();
				}
			}
			
			if (memcard_write > 0)
			{
				memcard_write--;
				if(memcard_write==0)
				{
				}
			}
			
			video_draw_screen1();
			
			neogeo_cdda_check();
			
			processEvents();
			
			neocd_time = flash.utils.getTimer()+REFRESHTIME;
		}
		
		private	function neogeo_prio_switch():void
		{
			if (m68k_get_reg(null,M68K_REG_D7) == 0xFFFF)
				return;
			
			if (m68k_get_reg(null,M68K_REG_D7)==9 && m68k_get_reg(null,M68K_REG_A3)==0x10DED9 && (m68k_get_reg(null,M68K_REG_A2)==0x1081d0 || (m68k_get_reg(null,M68K_REG_A2)&0xFFF000)==0x102000))
			{
				neogeo_prio_mode = 0;
				return;
			}
			
			if (m68k_get_reg(null,M68K_REG_D7)==8 && m68k_get_reg(null,M68K_REG_A3)==0x10DEC7 && m68k_get_reg(null,M68K_REG_A2)==0x102900)
			{
				neogeo_prio_mode = 0;
				return;
			}
			
			if (m68k_get_reg(null,M68K_REG_A7) == 0x10F29C)
			{
				if ((m68k_get_reg(null,M68K_REG_D4)&0x4010) == 0x4010)
				{
					neogeo_prio_mode = 0;
					return;
				}
				
				neogeo_prio_mode = 1;
			}
			else
			{
				if (m68k_get_reg(null,M68K_REG_A3) == 0x5140)
				{
					neogeo_prio_mode = 1;
					return;
				}
				
				if ( (m68k_get_reg(null,M68K_REG_A3)&~0xF) == (m68k_get_reg(null,M68K_REG_A4)&~0xF) )
				{
					neogeo_prio_mode = 1;
				}
				else
				{
					neogeo_prio_mode = 0;
				}
			}
		}
		
		private	function not_implemented():void
		{
			trace("Error: This function isn't implemented.");
		}
		
		private	function neogeo_quit():void
		{
			removeEventListener(Event.ENTER_FRAME, neogeo_on_vbl);
		}
		
		private	function neogeo_cdda_check():void
		{
			var offset:int = m68k_read_memory_32(0x10F6EA);
			if (offset < 0xE00000)
			{
				return;
			}
			
			offset -= 0xE00000;
			offset = offset >> 1;
			
			neogeo_do_cdda(subcpu_memspace[offset], subcpu_memspace[offset+1]);
		}
		
		private	function neogeo_cdda_control():void
		{
			neogeo_do_cdda( (m68k_get_reg(null,M68K_REG_D0)>>8)&0xFF, 
			m68k_get_reg(null,M68K_REG_D0)&0xFF );
		}
		
		private	function neogeo_do_cdda( command:int, track_number_bcd:int):void
		{
			var track_number:int;
			var offset:int;
			
			if ((command == 0)&&(track_number_bcd == 0))
			{
				return;
			}
			
			m68k_write_memory_8(0x10F64B, track_number_bcd);
			m68k_write_memory_8(0x10F6F8, track_number_bcd);
			m68k_write_memory_8(0x10F6F7, command);
			m68k_write_memory_8(0x10F6F6, command);
			
			offset = m68k_read_memory_32(0x10F6EA);
			
			if (offset!=0)
			{
				offset -= 0xE00000;
				offset >>= 1;
				
				m68k_write_memory_8(0x10F678, 1);
				
				subcpu_memspace[offset] = 0;
				subcpu_memspace[offset+1] = 0;
			}
			
			switch( command )
			{
				case	0:
				case	1:
				case	5:
				case	4:
				case	3:
				case	7:
					track_number = ((track_number_bcd>>4)*10) + (track_number_bcd&0x0F);
					if ((track_number == 0)&&(cdda_playing!=true))
					{
						cdda_resume();
					}
					else if ((track_number>1)&&(track_number<99))
					{
						cdda_play(track_number);
						cdda_autoloop = ((command&1) == 0);
					}
					break;
				case	6:
				case	2:
					if (cdda_playing)
					{
						cdda_pause();
					}
					break;
			}
		}

		private	function neogeo_read_gamename():void
		{
			var game_name:Vector.<uint> = new Vector.<uint>(80, true);
			Util.swab(neogeo_prg_memory, m68k_read_memory_32(0x11A), game_name, 0, 80);
			
			config_game_name = "";
			for (var temp:int = 0 ; temp < 80 ; temp++)
			{
				if (game_name[temp] > 255)
				{
					config_game_name += String.fromCharCode(game_name[temp]);
				}
			}
		}
	}
}
