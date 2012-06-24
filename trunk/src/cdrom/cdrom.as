import flash.display.BitmapData;
import flash.utils.ByteArray;
import flash.utils.getTimer;

public	var cdrom_current_drive	:int;
public	var cdpath				:String;
public	var img_display			:Boolean;
private	var cdrom_buffer		:Vector.<uint> = new Vector.<uint>(BUFFER_SIZE, true);

private	const IPL_TXT		:String = "IPL.TXT";
private	const PRG			:String = "PRG";
private	const FIX			:String = "FIX";
private	const SPR			:String = "SPR";
private	const Z80			:String = "Z80";
private	const PAT			:String = "PAT";
private	const PCM			:String = "PCM";
private	const JUE			:String = "JUE";
private	const TITLE_X_SYS	:String = "TITLE_X.SYS";

private	const BUFFER_SIZE	:uint = 131072;
private	const PRG_TYPE		:uint = 0;
private	const FIX_TYPE		:uint = 1;
private	const SPR_TYPE		:uint = 2;
private	const Z80_TYPE		:uint = 3;
private	const PAT_TYPE		:uint = 4;
private	const PCM_TYPE		:uint = 5;


private	function cdrom_init1():Boolean
{
	trace("Detecting CD-ROM drives... ");
	if (disk.getIso()==null)
	{
		trace("No CDROM devices available");
		return false;
	}
	else
	{
		trace("CD-ROM drives found");
	}		
	
	var fp:ByteArray = disk.openFile(IPL_TXT);
	if (fp!=null)
	{
		disk.closeFile(fp);
		trace("Found Neogeo CD in drive");
		return true;
	}
	else
	{
		trace("No NeogeoCD Discs available");
		return false;
	}
}

private	function cdrom_shutdown():void
{
}

private	function cdrom_load_prg_file(filename:String, offset:uint):Boolean
{
	var fp:ByteArray = disk.openFile(filename);
	if (fp==null || fp.length==0)
	{
		trace("Could not open " + filename);
		return false;
	}
	
	do
	{
		var readed:int = disk.readFile(cdrom_buffer, 0, 1, BUFFER_SIZE, fp);
		Util.swab(cdrom_buffer, 0, neogeo_prg_memory, offset, readed);
		offset += readed;
	}while ( fp.bytesAvailable > 0 );
	
	disk.closeFile(fp);
	return true;
}

private	function cdrom_load_z80_file(filename:String, offset:uint):Boolean
{
	var fp:ByteArray = disk.openFile(filename);
	if (fp==null || fp.length==0)
	{
		trace("Could not open " + filename);
		return false;
	}
	
	disk.readFile(subcpu_memspace, offset, 1, 0x10000, fp);
	disk.closeFile(fp);
	
	return true;
}

private	function cdrom_load_fix_file(filename:String, offset:uint):Boolean
{
	var fp:ByteArray = disk.openFile(filename);
	if (fp==null || fp.length==0)
	{
		trace("Could not open " + filename);
		return false;
	}
	
	var readed:int;
	do
	{
		Util.memset(cdrom_buffer,0,0,BUFFER_SIZE);
		readed = disk.readFile(cdrom_buffer, 0, 1, BUFFER_SIZE, fp);
		
		fix_conv(cdrom_buffer, 0, neogeo_fix_memory, offset, readed, video_fix_usage, offset>>5);
		offset += readed;
	} while (readed == BUFFER_SIZE);
	
	disk.closeFile(fp);
	return true;
}

private	function cdrom_load_spr_file(filename:String, offset:uint):Boolean
{
	var fp:ByteArray = disk.openFile(filename);
	if (fp==null || fp.length==0)
	{
		trace("Could not open " + filename);
		return false;
	}
	
	var readed:int;
	do
	{
		Util.memset(cdrom_buffer,0,0,BUFFER_SIZE);
		readed = disk.readFile(cdrom_buffer,0,1,BUFFER_SIZE, fp);
		spr_conv(cdrom_buffer,0, neogeo_spr_memory,offset, readed, video_spr_usage, offset>>7);
		offset += readed;
	} while (readed==BUFFER_SIZE);
	
	disk.closeFile(fp);
	return true;
}

private	function cdrom_load_pcm_file(filename:String, offset:uint):Boolean
{
	var fp:ByteArray = disk.openFile(filename);
	if (fp==null || fp.length==0)
	{
		trace("Could not open " + filename);
		return false;
	}
	
	disk.readFile(neogeo_pcm_memory, offset, 1, 0x100000, fp);
	disk.closeFile(fp);
	
	return true;
}

