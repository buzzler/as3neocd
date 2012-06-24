package z80
{
	public class MemoryWriteByte
	{
		public	var lowAddr		:uint;
		public	var highAddr	:uint;
		public	var memoryCall	:Function;
		public	var pUserArea	:*;
	}
	
	public class MemoryReadByte
	{
		public	var lowAddr		:uint;
		public	var highAddr	:uint;
		public	var memoryCall	:Function;
		public	var pUserArea	:*;
	}
	
	public class z80PortWrite
	{
		public	var lowIoAddr	:uint;
		public	var highIoAddr	:uint;
		public	var IOCall		:Function;
		public	var pUserArea	:*;
	}
	
	public class z80PortRead
	{
		public	var lowIoAddr	:uint;
		public	var highIoAddr	:uint;
		public	var	IOCall		:Function;
		public	var pUserArea	:*;
	}
	
	public class z80TrapRec
	{
		public	var trapAddr:uint;
		public	var skipCnt	:uint;
		public	var origIns	:uint;
	}
	
	public class reg_af
	{
		public	var wFiller:uint = 0;
		public	var a:uint = 0;
		public	var f:uint = 0;
		
		public	function get af():uint
		{
			return wFiller<<16 | a<<8 | f;
		}
		
		public	function set af(value:uint):void
		{
			wFiller = value & 0xFFFF0000;
			a = value & 0xFF00;
			f = value & 0xFF;
		}
	}
	
	public class reg_bc
	{
		public	var wFiller:uint = 0;
		public	var b:uint = 0;
		public	var c:uint = 0;
		
		public	function get bc():uint
		{
			return wFiller<<16 | b<<8 | c;
		}
		
		public	function set bc(value:uint):void
		{
			wFiller = value & 0xFFFF0000;
			b = value & 0xFF00;
			c = value & 0xFF;
		}
	}
	
	public class reg_de
	{
		public	var wFiller:uint = 0;
		public	var d:uint = 0;
		public	var e:uint = 0;
		
		public	function get de():uint
		{
			return wFiller<<16 | d<<8 | e;
		}
		
		public	function set de(value:uint):void
		{
			wFiller = value & 0xFFFF0000;
			d = value & 0xFF00;
			e = value & 0xFF;
		}
	}
	
	public class reg_hl
	{
		public	var wFiller:uint = 0;
		public	var h:uint = 0;
		public	var l:uint = 0;
		
		public	function get hl():uint
		{
			return wFiller<<16 | h <<8 | l;
		}
		
		public	function set hl(value:uint):void
		{
			wFiller = value & 0xFFFF0000;
			h = value & 0xFF00;
			l = value & 0xFF;
		}
	}
	
	public class reg_ix
	{
		public	var wFiller:uint = 0;
		public	var xh:uint = 0;
		public	var xl:uint = 0;
		
		public	function get ix():uint
		{
			return wFiller<<16 | xh<<8 | xl;
		}
		
		public	function set ix(value:uint):void
		{
			wFiller = value & 0xFFFF0000;
			xh = value & 0xFF00;
			xl = value & 0xFF;
		}
	}
	
	public class reg_iy
	{
		public	var wFiller:uint = 0;
		public	var yh:uint = 0;
		public	var yl:uint = 0;
		
		public	function get iy():uint
		{
			return wFiller<<16 | yh<<8 | yl;
		}
		
		public	function set iy(value:uint):void
		{
			wFiller = value & 0xFFFF0000;
			yh = value & 0xFF00;
			yl = value & 0xFF;
		}
	}
	
	public class CONTEXTMZ80
	{
		public	var z80base:uint;
		public	var z80MemRead:MemoryReadByte;
		public	var z80MemWrite:MemoryWriteByte;
		public	var z80IoRead:z80PortRead;
		public	var z80IoWrite:z80PortWrite;
		public	var z80clockticks:uint;
		public	var z80iff:uint;
		public	var z80interruptMode:uint;
		public	var z80halted:uint;
		public	var z80af:reg_af;
		public	var z80bc:reg_bc;
		public	var z80de:reg_de;
		public	var z80hl:reg_hl;
		public	var z80afprime:uint;
		public	var z80bcprime:uint;
		public	var z80deprime:uint;
		public	var z80hlprime:uint;
		public	var z80ix:reg_ix;
		public	var z80iy:reg_iy;
		public	var z80sp:uint;
		public	var z80pc:uint;
		public	var z80nmiAddr:uint;
		public	var z80intAddr:uint;
		public	var z80rCounter:uint;
		public	var z80i:uint;
		public	var z80r:uint;
		public	var z80intPending:uint;
		
		public	function set z80AF(value:uint):void	{z80af.af=value;}
		public	function get z80AF():uint			{return z80af.af;}
		public	function set z80A(value:uint):void	{z80af.a=value;}
		public	function get z80A():uint			{return z80af.a;}
		public	function set z80F(value:uint):void	{z80af.f=value;}
		public	function get z80F():uint			{return z80af.f;}
		
		public	function set z80BC(value:uint):void	{z80bc.bc=value;}
		public	function get z80BC():uint			{return z80bc.bc;}
		public	function set z80B(value:uint):void	{z80bc.b=value;}
		public	function get z80B():uint			{return z80bc.b;}
		public	function set z80C(value:uint):void	{z80bc.c=value;}
		public	function get z80C():uint			{return z80bc.c;}
		
		public	function set z80DE(value:uint):void	{z80de.de=value;}
		public	function get z80DE():uint			{return z80de.de;}
		public	function set z80D(value:uint):void	{z80de.d=value;}
		public	function get z80D():uint			{return z80de.d;}
		public	function set z80E(value:uint):void	{z80de.e=value;}
		public	function get z80E():uint			{return z80de.e;}
		
		public	function set z80HL(value:uint):void	{z80hl.hl=value;}
		public	function get z80HL():uint			{return z80hl.hl;}
		public	function set z80H(value:uint):void	{z80hl.h=value;}
		public	function get z80H():uint			{return z80hl.h;}
		public	function set z80L(value:uint):void	{z80hl.l=value;}
		public	function get z80L():uint			{return z80hl.l;}
		
		public	function set z80SP(value:uint):void	{z80sp=value;}
		public	function get z80SP():uint			{return z80sp;}
		
		public	function set z80IX(value:uint):void	{z80ix.ix=value;}
		public	function get z80IX():uint			{return z80ix.ix;}
		public	function set z80XH(value:uint):void	{z80ix.xh=value;}
		public	function get z80XH():uint			{return z80ix.xh;}
		public	function set z80XL(value:uint):void	{z80ix.xl=value;}
		public	function get z80XL():uint			{return z80ix.xl;}
		
		public	function set z80IY(value:uint):void	{z80iy.iy=value;}
		public	function get z80IY():uint			{return z80iy.iy;}
		public	function set z80YH(value:uint):void	{z80iy.yh=value;}
		public	function get z80YH():uint			{return z80iy.yh;}
		public	function set z80YL(value:uint):void	{z80iy.yl=value;}
		public	function get z80YL():uint			{return z80iy.yl;}
	}
}

