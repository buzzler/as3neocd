package sound
{
	public	class ADPCM_CH
	{
		public	var flag:uint;
		public	var flagMask:uint;
		public	var now_data:uint;
		public	var now_addr:uint;
		public	var now_step:uint;
		public	var step:uint;
		public	var start:uint;
		public	var end:uint;
		public	var IL:int;
		public	var volume:int;
		public	var pan:int;
		public	var adpcmx:int;
		public	var adpcmd:int;
		public	var adpcml:int;
		
		public	function ADPCM_CH():void
		{
			flag		= 0;
			flagMask	= 0;
			now_data	= 0;
			now_addr	= 0;
			now_step	= 0;
			step		= 0;
			start		= 0;
			end			= 0;
			IL			= 0;
			volume		= 0;
			adpcmx		= 0;
			adpcmd		= 0;
			adpcml		= 0;
		}
	}
}