private	function cdrom_load_pat_file(filename:String, offset:uint, bank:uint):Boolean
{
	var fp:ByteArray = disk.openFile(filename);
	if (fp==null || fp.length==0)
	{
		trace("Could not open " + filename);
		return false;
	}
	
	var readed:int = disk.readFile(cdrom_buffer, 0, 1, BUFFER_SIZE, fp);
	Util.swab(cdrom_buffer,0, cdrom_buffer,0, readed);
	cdrom_apply_patch(cdrom_buffer, 0, offset, bank);
	
	disk.closeFile(fp);
	return true;
}


private function hextodec(c:String):int {
	switch (c.toLowerCase())
	{
		case '0':	return 0;
		case '1':	return 1;
		case '2':	return 2;
		case '3':	return 3;
		case '4':	return 4;
		case '5':	return 5;
		case '6':	return 6;
		case '7':	return 7;
		case '8':	return 8;
		case '9':	return 9;
		case 'a':	return 10;
		case 'b':	return 11;
		case 'c':	return 12;
		case 'd':	return 13;
		case 'e':	return 14;
		case 'f':	return 15;
		default:	return 0;
	}
}

private	function cdrom_process_ipl():Boolean
{
	var fp:ByteArray = disk.openFile(IPL_TXT);
	if (fp==null || fp.length==0)
	{
		trace("Could not open " + IPL_TXT);
		return false;
	}
	
	var params:Array;
	var lines:Array = fp.readMultiByte(fp.length, "us-ascii").split('\n');
	for each (var single:String in lines)
	{
		params = single.split(',');
		if (params.length < 3)
		{
			break;
		}
		
		var filename:String = params[0] as String;
		var filetype:String = filename.substr( filename.lastIndexOf('.')+1 );
		var bnk:uint = parseInt(params[1] as String, 16);
		var off:uint = parseInt(params[2] as String, 16);
		trace("Loading File: " + filename, bnk.toString(16), off.toString(16));
		
		switch( filetype )
		{
			case PRG:
				if (!cdrom_load_prg_file(filename, off))
				{
					disk.closeFile(fp);
					return false;
				}
				break;
			case FIX:
				if (!cdrom_load_fix_file(filename, (off>>1)))
				{
					disk.closeFile(fp);
					return false;
				}
				break;
			case SPR:
				if (!cdrom_load_spr_file(filename, (bnk*0x100000) + off))
				{
					disk.closeFile(fp);
					return false;
				}
				break;
			case Z80:
				if (!cdrom_load_z80_file(filename, (off>>1)))
				{
					disk.closeFile(fp);
					return false;
				}
				break;
			case PAT:
				if (!cdrom_load_pat_file(filename, off, bnk))
				{
					disk.closeFile(fp);
					return false;
				}
				break;
			case PCM:
				if (!cdrom_load_pcm_file(filename, (bnk*0x80000) + (off>>1)))
				{
					disk.closeFile(fp);
					return false;
				}
				break;
		}
	}
	
	disk.closeFile(fp);
	return true;
}

private	function recon_filetype(ext:String):uint
{    
	if (ext == PRG)
		return PRG_TYPE;
	
	if (ext == FIX)
		return FIX_TYPE;
	
	if (ext == SPR)
		return SPR_TYPE;
	
	if (ext == Z80)
		return Z80_TYPE;
	
	if (ext == PAT)
		return PAT_TYPE;
	
	if (ext == PCM)
		return PCM_TYPE;
	
	return uint.MAX_VALUE;
}

private	function motorola_peek(address:Vector.<uint>, offset:uint):uint
{
	var a:uint = address[offset+0] << 24;
	var b:uint = address[offset+1] << 16;
	var c:uint = address[offset+2] << 8;
	var d:uint = address[offset+3];
	
	return a|b|c|d;
}

