package sound
{
	public	class FM_OPN
	{
		public	var type	:uint;
		public	var ST		:FM_ST;
		public	var SL3		:FM_3SLOT;
		public	var P_CH	:FM_CH;
		public	var FN_TABLE:Vector.<uint>;
		public	var LFOCnt	:uint;
		public	var LFOIncr	:uint;
		public	var LFO_FREQ:Vector.<uint>;
		
		public	function FM_OPN():void
		{
			type		= 0;
			ST			= new FM_ST();
			SL3			= new FM_3SLOT();
			FN_TABLE	= new Vector.<uint>(2048, true);
			LFOCnt		= 0;
			LFOIncr		= 0;
			LFO_FREQ	= new Vector.<uint>(8, true);
		}
	}
}