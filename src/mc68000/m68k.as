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

/**
 * m68kcpu.h definition
 */
private	const M68K_INT_GT_32_BIT				:Boolean = false;
private	const EXCEPTION_BUS_ERROR				:uint = 2;
private	const EXCEPTION_ADDRESS_ERROR			:uint = 3;
private const EXCEPTION_ILLEGAL_INSTRUCTION		:uint = 4;
private	const EXCEPTION_ZERO_DIVIDE				:uint = 5;
private	const EXCEPTION_CHK						:uint = 6;
private	const EXCEPTION_TRAPV					:uint = 7;
private	const EXCEPTION_PRIVILEGE_VIOLATION		:uint = 8;
private	const EXCEPTION_TRACE					:uint = 9;
private const EXCEPTION_1010					:uint = 10;
private	const EXCEPTION_1111					:uint = 11;
private	const EXCEPTION_FORMAT_ERROR			:uint = 14;
private	const EXCEPTION_UNINITIALIZED_INTERRUPT	:uint = 15;
private	const EXCEPTION_SPURIOUS_INTERRUPT		:uint = 24;
private	const EXCEPTION_INTERRUPT_AUTOVECTOR	:uint = 24;
private	const EXCEPTION_TRAP_BASE				:uint = 32;
private const FUNCTION_CODE_USER_DATA			:uint = 1;
private	const FUNCTION_CODE_USER_PROGRAM		:uint = 2;
private	const FUNCTION_CODE_SUPERVISOR_DATA		:uint = 5;
private	const FUNCTION_CODE_SUPERVISOR_PROGRAM	:uint = 6;
private	const FUNCTION_CODE_CPU_SPACE			:uint = 7;
private	const CPU_TYPE_000						:uint = 1;
private	const CPU_TYPE_010						:uint = 2;
private	const CPU_TYPE_EC020					:uint = 4;
private	const CPU_TYPE_020						:uint = 8;
private	const STOP_LEVEL_STOP					:uint = 1;
private	const STOP_LEVEL_HALT					:uint = 2;
private	const INSTRUCTION_YES					:uint = 0;
private	const INSTRUCTION_NO					:uint = 0x08;
private	const MODE_READ							:uint = 0x10;
private	const MODE_WRITE						:uint = 0;
private	const RUN_MODE_NORMAL					:uint = 0;
private	const RUN_MODE_BERR_AERR_RESET			:uint = 1;

/**
 * MACRO - REFACTORING
 */