private	function cdrom_load_files():void
{
	if (m68k_read_memory_8(m68k_get_reg(null,M68K_REG_A0)) == 0)
	{
		return;
	}
	
	cdda_stop();
	cdda_current_track = 0;
	
	m68k_write_memory_32(0x10F68C, 0x00000000);
	m68k_write_memory_8(0x10F6C3, 0x00);
	m68k_write_memory_8(0x10F6D9, 0x01);
	m68k_write_memory_8(0x10F6DB, 0x01);
	m68k_write_memory_32(0x10F742, 0x00000000);
	m68k_write_memory_32(0x10F746, 0x00000000);
	m68k_write_memory_8(0x10FDC2, 0x01);
	m68k_write_memory_8(0x10FDDC, 0x00);
	m68k_write_memory_8(0x10FDDD, 0x00);
	m68k_write_memory_8(0x10FE85, 0x01);
	m68k_write_memory_8(0x10FE88, 0x00);
	m68k_write_memory_8(0x10FEC4, 0x01);
	
	if (img_display == true) {
		video_buffer.draw(loading);
		blitter();
	}
	
	var entry:Vector.<uint> = new Vector.<uint>(32,true);
	var filename:String = "";
	var fileext:String = "";
	var i:int, j:int, religuat:int;
	var bnk:uint, off:uint, type:uint;
	var pointer:uint = m68k_get_reg(null,M68K_REG_A0);
	do
	{
		religuat = (neogeo_prg_memory[pointer]|neogeo_prg_memory[pointer+1]<<8|neogeo_prg_memory[pointer+2]<<16|neogeo_prg_memory[pointer+3]<<24) & 1;
		if (religuat>0)
		{
			pointer--;
		}
		
		Util.swab(neogeo_prg_memory, pointer, entry, 0, 32);
		i = religuat;
		
		while ( (entry[i]!=0) && (String.fromCharCode(entry[i]) != ';') )
		{
			filename += String.fromCharCode(entry[i]);
			i++
		}
		
		if (String.fromCharCode(entry[i-religuat]) == ';')
		{
			i += 2;
		}
		i++;
		
		bnk = entry[i++] & 3;
		if (i&1 > 0)
		{
			i++;
		}
		
		off = motorola_peek(entry, i);
		i += 4;
		pointer += i;
		
		trace("Loading File: " + filename, bnk.toString(16), off.toString(16));
		var lastidx:int = filename.lastIndexOf('.');
		if (lastidx >= 0)
		{
			fileext = filename.substr( filename.lastIndexOf('.')+1 );
		}
		else
		{
			throw new Error("Internal Error loading file: " + filename);
		}
		
		switch (fileext)
		{
			case PRG:
				cdrom_load_prg_file(filename, off);
				break;
			case FIX:
				cdrom_load_fix_file(filename, off>>1);
				break;
			case SPR:
				cdrom_load_spr_file(filename, (bnk*0x100000) + off);
				break;
			case Z80:
				cdrom_load_z80_file(filename, off>>1);
				break;
			case PAT:
				cdrom_load_pat_file(filename, off, bnk);
				break;
			case PCM:
				cdrom_load_pcm_file(filename, (bnk*0x80000) + (off>>1));
				break;
		}
		
		processEvents();
	} while (entry[i] != 0);
	
	neocd_time = getTimer() + REFRESHTIME;
}

private	function fix_conv(src:Vector.<uint>, offsetSrc:uint, ptr:Vector.<uint>, offsetPtr:uint, taille:int, usage_ptr:Vector.<uint>, offsetUse:uint=0):void
{
	for (var i:int = taille ; i > 0 ; i-=32)
	{
		var usage:uint = 0;
		for (var j:int = 0 ; j < 8 ; j++)
		{
			ptr[offsetPtr++] = src[offsetSrc+16];
			usage |= src[offsetSrc+16];
			ptr[offsetPtr++] = src[offsetSrc+24];
			usage |= src[offsetSrc+24];
			ptr[offsetPtr++] = src[offsetSrc];
			usage |= src[offsetSrc];
			ptr[offsetPtr++] = src[offsetSrc+8];
			usage |= src[offsetSrc+8];
			offsetSrc++;
		}
		offsetSrc+= 24;
		usage_ptr[offsetUse++] = usage;
	}
}

private	function COPY_BIT(a:Vector.<uint>, offsetA:uint, b:Vector.<uint>, offsetB:uint):void
{
	a[offsetA] <<= 1;
	a[offsetA] |= b[offsetB] & 0x1;
	b[offsetB] >>= 1;
}

private	function extract8(src:Vector.<uint>, offsetSrc:uint, dst:Vector.<uint>, offsetDst:uint):void
{
	var bh:uint = offsetSrc++;
	var bl:uint = offsetSrc++;
	var ch:uint = offsetSrc++;
	var cl:uint = offsetSrc;
	var al:uint;
	var ah:uint;
	
	for (var i:int = 0 ; i < 4 ; i++)
	{
		al = ah = 0;
		
		COPY_BIT(src, al, src, ch);
		COPY_BIT(src, al, src, cl);
		COPY_BIT(src, al, src, bh);
		COPY_BIT(src, al, src, bl);
		
		COPY_BIT(src, ah, src, ch);
		COPY_BIT(src, ah, src, cl);
		COPY_BIT(src, ah, src, bh);
		COPY_BIT(src, ah, src, bl);
		
		dst[offsetDst++] = (src[ah]<<4) | src[al];
	}
}

