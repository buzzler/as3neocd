import mc68000.m68ki_cpu_core;

include "m68kconf.as";

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
private	var m68ki_cpu_names			:Vector.<String>;
public	var m68ki_initial_cycles	:int;
public	var m68ki_remaining_cycles	:int;
public	var m68ki_tracing			:uint;
public	var m68ki_shift_8_table		:Vector.<uint>;
public	var m68ki_shift_16_table	:Vector.<uint>;
public	var m68ki_shift_32_table	:Vector.<uint>;
public	var m68ki_exception_cycle_table:Vector.<Vector.<uint>>;
public	var m68ki_address_space		:uint;
public	var m68ki_ea_idx_cycle_table:Vector.<uint>;
public	var m68ki_aerr_address		:uint;
public	var m68ki_aerr_write_mode	:uint;
public	var m68ki_aerr_fc			:uint;

include "m68kopac.as"
include "m68kopdm.as"
include "m68kopnz.as"
include "m68kops.as"

private	function init_m68k():void
{
	m68ki_initial_cycles = 0;
	m68ki_remaining_cycles = 0;
	m68ki_tracing = 0;
	m68ki_address_space = 0;
	
	m68ki_cpu_names = Util.toVector(["Invalid CPU",	"M68000", "M68010",	"Invalid CPU", "M68EC020", "Invalid CPU", "Invalid CPU", "Invalid CPU",	"M68020"], "string", true);
	m68ki_cpu = new m68ki_cpu_core();
	m68ki_aerr_address = 0;
	m68ki_aerr_write_mode = 0;
	m68ki_aerr_fc = 0;
	
	m68ki_shift_8_table = Util.toVector([
		0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff
	], "uint", true);
	
	m68ki_shift_16_table = Util.toVector([
		0x0000, 0x8000, 0xc000, 0xe000, 0xf000, 0xf800, 0xfc00, 0xfe00, 0xff00,
		0xff80, 0xffc0, 0xffe0, 0xfff0, 0xfff8, 0xfffc, 0xfffe, 0xffff, 0xffff,
		0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
		0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
		0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
		0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
		0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
		0xffff, 0xffff
	], "uint", true);
	
	m68ki_shift_32_table = Util.toVector([
		0x00000000, 0x80000000, 0xc0000000, 0xe0000000, 0xf0000000, 0xf8000000,
		0xfc000000, 0xfe000000, 0xff000000, 0xff800000, 0xffc00000, 0xffe00000,
		0xfff00000, 0xfff80000, 0xfffc0000, 0xfffe0000, 0xffff0000, 0xffff8000,
		0xffffc000, 0xffffe000, 0xfffff000, 0xfffff800, 0xfffffc00, 0xfffffe00,
		0xffffff00, 0xffffff80, 0xffffffc0, 0xffffffe0, 0xfffffff0, 0xfffffff8,
		0xfffffffc, 0xfffffffe, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
		0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
		0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
		0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
		0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
		0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
	], "uint", true);
	
	m68ki_exception_cycle_table = new Vector.<Vector.<uint>>(3, true);
	m68ki_exception_cycle_table[0] = Util.toVector([
		4,
		4,
		50,
		50,
		34,
		38,
		40,
		34,
		34,
		34,
		4,
		4,
		4,
		4,
		4,
		44,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		44,
		44,
		44,
		44,
		44,
		44,
		44,
		44,
		34,
		34,
		34,
		34,
		34,
		34,
		34,
		34,
		34,
		34,
		34,
		34,
		34,
		34,
		34,
		34,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
	], "uint", true);
	m68ki_exception_cycle_table[1] = Util.toVector([
		4,
		4,
		126,
		126,
		38,
		44,
		44,
		34,
		38,
		38,
		4,
		4,
		4,
		4,
		4,
		44,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		46,
		46,
		46,
		46,
		46,
		46,
		46,
		46,
		38,
		38,
		38,
		38,
		38,
		38,
		38,
		38,
		38,
		38,
		38,
		38,
		38,
		38,
		38,
		38,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
	], "uint", true);
	m68ki_exception_cycle_table[2] = Util.toVector([
		4,
		4,
		50,
		50,
		20,
		38,
		40,
		20,
		34,
		25,
		20,
		20,
		4,
		4,
		4,
		30,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		30,
		30,
		30,
		30,
		30,
		30,
		30,
		30,
		20,
		20,
		20,
		20,
		20,
		20,
		20,
		20,
		20,
		20,
		20,
		20,
		20,
		20,
		20,
		20,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
	], "uint", true);
	
	m68ki_ea_idx_cycle_table = Util.toVector([
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0,
		5,
		7,
		7,
		0, 5, 7, 7, 0, 5, 7, 7, 0, 5, 7, 7,
		2,
		7,
		9,
		9,
		0, 7, 9, 9, 0, 7, 9, 9, 0, 7, 9, 9,
		6,
		11,
		13,
		13,
		0, 11, 13, 13, 0, 11, 13, 13, 0, 11, 13, 13
	], "uint", true);
	
	init_m68kops();
}

