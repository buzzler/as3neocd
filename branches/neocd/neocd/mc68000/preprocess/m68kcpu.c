typedef struct
{
 unsigned int cpu_type;
 unsigned int dar[16];
 unsigned int ppc;
 unsigned int pc;
 unsigned int sp[7];
 unsigned int vbr;
 unsigned int sfc;
 unsigned int dfc;
 unsigned int cacr;
 unsigned int caar;
 unsigned int ir;
 unsigned int t1_flag;
 unsigned int t0_flag;
 unsigned int s_flag;
 unsigned int m_flag;
 unsigned int x_flag;
 unsigned int n_flag;
 unsigned int not_z_flag;
 unsigned int v_flag;
 unsigned int c_flag;
 unsigned int int_mask;
 unsigned int int_level;
 unsigned int int_cycles;
 unsigned int stopped;
 unsigned int pref_addr;
 unsigned int pref_data;
 unsigned int address_mask;
 unsigned int sr_mask;
 unsigned int instr_mode;
 unsigned int run_mode;


 unsigned int cyc_bcc_notake_b;
 unsigned int cyc_bcc_notake_w;
 unsigned int cyc_dbcc_f_noexp;
 unsigned int cyc_dbcc_f_exp;
 unsigned int cyc_scc_r_false;
 unsigned int cyc_movem_w;
 unsigned int cyc_movem_l;
 unsigned int cyc_shift;
 unsigned int cyc_reset;
 unsigned char* cyc_instruction;
 unsigned char* cyc_exception;


 int (*int_ack_callback)(int int_line);
 void (*bkpt_ack_callback)(unsigned int data);
 void (*reset_instr_callback)(void);
 void (*pc_changed_callback)(unsigned int new_pc);
 void (*set_fc_callback)(unsigned int new_fc);
 void (*instr_hook_callback)(void);

} m68ki_cpu_core;


extern m68ki_cpu_core m68ki_cpu;
extern signed int m68ki_remaining_cycles;
extern unsigned int m68ki_tracing;
extern unsigned char m68ki_shift_8_table[];
extern unsigned short m68ki_shift_16_table[];
extern unsigned int m68ki_shift_32_table[];
extern unsigned char m68ki_exception_cycle_table[][256];
extern unsigned int m68ki_address_space;
extern unsigned char m68ki_ea_idx_cycle_table[];

extern unsigned int m68ki_aerr_address;
extern unsigned int m68ki_aerr_write_mode;
extern unsigned int m68ki_aerr_fc;



static __inline__ unsigned int m68ki_read_imm_16(void)
{
 m68ki_cpu.pc += 2;
 return m68ki_read_16_fc(((m68ki_cpu.pc-2)&m68ki_cpu.address_mask), m68ki_cpu.s_flag | 2);

}
static __inline__ unsigned int m68ki_read_imm_32(void)
{
 m68ki_cpu.pc += 4;
 return m68ki_read_32_fc(((m68ki_cpu.pc-4)&m68ki_cpu.address_mask), m68ki_cpu.s_flag | 2);

}
static __inline__ unsigned int m68ki_read_8_fc(unsigned int address, unsigned int fc)
{
 return m68k_read_memory_8(((address)&m68ki_cpu.address_mask));
}
static __inline__ unsigned int m68ki_read_16_fc(unsigned int address, unsigned int fc)
{
 return m68k_read_memory_16(((address)&m68ki_cpu.address_mask));
}
static __inline__ unsigned int m68ki_read_32_fc(unsigned int address, unsigned int fc)
{
 return m68k_read_memory_32(((address)&m68ki_cpu.address_mask));
}

static __inline__ void m68ki_write_8_fc(unsigned int address, unsigned int fc, unsigned int value)
{
 m68k_write_memory_8(((address)&m68ki_cpu.address_mask), value);
}
static __inline__ void m68ki_write_16_fc(unsigned int address, unsigned int fc, unsigned int value)
{
 m68k_write_memory_16(((address)&m68ki_cpu.address_mask), value);
}
static __inline__ void m68ki_write_32_fc(unsigned int address, unsigned int fc, unsigned int value)
{
 m68k_write_memory_32(((address)&m68ki_cpu.address_mask), value);
}
static __inline__ unsigned int m68ki_get_ea_pcdi(void)
{
 unsigned int old_pc = m68ki_cpu.pc;
 return old_pc + (signed short)(m68ki_read_imm_16());
}