private	function spr_conv(src:Vector.<uint>, offsetSrc:uint, dst:Vector.<uint>, offsetDst:uint, len:int, usage_ptr:Vector.<uint>, offsetUse:uint=0):void
{
	var offset:int;

	for (var i:uint ; i < len ; i+=4)
	{
		if ((i&0x7F) < 64)
		{
			offset = (i&0xFFF80) + ((i&0x7F)<<1) + 4;
		}
		else
		{
			offset = (i&0xFFF80) + ((i&0x7F)<<1) - 128;
		}
		
		extract8(src, offsetSrc, dst, offsetDst+offset);
		offsetSrc += 4;
	}
}

private	function neogeo_upload():void
{
	var zone:uint = m68k_read_memory_8(0x10FEDA);
	var taille:uint;
	var source:uint;
	var dest:uint;
	var offset:uint = 0;
	var banque:uint;
	
	switch (zone & 0x0F)
	{
		case 0:
			source = m68k_read_memory_32(0x10FEF8);
			dest = m68k_read_memory_32(0x10FEF4);
			taille = m68k_read_memory_32(0x10FEFC);
			Util.memcpy(neogeo_prg_memory, dest, neogeo_prg_memory, source, taille);
			m68k_write_memory_32(0x10FEF4, m68k_read_memory_32(0x10FEF4) + taille);
			break;
		
		case 2:
			banque = m68k_read_memory_8(0x10FEDB);
			source = m68k_read_memory_32(0x10FEF8);
			offset = m68k_read_memory_32(0x10FEF4) + (banque<<20);
			dest = offset;
			taille = m68k_read_memory_32(0x10FEFC);
			
			do {
				Util.memset(cdrom_buffer, 0, 0, BUFFER_SIZE);
				Util.swab(neogeo_prg_memory, source, cdrom_buffer, 0, Math.min(BUFFER_SIZE, taille) );
				spr_conv(cdrom_buffer, 0, neogeo_prg_memory, dest, Math.min(BUFFER_SIZE, taille), video_spr_usage, offset>>7);
				source += Math.min(BUFFER_SIZE, taille);
				dest += Math.min(BUFFER_SIZE, taille);
				offset += Math.min(BUFFER_SIZE, taille);
				taille -= Math.min(BUFFER_SIZE, taille);
			} while (taille!=0);

			offset = m68k_read_memory_32( 0x10FEF4 );
			banque = m68k_read_memory_8( 0x10FEDB );
			taille = m68k_read_memory_8( 0x10FEFC );
			
			offset += taille;
			
			while (offset > 0x100000 )
			{
				banque++;
				offset -= 0x100000;
			}
			
			m68k_write_memory_32( 0x10FEF4, offset );
			m68k_write_memory_16( 0x10FEDB, banque );
			break;
		
		case 1:
			source = m68k_read_memory_32(0x10FEF8);
			offset = m68k_read_memory_32(0x10FEF4)>>1;
			dest = offset;
			taille = m68k_read_memory_32(0x10FEFC);
			
			do {
				Util.memset(cdrom_buffer, 0, 0, BUFFER_SIZE);
				Util.swab(neogeo_prg_memory, source, cdrom_buffer, 0, Math.min(BUFFER_SIZE, taille));
				fix_conv(cdrom_buffer, 0, neogeo_fix_memory, dest, Math.min(BUFFER_SIZE, taille), video_fix_usage, offset>>5);
				source += Math.min(BUFFER_SIZE, taille);
				dest += Math.min(BUFFER_SIZE, taille);
				offset += Math.min(BUFFER_SIZE, taille);
				taille -= Math.min(BUFFER_SIZE, taille);
			} while (taille!=0);
			
			offset = m68k_read_memory_32( 0x10FEF4 );
			taille = m68k_read_memory_32( 0x10FEFC );
			
			offset += (taille<<1);
			
			m68k_write_memory_32( 0x10FEF4, offset);
			break;
		
		case 3:
			source = m68k_read_memory_32(0x10FEF8);
			dest = m68k_read_memory_32(0x10FEF4) >> 1;
			taille = m68k_read_memory_32(0x10FEFC);
			Util.swab(neogeo_prg_memory, source, subcpu_memspace, dest, taille);        
			m68k_write_memory_32( 0x10FEF4, m68k_read_memory_32(0x10FEF4) + (taille<<1) );
			break;
		
		case 5:
			source = m68k_read_memory_32(0x10FEF8);
			cdrom_apply_patch(neogeo_prg_memory, source, m68k_read_memory_32(0x10FEF4), m68k_read_memory_8(0x10FEDB));
			break;
		
		case 4:
			banque = m68k_read_memory_8(0x10FEDB);
			source = m68k_read_memory_32(0x10FEF8);
			offset = (m68k_read_memory_32(0x10FEF4)>>1) + (banque<<19);
			dest = offset;
			taille = m68k_read_memory_32(0x10FEFC);
			
			Util.swab(neogeo_prg_memory, source, neogeo_pcm_memory, dest, taille);        
			
			offset = m68k_read_memory_32( 0x10FEF4 );
			banque = m68k_read_memory_8( 0x10FEDB );
			taille = m68k_read_memory_8( 0x10FEFC );
			
			offset += (taille<<1);
			
			while (offset > 0x100000 )
			{
				banque++;
				offset -= 0x100000;
			}
			
			m68k_write_memory_32( 0x10FEF4, offset );
			m68k_write_memory_16( 0x10FEDB, banque );
			break;
	}
}

