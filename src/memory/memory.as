private	function initialize_memmap():void
{
	;
}

private	function cpu_setOPbase(a:int):void
{
	;
}

private	function m68k_read_memory_8(address:uint):uint
{
	return 0;
}
private	function m68k_read_memory_16(address:uint):uint
{
	return 0;
}
private	function m68k_read_memory_32(address:uint):uint
{
	return 0;
}
private	function m68k_write_memory_8(address:uint, value:uint):void
{
	;
}
private	function m68k_write_memory_16(address:uint, value:uint):void
{
	;
}
private	function m68k_write_memory_32(address:uint, value:uint):void
{
	;
}

private	function neogeo_sound_irq(irq:int):void
{
	;
}

public	var watchdog_counter:int;
public	var memcard_write	:int;