static __inline__ unsigned int m68ki_get_ea_pcix(void)
{
 return m68ki_get_ea_ix(m68ki_cpu.pc);
}
static __inline__ unsigned int m68ki_get_ea_ix(unsigned int An)
{
 unsigned int extension = m68ki_read_imm_16();
 unsigned int Xn = 0;
 unsigned int bd = 0;
 unsigned int od = 0;

 if(1)
 {

  Xn = m68ki_cpu.dar[extension>>12];
  if(!((extension) & 0x00000800))
   Xn = (signed short)(Xn);


  return An + Xn + (signed char)(extension);
 }


 if(!((extension) & 0x00000100))
 {

  Xn = m68ki_cpu.dar[extension>>12];
  if(!((extension) & 0x00000800))
   Xn = (signed short)(Xn);

  if(0)
   Xn <<= (extension>>9) & 3;


  return An + Xn + (signed char)(extension);
 }



 m68ki_remaining_cycles -= (m68ki_ea_idx_cycle_table[extension&0x3f]);


 if(((extension) & 0x00000080))
  An = 0;


 if(!((extension) & 0x00000040))
 {
  Xn = m68ki_cpu.dar[extension>>12];
  if(!((extension) & 0x00000800))
   Xn = (signed short)(Xn);
  Xn <<= (extension>>9) & 3;
 }


 if(((extension) & 0x00000020))
  bd = ((extension) & 0x00000010) ? m68ki_read_imm_32() : (signed short)(m68ki_read_imm_16());


 if(!(extension&7))
  return An + bd + Xn;


 if(((extension) & 0x00000002))
  od = ((extension) & 0x00000001) ? m68ki_read_imm_32() : (signed short)(m68ki_read_imm_16());


 if(((extension) & 0x00000004))
  return m68ki_read_32_fc(An + bd, m68ki_cpu.s_flag | 1) + Xn + od;


 return m68ki_read_32_fc(An + bd + Xn, m68ki_cpu.s_flag | 1) + od;
}



