import flash.display.BitmapData;

private	const VIDEO_TEXT			:uint = 0;
private	const VIDEO_NORMAL			:uint = 1;
private	const VIDEO_SCANLINES		:uint = 2;

public	var video_vidram			:Vector.<uint>;
public	var video_paletteram_ng		:Vector.<uint>;
public	var video_palette_bank0_ng	:Vector.<uint> = new Vector.<uint>(4096, true);
public	var video_palette_bank1_ng	:Vector.<uint> = new Vector.<uint>(4096, true);
public	var video_paletteram_pc		:Vector.<uint>;
public	var video_palette_bank0_pc	:Vector.<uint> = new Vector.<uint>(4096, true);
public	var video_palette_bank1_pc	:Vector.<uint> = new Vector.<uint>(4096, true);
public	var video_modulo			:uint;
public	var video_pointer			:uint;
public	var video_paletteram		:Vector.<uint>;
public	var video_palette_bank0		:Vector.<uint> = new Vector.<uint>(4096, true);
public	var video_palette_bank1		:Vector.<uint> = new Vector.<uint>(4096, true);
public	var video_line_ptr			:Vector.<uint> = new Vector.<uint>(224, true);
public	var video_fix_usage			:Vector.<uint> = new Vector.<uint>(4096, true);
public	var rom_fix_usage			:Vector.<uint> = new Vector.<uint>(4096, true);
public	var video_spr_usage			:Vector.<uint> = new Vector.<uint>(32768, true);
public	var rom_spr_usage			:Vector.<uint> = new Vector.<uint>(32768, true);
public	var video_hide_fps			:Vector.<uint>;
public	var video_color_lut			:Vector.<uint> = new Vector.<uint>(32768, true);

public	var screen					:BitmapData;
public	var video_buffer			:BitmapData;
public	var game_title				:BitmapData;
public	var video_mode				:int;
public	var gamma_correction		:Number;
public	var frameskip				:int;

public	var neogeo_frame_count		:uint;
public	var neogeo_frame_counter_speed:uint;

/*-- video.c functions ----------------------------------------------------*/
public	function video_init():Boolean
{
	return true;
}

public	function video_shutdown():void
{
	;
}

public	function video_set_mode(a:int):int
{
	return 0;
}

public	function video_draw_screen1():void
{
	;
}

public	function video_save_snapshot():void
{
	;
}

public	function video_draw_spr(code:uint, color:uint, flipx:int, flipy:int, sx:int, sy:int, zx:int, zy:int):void
{
	;
}

public	function video_setup():void
{
	;
}

public	function video_fullscreen_toggle():void
{
	;
}

public	function video_mode_toggle():void
{
	;
}

public	function incframeskip():void
{
	;
}

public	var blitter:Function;


/*-- draw_fix.c functions -------------------------------------------------*/
public	function video_draw_fix():void
{
	;
}

public	function fixputs(x:uint, y:uint, string:String):void
{
	;
}
