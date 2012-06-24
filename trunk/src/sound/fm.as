import sound.YM_DELTAT;
import sound.YM2610;

include "ymdeltat.as"

private	const BUILD_YM2610:uint = 1;
private	const BUILD_YM2608:uint = 0;

private	const FM_STEREO_MIX:uint = 0;
private	const FM_OUTPUT_BIT:uint = 16;
private	const FM_INTERNAL_TIMER:uint = 0;

private	const FM_LFO_SUPPORT:uint = 1;
private	const FM_SEG_SUPPORT:uint = 1;



/* --- external SSG(YM2149/AY-3-8910)emulator interface port */
/* used by YM2203,YM2608,and YM2610 */

/* SSGClk   : Set SSG Clock      */
/* int n    = chip number        */
/* int clk  = MasterClock(Hz)    */
/* int rate = sample rate(Hz) */
private	function SSGClk(clock:int):void
{
	AY8910_set_clock(clock);
}

/* SSGWrite : Write SSG port     */
/* int n    = chip number        */
/* int a    = address            */
/* int v    = data               */
private	function SSGWrite(a:int, v:int):void
{
	AY8910Write(a,v);
}

/* SSGRead  : Read SSG port */
/* int n    = chip number   */
/* return   = Read data     */
private	function SSGRead():int
{
	return AY8910Read();
}

/* SSGReset : Reset SSG chip */
/* int n    = chip number   */
private	function SSGReset():void
{
	AY8910_reset();
}

private	function YM2610UpdateReq():void
{
	;
}

private	const YM2151_NUMBUF	:uint = 2;
private	const YM2608_NUMBUF	:uint = 2;
private	const YM2610_NUMBUF	:uint = 2;
private	const YM2612_NUMBUF	:uint = 2;

private	var FM_TIMERHANDLER	:Function;
private	var FM_IRQHANDLER	:Function;

public	var FM2610:YM2610 = new YM2610();

private	function YM2610Init(baseclock:int, rate:int, pcmroma:*, pcmasize:int, pcmromb:*, pcmbsize:int, TimerHandler:Function, IRQHandler:Function):int
{
	return 0;
}

private	function YM2610Shutdown():void
{
	;
}

private	function YM2610ResetChip():void
{
	;
}

private	function YM2610UpdateOne(num:int, buffer:Vector.<int>, length:int):void
{
	;
}

private	function YM2610Write(a:int, v:uint):int
{
	return 0;
}

private	function YM2610Read(a:int):uint
{
	return 0;
}

private	function YM2610TimerOver(c:int):int
{
	return 0;
}
