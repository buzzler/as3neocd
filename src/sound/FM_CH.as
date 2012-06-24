package sound
{
	public	class FM_CH
	{
		public	var SLOT:Vector.<FM_SLOT> = new Vector.<FM_SLOT>(4, true);
		public	var PAN	:uint;
		public	var ANGO:uint;
		public	var FB	:uint;
		public	var op1_out:Vector.<int> = new Vector.<int>(2, true);
		public	var connect1:int;
		public	var connect2:int;
		public	var connect3:int;
		public	var connect4:int;
		public	var pms:int;
		public	var ams:uint;
		public	var fc:uint;
		public	var fn_h:uint;
		public	var kcode:uint;
	}
}