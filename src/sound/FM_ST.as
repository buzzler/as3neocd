package sound
{
	public	class FM_ST
	{
		public	var index:uint;
		public	var clock:int;
		public	var rate:int;
		public	var freqbase:Number;
		public	var TimerBase:Number;
		public	var address:uint;
		public	var irq:uint;
		public	var irqmask:uint;
		public	var status:uint;
		public	var mode:uint;
		public	var prescaler_sel:uint;
		public	var fn_h:uint;
		public	var TA:int;
		public	var TAC:int;
		public	var TB:uint;
		public	var TBC:int;
		public	var DT_TABLE:Vector.<Vector.<int>>;
		public	var AR_TABLE:Vector.<int>;
		public	var DR_TABLE:Vector.<int>;
		public	var Timer_Handler:Function;
		public	var IRQ_Handler:Function;
		public	var timermodel:uint;
		
		public	function FM_ST()
		{
			DT_TABLE = new Vector.<Vector.<int>>(8, true);
			for (var i:int=0 ; i < DT_TABLE.length ; i++)
			{
				DT_TABLE[i] = new Vector.<int>(32, true);
			}
			AR_TABLE = new Vector.<int>(94, true);
			DR_TABLE = new Vector.<int>(94, true);
		}
	}
}