static __inline__ unsigned int OPER_AY_AI_8(void) {unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AY_AI_16(void) {unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AY_AI_32(void) {unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AY_PI_8(void) {unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AY_PI_16(void) {unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AY_PI_32(void) {unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AY_PD_8(void) {unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AY_PD_16(void) {unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AY_PD_32(void) {unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AY_DI_8(void) {unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AY_DI_16(void) {unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AY_DI_32(void) {unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AY_IX_8(void) {unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AY_IX_16(void) {unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AY_IX_32(void) {unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}

static __inline__ unsigned int OPER_AX_AI_8(void) {unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AX_AI_16(void) {unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AX_AI_32(void) {unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AX_PI_8(void) {unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AX_PI_16(void) {unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AX_PI_32(void) {unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AX_PD_8(void) {unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AX_PD_16(void) {unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AX_PD_32(void) {unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AX_DI_8(void) {unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16())); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AX_DI_16(void) {unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16())); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AX_DI_32(void) {unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16())); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AX_IX_8(void) {unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AX_IX_16(void) {unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AX_IX_32(void) {unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}

static __inline__ unsigned int OPER_A7_PI_8(void) {unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_A7_PD_8(void) {unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }

static __inline__ unsigned int OPER_AW_8(void) {unsigned int ea = (signed short)(m68ki_read_imm_16()); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AW_16(void) {unsigned int ea = (signed short)(m68ki_read_imm_16()); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AW_32(void) {unsigned int ea = (signed short)(m68ki_read_imm_16()); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AL_8(void) {unsigned int ea = m68ki_read_imm_32(); return m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1); }
static __inline__ unsigned int OPER_AL_16(void) {unsigned int ea = m68ki_read_imm_32(); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_AL_32(void) {unsigned int ea = m68ki_read_imm_32(); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);}
static __inline__ unsigned int OPER_PCDI_8(void) {unsigned int ea = m68ki_get_ea_pcdi(); return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 2); }
static __inline__ unsigned int OPER_PCDI_16(void) {unsigned int ea = m68ki_get_ea_pcdi(); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 2);}
static __inline__ unsigned int OPER_PCDI_32(void) {unsigned int ea = m68ki_get_ea_pcdi(); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 2);}
static __inline__ unsigned int OPER_PCIX_8(void) {unsigned int ea = m68ki_get_ea_pcix(); return m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 2); }
static __inline__ unsigned int OPER_PCIX_16(void) {unsigned int ea = m68ki_get_ea_pcix(); return m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 2);}
static __inline__ unsigned int OPER_PCIX_32(void) {unsigned int ea = m68ki_get_ea_pcix(); return m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 2);}






static __inline__ void m68ki_push_16(unsigned int value)
{
 m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] - 2);
 m68ki_write_16_fc(m68ki_cpu.dar[15], m68ki_cpu.s_flag | 1, value);
}

static __inline__ void m68ki_push_32(unsigned int value)
{
 m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] - 4);
 m68ki_write_32_fc(m68ki_cpu.dar[15], m68ki_cpu.s_flag | 1, value);
}

static __inline__ unsigned int m68ki_pull_16(void)
{
 m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] + 2);
 return m68ki_read_16_fc(m68ki_cpu.dar[15]-2, m68ki_cpu.s_flag | 1);
}

static __inline__ unsigned int m68ki_pull_32(void)
{
 m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] + 4);
 return m68ki_read_32_fc(m68ki_cpu.dar[15]-4, m68ki_cpu.s_flag | 1);
}





static __inline__ void m68ki_fake_push_16(void)
{
 m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] - 2);
}

static __inline__ void m68ki_fake_push_32(void)
{
 m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] - 4);
}

static __inline__ void m68ki_fake_pull_16(void)
{
 m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] + 2);
}

static __inline__ void m68ki_fake_pull_32(void)
{
 m68ki_cpu.dar[15] = (m68ki_cpu.dar[15] + 4);
}
static __inline__ void m68ki_jump(unsigned int new_pc)
{
 m68ki_cpu.pc = new_pc;
}

static __inline__ void m68ki_jump_vector(unsigned int vector)
{
 m68ki_cpu.pc = (vector<<2) + m68ki_cpu.vbr;
 m68ki_cpu.pc = m68ki_read_32_fc(m68ki_cpu.pc, m68ki_cpu.s_flag | 1);
}







static __inline__ void m68ki_branch_8(unsigned int offset)
{
 m68ki_cpu.pc += (signed char)(offset);
}

static __inline__ void m68ki_branch_16(unsigned int offset)
{
 m68ki_cpu.pc += (signed short)(offset);
}

static __inline__ void m68ki_branch_32(unsigned int offset)
{
 m68ki_cpu.pc += offset;
}
static __inline__ void m68ki_set_s_flag(unsigned int value)
{

 m68ki_cpu.sp[m68ki_cpu.s_flag | ((m68ki_cpu.s_flag>>1) & m68ki_cpu.m_flag)] = m68ki_cpu.dar[15];

 m68ki_cpu.s_flag = value;

 m68ki_cpu.dar[15] = m68ki_cpu.sp[m68ki_cpu.s_flag | ((m68ki_cpu.s_flag>>1) & m68ki_cpu.m_flag)];
}




static __inline__ void m68ki_set_sm_flag(unsigned int value)
{

 m68ki_cpu.sp[m68ki_cpu.s_flag | ((m68ki_cpu.s_flag>>1) & m68ki_cpu.m_flag)] = m68ki_cpu.dar[15];

 m68ki_cpu.s_flag = value & 4;
 m68ki_cpu.m_flag = value & 2;

 m68ki_cpu.dar[15] = m68ki_cpu.sp[m68ki_cpu.s_flag | ((m68ki_cpu.s_flag>>1) & m68ki_cpu.m_flag)];
}


static __inline__ void m68ki_set_sm_flag_nosp(unsigned int value)
{

 m68ki_cpu.s_flag = value & 4;
 m68ki_cpu.m_flag = value & 2;
}



static __inline__ void m68ki_set_ccr(unsigned int value)
{
 m68ki_cpu.x_flag = ((value) & 0x00000010) << 4;
 m68ki_cpu.n_flag = ((value) & 0x00000008) << 4;
 m68ki_cpu.not_z_flag = !((value) & 0x00000004);
 m68ki_cpu.v_flag = ((value) & 0x00000002) << 6;
 m68ki_cpu.c_flag = ((value) & 0x00000001) << 8;
}


static __inline__ void m68ki_set_sr_noint(unsigned int value)
{

 value &= m68ki_cpu.sr_mask;


 m68ki_cpu.t1_flag = ((value) & 0x00008000);
 m68ki_cpu.t0_flag = ((value) & 0x00004000);
 m68ki_cpu.int_mask = value & 0x0700;
 m68ki_set_ccr(value);
 m68ki_set_sm_flag((value >> 11) & 6);
}




static __inline__ void m68ki_set_sr_noint_nosp(unsigned int value)
{

 value &= m68ki_cpu.sr_mask;


 m68ki_cpu.t1_flag = ((value) & 0x00008000);
 m68ki_cpu.t0_flag = ((value) & 0x00004000);
 m68ki_cpu.int_mask = value & 0x0700;
 m68ki_set_ccr(value);
 m68ki_set_sm_flag_nosp((value >> 11) & 6);
}


static __inline__ void m68ki_set_sr(unsigned int value)
{
 m68ki_set_sr_noint(value);
 m68ki_check_interrupts();
}





static __inline__ unsigned int m68ki_init_exception(void)
{

 unsigned int sr = ( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)));


 m68ki_cpu.t1_flag = m68ki_cpu.t0_flag = 0;

 m68ki_set_s_flag(4);

 return sr;
}


static __inline__ void m68ki_stack_frame_3word(unsigned int pc, unsigned int sr)
{
 m68ki_push_32(pc);
 m68ki_push_16(sr);
}




static __inline__ void m68ki_stack_frame_0000(unsigned int pc, unsigned int sr, unsigned int vector)
{

 if(m68ki_cpu.cpu_type == 1)
 {
  m68ki_stack_frame_3word(pc, sr);
  return;
 }
 m68ki_push_16(vector<<2);
 m68ki_push_32(pc);
 m68ki_push_16(sr);
}




static __inline__ void m68ki_stack_frame_0001(unsigned int pc, unsigned int sr, unsigned int vector)
{
 m68ki_push_16(0x1000 | (vector<<2));
 m68ki_push_32(pc);
 m68ki_push_16(sr);
}




static __inline__ void m68ki_stack_frame_0010(unsigned int sr, unsigned int vector)
{
 m68ki_push_32(m68ki_cpu.ppc);
 m68ki_push_16(0x2000 | (vector<<2));
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_push_16(sr);
}




static __inline__ void m68ki_stack_frame_buserr(unsigned int sr)
{
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_push_16(sr);
 m68ki_push_16(m68ki_cpu.ir);
 m68ki_push_32(m68ki_aerr_address);





 m68ki_push_16(m68ki_aerr_write_mode | m68ki_cpu.instr_mode | m68ki_aerr_fc);
}




void m68ki_stack_frame_1000(unsigned int pc, unsigned int sr, unsigned int vector)
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






void m68ki_stack_frame_1010(unsigned int sr, unsigned int vector, unsigned int pc)
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






void m68ki_stack_frame_1011(unsigned int sr, unsigned int vector, unsigned int pc)
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





static __inline__ void m68ki_exception_trap(unsigned int vector)
{
 unsigned int sr = m68ki_init_exception();

 if(1)
  m68ki_stack_frame_0000(m68ki_cpu.pc, sr, vector);
 else
  m68ki_stack_frame_0010(sr, vector);

 m68ki_jump_vector(vector);


 m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[vector]);
}


static __inline__ void m68ki_exception_trapN(unsigned int vector)
{
 unsigned int sr = m68ki_init_exception();
 m68ki_stack_frame_0000(m68ki_cpu.pc, sr, vector);
 m68ki_jump_vector(vector);


 m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[vector]);
}


static __inline__ void m68ki_exception_trace(void)
{
 unsigned int sr = m68ki_init_exception();

 if(1)
 {
  m68ki_stack_frame_0000(m68ki_cpu.pc, sr, 9);
 }
 else
  m68ki_stack_frame_0010(sr, 9);

 m68ki_jump_vector(9);


 m68ki_cpu.stopped &= ~1;


 m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[9]);
}


