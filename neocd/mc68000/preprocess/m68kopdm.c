void cdrom_load_files(void);
void neogeo_cdda_control(void);
void neogeo_prio_switch(void);
void neogeo_upload(void);

extern int img_display;






void m68k_op_dbt_16(void)
{
 m68ki_cpu.pc += 2;
}


void m68k_op_dbf_16(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = ((*r_dst - 1) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | res;
 if(res != 0xffff)
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbhi_16(void)
{
 if(((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbls_16(void)
{
 if(((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbcc_16(void)
{
 if((m68ki_cpu.c_flag&0x100))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbcs_16(void)
{
 if((!(m68ki_cpu.c_flag&0x100)))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbne_16(void)
{
 if((!m68ki_cpu.not_z_flag))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbeq_16(void)
{
 if(m68ki_cpu.not_z_flag)
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbvc_16(void)
{
 if((m68ki_cpu.v_flag&0x80))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbvs_16(void)
{
 if((!(m68ki_cpu.v_flag&0x80)))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbpl_16(void)
{
 if((m68ki_cpu.n_flag&0x80))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbmi_16(void)
{
 if((!(m68ki_cpu.n_flag&0x80)))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbge_16(void)
{
 if(((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dblt_16(void)
{
 if((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dbgt_16(void)
{
 if((((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_dble_16(void)
{
 if(((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag))
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int res = ((*r_dst - 1) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  if(res != 0xffff)
  {
   unsigned int offset = m68ki_read_imm_16();
   m68ki_cpu.pc -= 2;
   ;
   m68ki_branch_16(offset);
   m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_noexp);
   return;
  }
  m68ki_cpu.pc += 2;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_dbcc_f_exp);
  return;
 }
 m68ki_cpu.pc += 2;
}


void m68k_op_divs_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)((m68ki_cpu.dar[m68ki_cpu.ir & 7]));
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divs_16_ai(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)(OPER_AY_AI_16());
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divs_16_pi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)(OPER_AY_PI_16());
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divs_16_pd(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)(OPER_AY_PD_16());
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divs_16_di(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)(OPER_AY_DI_16());
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divs_16_ix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)(OPER_AY_IX_16());
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divs_16_aw(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)(OPER_AW_16());
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divs_16_al(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)(OPER_AL_16());
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divs_16_pcdi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)(OPER_PCDI_16());
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divs_16_pcix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)(OPER_PCIX_16());
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divs_16_i(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 signed int src = (signed short)(m68ki_read_imm_16());
 signed int quotient;
 signed int remainder;

 if(src != 0)
 {
  if((unsigned long)*r_dst == 0x80000000 && src == -1)
  {
   m68ki_cpu.not_z_flag = 0;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = 0;
   return;
  }

  quotient = (signed long)(*r_dst) / src;
  remainder = (signed long)(*r_dst) % src;

  if(quotient == (signed short)(quotient))
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_ai(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_AI_16();

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_pi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PI_16();

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_pd(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PD_16();

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_di(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_DI_16();

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_ix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_IX_16();

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_aw(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AW_16();

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_al(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AL_16();

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_pcdi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCDI_16();

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_pcix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCIX_16();

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divu_16_i(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = m68ki_read_imm_16();

 if(src != 0)
 {
  unsigned int quotient = *r_dst / src;
  unsigned int remainder = *r_dst % src;

  if(quotient < 0x10000)
  {
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.n_flag = ((quotient)>>8);
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   *r_dst = (((quotient) & 0xffff) | (remainder << 16));
   return;
  }
  m68ki_cpu.v_flag = 0x80;
  return;
 }
 m68ki_exception_trap(5);
}


void m68k_op_divl_32_d(void)
{
# 1166 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_divl_32_ai(void)
{
# 1377 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = OPER_AY_AI_32();
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_divl_32_pi(void)
{
# 1588 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = OPER_AY_PI_32();
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_divl_32_pd(void)
{
# 1799 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = OPER_AY_PD_32();
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_divl_32_di(void)
{
# 2010 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = OPER_AY_DI_32();
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_divl_32_ix(void)
{
# 2221 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = OPER_AY_IX_32();
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_divl_32_aw(void)
{
# 2432 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = OPER_AW_32();
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_divl_32_al(void)
{
# 2643 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = OPER_AL_32();
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_divl_32_pcdi(void)
{
# 2854 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = OPER_PCDI_32();
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_divl_32_pcix(void)
{
# 3065 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = OPER_PCIX_32();
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_divl_32_i(void)
{
# 3276 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int divisor = m68ki_read_imm_32();
  unsigned int dividend_hi = m68ki_cpu.dar[word2 & 7];
  unsigned int dividend_lo = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  unsigned int dividend_neg = 0;
  unsigned int divisor_neg = 0;
  signed int i;
  unsigned int overflow;

  if(divisor != 0)
  {

   if(((word2) & 0x00000400))
   {
    if(((word2) & 0x00000800))
    {

     if(dividend_hi == 0 && dividend_lo == 0x80000000 && divisor == 0xffffffff)
     {
      m68ki_cpu.dar[word2 & 7] = 0;
      m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;

      m68ki_cpu.n_flag = 0x80;
      m68ki_cpu.not_z_flag = 0xffffffff;
      m68ki_cpu.v_flag = 0;
      m68ki_cpu.c_flag = 0;
      return;
     }
     if(((dividend_hi) & 0x80000000))
     {
      dividend_neg = 1;
      dividend_hi = (unsigned int)((-(signed int)dividend_hi) - (dividend_lo != 0));
      dividend_lo = (unsigned int)(-(signed int)dividend_lo);
     }
     if(((divisor) & 0x80000000))
     {
      divisor_neg = 1;
      divisor = (unsigned int)(-(signed int)divisor);

     }
    }


    if(dividend_hi >= divisor)
    {
     m68ki_cpu.v_flag = 0x80;
     return;
    }

    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     remainder = (remainder << 1) + ((dividend_hi >> i) & 1);
     if(remainder >= divisor)
     {
      remainder -= divisor;
      quotient++;
     }
    }
    for(i = 31; i >= 0; i--)
    {
     quotient <<= 1;
     overflow = ((remainder) & 0x80000000);
     remainder = (remainder << 1) + ((dividend_lo >> i) & 1);
     if(remainder >= divisor || overflow)
     {
      remainder -= divisor;
      quotient++;
     }
    }

    if(((word2) & 0x00000800))
    {
     if(quotient > 0x7fffffff)
     {
      m68ki_cpu.v_flag = 0x80;
      return;
     }
     if(dividend_neg)
     {
      remainder = (unsigned int)(-(signed int)remainder);
      quotient = (unsigned int)(-(signed int)quotient);
     }
     if(divisor_neg)
      quotient = (unsigned int)(-(signed int)quotient);
    }

    m68ki_cpu.dar[word2 & 7] = remainder;
    m68ki_cpu.dar[(word2 >> 12) & 7] = quotient;

    m68ki_cpu.n_flag = ((quotient)>>24);
    m68ki_cpu.not_z_flag = quotient;
    m68ki_cpu.v_flag = 0;
    m68ki_cpu.c_flag = 0;
    return;
   }


   if(((word2) & 0x00000800))
   {

    if(dividend_lo == 0x80000000 && divisor == 0xffffffff)
    {
     m68ki_cpu.n_flag = 0x80;
     m68ki_cpu.not_z_flag = 0xffffffff;
     m68ki_cpu.v_flag = 0;
     m68ki_cpu.c_flag = 0;
     m68ki_cpu.dar[(word2 >> 12) & 7] = 0x80000000;
     m68ki_cpu.dar[word2 & 7] = 0;
     return;
    }
    m68ki_cpu.dar[word2 & 7] = (signed long)(dividend_lo) % (signed long)(divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (signed long)(dividend_lo) / (signed long)(divisor);
   }
   else
   {
    m68ki_cpu.dar[word2 & 7] = (dividend_lo) % (divisor);
    quotient = m68ki_cpu.dar[(word2 >> 12) & 7] = (dividend_lo) / (divisor);
   }

   m68ki_cpu.n_flag = ((quotient)>>24);
   m68ki_cpu.not_z_flag = quotient;
   m68ki_cpu.v_flag = 0;
   m68ki_cpu.c_flag = 0;
   return;
  }
  m68ki_exception_trap(5);
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_eor_8_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7]) ^= (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff)) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_8_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_8_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_8_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_8_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_8_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_8_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_8_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_8_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_8_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_16_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7]) ^= (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff)) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_32_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]) ^= (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_32_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_32_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_32_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_32_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_32_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_32_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eor_32_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_8_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7]) ^= ((m68ki_read_imm_16()) & 0xff)) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_8_ai(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = src ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_8_pi(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int res = src ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_8_pi7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int res = src ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_8_pd(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = src ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_8_pd7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int res = src ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_8_di(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = src ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_8_ix(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = src ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_8_aw(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = src ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_8_al(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = src ^ m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_16_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7]) ^= m68ki_read_imm_16()) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_16_ai(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = src ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_16_pi(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int res = src ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_16_pd(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int res = src ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_16_di(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = src ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_16_ix(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = src ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_16_aw(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = src ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_16_al(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = src ^ m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_32_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]) ^= m68ki_read_imm_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_32_ai(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = src ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_32_pi(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int res = src ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_32_pd(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int res = src ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_32_di(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = src ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_32_ix(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = src ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_32_aw(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = src ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_32_al(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = src ^ m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_eori_16_toc(void)
{
 m68ki_set_ccr((((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)) ^ m68ki_read_imm_16());
}


void m68k_op_eori_16_tos(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int src = m68ki_read_imm_16();
  ;
  m68ki_set_sr(( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8))) ^ src);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_exg_32_dd(void)
{
 unsigned int* reg_a = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int* reg_b = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int tmp = *reg_a;
 *reg_a = *reg_b;
 *reg_b = tmp;
}


void m68k_op_exg_32_aa(void)
{
 unsigned int* reg_a = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int* reg_b = &((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int tmp = *reg_a;
 *reg_a = *reg_b;
 *reg_b = tmp;
}


void m68k_op_exg_32_da(void)
{
 unsigned int* reg_a = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int* reg_b = &((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int tmp = *reg_a;
 *reg_a = *reg_b;
 *reg_b = tmp;
}


void m68k_op_ext_16(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | ((*r_dst) & 0xff) | (((*r_dst) & 0x80) ? 0xff00 : 0);

 m68ki_cpu.n_flag = ((*r_dst)>>8);
 m68ki_cpu.not_z_flag = ((*r_dst) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_ext_32(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);

 *r_dst = ((*r_dst) & 0xffff) | (((*r_dst) & 0x8000) ? 0xffff0000 : 0);

 m68ki_cpu.n_flag = ((*r_dst)>>24);
 m68ki_cpu.not_z_flag = *r_dst;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_extb_32(void)
{
 if(0)
 {
  unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);

  *r_dst = ((*r_dst) & 0xff) | (((*r_dst) & 0x80) ? 0xffffff00 : 0);

  m68ki_cpu.n_flag = ((*r_dst)>>24);
  m68ki_cpu.not_z_flag = *r_dst;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_illegal(void)
{
 m68ki_exception_illegal();
}


void m68k_op_jmp_32_ai(void)
{
 m68ki_jump(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 ;
 if(m68ki_cpu.pc == m68ki_cpu.ppc)
  m68ki_remaining_cycles = 0;
}


void m68k_op_jmp_32_di(void)
{
 m68ki_jump((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())));
 ;
 if(m68ki_cpu.pc == m68ki_cpu.ppc)
  m68ki_remaining_cycles = 0;
}


void m68k_op_jmp_32_ix(void)
{
 m68ki_jump(m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])));
 ;
 if(m68ki_cpu.pc == m68ki_cpu.ppc)
  m68ki_remaining_cycles = 0;
}


void m68k_op_jmp_32_aw(void)
{
 m68ki_jump((signed short)(m68ki_read_imm_16()));
 ;
 if(m68ki_cpu.pc == m68ki_cpu.ppc)
  m68ki_remaining_cycles = 0;
}


void m68k_op_jmp_32_al(void)
{
 m68ki_jump(m68ki_read_imm_32());
 ;
 if(m68ki_cpu.pc == m68ki_cpu.ppc)
  m68ki_remaining_cycles = 0;
}


void m68k_op_jmp_32_pcdi(void)
{
 m68ki_jump(m68ki_get_ea_pcdi());
 ;
 if(m68ki_cpu.pc == m68ki_cpu.ppc)
  m68ki_remaining_cycles = 0;
}


void m68k_op_jmp_32_pcix(void)
{
 m68ki_jump(m68ki_get_ea_pcix());
 ;
 if(m68ki_cpu.pc == m68ki_cpu.ppc)
  m68ki_remaining_cycles = 0;
}


void m68k_op_jsr_32_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 ;
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_jump(ea);
}


void m68k_op_jsr_32_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 ;
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_jump(ea);
}


void m68k_op_jsr_32_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 ;
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_jump(ea);
}


void m68k_op_jsr_32_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 ;
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_jump(ea);
}


void m68k_op_jsr_32_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 ;
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_jump(ea);
}


void m68k_op_jsr_32_pcdi(void)
{
 unsigned int ea = m68ki_get_ea_pcdi();
 ;
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_jump(ea);
}


void m68k_op_jsr_32_pcix(void)
{
 unsigned int ea = m68ki_get_ea_pcix();
 ;
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_jump(ea);
}


void m68k_op_lea_32_ai(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
}


void m68k_op_lea_32_di(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
}


void m68k_op_lea_32_ix(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
}


void m68k_op_lea_32_aw(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(m68ki_read_imm_16());
}


void m68k_op_lea_32_al(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = m68ki_read_imm_32();
}


void m68k_op_lea_32_pcdi(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = m68ki_get_ea_pcdi();
}


void m68k_op_lea_32_pcix(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = m68ki_get_ea_pcix();
}


void m68k_op_link_16_a7(void)
{
 (m68ki_cpu.dar+8)[7] -= 4;
 m68ki_write_32_fc((m68ki_cpu.dar+8)[7], m68ki_cpu.s_flag | 1, (m68ki_cpu.dar+8)[7]);
 (m68ki_cpu.dar+8)[7] = ((m68ki_cpu.dar+8)[7] + (signed short)(m68ki_read_imm_16()));
}


void m68k_op_link_16(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

 m68ki_push_32(*r_dst);
 *r_dst = (m68ki_cpu.dar+8)[7];
 (m68ki_cpu.dar+8)[7] = ((m68ki_cpu.dar+8)[7] + (signed short)(m68ki_read_imm_16()));
}


void m68k_op_link_32_a7(void)
{
 if(0)
 {
  (m68ki_cpu.dar+8)[7] -= 4;
  m68ki_write_32_fc((m68ki_cpu.dar+8)[7], m68ki_cpu.s_flag | 1, (m68ki_cpu.dar+8)[7]);
  (m68ki_cpu.dar+8)[7] = ((m68ki_cpu.dar+8)[7] + m68ki_read_imm_32());
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_link_32(void)
{
 if(0)
 {
  unsigned int* r_dst = &((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

  m68ki_push_32(*r_dst);
  *r_dst = (m68ki_cpu.dar+8)[7];
  (m68ki_cpu.dar+8)[7] = ((m68ki_cpu.dar+8)[7] + m68ki_read_imm_32());
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_lsr_8_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = src >> shift;

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << (9-shift);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_16_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = src >> shift;

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << (9-shift);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_32_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = *r_dst;
 unsigned int res = src >> shift;

 *r_dst = res;

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << (9-shift);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_8_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = src >> shift;

 if(shift != 0)
 {
  m68ki_remaining_cycles -= (shift<<m68ki_cpu.cyc_shift);

  if(shift <= 8)
  {
   *r_dst = ((*r_dst) & ~0xff) | res;
   m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << (9-shift);
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }

  *r_dst &= 0xffffff00;
  m68ki_cpu.x_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.n_flag = 0;
  m68ki_cpu.not_z_flag = 0;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = (src);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_16_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = src >> shift;

 if(shift != 0)
 {
  m68ki_remaining_cycles -= (shift<<m68ki_cpu.cyc_shift);

  if(shift <= 16)
  {
   *r_dst = ((*r_dst) & ~0xffff) | res;
   m68ki_cpu.c_flag = m68ki_cpu.x_flag = (src >> (shift - 1))<<8;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }

  *r_dst &= 0xffff0000;
  m68ki_cpu.x_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.n_flag = 0;
  m68ki_cpu.not_z_flag = 0;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = ((src)>>8);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_32_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int src = *r_dst;
 unsigned int res = src >> shift;

 if(shift != 0)
 {
  m68ki_remaining_cycles -= (shift<<m68ki_cpu.cyc_shift);

  if(shift < 32)
  {
   *r_dst = res;
   m68ki_cpu.c_flag = m68ki_cpu.x_flag = (src >> (shift - 1))<<8;
   m68ki_cpu.n_flag = 0;
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }

  *r_dst = 0;
  m68ki_cpu.x_flag = m68ki_cpu.c_flag = (shift == 32 ? ((src) & 0x80000000)>>23 : 0);
  m68ki_cpu.n_flag = 0;
  m68ki_cpu.not_z_flag = 0;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = ((src)>>24);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsr_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_8_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = ((src << shift) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << shift;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_16_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = ((src << shift) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> (8-shift);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_32_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = *r_dst;
 unsigned int res = (src << shift);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> (24-shift);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_8_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = ((src << shift) & 0xff);

 if(shift != 0)
 {
  m68ki_remaining_cycles -= (shift<<m68ki_cpu.cyc_shift);

  if(shift <= 8)
  {
   *r_dst = ((*r_dst) & ~0xff) | res;
   m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << shift;
   m68ki_cpu.n_flag = (res);
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }

  *r_dst &= 0xffffff00;
  m68ki_cpu.x_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.n_flag = 0;
  m68ki_cpu.not_z_flag = 0;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = (src);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_16_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = ((src << shift) & 0xffff);

 if(shift != 0)
 {
  m68ki_remaining_cycles -= (shift<<m68ki_cpu.cyc_shift);

  if(shift <= 16)
  {
   *r_dst = ((*r_dst) & ~0xffff) | res;
   m68ki_cpu.x_flag = m68ki_cpu.c_flag = (src << shift) >> 8;
   m68ki_cpu.n_flag = ((res)>>8);
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }

  *r_dst &= 0xffff0000;
  m68ki_cpu.x_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.n_flag = 0;
  m68ki_cpu.not_z_flag = 0;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = ((src)>>8);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_32_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int src = *r_dst;
 unsigned int res = (src << shift);

 if(shift != 0)
 {
  m68ki_remaining_cycles -= (shift<<m68ki_cpu.cyc_shift);

  if(shift < 32)
  {
   *r_dst = res;
   m68ki_cpu.x_flag = m68ki_cpu.c_flag = (src >> (32 - shift)) << 8;
   m68ki_cpu.n_flag = ((res)>>24);
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }

  *r_dst = 0;
  m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((shift == 32 ? src & 1 : 0))<<8;
  m68ki_cpu.n_flag = 0;
  m68ki_cpu.not_z_flag = 0;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = ((src)>>24);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_lsl_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_move_8_d_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_ai(void)
{
 unsigned int res = OPER_AY_AI_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_pi(void)
{
 unsigned int res = OPER_AY_PI_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_pd(void)
{
 unsigned int res = OPER_AY_PD_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_di(void)
{
 unsigned int res = OPER_AY_DI_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_ix(void)
{
 unsigned int res = OPER_AY_IX_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_aw(void)
{
 unsigned int res = OPER_AW_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_al(void)
{
 unsigned int res = OPER_AL_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_pcdi(void)
{
 unsigned int res = OPER_PCDI_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_pcix(void)
{
 unsigned int res = OPER_PCIX_8();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_d_i(void)
{
 unsigned int res = ((m68ki_read_imm_16()) & 0xff);
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_ai(void)
{
 unsigned int res = OPER_AY_AI_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_pi(void)
{
 unsigned int res = OPER_AY_PI_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_pd(void)
{
 unsigned int res = OPER_AY_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_di(void)
{
 unsigned int res = OPER_AY_DI_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_ix(void)
{
 unsigned int res = OPER_AY_IX_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_aw(void)
{
 unsigned int res = OPER_AW_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_al(void)
{
 unsigned int res = OPER_AL_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_pcdi(void)
{
 unsigned int res = OPER_PCDI_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_pcix(void)
{
 unsigned int res = OPER_PCIX_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ai_i(void)
{
 unsigned int res = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_ai(void)
{
 unsigned int res = OPER_AY_AI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_pi(void)
{
 unsigned int res = OPER_AY_PI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_pd(void)
{
 unsigned int res = OPER_AY_PD_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_di(void)
{
 unsigned int res = OPER_AY_DI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_ix(void)
{
 unsigned int res = OPER_AY_IX_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_aw(void)
{
 unsigned int res = OPER_AW_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_al(void)
{
 unsigned int res = OPER_AL_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_pcdi(void)
{
 unsigned int res = OPER_PCDI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_pcix(void)
{
 unsigned int res = OPER_PCIX_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi7_i(void)
{
 unsigned int res = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_ai(void)
{
 unsigned int res = OPER_AY_AI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_pi(void)
{
 unsigned int res = OPER_AY_PI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_pd(void)
{
 unsigned int res = OPER_AY_PD_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_di(void)
{
 unsigned int res = OPER_AY_DI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_ix(void)
{
 unsigned int res = OPER_AY_IX_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_aw(void)
{
 unsigned int res = OPER_AW_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_al(void)
{
 unsigned int res = OPER_AL_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_pcdi(void)
{
 unsigned int res = OPER_PCDI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_pcix(void)
{
 unsigned int res = OPER_PCIX_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pi_i(void)
{
 unsigned int res = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])++);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_ai(void)
{
 unsigned int res = OPER_AY_AI_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_pi(void)
{
 unsigned int res = OPER_AY_PI_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_pd(void)
{
 unsigned int res = OPER_AY_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_di(void)
{
 unsigned int res = OPER_AY_DI_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_ix(void)
{
 unsigned int res = OPER_AY_IX_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_aw(void)
{
 unsigned int res = OPER_AW_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_al(void)
{
 unsigned int res = OPER_AL_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_pcdi(void)
{
 unsigned int res = OPER_PCDI_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_pcix(void)
{
 unsigned int res = OPER_PCIX_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd7_i(void)
{
 unsigned int res = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_ai(void)
{
 unsigned int res = OPER_AY_AI_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_pi(void)
{
 unsigned int res = OPER_AY_PI_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_pd(void)
{
 unsigned int res = OPER_AY_PD_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_di(void)
{
 unsigned int res = OPER_AY_DI_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_ix(void)
{
 unsigned int res = OPER_AY_IX_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_aw(void)
{
 unsigned int res = OPER_AW_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_al(void)
{
 unsigned int res = OPER_AL_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_pcdi(void)
{
 unsigned int res = OPER_PCDI_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_pcix(void)
{
 unsigned int res = OPER_PCIX_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_pd_i(void)
{
 unsigned int res = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_ai(void)
{
 unsigned int res = OPER_AY_AI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_pi(void)
{
 unsigned int res = OPER_AY_PI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_pd(void)
{
 unsigned int res = OPER_AY_PD_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_di(void)
{
 unsigned int res = OPER_AY_DI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_ix(void)
{
 unsigned int res = OPER_AY_IX_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_aw(void)
{
 unsigned int res = OPER_AW_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_al(void)
{
 unsigned int res = OPER_AL_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_pcdi(void)
{
 unsigned int res = OPER_PCDI_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_pcix(void)
{
 unsigned int res = OPER_PCIX_8();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_di_i(void)
{
 unsigned int res = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_ai(void)
{
 unsigned int res = OPER_AY_AI_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_pi(void)
{
 unsigned int res = OPER_AY_PI_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_pd(void)
{
 unsigned int res = OPER_AY_PD_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_di(void)
{
 unsigned int res = OPER_AY_DI_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_ix(void)
{
 unsigned int res = OPER_AY_IX_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_aw(void)
{
 unsigned int res = OPER_AW_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_al(void)
{
 unsigned int res = OPER_AL_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_pcdi(void)
{
 unsigned int res = OPER_PCDI_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_pcix(void)
{
 unsigned int res = OPER_PCIX_8();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_ix_i(void)
{
 unsigned int res = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_ai(void)
{
 unsigned int res = OPER_AY_AI_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_pi(void)
{
 unsigned int res = OPER_AY_PI_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_pd(void)
{
 unsigned int res = OPER_AY_PD_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_di(void)
{
 unsigned int res = OPER_AY_DI_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_ix(void)
{
 unsigned int res = OPER_AY_IX_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_aw(void)
{
 unsigned int res = OPER_AW_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_al(void)
{
 unsigned int res = OPER_AL_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_pcdi(void)
{
 unsigned int res = OPER_PCDI_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_pcix(void)
{
 unsigned int res = OPER_PCIX_8();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_aw_i(void)
{
 unsigned int res = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_ai(void)
{
 unsigned int res = OPER_AY_AI_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_pi(void)
{
 unsigned int res = OPER_AY_PI_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_pd(void)
{
 unsigned int res = OPER_AY_PD_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_di(void)
{
 unsigned int res = OPER_AY_DI_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_ix(void)
{
 unsigned int res = OPER_AY_IX_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_aw(void)
{
 unsigned int res = OPER_AW_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_al(void)
{
 unsigned int res = OPER_AL_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_pcdi(void)
{
 unsigned int res = OPER_PCDI_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_pcix(void)
{
 unsigned int res = OPER_PCIX_8();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_8_al_i(void)
{
 unsigned int res = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_a(void)
{
 unsigned int res = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_ai(void)
{
 unsigned int res = OPER_AY_AI_16();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_pi(void)
{
 unsigned int res = OPER_AY_PI_16();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_pd(void)
{
 unsigned int res = OPER_AY_PD_16();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_di(void)
{
 unsigned int res = OPER_AY_DI_16();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_ix(void)
{
 unsigned int res = OPER_AY_IX_16();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_aw(void)
{
 unsigned int res = OPER_AW_16();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_al(void)
{
 unsigned int res = OPER_AL_16();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_pcdi(void)
{
 unsigned int res = OPER_PCDI_16();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_pcix(void)
{
 unsigned int res = OPER_PCIX_16();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_d_i(void)
{
 unsigned int res = m68ki_read_imm_16();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_a(void)
{
 unsigned int res = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_ai(void)
{
 unsigned int res = OPER_AY_AI_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_pi(void)
{
 unsigned int res = OPER_AY_PI_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_pd(void)
{
 unsigned int res = OPER_AY_PD_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_di(void)
{
 unsigned int res = OPER_AY_DI_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_ix(void)
{
 unsigned int res = OPER_AY_IX_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_aw(void)
{
 unsigned int res = OPER_AW_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_al(void)
{
 unsigned int res = OPER_AL_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_pcdi(void)
{
 unsigned int res = OPER_PCDI_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_pcix(void)
{
 unsigned int res = OPER_PCIX_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ai_i(void)
{
 unsigned int res = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_a(void)
{
 unsigned int res = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_ai(void)
{
 unsigned int res = OPER_AY_AI_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_pi(void)
{
 unsigned int res = OPER_AY_PI_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_pd(void)
{
 unsigned int res = OPER_AY_PD_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_di(void)
{
 unsigned int res = OPER_AY_DI_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_ix(void)
{
 unsigned int res = OPER_AY_IX_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_aw(void)
{
 unsigned int res = OPER_AW_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_al(void)
{
 unsigned int res = OPER_AL_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_pcdi(void)
{
 unsigned int res = OPER_PCDI_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_pcix(void)
{
 unsigned int res = OPER_PCIX_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pi_i(void)
{
 unsigned int res = m68ki_read_imm_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=2)-2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_a(void)
{
 unsigned int res = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_ai(void)
{
 unsigned int res = OPER_AY_AI_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_pi(void)
{
 unsigned int res = OPER_AY_PI_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_pd(void)
{
 unsigned int res = OPER_AY_PD_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_di(void)
{
 unsigned int res = OPER_AY_DI_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_ix(void)
{
 unsigned int res = OPER_AY_IX_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_aw(void)
{
 unsigned int res = OPER_AW_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_al(void)
{
 unsigned int res = OPER_AL_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_pcdi(void)
{
 unsigned int res = OPER_PCDI_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_pcix(void)
{
 unsigned int res = OPER_PCIX_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_pd_i(void)
{
 unsigned int res = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_a(void)
{
 unsigned int res = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_ai(void)
{
 unsigned int res = OPER_AY_AI_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_pi(void)
{
 unsigned int res = OPER_AY_PI_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_pd(void)
{
 unsigned int res = OPER_AY_PD_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_di(void)
{
 unsigned int res = OPER_AY_DI_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_ix(void)
{
 unsigned int res = OPER_AY_IX_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_aw(void)
{
 unsigned int res = OPER_AW_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_al(void)
{
 unsigned int res = OPER_AL_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_pcdi(void)
{
 unsigned int res = OPER_PCDI_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_pcix(void)
{
 unsigned int res = OPER_PCIX_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_di_i(void)
{
 unsigned int res = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_a(void)
{
 unsigned int res = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_ai(void)
{
 unsigned int res = OPER_AY_AI_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_pi(void)
{
 unsigned int res = OPER_AY_PI_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_pd(void)
{
 unsigned int res = OPER_AY_PD_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_di(void)
{
 unsigned int res = OPER_AY_DI_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_ix(void)
{
 unsigned int res = OPER_AY_IX_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_aw(void)
{
 unsigned int res = OPER_AW_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_al(void)
{
 unsigned int res = OPER_AL_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_pcdi(void)
{
 unsigned int res = OPER_PCDI_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_pcix(void)
{
 unsigned int res = OPER_PCIX_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_ix_i(void)
{
 unsigned int res = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_a(void)
{
 unsigned int res = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_ai(void)
{
 unsigned int res = OPER_AY_AI_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_pi(void)
{
 unsigned int res = OPER_AY_PI_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_pd(void)
{
 unsigned int res = OPER_AY_PD_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_di(void)
{
 unsigned int res = OPER_AY_DI_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_ix(void)
{
 unsigned int res = OPER_AY_IX_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_aw(void)
{
 unsigned int res = OPER_AW_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_al(void)
{
 unsigned int res = OPER_AL_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_pcdi(void)
{
 unsigned int res = OPER_PCDI_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_pcix(void)
{
 unsigned int res = OPER_PCIX_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_aw_i(void)
{
 unsigned int res = m68ki_read_imm_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_a(void)
{
 unsigned int res = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_ai(void)
{
 unsigned int res = OPER_AY_AI_16();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_pi(void)
{
 unsigned int res = OPER_AY_PI_16();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_pd(void)
{
 unsigned int res = OPER_AY_PD_16();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_di(void)
{
 unsigned int res = OPER_AY_DI_16();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_ix(void)
{
 unsigned int res = OPER_AY_IX_16();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_aw(void)
{
 unsigned int res = OPER_AW_16();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_al(void)
{
 unsigned int res = OPER_AL_16();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_pcdi(void)
{
 unsigned int res = OPER_PCDI_16();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_pcix(void)
{
 unsigned int res = OPER_PCIX_16();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_16_al_i(void)
{
 unsigned int res = m68ki_read_imm_16();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_a(void)
{
 unsigned int res = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_ai(void)
{
 unsigned int res = OPER_AY_AI_32();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_pi(void)
{
 unsigned int res = OPER_AY_PI_32();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_pd(void)
{
 unsigned int res = OPER_AY_PD_32();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_di(void)
{
 unsigned int res = OPER_AY_DI_32();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_ix(void)
{
 unsigned int res = OPER_AY_IX_32();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_aw(void)
{
 unsigned int res = OPER_AW_32();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_al(void)
{
 unsigned int res = OPER_AL_32();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_pcdi(void)
{
 unsigned int res = OPER_PCDI_32();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_pcix(void)
{
 unsigned int res = OPER_PCIX_32();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_d_i(void)
{
 unsigned int res = m68ki_read_imm_32();
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_a(void)
{
 unsigned int res = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_ai(void)
{
 unsigned int res = OPER_AY_AI_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_pi(void)
{
 unsigned int res = OPER_AY_PI_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_pd(void)
{
 unsigned int res = OPER_AY_PD_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_di(void)
{
 unsigned int res = OPER_AY_DI_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_ix(void)
{
 unsigned int res = OPER_AY_IX_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_aw(void)
{
 unsigned int res = OPER_AW_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_al(void)
{
 unsigned int res = OPER_AL_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_pcdi(void)
{
 unsigned int res = OPER_PCDI_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_pcix(void)
{
 unsigned int res = OPER_PCIX_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ai_i(void)
{
 unsigned int res = m68ki_read_imm_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_a(void)
{
 unsigned int res = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_ai(void)
{
 unsigned int res = OPER_AY_AI_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_pi(void)
{
 unsigned int res = OPER_AY_PI_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_pd(void)
{
 unsigned int res = OPER_AY_PD_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_di(void)
{
 unsigned int res = OPER_AY_DI_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_ix(void)
{
 unsigned int res = OPER_AY_IX_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_aw(void)
{
 unsigned int res = OPER_AW_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_al(void)
{
 unsigned int res = OPER_AL_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_pcdi(void)
{
 unsigned int res = OPER_PCDI_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_pcix(void)
{
 unsigned int res = OPER_PCIX_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pi_i(void)
{
 unsigned int res = m68ki_read_imm_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+=4)-4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_a(void)
{
 unsigned int res = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_ai(void)
{
 unsigned int res = OPER_AY_AI_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_pi(void)
{
 unsigned int res = OPER_AY_PI_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_pd(void)
{
 unsigned int res = OPER_AY_PD_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_di(void)
{
 unsigned int res = OPER_AY_DI_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_ix(void)
{
 unsigned int res = OPER_AY_IX_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_aw(void)
{
 unsigned int res = OPER_AW_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_al(void)
{
 unsigned int res = OPER_AL_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_pcdi(void)
{
 unsigned int res = OPER_PCDI_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_pcix(void)
{
 unsigned int res = OPER_PCIX_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_pd_i(void)
{
 unsigned int res = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_a(void)
{
 unsigned int res = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_ai(void)
{
 unsigned int res = OPER_AY_AI_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_pi(void)
{
 unsigned int res = OPER_AY_PI_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_pd(void)
{
 unsigned int res = OPER_AY_PD_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_di(void)
{
 unsigned int res = OPER_AY_DI_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_ix(void)
{
 unsigned int res = OPER_AY_IX_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_aw(void)
{
 unsigned int res = OPER_AW_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_al(void)
{
 unsigned int res = OPER_AL_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_pcdi(void)
{
 unsigned int res = OPER_PCDI_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_pcix(void)
{
 unsigned int res = OPER_PCIX_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_di_i(void)
{
 unsigned int res = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_a(void)
{
 unsigned int res = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_ai(void)
{
 unsigned int res = OPER_AY_AI_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_pi(void)
{
 unsigned int res = OPER_AY_PI_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_pd(void)
{
 unsigned int res = OPER_AY_PD_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_di(void)
{
 unsigned int res = OPER_AY_DI_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_ix(void)
{
 unsigned int res = OPER_AY_IX_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_aw(void)
{
 unsigned int res = OPER_AW_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_al(void)
{
 unsigned int res = OPER_AL_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_pcdi(void)
{
 unsigned int res = OPER_PCDI_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_pcix(void)
{
 unsigned int res = OPER_PCIX_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_ix_i(void)
{
 unsigned int res = m68ki_read_imm_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_a(void)
{
 unsigned int res = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_ai(void)
{
 unsigned int res = OPER_AY_AI_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_pi(void)
{
 unsigned int res = OPER_AY_PI_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_pd(void)
{
 unsigned int res = OPER_AY_PD_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_di(void)
{
 unsigned int res = OPER_AY_DI_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_ix(void)
{
 unsigned int res = OPER_AY_IX_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_aw(void)
{
 unsigned int res = OPER_AW_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_al(void)
{
 unsigned int res = OPER_AL_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_pcdi(void)
{
 unsigned int res = OPER_PCDI_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_pcix(void)
{
 unsigned int res = OPER_PCIX_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_aw_i(void)
{
 unsigned int res = m68ki_read_imm_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_a(void)
{
 unsigned int res = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_ai(void)
{
 unsigned int res = OPER_AY_AI_32();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_pi(void)
{
 unsigned int res = OPER_AY_PI_32();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_pd(void)
{
 unsigned int res = OPER_AY_PD_32();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_di(void)
{
 unsigned int res = OPER_AY_DI_32();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_ix(void)
{
 unsigned int res = OPER_AY_IX_32();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_aw(void)
{
 unsigned int res = OPER_AW_32();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_al(void)
{
 unsigned int res = OPER_AL_32();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_pcdi(void)
{
 unsigned int res = OPER_PCDI_32();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_pcix(void)
{
 unsigned int res = OPER_PCIX_32();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_move_32_al_i(void)
{
 unsigned int res = m68ki_read_imm_32();
 unsigned int ea = m68ki_read_imm_32();

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_movea_16_d(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)((m68ki_cpu.dar[m68ki_cpu.ir & 7]));
}


void m68k_op_movea_16_a(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
}


void m68k_op_movea_16_ai(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(OPER_AY_AI_16());
}


void m68k_op_movea_16_pi(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(OPER_AY_PI_16());
}


void m68k_op_movea_16_pd(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(OPER_AY_PD_16());
}


void m68k_op_movea_16_di(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(OPER_AY_DI_16());
}


void m68k_op_movea_16_ix(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(OPER_AY_IX_16());
}


void m68k_op_movea_16_aw(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(OPER_AW_16());
}


void m68k_op_movea_16_al(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(OPER_AL_16());
}


void m68k_op_movea_16_pcdi(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(OPER_PCDI_16());
}


void m68k_op_movea_16_pcix(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(OPER_PCIX_16());
}


void m68k_op_movea_16_i(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (signed short)(m68ki_read_imm_16());
}


void m68k_op_movea_32_d(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
}


void m68k_op_movea_32_a(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
}


void m68k_op_movea_32_ai(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = OPER_AY_AI_32();
}


void m68k_op_movea_32_pi(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = OPER_AY_PI_32();
}


void m68k_op_movea_32_pd(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = OPER_AY_PD_32();
}


void m68k_op_movea_32_di(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = OPER_AY_DI_32();
}


void m68k_op_movea_32_ix(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = OPER_AY_IX_32();
}


void m68k_op_movea_32_aw(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = OPER_AW_32();
}


void m68k_op_movea_32_al(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = OPER_AL_32();
}


void m68k_op_movea_32_pcdi(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = OPER_PCDI_32();
}


void m68k_op_movea_32_pcix(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = OPER_PCIX_32();
}


void m68k_op_movea_32_i(void)
{
 ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]) = m68ki_read_imm_32();
}


void m68k_op_move_16_frc_d(void)
{
 if(0)
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & ~0xffff) | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_move_16_frc_ai(void)
{
 if(0)
 {
  m68ki_write_16_fc(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_move_16_frc_pi(void)
{
 if(0)
 {
  m68ki_write_16_fc(((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2), m68ki_cpu.s_flag | 1, (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_move_16_frc_pd(void)
{
 if(0)
 {
  m68ki_write_16_fc((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2), m68ki_cpu.s_flag | 1, (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_move_16_frc_di(void)
{
 if(0)
 {
  m68ki_write_16_fc((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_move_16_frc_ix(void)
{
 if(0)
 {
  m68ki_write_16_fc(m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_move_16_frc_aw(void)
{
 if(0)
 {
  m68ki_write_16_fc((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_move_16_frc_al(void)
{
 if(0)
 {
  m68ki_write_16_fc(m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_move_16_toc_d(void)
{
 m68ki_set_ccr((m68ki_cpu.dar[m68ki_cpu.ir & 7]));
}


void m68k_op_move_16_toc_ai(void)
{
 m68ki_set_ccr(OPER_AY_AI_16());
}


void m68k_op_move_16_toc_pi(void)
{
 m68ki_set_ccr(OPER_AY_PI_16());
}


void m68k_op_move_16_toc_pd(void)
{
 m68ki_set_ccr(OPER_AY_PD_16());
}


void m68k_op_move_16_toc_di(void)
{
 m68ki_set_ccr(OPER_AY_DI_16());
}


void m68k_op_move_16_toc_ix(void)
{
 m68ki_set_ccr(OPER_AY_IX_16());
}


void m68k_op_move_16_toc_aw(void)
{
 m68ki_set_ccr(OPER_AW_16());
}


void m68k_op_move_16_toc_al(void)
{
 m68ki_set_ccr(OPER_AL_16());
}


void m68k_op_move_16_toc_pcdi(void)
{
 m68ki_set_ccr(OPER_PCDI_16());
}


void m68k_op_move_16_toc_pcix(void)
{
 m68ki_set_ccr(OPER_PCIX_16());
}


void m68k_op_move_16_toc_i(void)
{
 m68ki_set_ccr(m68ki_read_imm_16());
}


void m68k_op_move_16_frs_d(void)
{
 if(1 || m68ki_cpu.s_flag)
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & ~0xffff) | ( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)));
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_frs_ai(void)
{
 if(1 || m68ki_cpu.s_flag)
 {
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
  m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8))));
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_frs_pi(void)
{
 if(1 || m68ki_cpu.s_flag)
 {
  unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
  m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8))));
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_frs_pd(void)
{
 if(1 || m68ki_cpu.s_flag)
 {
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
  m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8))));
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_frs_di(void)
{
 if(1 || m68ki_cpu.s_flag)
 {
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
  m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8))));
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_frs_ix(void)
{
 if(1 || m68ki_cpu.s_flag)
 {
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8))));
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_frs_aw(void)
{
 if(1 || m68ki_cpu.s_flag)
 {
  unsigned int ea = (signed short)(m68ki_read_imm_16());
  m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8))));
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_frs_al(void)
{
 if(1 || m68ki_cpu.s_flag)
 {
  unsigned int ea = m68ki_read_imm_32();
  m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8))));
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_d(void)
{
 if(m68ki_cpu.s_flag)
 {
  m68ki_set_sr((m68ki_cpu.dar[m68ki_cpu.ir & 7]));
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_ai(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = OPER_AY_AI_16();
  ;
  m68ki_set_sr(new_sr);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_pi(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = OPER_AY_PI_16();
  ;
  m68ki_set_sr(new_sr);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_pd(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = OPER_AY_PD_16();
  ;
  m68ki_set_sr(new_sr);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_di(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = OPER_AY_DI_16();
  ;
  m68ki_set_sr(new_sr);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_ix(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = OPER_AY_IX_16();
  ;
  m68ki_set_sr(new_sr);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_aw(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = OPER_AW_16();
  ;
  m68ki_set_sr(new_sr);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_al(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = OPER_AL_16();
  ;
  m68ki_set_sr(new_sr);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_pcdi(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = OPER_PCDI_16();
  ;
  m68ki_set_sr(new_sr);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_pcix(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = OPER_PCIX_16();
  ;
  m68ki_set_sr(new_sr);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_16_tos_i(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = m68ki_read_imm_16();
  ;
  m68ki_set_sr(new_sr);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_32_fru(void)
{
 if(m68ki_cpu.s_flag)
 {
  ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]) = m68ki_cpu.sp[0];
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_move_32_tou(void)
{
 if(m68ki_cpu.s_flag)
 {
  ;
  m68ki_cpu.sp[0] = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_movec_32_cr(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();

   ;
   switch (word2 & 0xfff)
   {
   case 0x000:
    m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_cpu.sfc;
    return;
   case 0x001:
    m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_cpu.dfc;
    return;
   case 0x002:
    if(0)
    {
     m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_cpu.cacr;
     return;
    }
    return;
   case 0x800:
    m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_cpu.sp[0];
    return;
   case 0x801:
    m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_cpu.vbr;
    return;
   case 0x802:
    if(0)
    {
     m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_cpu.caar;
     return;
    }
    m68ki_exception_illegal();
    break;
   case 0x803:
    if(0)
    {
     m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_cpu.m_flag ? m68ki_cpu.dar[15] : m68ki_cpu.sp[6];
     return;
    }
    m68ki_exception_illegal();
    return;
   case 0x804:
    if(0)
    {
     m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_cpu.m_flag ? m68ki_cpu.sp[4] : m68ki_cpu.dar[15];
     return;
    }
    m68ki_exception_illegal();
    return;
   default:
    m68ki_exception_illegal();
    return;
   }
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_movec_32_rc(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();

   ;
   switch (word2 & 0xfff)
   {
   case 0x000:
    m68ki_cpu.sfc = m68ki_cpu.dar[(word2 >> 12) & 15] & 7;
    return;
   case 0x001:
    m68ki_cpu.dfc = m68ki_cpu.dar[(word2 >> 12) & 15] & 7;
    return;
   case 0x002:
    if(0)
    {
     m68ki_cpu.cacr = m68ki_cpu.dar[(word2 >> 12) & 15];
     return;
    }
    m68ki_exception_illegal();
    return;
   case 0x800:
    m68ki_cpu.sp[0] = m68ki_cpu.dar[(word2 >> 12) & 15];
    return;
   case 0x801:
    m68ki_cpu.vbr = m68ki_cpu.dar[(word2 >> 12) & 15];
    return;
   case 0x802:
    if(0)
    {
     m68ki_cpu.caar = m68ki_cpu.dar[(word2 >> 12) & 15];
     return;
    }
    m68ki_exception_illegal();
    return;
   case 0x803:
    if(0)
    {

     if(!m68ki_cpu.m_flag)
     {
      m68ki_cpu.sp[6] = m68ki_cpu.dar[(word2 >> 12) & 15];
      return;
     }
     m68ki_cpu.dar[15] = m68ki_cpu.dar[(word2 >> 12) & 15];
     return;
    }
    m68ki_exception_illegal();
    return;
   case 0x804:
    if(0)
    {
     if(!m68ki_cpu.m_flag)
     {
      m68ki_cpu.dar[15] = m68ki_cpu.dar[(word2 >> 12) & 15];
      return;
     }
     m68ki_cpu.sp[4] = m68ki_cpu.dar[(word2 >> 12) & 15];
     return;
    }
    m68ki_exception_illegal();
    return;
   default:
    m68ki_exception_illegal();
    return;
   }
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_movem_16_re_pd(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   ea -= 2;
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[15-i]) & 0xffff));
   count++;
  }
 ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]) = ea;

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_re_ai(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[i]) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_re_di(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[i]) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_re_ix(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[i]) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_re_aw(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[i]) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_re_al(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[i]) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_32_re_pd(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   ea -= 4;
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[15-i]);
   count++;
  }
 ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]) = ea;

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_re_ai(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[i]);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_re_di(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[i]);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_re_ix(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[i]);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_re_aw(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[i]);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_re_al(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[i]);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_16_er_pi(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = (signed short)(((m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff));
   ea += 2;
   count++;
  }
 ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]) = ea;

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_er_pcdi(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_pcdi();
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = (signed short)(((m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 2)) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_er_pcix(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_pcix();
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = (signed short)(((m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 2)) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_er_ai(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = (signed short)(((m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_er_di(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = (signed short)(((m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_er_ix(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = (signed short)(((m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_er_aw(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = (signed short)(((m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_16_er_al(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = (signed short)(((m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff));
   ea += 2;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_w);
}


void m68k_op_movem_32_er_pi(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
   ea += 4;
   count++;
  }
 ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]) = ea;

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_er_pcdi(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_pcdi();
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 2);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_er_pcix(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_pcix();
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 2);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_er_ai(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_er_di(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_er_ix(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_er_aw(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movem_32_er_al(void)
{
 unsigned int i = 0;
 unsigned int register_list = m68ki_read_imm_16();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int count = 0;

 for(; i < 16; i++)
  if(register_list & (1 << i))
  {
   m68ki_cpu.dar[i] = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
   ea += 4;
   count++;
  }

 m68ki_remaining_cycles -= (count<<m68ki_cpu.cyc_movem_l);
}


void m68k_op_movep_16_re(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((src >> 8) & 0xff));
 m68ki_write_8_fc (ea += 2, m68ki_cpu.s_flag | 1, ((src) & 0xff));
}


void m68k_op_movep_32_re(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((src >> 24) & 0xff));
 m68ki_write_8_fc (ea += 2, m68ki_cpu.s_flag | 1, ((src >> 16) & 0xff));
 m68ki_write_8_fc (ea += 2, m68ki_cpu.s_flag | 1, ((src >> 8) & 0xff));
 m68ki_write_8_fc (ea += 2, m68ki_cpu.s_flag | 1, ((src) & 0xff));
}


void m68k_op_movep_16_er(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = ((*r_dst) & ~0xffff) | ((m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1) << 8) + m68ki_read_8_fc (ea + 2, m68ki_cpu.s_flag | 1));
}


void m68k_op_movep_32_er(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));

 (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) = (m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1) << 24) + (m68ki_read_8_fc (ea + 2, m68ki_cpu.s_flag | 1) << 16)
  + (m68ki_read_8_fc (ea + 4, m68ki_cpu.s_flag | 1) << 8) + m68ki_read_8_fc (ea + 6, m68ki_cpu.s_flag | 1);
}


void m68k_op_moves_8_ai(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_8_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed char)(m68ki_read_8_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xff) | m68ki_read_8_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_8_pi(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_8_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed char)(m68ki_read_8_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xff) | m68ki_read_8_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_8_pi7(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_8_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed char)(m68ki_read_8_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xff) | m68ki_read_8_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_8_pd(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_8_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed char)(m68ki_read_8_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xff) | m68ki_read_8_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_8_pd7(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_8_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed char)(m68ki_read_8_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xff) | m68ki_read_8_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_8_di(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_8_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed char)(m68ki_read_8_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xff) | m68ki_read_8_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_8_ix(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_8_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed char)(m68ki_read_8_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xff) | m68ki_read_8_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_8_aw(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (signed short)(m68ki_read_imm_16());

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_8_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed char)(m68ki_read_8_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xff) | m68ki_read_8_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_8_al(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = m68ki_read_imm_32();

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_8_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed char)(m68ki_read_8_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xff) | m68ki_read_8_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_16_ai(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_16_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xffff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed short)(m68ki_read_16_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xffff) | m68ki_read_16_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_16_pi(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_16_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xffff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed short)(m68ki_read_16_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xffff) | m68ki_read_16_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_16_pd(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_16_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xffff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed short)(m68ki_read_16_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xffff) | m68ki_read_16_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_16_di(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_16_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xffff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed short)(m68ki_read_16_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xffff) | m68ki_read_16_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_16_ix(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_16_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xffff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed short)(m68ki_read_16_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xffff) | m68ki_read_16_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_16_aw(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (signed short)(m68ki_read_imm_16());

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_16_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xffff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed short)(m68ki_read_16_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xffff) | m68ki_read_16_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_16_al(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = m68ki_read_imm_32();

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_16_fc(ea, m68ki_cpu.dfc, ((m68ki_cpu.dar[(word2 >> 12) & 15]) & 0xffff));
    return;
   }
   if(((word2) & 0x00008000))
   {
    (m68ki_cpu.dar+8)[(word2 >> 12) & 7] = (signed short)(m68ki_read_16_fc(ea, m68ki_cpu.sfc));
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 7] = ((m68ki_cpu.dar[(word2 >> 12) & 7]) & ~0xffff) | m68ki_read_16_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_32_ai(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_32_fc(ea, m68ki_cpu.dfc, m68ki_cpu.dar[(word2 >> 12) & 15]);
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_read_32_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_32_pi(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_32_fc(ea, m68ki_cpu.dfc, m68ki_cpu.dar[(word2 >> 12) & 15]);
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_read_32_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_32_pd(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_32_fc(ea, m68ki_cpu.dfc, m68ki_cpu.dar[(word2 >> 12) & 15]);
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_read_32_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_32_di(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_32_fc(ea, m68ki_cpu.dfc, m68ki_cpu.dar[(word2 >> 12) & 15]);
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_read_32_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_32_ix(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_32_fc(ea, m68ki_cpu.dfc, m68ki_cpu.dar[(word2 >> 12) & 15]);
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_read_32_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_32_aw(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = (signed short)(m68ki_read_imm_16());

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_32_fc(ea, m68ki_cpu.dfc, m68ki_cpu.dar[(word2 >> 12) & 15]);
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_read_32_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moves_32_al(void)
{
 if(0)
 {
  if(m68ki_cpu.s_flag)
  {
   unsigned int word2 = m68ki_read_imm_16();
   unsigned int ea = m68ki_read_imm_32();

   ;
   if(((word2) & 0x00000800))
   {
    m68ki_write_32_fc(ea, m68ki_cpu.dfc, m68ki_cpu.dar[(word2 >> 12) & 15]);
    if(0)
     m68ki_remaining_cycles -= (2);
    return;
   }

   m68ki_cpu.dar[(word2 >> 12) & 15] = m68ki_read_32_fc(ea, m68ki_cpu.sfc);
   if(0)
    m68ki_remaining_cycles -= (2);
   return;
  }
  m68ki_exception_privilege_violation();
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_moveq_32(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) = (signed char)(((m68ki_cpu.ir) & 0xff));

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)((m68ki_cpu.dar[m68ki_cpu.ir & 7])) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_ai(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)(OPER_AY_AI_16()) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_pi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)(OPER_AY_PI_16()) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_pd(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)(OPER_AY_PD_16()) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_di(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)(OPER_AY_DI_16()) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_ix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)(OPER_AY_IX_16()) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_aw(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)(OPER_AW_16()) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_al(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)(OPER_AL_16()) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_pcdi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)(OPER_PCDI_16()) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_pcix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)(OPER_PCIX_16()) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_muls_16_i(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = ((signed short)(m68ki_read_imm_16()) * (signed short)(((*r_dst) & 0xffff)));

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff) * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_ai(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = OPER_AY_AI_16() * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_pi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = OPER_AY_PI_16() * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_pd(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = OPER_AY_PD_16() * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_di(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = OPER_AY_DI_16() * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_ix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = OPER_AY_IX_16() * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_aw(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = OPER_AW_16() * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_al(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = OPER_AL_16() * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_pcdi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = OPER_PCDI_16() * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_pcix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = OPER_PCIX_16() * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mulu_16_i(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = m68ki_read_imm_16() * ((*r_dst) & 0xffff);

 *r_dst = res;

 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_mull_32_d(void)
{
# 11913 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_mull_32_ai(void)
{
# 12037 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = OPER_AY_AI_32();
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_mull_32_pi(void)
{
# 12161 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = OPER_AY_PI_32();
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_mull_32_pd(void)
{
# 12285 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = OPER_AY_PD_32();
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_mull_32_di(void)
{
# 12409 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = OPER_AY_DI_32();
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_mull_32_ix(void)
{
# 12533 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = OPER_AY_IX_32();
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_mull_32_aw(void)
{
# 12657 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = OPER_AW_32();
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_mull_32_al(void)
{
# 12781 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = OPER_AL_32();
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_mull_32_pcdi(void)
{
# 12905 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = OPER_PCDI_32();
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_mull_32_pcix(void)
{
# 13029 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = OPER_PCIX_32();
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}


void m68k_op_mull_32_i(void)
{
# 13153 "obj/m68kopdm.c"
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int src = m68ki_read_imm_32();
  unsigned int dst = m68ki_cpu.dar[(word2 >> 12) & 7];
  unsigned int neg = ((src ^ dst) & 0x80000000);
  unsigned int src1;
  unsigned int src2;
  unsigned int dst1;
  unsigned int dst2;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r4;
  unsigned int lo;
  unsigned int hi;

  m68ki_cpu.c_flag = 0;

  if(((word2) & 0x00000800))
  {
   if(((src) & 0x80000000))
    src = (unsigned int)(-(signed int)src);
   if(((dst) & 0x80000000))
    dst = (unsigned int)(-(signed int)dst);
  }

  src1 = ((src) & 0xffff);
  src2 = src>>16;
  dst1 = ((dst) & 0xffff);
  dst2 = dst>>16;


  r1 = src1 * dst1;
  r2 = src1 * dst2;
  r3 = src2 * dst1;
  r4 = src2 * dst2;

  lo = r1 + (((r2) & 0xffff)<<16) + (((r3) & 0xffff)<<16);
  hi = r4 + (r2>>16) + (r3>>16) + (((r1>>16) + ((r2) & 0xffff) + ((r3) & 0xffff)) >> 16);

  if(((word2) & 0x00000800) && neg)
  {
   hi = (unsigned int)((-(signed int)hi) - (lo != 0));
   lo = (unsigned int)(-(signed int)lo);
  }

  if(((word2) & 0x00000400))
  {
   m68ki_cpu.dar[word2 & 7] = hi;
   m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
   m68ki_cpu.n_flag = ((hi)>>24);
   m68ki_cpu.not_z_flag = hi | lo;
   m68ki_cpu.v_flag = 0;
   return;
  }

  m68ki_cpu.dar[(word2 >> 12) & 7] = lo;
  m68ki_cpu.n_flag = ((lo)>>24);
  m68ki_cpu.not_z_flag = lo;
  if(((word2) & 0x00000800))
   m68ki_cpu.v_flag = (!((((lo) & 0x80000000) && hi == 0xffffffff) || (!((lo) & 0x80000000) && !hi)))<<7;
  else
   m68ki_cpu.v_flag = (hi != 0) << 7;
  return;
 }
 m68ki_exception_illegal();


}
