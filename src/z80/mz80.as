/* Multi-Z80 32 Bit emulator */

/* Copyright 1996, Neil Bradley, All rights reserved
*
* License agreement:
*
* The mZ80 emulator may be distributed in unmodified form to any medium.
*
* mZ80 May not be sold, or sold as a part of a commercial package without
* the express written permission of Neil Bradley (neil@synthcom.com). This
* includes shareware.
*
* Modified versions of mZ80 may not be publicly redistributed without author
* approval (neil@synthcom.com). This includes distributing via a publicly
* accessible LAN. You may make your own source modifications and distribute
* mZ80 in object only form.
*
* mZ80 Licensing for commercial applications is available. Please email
* neil@synthcom.com for details.
*
* Synthcom Systems, Inc, and Neil Bradley will not be held responsible for
* any damage done by the use of mZ80. It is purely "as-is".
*
* If you use mZ80 in a freeware application, credit in the following text:
*
* "Multi-Z80 CPU emulator by Neil Bradley (neil@synthcom.com)"
*
* must accompany the freeware application within the application itself or
* in the documentation.
*
* Legal stuff aside:
*
* If you find problems with mZ80, please email the author so they can get
* resolved. If you find a bug and fix it, please also email the author so
* that those bug fixes can be propogated to the installed base of mZ80
* users. If you find performance improvements or problems with mZ80, please
* email the author with your changes/suggestions and they will be rolled in
* with subsequent releases of mZ80.
*
* The whole idea of this emulator is to have the fastest available 32 bit
* Multi-z80 emulator for the PC, giving maximum performance. 
*/ 

private	const CPUREG_PC 			:uint = 0;
private	const CPUREG_Z80_AF			:uint = 1;
private	const CPUREG_Z80_BC			:uint = 2;
private	const CPUREG_Z80_DE			:uint = 3;
private	const CPUREG_Z80_HL			:uint = 4;
private	const CPUREG_Z80_AFPRIME	:uint = 5;
private	const CPUREG_Z80_BCPRIME	:uint = 6;
private	const CPUREG_Z80_DEPRIME	:uint = 7;
private	const CPUREG_Z80_HLPRIME	:uint = 8;
private	const CPUREG_Z80_IX			:uint = 9;
private	const CPUREG_Z80_IY			:uint = 10;
private	const CPUREG_Z80_SP			:uint = 11;
private	const CPUREG_Z80_I			:uint = 12;
private	const CPUREG_Z80_R			:uint = 13;
private	const CPUREG_Z80_A			:uint = 14;
private	const CPUREG_Z80_B			:uint = 15;
private	const CPUREG_Z80_C			:uint = 16;
private	const CPUREG_Z80_D			:uint = 17;
private	const CPUREG_Z80_E			:uint = 18;
private	const CPUREG_Z80_H			:uint = 19;
private	const CPUREG_Z80_L			:uint = 20;
private	const CPUREG_Z80_F			:uint = 21;
private	const CPUREG_Z80_CARRY		:uint = 22;
private	const CPUREG_Z80_NEGATIVE	:uint = 23;
private	const CPUREG_Z80_PARITY		:uint = 24;
private	const CPUREG_Z80_OVERFLOW	:uint = 25;
private	const CPUREG_Z80_HALFCARRY	:uint = 26;
private	const CPUREG_Z80_ZERO		:uint = 27;
private	const CPUREG_Z80_SIGN		:uint = 28;
private	const CPUREG_Z80_IFF1		:uint = 29;
private	const CPUREG_Z80_IFF2		:uint = 30;
private	const CPUREG_Z80_MAX_INDEX	:uint = 31;

public	function mz80exec(a:uint):uint
{
	return 0;
}

public	function mz80GetContextSize():uint
{
	return 0;
}

public	function mz80GetElapsedTicks(a:uint):uint
{
	return 0;
}

public	function mz80ReleaseTimeslice():void
{
	;
}

public	function mz80GetContext(a:*):void
{
	;
}

public	function mz80SetContext(a:*):void
{
	;
}

public	function mz80reset():void
{
	;
}

public	function mz80ClearPendingInterrupt():void
{
	;
}

public	function mz80int(a:uint):uint
{
	return 0;
}

public	function mz80nmi():uint
{
	return 0;
}

public	function mz80init():void
{
	;
}

public	var z80intAddr:uint;
public	var z80nmiAddr:uint;

public	function mz80SetRegisterValue(a:*, b:uint, c:uint):uint
{
	return 0;
}

public	function mz80GetRegisterValue(a:*, b:uint):uint
{
	return 0;
}

public	function mz80GetRegisterTextValue(a:*, b:uint, c:String):uint
{
	return 0;
}

public	function mz80GetRegisterName(a:uint):String
{
	return "";
}
	
private	const VALUE_BYTE	:uint = 0;
private	const VALUE_WORD	:uint = 1;
private	const VALUE_DWORD	:uint = 2;
private	const VALUE_IO		:uint = 3;

public	function mz80WriteValue(bWhat:uint, dwAddr:uint, dwData:uint):void
{
	;
}

public	function mz80ReadValue(bWhat:uint, dwAddr:uint):uint
{
	return 0;
}
	
private	const Z80_FLAG_CARRY			:uint = 0x01;
private	const Z80_FLAG_NEGATIVE			:uint = 0x02;
private	const Z80_FLAG_OVERFLOW_PARITY	:uint = 0x04;
private	const Z80_FLAG_UNDEFINED1		:uint = 0x08;
private	const Z80_FLAG_HALF_CARRY		:uint = 0x10;
private	const Z80_FLAG_UNDEFINED2		:uint = 0x20;
private	const Z80_FLAG_ZERO				:uint = 0x40;
private	const Z80_FLAG_SIGN				:uint = 0x80;
private	const IFF1						:uint = 0x01;
private	const IFF2						:uint = 0x02;

