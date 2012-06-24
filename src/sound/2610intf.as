
include "fm.as"
include "ay8910.as"

private	function YM2610UpdateRequest():void
{
	;
}

private	function YM2610_sh_start():int
{
	return 0;
}

private	function YM2610_sh_stop():void
{
	;
}

private	function YM2610_sh_reset():void
{
	;
}

private	function YM2610_status_port_0_A_r(offset:uint):uint
{
	return 0
}

private	function YM2610_status_port_0_B_r(offset:uint):uint
{
	return 0;
}

private	function YM2610_read_port_0_r(offset:uint):uint
{
	return 0;
}

private	function YM2610_control_port_0_A_w(offset:uint, data:uint):void
{
	;
}

private	function YM2610_control_port_0_B_w(offset:uint, data:uint):void
{
	;
}

private	function YM2610_data_port_0_A_w(offset:uint, data:uint):void
{
	;
}

private	function YM2610_data_port_0_B_w(offset:uint, data:uint):void
{
	;
}

private	function FMTimerInit():void
{
	;
}