private	function m68ki_read_imm_16():uint
{
	m68ki_cpu.pc += 2;
	return m68ki_read_16_fc(((m68ki_cpu.pc-2)&m68ki_cpu.address_mask), m68ki_cpu.s_flag | 2);
}

private	function m68ki_read_imm_32():uint
{
	m68ki_cpu.pc += 4;
	return m68ki_read_32_fc(((m68ki_cpu.pc-4)&m68ki_cpu.address_mask), m68ki_cpu.s_flag | 2);
	
}
private function m68ki_read_8_fc(address:uint, fc:uint):uint
{
	return m68k_read_memory_8(((address)&m68ki_cpu.address_mask));
}

private function m68ki_read_16_fc(address:uint, fc:uint):uint
{
	return m68k_read_memory_16(((address)&m68ki_cpu.address_mask));
}

private function m68ki_read_32_fc(address:uint, fc:uint):uint
{
	return m68k_read_memory_32(((address)&m68ki_cpu.address_mask));
}

private function m68ki_write_8_fc(address:uint, fc:uint, value:uint):void
{
	m68k_write_memory_8(((address)&m68ki_cpu.address_mask), value);
}

private function m68ki_write_16_fc(address:uint, fc:uint, value:uint):void
{
	m68k_write_memory_16(((address)&m68ki_cpu.address_mask), value);
}

private function m68ki_write_32_fc(address:uint, fc:uint, value:uint):void
{
	m68k_write_memory_32(((address)&m68ki_cpu.address_mask), value);
}

private function m68ki_get_ea_pcdi():uint
{
	var old_pc:uint = m68ki_cpu.pc;
	return old_pc + (m68ki_read_imm_16() as int);
}

private	function m68ki_get_ea_pcix():uint
{
	return m68ki_get_ea_ix(m68ki_cpu.pc);
}

private	function m68ki_get_ea_ix(An:uint):uint
{
	var extension:uint = m68ki_read_imm_16();
	var Xn:uint = 0;
	
	Xn = m68ki_cpu.dar[extension>>12];
	if ((extension & 0x00000800) == 0)
		Xn = (Xn as int);
	
	return An + Xn + (extension as int);
}

private	function OPER_AY_AI_8():uint {var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]; return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_AI_16():uint {var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]; return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_AI_32():uint {var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]; return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_PI_8():uint {var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]++; return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_PI_16():uint {var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+=2)-2); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_PI_32():uint {var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+=4)-4); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_PD_8():uint {var ea:uint = --m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]; return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_PD_16():uint {var ea:uint = (m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]-=2); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_PD_32():uint {var ea:uint = (m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]-=4); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_DI_8():uint {var ea:uint = (m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8])+(m68ki_read_imm_16() as int); return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_DI_16():uint {var ea:uint = (m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8])+(m68ki_read_imm_16() as int); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_DI_32():uint {var ea:uint = (m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8])+(m68ki_read_imm_16() as int); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_IX_8():uint {var ea:uint = m68ki_get_ea_ix(m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]); return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_IX_16():uint {var ea:uint = m68ki_get_ea_ix(m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AY_IX_32():uint {var ea:uint = m68ki_get_ea_ix(m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_AI_8():uint {var ea:uint = m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]; return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_AI_16():uint {var ea:uint = m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]; return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_AI_32():uint {var ea:uint = m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]; return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_PI_8():uint {var ea:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]++); return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_PI_16():uint {var ea:uint = ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]+=2)-2); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_PI_32():uint {var ea:uint = ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]+=4)-4); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_PD_8():uint {var ea:uint = --m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]; return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_PD_16():uint {var ea:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]-=2); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_PD_32():uint {var ea:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]-=4); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_DI_8():uint {var ea:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8])+(m68ki_read_imm_16() as int); return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_DI_16():uint {var ea:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8])+(m68ki_read_imm_16() as int); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_DI_32():uint {var ea:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8])+(m68ki_read_imm_16() as int); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_IX_8():uint {var ea:uint = m68ki_get_ea_ix(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
private function OPER_AX_IX_16():uint {var ea:uint = m68ki_get_ea_ix(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AX_IX_32():uint {var ea:uint = m68ki_get_ea_ix(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_A7_PI_8():uint {var ea:uint = ((m68ki_cpu.dar[15]+=2)-2); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
private function OPER_A7_PD_8():uint {var ea:uint = (m68ki_cpu.dar[15]-=2); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
private function OPER_AW_8():uint {var ea:uint = m68ki_read_imm_16() as int; return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
private function OPER_AW_16():uint {var ea:uint = m68ki_read_imm_16() as int; return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AW_32():uint {var ea:uint = m68ki_read_imm_16() as int; return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AL_8():uint {var ea:uint = m68ki_read_imm_32(); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
private function OPER_AL_16():uint {var ea:uint = m68ki_read_imm_32(); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_AL_32():uint {var ea:uint = m68ki_read_imm_32(); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
private function OPER_PCDI_8():uint {var ea:uint = m68ki_get_ea_pcdi(); return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 2); }
private function OPER_PCDI_16():uint {var ea:uint = m68ki_get_ea_pcdi(); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 2);}
private function OPER_PCDI_32():uint {var ea:uint = m68ki_get_ea_pcdi(); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 2);}
private function OPER_PCIX_8():uint {var ea:uint = m68ki_get_ea_pcix(); return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 2); }
private function OPER_PCIX_16():uint {var ea:uint = m68ki_get_ea_pcix(); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 2);}
private function OPER_PCIX_32():uint {var ea:uint = m68ki_get_ea_pcix(); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 2);}

private function m68ki_push_16(value:uint):void
{
	m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] - 2);
	m68ki_write_16_fc(m68ki_cpu.dar[15], m68ki_cpu.s_flag | 1, value);
}

private function m68ki_push_32(value:uint):void
{
	m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] - 4);
	m68ki_write_32_fc(m68ki_cpu.dar[15], m68ki_cpu.s_flag | 1, value);
}

private function m68ki_pull_16():uint
{
	m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] + 2);
	return m68ki_read_16_fc(m68ki_cpu.dar[15]-2, m68ki_cpu.s_flag | 1);
}

private function m68ki_pull_32():uint
{
	m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] + 4);
	return m68ki_read_32_fc(m68ki_cpu.dar[15]-4, m68ki_cpu.s_flag | 1);
}