private	function MAKE_INT_8(value:uint):int	{return (value&0x80 > 0) ? value | ~0x000000FF : value & 0x000000FF;}
private	function MAKE_INT_16(value:uint):int{return (value&0x8000 > 0) ? value | ~0x0000FFFF : value & 0x0000FFFF;}
private	function MAKE_INT_32(value:uint):int{return (value&0x80000000 > 0) ? value | ~0x7FFFFFFF : value & 0xFFFFFFFF;}
private	function BIT_0(A:uint):uint			{return A & 0x00000001;}
private	function BIT_1(A:uint):uint			{return A & 0x00000002;}
private	function BIT_2(A:uint):uint			{return A & 0x00000004;}
private	function BIT_3(A:uint):uint			{return A & 0x00000008;}
private	function BIT_4(A:uint):uint			{return A & 0x00000010;}
private	function BIT_5(A:uint):uint			{return A & 0x00000020;}
private	function BIT_6(A:uint):uint			{return A & 0x00000040;}
private	function BIT_7(A:uint):uint			{return A & 0x00000080;}
private	function BIT_8(A:uint):uint			{return A & 0x00000100;}
private	function BIT_9(A:uint):uint			{return A & 0x00000200;}
private	function BIT_A(A:uint):uint			{return A & 0x00000400;}
private	function BIT_B(A:uint):uint			{return A & 0x00000800;}
private	function BIT_C(A:uint):uint			{return A & 0x00001000;}
private	function BIT_D(A:uint):uint			{return A & 0x00002000;}
private	function BIT_E(A:uint):uint			{return A & 0x00004000;}
private	function BIT_F(A:uint):uint			{return A & 0x00008000;}
private	function BIT_10(A:uint):uint		{return A & 0x00010000;}
private	function BIT_11(A:uint):uint		{return A & 0x00020000;}
private	function BIT_12(A:uint):uint		{return A & 0x00040000;}
private	function BIT_13(A:uint):uint		{return A & 0x00080000;}
private	function BIT_14(A:uint):uint		{return A & 0x00100000;}
private	function BIT_15(A:uint):uint		{return A & 0x00200000;}
private	function BIT_16(A:uint):uint		{return A & 0x00400000;}
private	function BIT_17(A:uint):uint		{return A & 0x00800000;}
private	function BIT_18(A:uint):uint		{return A & 0x01000000;}
private	function BIT_19(A:uint):uint		{return A & 0x02000000;}
private	function BIT_1A(A:uint):uint		{return A & 0x04000000;}
private	function BIT_1B(A:uint):uint		{return A & 0x08000000;}
private	function BIT_1C(A:uint):uint		{return A & 0x10000000;}
private	function BIT_1D(A:uint):uint		{return A & 0x20000000;}
private	function BIT_1E(A:uint):uint		{return A & 0x40000000;}
private	function BIT_1F(A:uint):uint		{return A & 0x80000000;}
private	function GET_MSB_8(A:uint)			{return A & 0x80;}
private	function GET_MSB_9(A:uint)			{return A & 0x100;}
private	function GET_MSB_16(A:uint)			{return A & 0x8000;}
private	function GET_MSB_17(A:uint)			{return A & 0x10000;}
private	function GET_MSB_32(A:uint)			{return A & 0x80000000;}
private	function LOW_NIBBLE(A:uint)			{return A & 0x0F;}
private	function HIGH_NIBBLE(A:uint)		{return A & 0xF0;}
private	function MASK_OUT_ABOVE_2(A:uint)	{return A & 3;}
private	function MASK_OUT_ABOVE_8(A:uint)	{return A & 0xFF;}
private	function MASK_OUT_ABOVE_16(A:uint)	{return A & 0xFFFF;}
private	function MASK_OUT_ABOVE_32(A:uint)	{return A;}
private	function MASK_OUT_BELOW_2(A:uint)	{return A & ~3;}
private	function MASK_OUT_BELOW_8(A:uint)	{return A & ~0xFF;}
private	function MASK_OUT_BELOW_16(A:uint)	{return A & ~0xFFFF;}
private	function MASK_OUT_BELOW_32(A:uint)	{return 0;}
private	function ADDRESS_68K(A:uint)		{return A & CPU_ADDRESS_MASK;}
private	function LSL(A:uint, C:uint)		{return A << C;}
private	function LSR(A:uint, C:uint)		{return A >> C;}
private	function LSR_32(A:uint, C:uint)		{return (C<32) ? A >> C:0;}
private	function LSL_32(A:uint, C:uint)		{return (C<32) ? A << C:0;}
private	function ROL_8(A:uint, C:uint)		{return MASK_OUT_ABOVE_8( LSL(A,C) | (A,8-C));}
private	function ROL_9(A:uint, C:uint)		{return LSL(A,C) | LSR(A,9-C);}
private	function ROL_16(A:uint, C:uint)		{return MASK_OUT_ABOVE_16( LSL(A,C) | LSR(A,16-C) );}
private	function ROL_17(A:uint, C:uint)		{return LSL(A,C) | LSR(A,17-C);}
private	function ROL_32(A:uint, C:uint)		{return MASK_OUT_ABOVE_32( LSL_32(A,C) | LSR_32(A,32-C) );}
private	function ROL_33(A:uint, C:uint)		{return LSL_32(A,C) | LSR_32(A,33-C);}
private	function ROR_8(A:uint, C:uint)		{return MASK_OUT_ABOVE_8( LSR(A,C) | LSL(A,8-C) );}
private	function ROR_9(A:uint, C:uint)		{return LSR(A,C) | LSL(A,9-C);}
private	function ROR_16(A:uint, C:uint)		{return MASK_OUT_ABOVE_16( LSR(A,C) | LSL(A,16-C) );}
private	function ROR_17(A:uint, C:uint)		{return LSR(A,C) | LSL(A,17-C);}
private	function ROR_32(A:uint, C:uint)		{return MASK_OUT_ABOVE_32( LSR_32(A,C) | LSL_32(A,32-C) );}
private	function ROR_33(A:uint, C:uint)		{return LSR_32(A,C) | LSL_32(A,33-C);}

private	function CPU_TYPE_IS_020_PLUS(A:uint):Boolean
{
	return false;
}

private	function CPU_TYPE_IS_020_LESS(A:uint):Boolean
{
	return true;
}

private	function CPU_TYPE_IS_EC020_PLUS(A:uint):Boolean
{
	return false;
}

private	function CPU_TYPE_IS_EC020_LESS(A:uint):Boolean
{
	return true;
}

private	function CPU_TYPE_IS_010(A:uint):Boolean
{
	return false;
}

private	function CPU_TYPE_IS_010_PLUS(A:uint):Boolean
{
	return false;
}

private	function CPU_TYPE_IS_010_LESS(A:uint):Boolean
{
	return true;
}

private	function CPU_TYPE_IS_020_VARIANT(A:uint):Boolean
{
	return false;
}

private	function CPU_TYPE_IS_000(A:uint):Boolean
{
	return true;
}

private	function m68ki_int_ack(A:uint):uint
{
	return M68K_INT_ACK_AUTOVECTOR;
}

