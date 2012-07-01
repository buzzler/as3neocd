package mc68000
{
	public class opcode_handler_struct
	{
		public	var opcode_handler:Function;
		public	var mask:uint;
		public	var match:uint;
		public	var cycles:Vector.<uint>;
		
		public function opcode_handler_struct(handler:Function, mask:uint, match:uint, cycles:Array)
		{
			this.opcode_handler = handler;
			this.mask = mask;
			this.match = match;
			this.cycles = Util.toVector(cycles, "uint", true);
		}
	}
}