private	function cdrom_load_title():void
{
	var filename:String = "TITLE_" + JUE.charAt( m68k_read_memory_8(0x10FD83) & 0x3 ) + ".SYS";
	var fp:ByteArray = disk.openFile(filename);
	if (fp==null || fp.length==0)
	{
		return;
	}
	
	disk.readFile(video_paletteram_pc, 0, 1, 0x5A0, fp);
	Util.swab(video_paletteram_pc, 0, video_paletteram_pc, 0, 0x5A0);

	var readed:int;
	for (readed = 0 ; readed < 720 ; readed++)
	{
		video_paletteram_pc[readed] = video_color_lut[ video_paletteram_pc[readed] ];
	}
	
	readed = disk.readFile(cdrom_buffer, 0, 1, BUFFER_SIZE, fp);
	spr_conv(cdrom_buffer, 1, neogeo_spr_memory, 0, readed, video_spr_usage, 0);
	disk.closeFile(fp);
	
	readed = 0;
	for (var y:int = 0 ; y < 80 ; y+=16)
	{
		for (var x:int = 0 ; x < 144 ; x+=16)
		{
			video_draw_spr(readed, readed, 0, 0, x+16, y+16, 15, 16);
			readed++;
		}
	}
	blitter();
	
	Util.memset(neogeo_spr_memory, 0, 0, 4194304);
	Util.memset(neogeo_fix_memory, 0, 0, 131072);
	Util.memset(video_spr_usage, 0, 0, 32768);
	Util.memset(video_fix_usage, 0, 0, 4096);
}


private	function PATCH_Z80(a:uint, b:uint):void
{
	subcpu_memspace[a] = b & 0xFF;
	subcpu_memspace[a+1] = (b>>8) & 0xFF;
}

private	function cdrom_apply_patch(source:Vector.<uint>, offsetSrc:uint, offset:uint, bank:uint):void
{
	var current:uint = 0;
	var master_offset:uint = (((bank*1048576) + offset)/256)&0xFFFF;
	while ( (source[offsetSrc+current] | source[offsetSrc+current+1]<<8) != 0 )
	{
		PATCH_Z80(source[offsetSrc+current]|source[offsetSrc+current+1]<<8, (source[offsetSrc+current+2]|source[offsetSrc+current+3]<<8 + master_offset)>>1 );
		PATCH_Z80(source[offsetSrc+current]|source[offsetSrc+current+1]<<8+2, (source[offsetSrc+current+4]|source[offsetSrc+current+5]<<8 + master_offset)>>1-1);
		
		if ( ((source[offsetSrc+current+6]|source[offsetSrc+current+7]<<8) != 0) && ((source[offsetSrc+current+8]|source[offsetSrc+current+9]<<8) != 0) )
		{
			PATCH_Z80(source[offsetSrc+current]|source[offsetSrc+current+1]<<8+5, (source[offsetSrc+current+6]|source[offsetSrc+current+7]<<8 + master_offset)>>1 );
			PATCH_Z80(source[offsetSrc+current]|source[offsetSrc+current+1]<<8+7, (source[offsetSrc+current+8]|source[offsetSrc+current+9]<<8 + master_offset)>>1-1 );
		}
		
		current += 10;
	}
}
