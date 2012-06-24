package sound
{
	public	class YM2610interface
	{
		public	var num			:int;
		public	var baseclock	:int;
		public	var volumeSSG	:Vector.<int> = new Vector.<int>(MAX_8910, true);
		public	var portAread	:Vector.<Function> = new Vector.<Function>(MAX_8910, true);
		public	var portBread	:Vector.<Function> = new Vector.<Function>(MAX_8910, true);
		public	var portAwrite	:Vector.<Function> = new Vector.<Function>(MAX_8910, true);
		public	var portBwrite	:Vector.<Function> = new Vector.<Function>(MAX_8910, true);
		
		public	var handler		:Function;
		
		public	var pcmromb		:Vector.<int> = new Vector.<int>(MAX_2610, true);
		public	var pcmroma		:Vector.<int> = new Vector.<int>(MAX_2610, true);
		public	var volumeFM	:Vector.<int> = new Vector.<int>(MAX_2610, true);
	}
}