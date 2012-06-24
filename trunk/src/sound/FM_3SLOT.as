package sound
{
	public	class FM_3SLOT
	{
		public	var fc		:Vector.<uint>;
		public	var fn_h	:Vector.<uint>;
		public	var kcode	:Vector.<uint>;
		
		public	function FM_3SLOT():void
		{
			fc		= new Vector.<uint>(3, true);
			fn_h	= new Vector.<uint>(3, true);
			kcode	= new Vector.<uint>(3, true);
		}
	}
}