private function m68ki_fake_push_16():void
{
	m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] - 2);
}

private function m68ki_fake_push_32():void
{
	m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] - 4);
}

private function m68ki_fake_pull_16():void
{
	m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] + 2);
}

private function m68ki_fake_pull_32():void
{
	m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] + 4);
}
private function m68ki_jump(new_pc:uint):void
{
	m68ki_cpu.pc = new_pc;
}

private function m68ki_jump_vector(vector:uint):void
{
	m68ki_cpu.pc = (vector<<2) + m68ki_cpu.vbr;
	m68ki_cpu.pc = m68ki_read_32_fc(m68ki_cpu.pc, m68ki_cpu.s_flag | 1);
}

private function m68ki_branch_8(offset:uint):void
{
	m68ki_cpu.pc += offset as int;
}

private function m68ki_branch_16(offset:uint):void
{
	m68ki_cpu.pc += offset as int;
}

private function m68ki_branch_32(offset:uint):void
{
	m68ki_cpu.pc += offset;
}
private function m68ki_set_s_flag(value:uint):void
{
	m68ki_cpu.sp[m68ki_cpu.s_flag | ((m68ki_cpu.s_flag>>1) & m68ki_cpu.m_flag)] = m68ki_cpu.dar[15];
	m68ki_cpu.s_flag = value;
	m68ki_cpu.dar[15] = m68ki_cpu.sp[m68ki_cpu.s_flag | ((m68ki_cpu.s_flag>>1) & m68ki_cpu.m_flag)];
}

private function m68ki_set_sm_flag(value:uint):void
{
	m68ki_cpu.sp[m68ki_cpu.s_flag | ((m68ki_cpu.s_flag>>1) & m68ki_cpu.m_flag)] = m68ki_cpu.dar[15];
	m68ki_cpu.s_flag = value & 4;
	m68ki_cpu.m_flag = value & 2;
	m68ki_cpu.dar[15] = m68ki_cpu.sp[m68ki_cpu.s_flag | ((m68ki_cpu.s_flag>>1) & m68ki_cpu.m_flag)];
}

private function m68ki_set_sm_flag_nosp(value:uint):void
{
	m68ki_cpu.s_flag = value & 4;
	m68ki_cpu.m_flag = value & 2;
}

private function m68ki_set_ccr(value:uint):void
{
	m68ki_cpu.x_flag = (value & 0x00000010) << 4;
	m68ki_cpu.n_flag = (value & 0x00000008) << 4;
	m68ki_cpu.not_z_flag = ((value & 0x00000004) == 0) ? 1:0;
	m68ki_cpu.v_flag = (value & 0x00000002) << 6;
	m68ki_cpu.c_flag = (value & 0x00000001) << 8;
}


