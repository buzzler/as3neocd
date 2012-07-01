package mc68000
{
	public class m68ki_cpu_core
	{
		public	var cpu_type		:uint;
		public	var dar				:Vector.<uint>;
		public	var ppc				:uint;
		public	var pc				:uint;
		public	var sp				:Vector.<uint>;
		public	var vbr				:uint;
		public	var sfc				:uint;
		public	var dfc				:uint;
		public	var cacr			:uint;
		public	var caar			:uint;
		public	var ir				:uint;
		public	var t1_flag			:uint;
		public	var t0_flag			:uint;
		public	var s_flag			:uint;
		public	var m_flag			:uint;
		public	var x_flag			:uint;
		public	var n_flag			:uint;
		public	var not_z_flag		:uint;
		public	var v_flag			:uint;
		public	var c_flag			:uint;
		public	var int_mask		:uint;
		public	var int_level		:uint;
		public	var int_cycles		:uint;
		public	var stopped			:uint;
		public	var pref_addr		:uint;
		public	var pref_data		:uint;
		public	var address_mask	:uint;
		public	var sr_mask			:uint;
		public	var instr_mode		:uint;
		public	var run_mode		:uint;
		public	var cyc_bcc_notake_b:uint;
		public	var cyc_bcc_notake_w:uint;
		public	var cyc_dbcc_f_noexp:uint;
		public	var cyc_dbcc_f_exp	:uint;
		public	var cyc_scc_r_false	:uint;
		public	var cyc_movem_w		:uint;
		public	var cyc_movem_l		:uint;
		public	var cyc_shift		:uint;
		public	var cyc_reset		:uint;
/*		
		public	function get usp():uint
		{
			return this.sp[0];
		}
		
		public	function set usp(value:uint):void
		{
			this.sp[0] = value;
		}
		
		public	function get isp():uint
		{
			return this.sp[4];
		}
		
		public	function set isp(value:uint):void
		{
			this.sp[4] = value;
		}
		
		public	function get msp():uint
		{
			return this.sp[6];
		}
		
		public	function set msp(value:uint):void
		{
			this.sp[6] = value;
		}
		
		public	function get sp():uint
		{
			return this.dar[15];
		}
		
		public	function set sp(value:uint):void
		{
			this.sp[15] = value;
		}*/
		
		/**
		 * POINTER REFACTORING
		 */
		public	var cyc_instruction		:Vector.<uint>;
		public	var cyc_exception		:Vector.<uint>;
		public	var int_ack_callback	:Function;
		public	var bkpt_ack_callback	:Function;
		public	var reset_instr_callback:Function;
		public	var pc_changed_callback	:Function;
		public	var set_fc_callback		:Function;
		public	var instr_hook_callback	:Function;
		
		public	function m68ki_cpu_core():void
		{
			dar = new Vector.<uint>(16, true);
			sp = new Vector.<uint>(7, true);
		}
	}
}