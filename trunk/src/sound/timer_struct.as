package sound
{
	public	class timer_struct
	{
		public	var time:Number;
		public	var odo_debut:uint;
		public	var nb_cycle:uint;
		public	var param:int;
		public	var del_it:uint;
		public	var func:Function;
		public	var next:timer_struct;
	}
}