private function m68ki_set_sr_noint(value:uint):void
{
	value &= m68ki_cpu.sr_mask;
	m68ki_cpu.t1_flag = ((value) & 0x00008000);
	m68ki_cpu.t0_flag = ((value) & 0x00004000);
	m68ki_cpu.int_mask = value & 0x0700;
	m68ki_set_ccr(value);
	m68ki_set_sm_flag((value >> 11) & 6);
}

private function m68ki_set_sr_noint_nosp(value:uint):void
{
	value &= m68ki_cpu.sr_mask;
	m68ki_cpu.t1_flag = (value & 0x00008000);
	m68ki_cpu.t0_flag = (value & 0x00004000);
	m68ki_cpu.int_mask = value & 0x0700;
	m68ki_set_ccr(value);
	m68ki_set_sm_flag_nosp((value >> 11) & 6);
}

private function m68ki_set_sr(value:uint):void
{
	m68ki_set_sr_noint(value);
	m68ki_check_interrupts();
}

private function m68ki_init_exception():uint
{
	var sr:uint = ( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | (((m68ki_cpu.not_z_flag>0) ? 0:1) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)));
	m68ki_cpu.t1_flag = m68ki_cpu.t0_flag = 0;
	m68ki_set_s_flag(4);
	return sr;
}

private function m68ki_stack_frame_3word(pc:uint, sr:uint):void
{
	m68ki_push_32(pc);
	m68ki_push_16(sr);
}

private function m68ki_stack_frame_0000(pc:uint, sr:uint, vector:uint):void
{
	if (m68ki_cpu.cpu_type == 1)
	{
		m68ki_stack_frame_3word(pc, sr);
		return;
	}
	m68ki_push_16(vector<<2);
	m68ki_push_32(pc);
	m68ki_push_16(sr);
}

private function m68ki_stack_frame_0001(pc:uint, sr:uint, vector:uint):void
{
	m68ki_push_16(0x1000 | (vector<<2));
	m68ki_push_32(pc);
	m68ki_push_16(sr);
}

private function m68ki_stack_frame_0010(sr:uint, vector:uint):void
{
	m68ki_push_32(m68ki_cpu.ppc);
	m68ki_push_16(0x2000 | (vector<<2));
	m68ki_push_32(m68ki_cpu.pc);
	m68ki_push_16(sr);
}

private function m68ki_stack_frame_buserr(sr:uint):void
{
	m68ki_push_32(m68ki_cpu.pc);
	m68ki_push_16(sr);
	m68ki_push_16(m68ki_cpu.ir);
	m68ki_push_32(m68ki_aerr_address);
	m68ki_push_16(m68ki_aerr_write_mode | m68ki_cpu.instr_mode | m68ki_aerr_fc);
}

private	function m68ki_stack_frame_1000(pc:uint, sr:uint, vector:uint):void
{
	m68ki_fake_push_32();
	m68ki_fake_push_32();
	m68ki_fake_push_32();
	m68ki_fake_push_32();
	m68ki_fake_push_32();
	m68ki_fake_push_32();
	m68ki_fake_push_32();
	m68ki_fake_push_32();
	m68ki_push_16(0);
	m68ki_fake_push_16();
	m68ki_push_16(0);
	m68ki_fake_push_16();
	m68ki_push_16(0);
	m68ki_fake_push_16();
	m68ki_push_32(0);
	m68ki_push_16(0);
	m68ki_push_16(0x8000 | (vector<<2));
	m68ki_push_32(pc);
	m68ki_push_16(sr);
}

private	function m68ki_stack_frame_1010(sr:uint, vector:uint, pc:uint):void
{
	m68ki_push_16(0);
	m68ki_push_16(0);
	m68ki_push_32(0);
	m68ki_push_16(0);
	m68ki_push_16(0);
	m68ki_push_32(0);
	m68ki_push_16(0);
	m68ki_push_16(0);
	m68ki_push_16(0);
	m68ki_push_16(0);
	m68ki_push_16(0xa000 | (vector<<2));
	m68ki_push_32(pc);
	m68ki_push_16(sr);
}

private	function m68ki_stack_frame_1011(sr:uint, vector:uint, pc:uint):void
{
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_16(0);
	m68ki_push_32(0);
	m68ki_push_16(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_32(0);
	m68ki_push_16(0);
	m68ki_push_16(0);
	m68ki_push_32(0);
	m68ki_push_16(0);
	m68ki_push_16(0);
	m68ki_push_16(0);
	m68ki_push_16(0);
	m68ki_push_16(0xb000 | (vector<<2));
	m68ki_push_32(pc);
	m68ki_push_16(sr);
}

private function m68ki_exception_trap(vector:uint):void
{
	var sr:uint = m68ki_init_exception();
	m68ki_stack_frame_0000(m68ki_cpu.pc, sr, vector);
	m68ki_jump_vector(vector);
	m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[vector]);
}