static __inline__ void m68ki_exception_privilege_violation(void)
{
 unsigned int sr = m68ki_init_exception();

 m68ki_stack_frame_0000(m68ki_cpu.ppc, sr, 8);
 m68ki_jump_vector(8);


 m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[8] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}


static __inline__ void m68ki_exception_1010(void)
{
 unsigned int sr;


 sr = m68ki_init_exception();
 m68ki_stack_frame_0000(m68ki_cpu.ppc, sr, 10);
 m68ki_jump_vector(10);


 m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[10] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}


static __inline__ void m68ki_exception_1111(void)
{
 unsigned int sr;


 sr = m68ki_init_exception();
 m68ki_stack_frame_0000(m68ki_cpu.ppc, sr, 11);
 m68ki_jump_vector(11);


 m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[11] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}


static __inline__ void m68ki_exception_illegal(void)
{
 unsigned int sr;
                                                    ;

 sr = m68ki_init_exception();

 m68ki_stack_frame_0000(m68ki_cpu.ppc, sr, 4);
 m68ki_jump_vector(4);


 m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[4] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}


static __inline__ void m68ki_exception_format_error(void)
{
 unsigned int sr = m68ki_init_exception();
 m68ki_stack_frame_0000(m68ki_cpu.pc, sr, 14);
 m68ki_jump_vector(14);


 m68ki_remaining_cycles -= (m68ki_cpu.cyc_exception[14] - m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
}


static __inline__ void m68ki_exception_address_error(void)
{
 unsigned int sr = m68ki_init_exception();


 if(m68ki_cpu.run_mode == 1)
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


void m68ki_exception_interrupt(unsigned int int_level)
{
 unsigned int vector;
 unsigned int sr;
 unsigned int new_pc;

 m68ki_cpu.stopped &= ~1;


 if(m68ki_cpu.stopped)
  return;


 vector = 0xffffffff;


 if(vector == 0xffffffff)

  vector = 24 +int_level;
 else if(vector == 0xfffffffe)

  vector = 24;
 else if(vector > 255)
 {
 
                                                             ;
  return;
 }


 sr = m68ki_init_exception();


 m68ki_cpu.int_mask = int_level<<8;


 new_pc = m68ki_read_32_fc((vector<<2) + m68ki_cpu.vbr, m68ki_cpu.s_flag | 1);


 if(new_pc == 0)
  new_pc = m68ki_read_32_fc((15<<2) + m68ki_cpu.vbr, m68ki_cpu.s_flag | 1);


 m68ki_stack_frame_0000(m68ki_cpu.pc, sr, vector);
 if(m68ki_cpu.m_flag && 0)
 {

  m68ki_set_sm_flag(m68ki_cpu.s_flag);
  sr |= 0x2000;
  m68ki_stack_frame_0001(m68ki_cpu.pc, sr, vector);
 }

 m68ki_jump(new_pc);


 m68ki_cpu.int_cycles += m68ki_cpu.cyc_exception[vector];



 m68ki_cpu.int_level = 0;

}

static __inline__ void m68ki_check_interrupts(void)
{
 if(m68ki_cpu.int_level > m68ki_cpu.int_mask)
  m68ki_exception_interrupt(m68ki_cpu.int_level>>8);
}


int m68ki_initial_cycles;
int m68ki_remaining_cycles = 0;
unsigned int m68ki_tracing = 0;
unsigned int m68ki_address_space;


const char* m68ki_cpu_names[9] =
{
 "Invalid CPU",
 "M68000",
 "M68010",
 "Invalid CPU",
 "M68EC020"
 "Invalid CPU",
 "Invalid CPU",
 "Invalid CPU",
 "M68020"
};



m68ki_cpu_core m68ki_cpu = {0};


unsigned int m68ki_aerr_address;
unsigned int m68ki_aerr_write_mode;
unsigned int m68ki_aerr_fc;


unsigned char m68ki_shift_8_table[65] =
{
 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff,
 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
 0xff, 0xff, 0xff, 0xff, 0xff
};
unsigned short m68ki_shift_16_table[65] =
{
 0x0000, 0x8000, 0xc000, 0xe000, 0xf000, 0xf800, 0xfc00, 0xfe00, 0xff00,
 0xff80, 0xffc0, 0xffe0, 0xfff0, 0xfff8, 0xfffc, 0xfffe, 0xffff, 0xffff,
 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
 0xffff, 0xffff
};
unsigned int m68ki_shift_32_table[65] =
{
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
};

unsigned char m68ki_exception_cycle_table[3][256] =
{
 {
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
 },
 {
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
 },
 {
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
 }
};

unsigned char m68ki_ea_idx_cycle_table[64] =
{
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
};
static int default_int_ack_callback_data;
static int default_int_ack_callback(int int_level)
{
 default_int_ack_callback_data = int_level;
 m68ki_cpu.int_level = 0;
 return 0xffffffff;
}


static unsigned int default_bkpt_ack_callback_data;
static void default_bkpt_ack_callback(unsigned int data)
{
 default_bkpt_ack_callback_data = data;
}


static void default_reset_instr_callback(void)
{
}


static unsigned int default_pc_changed_callback_data;
static void default_pc_changed_callback(unsigned int new_pc)
{
 default_pc_changed_callback_data = new_pc;
}


static unsigned int default_set_fc_callback_data;
static void default_set_fc_callback(unsigned int new_fc)
{
 default_set_fc_callback_data = new_fc;
}


static void default_instr_hook_callback(void)
{
}
unsigned int m68k_get_reg(void* context, m68k_register_t regnum)
{
 m68ki_cpu_core* cpu = context != ((void *)0) ?(m68ki_cpu_core*)context : &m68ki_cpu;

 switch(regnum)
 {
  case M68K_REG_D0: return cpu->dar[0];
  case M68K_REG_D1: return cpu->dar[1];
  case M68K_REG_D2: return cpu->dar[2];
  case M68K_REG_D3: return cpu->dar[3];
  case M68K_REG_D4: return cpu->dar[4];
  case M68K_REG_D5: return cpu->dar[5];
  case M68K_REG_D6: return cpu->dar[6];
  case M68K_REG_D7: return cpu->dar[7];
  case M68K_REG_A0: return cpu->dar[8];
  case M68K_REG_A1: return cpu->dar[9];
  case M68K_REG_A2: return cpu->dar[10];
  case M68K_REG_A3: return cpu->dar[11];
  case M68K_REG_A4: return cpu->dar[12];
  case M68K_REG_A5: return cpu->dar[13];
  case M68K_REG_A6: return cpu->dar[14];
  case M68K_REG_A7: return cpu->dar[15];
  case M68K_REG_PC: return (cpu->pc);
  case M68K_REG_SR: return cpu->t1_flag |
         cpu->t0_flag |
         (cpu->s_flag << 11) |
         (cpu->m_flag << 11) |
         cpu->int_mask |
         ((cpu->x_flag & 0x100) >> 4) |
         ((cpu->n_flag & 0x80) >> 4) |
         ((!cpu->not_z_flag) << 2) |
         ((cpu->v_flag & 0x80) >> 6) |
         ((cpu->c_flag & 0x100) >> 8);
  case M68K_REG_SP: return cpu->dar[15];
  case M68K_REG_USP: return cpu->s_flag ? cpu->sp[0] : cpu->dar[15];
  case M68K_REG_ISP: return cpu->s_flag && !cpu->m_flag ? cpu->dar[15] : cpu->sp[4];
  case M68K_REG_MSP: return cpu->s_flag && cpu->m_flag ? cpu->dar[15] : cpu->sp[6];
  case M68K_REG_SFC: return cpu->sfc;
  case M68K_REG_DFC: return cpu->dfc;
  case M68K_REG_VBR: return cpu->vbr;
  case M68K_REG_CACR: return cpu->cacr;
  case M68K_REG_CAAR: return cpu->caar;
  case M68K_REG_PREF_ADDR: return cpu->pref_addr;
  case M68K_REG_PREF_DATA: return cpu->pref_data;
  case M68K_REG_PPC: return (cpu->ppc);
  case M68K_REG_IR: return cpu->ir;
  case M68K_REG_CPU_TYPE:
   switch(cpu->cpu_type)
   {
    case 1: return (unsigned int)M68K_CPU_TYPE_68000;
    case 2: return (unsigned int)M68K_CPU_TYPE_68010;
    case 4: return (unsigned int)M68K_CPU_TYPE_68EC020;
    case 8: return (unsigned int)M68K_CPU_TYPE_68020;
   }
   return M68K_CPU_TYPE_INVALID;
  default: return 0;
 }
 return 0;
}

void m68k_set_reg(m68k_register_t regnum, unsigned int value)
{
 switch(regnum)
 {
  case M68K_REG_D0: m68ki_cpu.dar[0] = (value); return;
  case M68K_REG_D1: m68ki_cpu.dar[1] = (value); return;
  case M68K_REG_D2: m68ki_cpu.dar[2] = (value); return;
  case M68K_REG_D3: m68ki_cpu.dar[3] = (value); return;
  case M68K_REG_D4: m68ki_cpu.dar[4] = (value); return;
  case M68K_REG_D5: m68ki_cpu.dar[5] = (value); return;
  case M68K_REG_D6: m68ki_cpu.dar[6] = (value); return;
  case M68K_REG_D7: m68ki_cpu.dar[7] = (value); return;
  case M68K_REG_A0: (m68ki_cpu.dar+8)[0] = (value); return;
  case M68K_REG_A1: (m68ki_cpu.dar+8)[1] = (value); return;
  case M68K_REG_A2: (m68ki_cpu.dar+8)[2] = (value); return;
  case M68K_REG_A3: (m68ki_cpu.dar+8)[3] = (value); return;
  case M68K_REG_A4: (m68ki_cpu.dar+8)[4] = (value); return;
  case M68K_REG_A5: (m68ki_cpu.dar+8)[5] = (value); return;
  case M68K_REG_A6: (m68ki_cpu.dar+8)[6] = (value); return;
  case M68K_REG_A7: (m68ki_cpu.dar+8)[7] = (value); return;
  case M68K_REG_PC: m68ki_jump((value)); return;
  case M68K_REG_SR: m68ki_set_sr(value); return;
  case M68K_REG_SP: m68ki_cpu.dar[15] = (value); return;
  case M68K_REG_USP: if(m68ki_cpu.s_flag)
        m68ki_cpu.sp[0] = (value);
       else
        m68ki_cpu.dar[15] = (value);
       return;
  case M68K_REG_ISP: if(m68ki_cpu.s_flag && !m68ki_cpu.m_flag)
        m68ki_cpu.dar[15] = (value);
       else
        m68ki_cpu.sp[4] = (value);
       return;
  case M68K_REG_MSP: if(m68ki_cpu.s_flag && m68ki_cpu.m_flag)
        m68ki_cpu.dar[15] = (value);
       else
        m68ki_cpu.sp[6] = (value);
       return;
  case M68K_REG_VBR: m68ki_cpu.vbr = (value); return;
  case M68K_REG_SFC: m68ki_cpu.sfc = value & 7; return;
  case M68K_REG_DFC: m68ki_cpu.dfc = value & 7; return;
  case M68K_REG_CACR: m68ki_cpu.cacr = (value); return;
  case M68K_REG_CAAR: m68ki_cpu.caar = (value); return;
  case M68K_REG_PPC: m68ki_cpu.ppc = (value); return;
  case M68K_REG_IR: m68ki_cpu.ir = ((value) & 0xffff); return;
  case M68K_REG_CPU_TYPE: m68k_set_cpu_type(value); return;
  default: return;
 }
}


void m68k_set_int_ack_callback(int (*callback)(int int_level))
{
 m68ki_cpu.int_ack_callback = callback ? callback : default_int_ack_callback;
}

void m68k_set_bkpt_ack_callback(void (*callback)(unsigned int data))
{
 m68ki_cpu.bkpt_ack_callback = callback ? callback : default_bkpt_ack_callback;
}

void m68k_set_reset_instr_callback(void (*callback)(void))
{
 m68ki_cpu.reset_instr_callback = callback ? callback : default_reset_instr_callback;
}

void m68k_set_pc_changed_callback(void (*callback)(unsigned int new_pc))
{
 m68ki_cpu.pc_changed_callback = callback ? callback : default_pc_changed_callback;
}

void m68k_set_fc_callback(void (*callback)(unsigned int new_fc))
{
 m68ki_cpu.set_fc_callback = callback ? callback : default_set_fc_callback;
}

void m68k_set_instr_hook_callback(void (*callback)(void))
{
 m68ki_cpu.instr_hook_callback = callback ? callback : default_instr_hook_callback;
}



void m68k_set_cpu_type(unsigned int cpu_type)
{
 switch(cpu_type)
 {
  case M68K_CPU_TYPE_68000:
   m68ki_cpu.cpu_type = 1;
   m68ki_cpu.address_mask = 0x00ffffff;
   m68ki_cpu.sr_mask = 0xa71f;
   m68ki_cpu.cyc_instruction = m68ki_cycles[0];
   m68ki_cpu.cyc_exception = m68ki_exception_cycle_table[0];
   m68ki_cpu.cyc_bcc_notake_b = -2;
   m68ki_cpu.cyc_bcc_notake_w = 2;
   m68ki_cpu.cyc_dbcc_f_noexp = -2;
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
   m68ki_cpu.cyc_bcc_notake_b = -4;
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
   m68ki_cpu.cyc_bcc_notake_b = -2;
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
   m68ki_cpu.cyc_bcc_notake_b = -2;
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



int m68k_execute(int num_cycles)
{

 if(!m68ki_cpu.stopped)
 {

  m68ki_remaining_cycles = num_cycles;
  m68ki_initial_cycles = num_cycles;


  m68ki_remaining_cycles -= (m68ki_cpu.int_cycles);
  m68ki_cpu.int_cycles = 0;

  do
  {
   m68ki_cpu.ppc = m68ki_cpu.pc;

   m68ki_cpu.ir = m68ki_read_imm_16();
   m68ki_instruction_jump_table[m68ki_cpu.ir]();
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_instruction[m68ki_cpu.ir]);
  } while(m68ki_remaining_cycles > 0);


  m68ki_cpu.ppc = m68ki_cpu.pc;


  m68ki_remaining_cycles -= (m68ki_cpu.int_cycles);
  m68ki_cpu.int_cycles = 0;


  return m68ki_initial_cycles - m68ki_remaining_cycles;
 }


 m68ki_remaining_cycles = 0;
 m68ki_cpu.int_cycles = 0;

 return num_cycles;
}


int m68k_cycles_run(void)
{
 return m68ki_initial_cycles - m68ki_remaining_cycles;
}

int m68k_cycles_remaining(void)
{
 return m68ki_remaining_cycles;
}


void m68k_modify_timeslice(int cycles)
{
 m68ki_initial_cycles += cycles;
 m68ki_remaining_cycles += (cycles);
}


void m68k_end_timeslice(void)
{
 m68ki_initial_cycles = m68ki_remaining_cycles;
 m68ki_remaining_cycles = 0;
}






void m68k_set_irq(unsigned int int_level)
{
 unsigned int old_level = m68ki_cpu.int_level;
 m68ki_cpu.int_level = int_level << 8;



 if(old_level != 0x0700 && m68ki_cpu.int_level == 0x0700)
  m68ki_exception_interrupt(7);
 else
  m68ki_check_interrupts();
}



void m68k_pulse_reset(void)
{
 static unsigned int emulation_initialized = 0;


 if(!emulation_initialized)
 {
  m68ki_build_opcode_table();
  m68k_set_int_ack_callback(((void *)0));
  m68k_set_bkpt_ack_callback(((void *)0));
  m68k_set_reset_instr_callback(((void *)0));
  m68k_set_pc_changed_callback(((void *)0));
  m68k_set_fc_callback(((void *)0));
  m68k_set_instr_hook_callback(((void *)0));

  emulation_initialized = 1;
 }


 if(m68ki_cpu.cpu_type == 0)
  m68k_set_cpu_type(M68K_CPU_TYPE_68000);


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


void m68k_pulse_halt(void)
{
 m68ki_cpu.stopped |= 2;
}




unsigned int m68k_context_size()
{
 return sizeof(m68ki_cpu_core);
}

unsigned int m68k_get_context(void* dst)
{
 if(dst) *(m68ki_cpu_core*)dst = m68ki_cpu;
 return sizeof(m68ki_cpu_core);
}

void m68k_set_context(void* src)
{
 if(src) m68ki_cpu = *(m68ki_cpu_core*)src;
}
