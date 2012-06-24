import mc68000.m68ki_cpu_core;

include "m68kconf.as";

/**
 * m68k.h definitions
 */
private	var M68K_IRQ_NONE				:uint = 0;
private	var M68K_IRQ_1					:uint = 1;
private	var M68K_IRQ_2					:uint = 2;
private	var M68K_IRQ_3					:uint = 3;
private	var M68K_IRQ_4					:uint = 4;
private	var M68K_IRQ_5					:uint = 5;
private	var M68K_IRQ_6					:uint = 6;
private	var M68K_IRQ_7					:uint = 7;
private	var M68K_INT_ACK_AUTOVECTOR		:uint = 0xffffffff;
private	var M68K_INT_ACK_SPURIOUS		:uint = 0xfffffffe;
private	const M68K_CPU_TYPE_INVALID		:uint = 0;
private	const M68K_CPU_TYPE_68000		:uint = 1;
private	const M68K_CPU_TYPE_68010		:uint = 2;
private	const M68K_CPU_TYPE_68EC020		:uint = 3;
private	const M68K_CPU_TYPE_68020		:uint = 4;
private	const M68K_CPU_TYPE_68030		:uint = 5;
private	const M68K_CPU_TYPE_68040		:uint = 6;
private	const M68K_REG_D0				:uint = 0;
private	const M68K_REG_D1				:uint = 1;
private	const M68K_REG_D2				:uint = 2;
private	const M68K_REG_D3				:uint = 3;
private	const M68K_REG_D4				:uint = 4;
private	const M68K_REG_D5				:uint = 5;
private	const M68K_REG_D6				:uint = 6;
private	const M68K_REG_D7				:uint = 7;
private	const M68K_REG_A0				:uint = 8;
private	const M68K_REG_A1				:uint = 9;
private	const M68K_REG_A2				:uint = 10;
private	const M68K_REG_A3				:uint = 11;
private	const M68K_REG_A4				:uint = 12;
private	const M68K_REG_A5				:uint = 13;
private	const M68K_REG_A6				:uint = 14;
private	const M68K_REG_A7				:uint = 15;
private const M68K_REG_PC				:uint = 16;
private	const M68K_REG_SR				:uint = 17;
private	const M68K_REG_SP				:uint = 18;
private	const M68K_REG_USP				:uint = 19;
private	const M68K_REG_ISP				:uint = 20;
private	const M68K_REG_MSP				:uint = 21;
private	const M68K_REG_SFC				:uint = 22;
private	const M68K_REG_DFC				:uint = 23;
private	const M68K_REG_VBR				:uint = 24;
private	const M68K_REG_CACR				:uint = 25;
private	const M68K_REG_CAAR				:uint = 26;
private	const M68K_REG_PREF_ADDR		:uint = 27;
private	const M68K_REG_PREF_DATA		:uint = 28;
private	const M68K_REG_PPC				:uint = 29;
private	const M68K_REG_IR				:uint = 30;
private	const M68K_REG_CPU_TYPE			:uint = 31;

public	var m68ki_cpu				:m68ki_cpu_core;
public	var m68ki_remaining_cycles	:int;
public	var m68ki_tracing			:uint;
public	var m68ki_shift_8_table		:Vector.<uint>;
public	var m68ki_shift_16_table	:Vector.<uint>;
public	var m68ki_shift_32_table	:Vector.<uint>;
public	var m68ki_exception_cycle_table:Vector.<Vector.<uint>>;		// [][256]
public	var m68ki_address_space		:uint;
public	var m68ki_ea_idx_cycle_table:Vector.<uint>;
public	var m68ki_aerr_address		:uint;
public	var m68ki_aerr_write_mode	:uint;
public	var m68ki_aerr_fc			:uint;



private	function m68k_read_immediate_16(address:uint):uint
{
	return 0;
}
private	function m68k_read_immediate_32(address:uint):uint
{
	return 0;
}

private	function m68k_read_pcrelative_8(address:uint):uint
{
	return 0;
}
private	function m68k_read_pcrelative_16(address:uint):uint
{
	return 0;
}
private	function m68k_read_pcrelative_32(address:uint):uint
{
	return 0;
}

private	function m68k_read_disassembler_8  (address:uint):uint
{
	return 0;
}
private	function m68k_read_disassembler_16 (address:uint):uint
{
	return 0;
}
private	function m68k_read_disassembler_32 (address:uint):uint
{
	return 0;
}

private	function m68k_write_memory_32_pd(address:uint, value:uint):void
{
	;
}

private	function m68k_set_int_ack_callback(callback:Function):void
{
	;
}

private	function m68k_set_bkpt_ack_callback(callback:Function):void
{
	;
}

private	function m68k_set_reset_instr_callback(callback:Function):void
{
	;
}

private	function m68k_set_pc_changed_callback(callback:Function):void
{
	;
}

private	function m68k_set_fc_callback(callback:Function):void
{
	;
}

private	function m68k_set_instr_hook_callback(callback:Function):void
{
	;
}

private	function m68k_set_cpu_type(cpu_type:uint):void
{
	;
}

private	function m68k_init():void
{
	;
}

private	function m68k_pulse_reset():void
{
	;
}

private	function m68k_execute(num_cycles:int):int
{
	return 0;
}

private	function m68k_cycles_run():int              /* Number of cycles run so far */
{
	return 0;
}
private	function m68k_cycles_remaining():int        /* Number of cycles left */
{
	return 0;
}
private	function m68k_modify_timeslice(cycles:int):void		/* Modify cycles left */
{
	;
}
private	function m68k_end_timeslice():void          /* End timeslice now */
{
	;
}

private	function m68k_set_irq(int_level:uint):void
{
	;
}

private	function m68k_pulse_halt():void
{
	;
}

private	function m68k_context_size():uint
{
	return 0;
}

private	function m68k_get_context(dst:*):uint
{
	return 0;
}

private	function m68k_set_context(dst:*):void
{
	;
}

private	function m68k_state_register(type:String):void
{
	;
}

private	function m68k_get_reg(context:*, reg:uint):uint
{
	return 0;
}

private	function m68k_set_reg(reg:uint, value:uint):void
{
	;
}

private	function m68k_is_valid_instruction(instruction:uint, cpu_type:uint):uint
{
	return 0;
}

private	function m68k_disassemble(str_buff:String, pc:uint, cpu_type:uint):uint
{
	return 0;
}