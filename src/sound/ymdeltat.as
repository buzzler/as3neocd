
import sound.YM_DELTAT;

private	const YM_DELTAT_SHIFT:uint = 16;

public	var ym_deltat_memory:Vector.<uint>;

private	function YM_DELTAT_DECODE_PRESET(DELTAT:YM_DELTAT):void
{
	ym_deltat_memory = DELTAT.memory;
}

private	function YM_DELTAT_ADPCM_Write(DELTAT:YM_DELTAT, r:int, v:int):void
{
	;
}

private	function YM_DELTAT_ADPCM_Reset(DELTAT:YM_DELTAT, pan:int):void
{
	;
}

private	const YM_DELTAT_DELTA_MAX:int = 24576;
private	const YM_DELTAT_DELTA_MIN:int = 127;
private	const YM_DELTAT_DELTA_DEF:int = 127;

private	const YM_DELTAT_DECODE_RANGE:int = 32768;
private	const YM_DELTAT_DECODE_MIN:int = -YM_DELTAT_DECODE_RANGE;
private	const YM_DELTAT_DECODE_MAX:int = YM_DELTAT_DECODE_RANGE-1;

public	var ym_deltat_decode_tableB1:Vector.<int>;
public	var ym_deltat_decode_tableB2:Vector.<int>;

private	function YM_DELTAT_Limit(val:int,max:int,min:int):void
{
	if ( val > max ) val = max;
	else if ( val < min ) val = min;
}

private	function YM_DELTAT_ADPCM_CALC(DELTAT:YM_DELTAT):void
{
	;
}

private	function YM_DELTAT_postload(DELTAT:YM_DELTAT, regs:Vector.<uint>):void
{
	;
}

private	function YM_DELTAT_savestate(DELTAT:YM_DELTAT):void
{
	;
}