private function m68ki_exception_trapN(vector:uint):void
{
	var sr:uint = m68ki_init_exception();
	m68ki_stack_frame_0000(m68ki_cpu.pc, sr, vector);
	m68ki_jump_vector(vector);
	m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[vector]);
}

private function m68ki_exception_trace():void
{
	var sr:uint = m68ki_init_exception();
	m68ki_stack_frame_0000(m68ki_cpu.pc, sr, 9);
	m68ki_jump_vector(9);
	m68ki_cpu.stopped &= ~1;
	m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[9]);
}

private function m68ki_exception_privilege_violation():void
{
	var sr:uint = m68ki_init_exception();
	m68ki_stack_frame_0000(m68ki_cpu.ppc, sr, 8);
	m68ki_jump_vector(8);
	m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[8] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}

private function m68ki_exception_1010():void
{
	var sr:uint = m68ki_init_exception();
	m68ki_stack_frame_0000(m68ki_cpu.ppc, sr, 10);
	m68ki_jump_vector(10);
	m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[10] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}

private function m68ki_exception_1111():void
{
	var sr:uint = m68ki_init_exception();
	m68ki_stack_frame_0000(m68ki_cpu.ppc, sr, 11);
	m68ki_jump_vector(11);
	m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[11] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}

private function m68ki_exception_illegal():void
{
	var sr:uint = m68ki_init_exception();
	m68ki_stack_frame_0000(m68ki_cpu.ppc, sr, 4);
	m68ki_jump_vector(4);
	m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[4] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}

private function m68ki_exception_format_error():void
{
	var sr:uint = m68ki_init_exception();
	m68ki_stack_frame_0000(m68ki_cpu.pc, sr, 14);
	m68ki_jump_vector(14);
	m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[14] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}

private function m68ki_exception_address_error():void
{
	var sr:uint = m68ki_init_exception();
	if (m68ki_cpu.run_mode == 1)
	{
		m68k_read_memory_8(0x00ffff01);
		m68ki_cpu.stopped = 2;
		return;
	}
	m68ki_cpu.run_mode = 1;
	m68ki_stack_frame_buserr(sr);
	m68ki_jump_vector(3);
	m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[3] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}

private	function m68ki_exception_interrupt(int_level:uint):void
{
	var vector:uint;
	var sr:uint;
	var new_pc:uint;
	
	m68ki_cpu.stopped &= ~1;
	if (m68ki_cpu.stopped > 0)
	{
		return;
	}
	
	vector = 24 +int_level;
	sr = m68ki_init_exception();
	m68ki_cpu.int_mask = int_level<<8;
	
	new_pc = m68ki_read_32_fc((vector<<2) + m68ki_cpu.vbr, m68ki_cpu.s_flag | 1);
	if (new_pc == 0)
	{
		new_pc = m68ki_read_32_fc((15<<2) + m68ki_cpu.vbr, m68ki_cpu.s_flag | 1);
	}
	
	m68ki_stack_frame_0000(m68ki_cpu.pc, sr, vector);
	if (m68ki_cpu.m_flag && 0)
	{
		m68ki_set_sm_flag(m68ki_cpu.s_flag);
		sr |= 0x2000;
		m68ki_stack_frame_0001(m68ki_cpu.pc, sr, vector);
	}
	
	m68ki_jump(new_pc);
	m68ki_cpu.int_cycles += m68ki_cpu.cyc_exception[vector];
	m68ki_cpu.int_level = 0;
}

private	function m68ki_check_interrupts():void
{
	if (m68ki_cpu.int_level > m68ki_cpu.int_mask)
	{
		m68ki_exception_interrupt(m68ki_cpu.int_level>>8);
	}
}

private	var default_int_ack_callback_data:int;
private	function default_int_ack_callback(int_level:int):int
{
	default_int_ack_callback_data = int_level;
	m68ki_cpu.int_level = 0;
	return 0xffffffff;
}

private	var default_bkpt_ack_callback_data:uint;
private	function default_bkpt_ack_callback(data:uint):void
{
	default_bkpt_ack_callback_data = data;
}

private	function default_reset_instr_callback():void
{
}

private	var default_pc_changed_callback_data:uint;
private	function default_pc_changed_callback(new_pc:uint):void
{
	default_pc_changed_callback_data = new_pc;
}

private	var default_set_fc_callback_data:uint;
private	function default_set_fc_callback(new_fc:uint):void
{
	default_set_fc_callback_data = new_fc;
}

private	function default_instr_hook_callback():void
{
}

