package sound
{
	public	class YM_DELTAT
	{
		public	var memory:Vector.<uint>;
		public	var memory_size:int;
		public	var freqbase:Number;
		public	var output_pointer:Vector.<int>;
		public	var output_range:int;
		
		public	var reg:Vector.<uint> = new Vector.<uint>(16, true);
		public	var portstate:uint;
		public	var portcontrol:uint;
		public	var portshift:int;
		
		public	var flag:uint;
		public	var flagMask:uint;
		public	var now_data:uint;
		public	var now_addr:uint;
		public	var now_step:uint;
		public	var step:uint;
		public	var start:uint;
		public	var end:uint;
		public	var delta:uint;
		public	var volume:int;
		public	var pan:Vector.<int>;
		public	var adpcmx:int;
		public	var adpcmd:int;
		public	var adpcml:int;
		
		public	var volume_w_step:int;
		public	var next_leveling:int;
		public	var sample_step:int;
		
		public	var arrivedFlag:uint;	
	}
}