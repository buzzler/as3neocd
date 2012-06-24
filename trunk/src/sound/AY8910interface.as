package sound
{
	public	class AY8910interface
	{
		public	var num:int;
		public	var baseclock:int;
		public	var mixing_level:Vector.<int> = new Vector.<int>(MAX_8910, true);
		public	var portAread:Vector.<Function> = new Vector.<Function>(MAX_8910, true);
		public	var portBread:Vector.<Function> = new Vector.<Function>(MAX_8910, true);
		public	var portAwrite:Vector.<Function> = new Vector.<Function>(MAX_8910, true);
		public	var portBwrite:Vector.<Function> = new Vector.<Function>(MAX_8910, true);
		
		public	var handler:Function;
	}
}