private	function m68k_get_reg(context:m68ki_cpu_core, regnum:uint):uint
{
	var cpu:m68ki_cpu_core = (context != null) ? context:m68ki_cpu;
	
	switch(regnum)
	{
		case M68K_REG_D0: return cpu.dar[0];
		case M68K_REG_D1: return cpu.dar[1];
		case M68K_REG_D2: return cpu.dar[2];
		case M68K_REG_D3: return cpu.dar[3];
		case M68K_REG_D4: return cpu.dar[4];
		case M68K_REG_D5: return cpu.dar[5];
		case M68K_REG_D6: return cpu.dar[6];
		case M68K_REG_D7: return cpu.dar[7];
		case M68K_REG_A0: return cpu.dar[8];
		case M68K_REG_A1: return cpu.dar[9];
		case M68K_REG_A2: return cpu.dar[10];
		case M68K_REG_A3: return cpu.dar[11];
		case M68K_REG_A4: return cpu.dar[12];
		case M68K_REG_A5: return cpu.dar[13];
		case M68K_REG_A6: return cpu.dar[14];
		case M68K_REG_A7: return cpu.dar[15];
		case M68K_REG_PC: return cpu.pc;
		case M68K_REG_SR: return cpu.t1_flag | cpu.t0_flag | (cpu.s_flag << 11) | (cpu.m_flag << 11) | cpu.int_mask | ((cpu.x_flag & 0x100) >> 4) | ((cpu.n_flag & 0x80) >> 4) | (((cpu.not_z_flag==0) ? 1:0) << 2) | ((cpu.v_flag & 0x80) >> 6) |((cpu.c_flag & 0x100) >> 8);
		case M68K_REG_SP: return cpu.dar[15];
		case M68K_REG_USP: return (cpu.s_flag > 0) ? cpu.sp[0] : cpu.dar[15];
		case M68K_REG_ISP: return ((cpu.s_flag>0) && (cpu.m_flag==0)) ? cpu.dar[15] : cpu.sp[4];
		case M68K_REG_MSP: return ((cpu.s_flag>0) && (cpu.m_flag>0)) ? cpu.dar[15] : cpu.sp[6];
		case M68K_REG_SFC: return cpu.sfc;
		case M68K_REG_DFC: return cpu.dfc;
		case M68K_REG_VBR: return cpu.vbr;
		case M68K_REG_CACR: return cpu.cacr;
		case M68K_REG_CAAR: return cpu.caar;
		case M68K_REG_PREF_ADDR: return cpu.pref_addr;
		case M68K_REG_PREF_DATA: return cpu.pref_data;
		case M68K_REG_PPC: return cpu.ppc;
		case M68K_REG_IR: return cpu.ir;
		case M68K_REG_CPU_TYPE:
			switch(cpu.cpu_type)
			{
				case 1: return M68K_CPU_TYPE_68000;
				case 2: return M68K_CPU_TYPE_68010;
				case 4: return M68K_CPU_TYPE_68EC020;
				case 8: return M68K_CPU_TYPE_68020;
			}
			return M68K_CPU_TYPE_INVALID;
		default: return 0;
	}
	return 0;
}

private	function m68k_set_reg(regnum:uint, value:uint):void
{
	switch(regnum)
	{
		case M68K_REG_D0: m68ki_cpu.dar[0] = value; return;
		case M68K_REG_D1: m68ki_cpu.dar[1] = value; return;
		case M68K_REG_D2: m68ki_cpu.dar[2] = value; return;
		case M68K_REG_D3: m68ki_cpu.dar[3] = value; return;
		case M68K_REG_D4: m68ki_cpu.dar[4] = value; return;
		case M68K_REG_D5: m68ki_cpu.dar[5] = value; return;
		case M68K_REG_D6: m68ki_cpu.dar[6] = value; return;
		case M68K_REG_D7: m68ki_cpu.dar[7] = value; return;
		case M68K_REG_A0: m68ki_cpu.dar[8] = value; return;
		case M68K_REG_A1: m68ki_cpu.dar[9] = value; return;
		case M68K_REG_A2: m68ki_cpu.dar[10] = value; return;
		case M68K_REG_A3: m68ki_cpu.dar[11] = value; return;
		case M68K_REG_A4: m68ki_cpu.dar[12] = value; return;
		case M68K_REG_A5: m68ki_cpu.dar[13] = value; return;
		case M68K_REG_A6: m68ki_cpu.dar[14] = value; return;
		case M68K_REG_A7: m68ki_cpu.dar[15] = value; return;
		case M68K_REG_PC: m68ki_jump(value); return;
		case M68K_REG_SR: m68ki_set_sr(value); return;
		case M68K_REG_SP: m68ki_cpu.dar[15] = value; return;
		case M68K_REG_USP:
			if (m68ki_cpu.s_flag)
				m68ki_cpu.sp[0] = value;
			else
				m68ki_cpu.dar[15] = value;
			return;
		case M68K_REG_ISP:
			if ((m68ki_cpu.s_flag>0) && (m68ki_cpu.m_flag==0))
				m68ki_cpu.dar[15] = value;
			else
				m68ki_cpu.sp[4] = value;
			return;
		case M68K_REG_MSP:
			if ((m68ki_cpu.s_flag>0) && (m68ki_cpu.m_flag>0))
				m68ki_cpu.dar[15] = value;
			else
				m68ki_cpu.sp[6] = value;
			return;
		case M68K_REG_VBR: m68ki_cpu.vbr = value; return;
		case M68K_REG_SFC: m68ki_cpu.sfc = value & 7; return;
		case M68K_REG_DFC: m68ki_cpu.dfc = value & 7; return;
		case M68K_REG_CACR: m68ki_cpu.cacr = value; return;
		case M68K_REG_CAAR: m68ki_cpu.caar = value; return;
		case M68K_REG_PPC: m68ki_cpu.ppc = value; return;
		case M68K_REG_IR: m68ki_cpu.ir = value & 0xffff; return;
		case M68K_REG_CPU_TYPE: m68k_set_cpu_type(value); return;
		default: return;
	}
}

