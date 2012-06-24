package sound
{
	public	class YM2610
	{
		
		public	var REGS:Vector.<uint>;
		public	var OPN	:FM_OPN;
		public	var CH:Vector.<FM_CH>;
		public	var address1:int;
		public	var pcmbuf:uint;
		public	var pcm_size:uint;
		public	var adpcmTL:int;
		public	var adpcm:Vector.<ADPCM_CH>;
		public	var adpcmreg:Vector.<uint>
		public	var adpcm_arrivedEndAddress:uint;
		public	var deltaT:YM_DELTAT;
		
		public	function YM2610():void
		{
			REGS					= new Vector.<uint>(512, true);
			OPN						= new FM_OPN();
			CH						= new Vector.<FM_CH>(6, true);
			address1				= 0;
			pcm_size				= 0;
			adpcm					= new Vector.<ADPCM_CH>(6, true);
			adpcmreg				= new Vector.<uint>(0x30, true);
			adpcm_arrivedEndAddress	= 0;
		}
	}
}