private	function m68ki_bkpt_ack(A:uint):void {}
private	function m68ki_output_reset():void {}
private	function m68ki_instr_hook():void {}
private	function m68ki_pc_changed(A:uint):void {}
private	function m68ki_set_fc(A:uint):void {}
private	function m68ki_use_data_space():void {}
private	function m68ki_use_program_space():void {}
private	function m68ki_get_address_space():uint
{
	return FUNCTION_CODE_USER_DATA;
}
private	function m68ki_set_address_error_trap():void {}
private	function m68ki_check_address_error(ADDR:uint, WRITE_MODE:uint, FC:uint):void {}
private	function M68K_DO_LOG(A:uint):void {}
private	function M68K_DO_LOG_EMU(A:uint):void {}

/* ----------------------------- Configuration ---------------------------- */
#define m68k_read_immediate_16(A) m68ki_read_program_16(A)
#define m68k_read_immediate_32(A) m68ki_read_program_32(A)
#define m68k_read_pcrelative_8(A) m68ki_read_program_8(A)
#define m68k_read_pcrelative_16(A) m68ki_read_program_16(A)
#define m68k_read_pcrelative_32(A) m68ki_read_program_32(A)


/* -------------------------- EA / Operand Access ------------------------- */

/*
* The general instruction format follows this pattern:
* .... XXX. .... .YYY
* where XXX is register X and YYY is register Y
*/
/* Data Register Isolation */
#define DX (REG_D[(REG_IR >> 9) & 7])
#define DY (REG_D[REG_IR & 7])
/* Address Register Isolation */
#define AX (REG_A[(REG_IR >> 9) & 7])
#define AY (REG_A[REG_IR & 7])


/* Effective Address Calculations */
#define EA_AY_AI_8()   AY                                    /* address register indirect */
#define EA_AY_AI_16()  EA_AY_AI_8()
#define EA_AY_AI_32()  EA_AY_AI_8()
#define EA_AY_PI_8()   (AY++)                                /* postincrement (size = byte) */
#define EA_AY_PI_16()  ((AY+=2)-2)                           /* postincrement (size = word) */
#define EA_AY_PI_32()  ((AY+=4)-4)                           /* postincrement (size = long) */
#define EA_AY_PD_8()   (--AY)                                /* predecrement (size = byte) */
#define EA_AY_PD_16()  (AY-=2)                               /* predecrement (size = word) */
#define EA_AY_PD_32()  (AY-=4)                               /* predecrement (size = long) */
#define EA_AY_DI_8()   (AY+MAKE_INT_16(m68ki_read_imm_16())) /* displacement */
#define EA_AY_DI_16()  EA_AY_DI_8()
#define EA_AY_DI_32()  EA_AY_DI_8()
#define EA_AY_IX_8()   m68ki_get_ea_ix(AY)                   /* indirect + index */
#define EA_AY_IX_16()  EA_AY_IX_8()
#define EA_AY_IX_32()  EA_AY_IX_8()

#define EA_AX_AI_8()   AX
#define EA_AX_AI_16()  EA_AX_AI_8()
#define EA_AX_AI_32()  EA_AX_AI_8()
#define EA_AX_PI_8()   (AX++)
#define EA_AX_PI_16()  ((AX+=2)-2)
#define EA_AX_PI_32()  ((AX+=4)-4)
#define EA_AX_PD_8()   (--AX)
#define EA_AX_PD_16()  (AX-=2)
#define EA_AX_PD_32()  (AX-=4)
#define EA_AX_DI_8()   (AX+MAKE_INT_16(m68ki_read_imm_16()))
#define EA_AX_DI_16()  EA_AX_DI_8()
#define EA_AX_DI_32()  EA_AX_DI_8()
#define EA_AX_IX_8()   m68ki_get_ea_ix(AX)
#define EA_AX_IX_16()  EA_AX_IX_8()
#define EA_AX_IX_32()  EA_AX_IX_8()

#define EA_A7_PI_8()   ((REG_A[7]+=2)-2)
#define EA_A7_PD_8()   (REG_A[7]-=2)

#define EA_AW_8()      MAKE_INT_16(m68ki_read_imm_16())      /* absolute word */
#define EA_AW_16()     EA_AW_8()
#define EA_AW_32()     EA_AW_8()
#define EA_AL_8()      m68ki_read_imm_32()                   /* absolute long */
#define EA_AL_16()     EA_AL_8()
#define EA_AL_32()     EA_AL_8()
#define EA_PCDI_8()    m68ki_get_ea_pcdi()                   /* pc indirect + displacement */
#define EA_PCDI_16()   EA_PCDI_8()
#define EA_PCDI_32()   EA_PCDI_8()
#define EA_PCIX_8()    m68ki_get_ea_pcix()                   /* pc indirect + index */
#define EA_PCIX_16()   EA_PCIX_8()
#define EA_PCIX_32()   EA_PCIX_8()


#define OPER_I_8()     m68ki_read_imm_8()
#define OPER_I_16()    m68ki_read_imm_16()
#define OPER_I_32()    m68ki_read_imm_32()



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