private	function  m68k_set_int_ack_callback(callback:Function):void
{
	m68ki_cpu.int_ack_callback = (callback!=null) ? callback : default_int_ack_callback;
}

private	function m68k_set_bkpt_ack_callback(callback:Function):void
{
	m68ki_cpu.bkpt_ack_callback = (callback!=null) ? callback : default_bkpt_ack_callback;
}

private	function m68k_set_reset_instr_callback(callback:Function):void
{
	m68ki_cpu.reset_instr_callback = (callback!=null) ? callback : default_reset_instr_callback;
}

private	function m68k_set_pc_changed_callback(callback:Function):void
{
	m68ki_cpu.pc_changed_callback = (callback!=null) ? callback : default_pc_changed_callback;
}

private	function m68k_set_fc_callback(callback:Function):void
{
	m68ki_cpu.set_fc_callback = (callback!=null) ? callback : default_set_fc_callback;
}

private	function m68k_set_instr_hook_callback(callback:Function):void
{
	m68ki_cpu.instr_hook_callback = (callback!=null) ? callback : default_instr_hook_callback;
}

private	function m68k_set_cpu_type(cpu_type:uint):void
{
	switch(cpu_type)
	{
		case M68K_CPU_TYPE_68000:
			m68ki_cpu.cpu_type = 1;
			m68ki_cpu.address_mask = 0x00ffffff;
			m68ki_cpu.sr_mask = 0xa71f;
			m68ki_cpu.cyc_instruction = m68ki_cycles[0];
			m68ki_cpu.cyc_exception = m68ki_exception_cycle_table[0];
			m68ki_cpu.cyc_bcc_notake_b = 0xfffffffe;
			m68ki_cpu.cyc_bcc_notake_w = 2;
			m68ki_cpu.cyc_dbcc_f_noexp = 0xfffffffe;
			m68ki_cpu.cyc_dbcc_f_exp = 2;
			m68ki_cpu.cyc_scc_r_false = 2;
			m68ki_cpu.cyc_movem_w = 2;
			m68ki_cpu.cyc_movem_l = 3;
			m68ki_cpu.cyc_shift = 1;
			m68ki_cpu.cyc_reset = 132;
			return;
		case M68K_CPU_TYPE_68010:
			m68ki_cpu.cpu_type = 2;
			m68ki_cpu.address_mask = 0x00ffffff;
			m68ki_cpu.sr_mask = 0xa71f;
			m68ki_cpu.cyc_instruction = m68ki_cycles[1];
			m68ki_cpu.cyc_exception = m68ki_exception_cycle_table[1];
			m68ki_cpu.cyc_bcc_notake_b = 0xfffffffc;
			m68ki_cpu.cyc_bcc_notake_w = 0;
			m68ki_cpu.cyc_dbcc_f_noexp = 0;
			m68ki_cpu.cyc_dbcc_f_exp = 6;
			m68ki_cpu.cyc_scc_r_false = 0;
			m68ki_cpu.cyc_movem_w = 2;
			m68ki_cpu.cyc_movem_l = 3;
			m68ki_cpu.cyc_shift = 1;
			m68ki_cpu.cyc_reset = 130;
			return;
		case M68K_CPU_TYPE_68EC020:
			m68ki_cpu.cpu_type = 4;
			m68ki_cpu.address_mask = 0x00ffffff;
			m68ki_cpu.sr_mask = 0xf71f;
			m68ki_cpu.cyc_instruction = m68ki_cycles[2];
			m68ki_cpu.cyc_exception = m68ki_exception_cycle_table[2];
			m68ki_cpu.cyc_bcc_notake_b = 0xfffffffe;
			m68ki_cpu.cyc_bcc_notake_w = 0;
			m68ki_cpu.cyc_dbcc_f_noexp = 0;
			m68ki_cpu.cyc_dbcc_f_exp = 4;
			m68ki_cpu.cyc_scc_r_false = 0;
			m68ki_cpu.cyc_movem_w = 2;
			m68ki_cpu.cyc_movem_l = 2;
			m68ki_cpu.cyc_shift = 0;
			m68ki_cpu.cyc_reset = 518;
			return;
		case M68K_CPU_TYPE_68020:
			m68ki_cpu.cpu_type = 8;
			m68ki_cpu.address_mask = 0xffffffff;
			m68ki_cpu.sr_mask = 0xf71f;
			m68ki_cpu.cyc_instruction = m68ki_cycles[2];
			m68ki_cpu.cyc_exception = m68ki_exception_cycle_table[2];
			m68ki_cpu.cyc_bcc_notake_b = 0xfffffffe;
			m68ki_cpu.cyc_bcc_notake_w = 0;
			m68ki_cpu.cyc_dbcc_f_noexp = 0;
			m68ki_cpu.cyc_dbcc_f_exp = 4;
			m68ki_cpu.cyc_scc_r_false = 0;
			m68ki_cpu.cyc_movem_w = 2;
			m68ki_cpu.cyc_movem_l = 2;
			m68ki_cpu.cyc_shift = 0;
			m68ki_cpu.cyc_reset = 518;
			return;
	}
}

