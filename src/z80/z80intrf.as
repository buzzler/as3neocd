
include "mz80.as"

private	function z80_init():void
{
	;
}

public	var subcpu_memspace	:Vector.<uint> = new Vector.<uint>(65536, true);
public	var sound_code		:int;
public	var pending_command	:int;
public	var result_code		:int;
public	var z80_cycles		:int;