private	function m68k_execute(num_cycles:int):int
{
	
	if(m68ki_cpu.stopped==0)
	{
		m68ki_remaining_cycles = num_cycles;
		m68ki_initial_cycles = num_cycles;
		m68ki_remaining_cycles -= m68ki_cpu.int_cycles;
		m68ki_cpu.int_cycles = 0;
		
		do
		{
			m68ki_cpu.ppc = m68ki_cpu.pc;
			m68ki_cpu.ir = m68ki_read_imm_16();
			m68ki_instruction_jump_table[m68ki_cpu.ir]();
			m68ki_remaining_cycles -= m68ki_cpu.cyc_instruction[m68ki_cpu.ir];
		} while (m68ki_remaining_cycles > 0);
		
		m68ki_remaining_cycles -= m68ki_cpu.int_cycles;
		m68ki_cpu.int_cycles = 0;
		return m68ki_initial_cycles - m68ki_remaining_cycles;
	}
	
	m68ki_remaining_cycles = 0;
	m68ki_cpu.int_cycles = 0;
	return num_cycles;
}

private	function m68k_cycles_run():int
{
	return m68ki_initial_cycles - m68ki_remaining_cycles;
}

private	function m68k_cycles_remaining():int
{
	return m68ki_remaining_cycles;
}

private	function m68k_modify_timeslice(cycles:int):void
{
	m68ki_initial_cycles += cycles;
	m68ki_remaining_cycles += (cycles);
}

private	function m68k_end_timeslice():void
{
	m68ki_initial_cycles = m68ki_remaining_cycles;
	m68ki_remaining_cycles = 0;
}

private	function m68k_set_irq(int_level:uint):void
{
	var old_level:uint = m68ki_cpu.int_level;
	m68ki_cpu.int_level = int_level << 8;
	
	if((old_level != 0x0700) && (m68ki_cpu.int_level == 0x0700))
	{
		m68ki_exception_interrupt(7);
	}
	else
	{
		m68ki_check_interrupts();
	}
}

private	var emulation_initialized:Boolean;
private	function m68k_pulse_reset():void
{
	if(emulation_initialized!=true)
	{
		m68ki_build_opcode_table();
		m68k_set_int_ack_callback(null);
		m68k_set_bkpt_ack_callback(null);
		m68k_set_reset_instr_callback(null);
		m68k_set_pc_changed_callback(null);
		m68k_set_fc_callback(null);
		m68k_set_instr_hook_callback(null);
		emulation_initialized = true;
	}
	
	if(m68ki_cpu.cpu_type == 0)
	{
		m68k_set_cpu_type(M68K_CPU_TYPE_68000);
	}
	
	m68ki_cpu.stopped = 0;
	m68ki_remaining_cycles = 0;
	m68ki_cpu.t1_flag = m68ki_cpu.t0_flag = 0;
	m68ki_cpu.int_mask = 0x0700;
	m68ki_cpu.vbr = 0;
	m68ki_set_sm_flag(4 | 0);
	m68ki_jump(0);
	m68ki_cpu.dar[15] = m68ki_read_imm_32();
	m68ki_cpu.pc = m68ki_read_imm_32();
	m68ki_jump(m68ki_cpu.pc);
}

private	function m68k_pulse_halt():void
{
	m68ki_cpu.stopped |= 2;
}
