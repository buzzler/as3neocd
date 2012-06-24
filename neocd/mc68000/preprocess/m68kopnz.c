void cdrom_load_files(void);
void neogeo_cdda_control(void);
void neogeo_prio_switch(void);
void neogeo_upload(void);

extern int img_display;






void m68k_op_nbcd_8_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int dst = *r_dst;
 unsigned int res = ((0x9a - dst - ((m68ki_cpu.x_flag>>8)&1)) & 0xff);

 if(res != 0x9a)
 {
  m68ki_cpu.v_flag = ~res;

  if((res & 0x0f) == 0xa)
   res = (res & 0xf0) + 0x10;

  res = ((res) & 0xff);

  m68ki_cpu.v_flag &= res;

  *r_dst = ((*r_dst) & ~0xff) | res;

  m68ki_cpu.not_z_flag |= res;
  m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.x_flag = 0x100;
 }
 else
 {
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
 }
 m68ki_cpu.n_flag = (res);
}


void m68k_op_nbcd_8_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((0x9a - dst - ((m68ki_cpu.x_flag>>8)&1)) & 0xff);

 if(res != 0x9a)
 {
  m68ki_cpu.v_flag = ~res;

  if((res & 0x0f) == 0xa)
   res = (res & 0xf0) + 0x10;

  res = ((res) & 0xff);

  m68ki_cpu.v_flag &= res;

  m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((res) & 0xff));

  m68ki_cpu.not_z_flag |= res;
  m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.x_flag = 0x100;
 }
 else
 {
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
 }
 m68ki_cpu.n_flag = (res);
}


void m68k_op_nbcd_8_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((0x9a - dst - ((m68ki_cpu.x_flag>>8)&1)) & 0xff);

 if(res != 0x9a)
 {
  m68ki_cpu.v_flag = ~res;

  if((res & 0x0f) == 0xa)
   res = (res & 0xf0) + 0x10;

  res = ((res) & 0xff);

  m68ki_cpu.v_flag &= res;

  m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((res) & 0xff));

  m68ki_cpu.not_z_flag |= res;
  m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.x_flag = 0x100;
 }
 else
 {
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
 }
 m68ki_cpu.n_flag = (res);
}


void m68k_op_nbcd_8_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((0x9a - dst - ((m68ki_cpu.x_flag>>8)&1)) & 0xff);

 if(res != 0x9a)
 {
  m68ki_cpu.v_flag = ~res;

  if((res & 0x0f) == 0xa)
   res = (res & 0xf0) + 0x10;

  res = ((res) & 0xff);

  m68ki_cpu.v_flag &= res;

  m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((res) & 0xff));

  m68ki_cpu.not_z_flag |= res;
  m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.x_flag = 0x100;
 }
 else
 {
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
 }
 m68ki_cpu.n_flag = (res);
}


void m68k_op_nbcd_8_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((0x9a - dst - ((m68ki_cpu.x_flag>>8)&1)) & 0xff);

 if(res != 0x9a)
 {
  m68ki_cpu.v_flag = ~res;

  if((res & 0x0f) == 0xa)
   res = (res & 0xf0) + 0x10;

  res = ((res) & 0xff);

  m68ki_cpu.v_flag &= res;

  m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((res) & 0xff));

  m68ki_cpu.not_z_flag |= res;
  m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.x_flag = 0x100;
 }
 else
 {
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
 }
 m68ki_cpu.n_flag = (res);
}


void m68k_op_nbcd_8_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((0x9a - dst - ((m68ki_cpu.x_flag>>8)&1)) & 0xff);

 if(res != 0x9a)
 {
  m68ki_cpu.v_flag = ~res;

  if((res & 0x0f) == 0xa)
   res = (res & 0xf0) + 0x10;

  res = ((res) & 0xff);

  m68ki_cpu.v_flag &= res;

  m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((res) & 0xff));

  m68ki_cpu.not_z_flag |= res;
  m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.x_flag = 0x100;
 }
 else
 {
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
 }
 m68ki_cpu.n_flag = (res);
}


void m68k_op_nbcd_8_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((0x9a - dst - ((m68ki_cpu.x_flag>>8)&1)) & 0xff);

 if(res != 0x9a)
 {
  m68ki_cpu.v_flag = ~res;

  if((res & 0x0f) == 0xa)
   res = (res & 0xf0) + 0x10;

  res = ((res) & 0xff);

  m68ki_cpu.v_flag &= res;

  m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((res) & 0xff));

  m68ki_cpu.not_z_flag |= res;
  m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.x_flag = 0x100;
 }
 else
 {
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
 }
 m68ki_cpu.n_flag = (res);
}


void m68k_op_nbcd_8_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((0x9a - dst - ((m68ki_cpu.x_flag>>8)&1)) & 0xff);

 if(res != 0x9a)
 {
  m68ki_cpu.v_flag = ~res;

  if((res & 0x0f) == 0xa)
   res = (res & 0xf0) + 0x10;

  res = ((res) & 0xff);

  m68ki_cpu.v_flag &= res;

  m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((res) & 0xff));

  m68ki_cpu.not_z_flag |= res;
  m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.x_flag = 0x100;
 }
 else
 {
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
 }
 m68ki_cpu.n_flag = (res);
}


void m68k_op_nbcd_8_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((0x9a - dst - ((m68ki_cpu.x_flag>>8)&1)) & 0xff);

 if(res != 0x9a)
 {
  m68ki_cpu.v_flag = ~res;

  if((res & 0x0f) == 0xa)
   res = (res & 0xf0) + 0x10;

  res = ((res) & 0xff);

  m68ki_cpu.v_flag &= res;

  m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((res) & 0xff));

  m68ki_cpu.not_z_flag |= res;
  m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.x_flag = 0x100;
 }
 else
 {
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
 }
 m68ki_cpu.n_flag = (res);
}


void m68k_op_nbcd_8_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((0x9a - dst - ((m68ki_cpu.x_flag>>8)&1)) & 0xff);

 if(res != 0x9a)
 {
  m68ki_cpu.v_flag = ~res;

  if((res & 0x0f) == 0xa)
   res = (res & 0xf0) + 0x10;

  res = ((res) & 0xff);

  m68ki_cpu.v_flag &= res;

  m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((res) & 0xff));

  m68ki_cpu.not_z_flag |= res;
  m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.x_flag = 0x100;
 }
 else
 {
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
 }
 m68ki_cpu.n_flag = (res);
}


void m68k_op_neg_8_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = 0 - ((*r_dst) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (res);
 m68ki_cpu.v_flag = *r_dst & res;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_neg_8_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (res);
 m68ki_cpu.v_flag = src & res;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_8_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (res);
 m68ki_cpu.v_flag = src & res;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_8_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (res);
 m68ki_cpu.v_flag = src & res;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_8_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (res);
 m68ki_cpu.v_flag = src & res;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_8_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (res);
 m68ki_cpu.v_flag = src & res;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_8_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (res);
 m68ki_cpu.v_flag = src & res;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_8_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (res);
 m68ki_cpu.v_flag = src & res;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_8_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (res);
 m68ki_cpu.v_flag = src & res;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_8_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (res);
 m68ki_cpu.v_flag = src & res;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = 0 - ((*r_dst) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = ((res)>>8);
 m68ki_cpu.v_flag = (*r_dst & res)>>8;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_neg_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_32_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = 0 - *r_dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (((*r_dst & res) | (~0 & (*r_dst | res)))>>23);
 m68ki_cpu.v_flag = (*r_dst & res)>>24;
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_neg_32_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_32_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_32_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_32_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_32_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_32_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_neg_32_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_negx_8_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = 0 - ((*r_dst) & 0xff) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = *r_dst & res;

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 *r_dst = ((*r_dst) & ~0xff) | res;
}


void m68k_op_negx_8_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = src & res;

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_8_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = src & res;

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_8_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = src & res;

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_8_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = src & res;

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_8_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = src & res;

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_8_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = src & res;

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_8_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = src & res;

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_8_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = src & res;

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_8_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = src & res;

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = 0 - ((*r_dst) & 0xffff) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (*r_dst & res)>>8;

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 *r_dst = ((*r_dst) & ~0xffff) | res;
}


void m68k_op_negx_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - ((src) & 0xffff) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - ((src) & 0xffff) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - ((src) & 0xffff) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - ((src) & 0xffff) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - ((src) & 0xffff) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - ((src) & 0xffff) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - ((src) & 0xffff) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (src & res)>>8;

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_32_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = 0 - (*r_dst) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((*r_dst & res) | (~0 & (*r_dst | res)))>>23);
 m68ki_cpu.v_flag = (*r_dst & res)>>24;

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 *r_dst = res;
}


void m68k_op_negx_32_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - (src) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_32_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - (src) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_32_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - (src) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_32_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - (src) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_32_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - (src) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_32_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - (src) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_negx_32_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = 0 - (src) - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~0 & (src | res)))>>23);
 m68ki_cpu.v_flag = (src & res)>>24;

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_nop(void)
{
 ;
}


void m68k_op_not_8_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = ((~*r_dst) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_8_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = ((~m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_8_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int res = ((~m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_8_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int res = ((~m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_8_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = ((~m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_8_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int res = ((~m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_8_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = ((~m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_8_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = ((~m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_8_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = ((~m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_8_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = ((~m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = ((~*r_dst) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = ((~m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int res = ((~m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int res = ((~m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = ((~m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = ((~m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = ((~m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = ((~m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_32_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = *r_dst = (~*r_dst);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_32_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = (~m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_32_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int res = (~m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_32_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int res = (~m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_32_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = (~m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_32_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (~m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_32_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = (~m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_not_32_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = (~m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1));

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_d(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff))) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_ai(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_AI_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_pi(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_PI_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_pi7(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_A7_PI_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_pd(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_PD_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_pd7(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_A7_PD_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_di(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_DI_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_ix(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_IX_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_aw(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AW_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_al(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AL_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_pcdi(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_PCDI_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_pcix(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_PCIX_8())) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_er_i(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= ((m68ki_read_imm_16()) & 0xff))) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_d(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff))) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_ai(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_AI_16())) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_pi(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_PI_16())) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_pd(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_PD_16())) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_di(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_DI_16())) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_ix(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_IX_16())) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_aw(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AW_16())) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_al(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AL_16())) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_pcdi(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_PCDI_16())) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_pcix(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_PCIX_16())) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_er_i(void)
{
 unsigned int res = ((((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= m68ki_read_imm_16())) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_d(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= (m68ki_cpu.dar[m68ki_cpu.ir & 7]);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_ai(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_AI_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_pi(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_PI_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_pd(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_PD_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_di(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_DI_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_ix(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AY_IX_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_aw(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AW_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_al(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_AL_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_pcdi(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_PCDI_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_pcix(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= OPER_PCIX_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_er_i(void)
{
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) |= m68ki_read_imm_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_re_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_re_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_re_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_re_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_8_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_re_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_re_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_16_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_re_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_re_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_or_32_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_8_d(void)
{
 unsigned int res = ((((m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= ((m68ki_read_imm_16()) & 0xff))) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_8_ai(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = ((src | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_8_pi(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int res = ((src | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_8_pi7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int res = ((src | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_8_pd(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = ((src | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_8_pd7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int res = ((src | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_8_di(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = ((src | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_8_ix(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = ((src | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_8_aw(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = ((src | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_8_al(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = ((src | m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1)) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_16_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= m68ki_read_imm_16()) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_16_ai(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = ((src | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_16_pi(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int res = ((src | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_16_pd(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int res = ((src | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_16_di(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = ((src | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_16_ix(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = ((src | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_16_aw(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = ((src | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_16_al(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = ((src | m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_32_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= m68ki_read_imm_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_32_ai(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = src | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_32_pi(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int res = src | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_32_pd(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int res = src | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_32_di(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = src | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_32_ix(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = src | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_32_aw(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = src | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_32_al(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = src | m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ori_16_toc(void)
{
 m68ki_set_ccr((((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)) | m68ki_read_imm_16());
}


void m68k_op_ori_16_tos(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int src = m68ki_read_imm_16();
  ;
  m68ki_set_sr(( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8))) | src);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_pack_16_rr(void)
{
 if(0)
 {

  unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]) + m68ki_read_imm_16();
  unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

  *r_dst = ((*r_dst) & ~0xff) | ((src >> 4) & 0x00f0) | (src & 0x000f);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_pack_16_mm_ax7(void)
{
 if(0)
 {

  unsigned int ea_src = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  unsigned int src = m68ki_read_8_fc (ea_src, m68ki_cpu.s_flag | 1);
  ea_src = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  src = ((src << 8) | m68ki_read_8_fc (ea_src, m68ki_cpu.s_flag | 1)) + m68ki_read_imm_16();

  m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, ((src >> 4) & 0x00f0) | (src & 0x000f));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_pack_16_mm_ay7(void)
{
 if(0)
 {

  unsigned int ea_src = ((m68ki_cpu.dar+8)[7]-=2);
  unsigned int src = m68ki_read_8_fc (ea_src, m68ki_cpu.s_flag | 1);
  ea_src = ((m68ki_cpu.dar+8)[7]-=2);
  src = ((src << 8) | m68ki_read_8_fc (ea_src, m68ki_cpu.s_flag | 1)) + m68ki_read_imm_16();

  m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])), m68ki_cpu.s_flag | 1, ((src >> 4) & 0x00f0) | (src & 0x000f));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_pack_16_mm_axy7(void)
{
 if(0)
 {
  unsigned int ea_src = ((m68ki_cpu.dar+8)[7]-=2);
  unsigned int src = m68ki_read_8_fc (ea_src, m68ki_cpu.s_flag | 1);
  ea_src = ((m68ki_cpu.dar+8)[7]-=2);
  src = ((src << 8) | m68ki_read_8_fc (ea_src, m68ki_cpu.s_flag | 1)) + m68ki_read_imm_16();

  m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, ((src >> 4) & 0x00f0) | (src & 0x000f));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_pack_16_mm(void)
{
 if(0)
 {

  unsigned int ea_src = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  unsigned int src = m68ki_read_8_fc (ea_src, m68ki_cpu.s_flag | 1);
  ea_src = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  src = ((src << 8) | m68ki_read_8_fc (ea_src, m68ki_cpu.s_flag | 1)) + m68ki_read_imm_16();

  m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])), m68ki_cpu.s_flag | 1, ((src >> 4) & 0x00f0) | (src & 0x000f));
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_pea_32_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

 m68ki_push_32(ea);
}


void m68k_op_pea_32_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));

 m68ki_push_32(ea);
}


void m68k_op_pea_32_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));

 m68ki_push_32(ea);
}


void m68k_op_pea_32_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());

 m68ki_push_32(ea);
}


void m68k_op_pea_32_al(void)
{
 unsigned int ea = m68ki_read_imm_32();

 m68ki_push_32(ea);
}


void m68k_op_pea_32_pcdi(void)
{
 unsigned int ea = m68ki_get_ea_pcdi();

 m68ki_push_32(ea);
}


void m68k_op_pea_32_pcix(void)
{
 unsigned int ea = m68ki_get_ea_pcix();

 m68ki_push_32(ea);
}


void m68k_op_reset(void)
{
 if(m68ki_cpu.s_flag)
 {
  ;
  m68ki_remaining_cycles -= (m68ki_cpu.cyc_reset);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_ror_8_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int shift = orig_shift & 7;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = ((((src) >> (shift)) | ((src) << (8-(shift)))) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << (9-orig_shift);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_16_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = ((((src) >> (shift)) | ((src) << (16-(shift)))) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << (9-shift);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_32_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned long src = *r_dst;
 unsigned int res = (((shift) < 32 ? (src) >> (shift) : 0) | ((32-(shift)) < 32 ? (src) << (32-(shift)) : 0));

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << (9-shift);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_8_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int shift = orig_shift & 7;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = ((((src) >> (shift)) | ((src) << (8-(shift)))) & 0xff);

 if(orig_shift != 0)
 {
  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

  *r_dst = ((*r_dst) & ~0xff) | res;
  m68ki_cpu.c_flag = src << (8-((shift-1)&7));
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = (src);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_16_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int shift = orig_shift & 15;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = ((((src) >> (shift)) | ((src) << (16-(shift)))) & 0xffff);

 if(orig_shift != 0)
 {
  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  m68ki_cpu.c_flag = (src >> ((shift - 1) & 15)) << 8;
  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = ((src)>>8);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_32_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int shift = orig_shift & 31;
 unsigned long src = *r_dst;
 unsigned int res = (((shift) < 32 ? (src) >> (shift) : 0) | ((32-(shift)) < 32 ? (src) << (32-(shift)) : 0));

 if(orig_shift != 0)
 {
  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

  *r_dst = res;
  m68ki_cpu.c_flag = (src >> ((shift - 1) & 31)) << 8;
  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = ((src)>>24);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((src) >> (1)) | ((src) << (16-(1)))) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((src) >> (1)) | ((src) << (16-(1)))) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((src) >> (1)) | ((src) << (16-(1)))) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((src) >> (1)) | ((src) << (16-(1)))) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((src) >> (1)) | ((src) << (16-(1)))) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((src) >> (1)) | ((src) << (16-(1)))) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_ror_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((src) >> (1)) | ((src) << (16-(1)))) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << 8;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_8_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int shift = orig_shift & 7;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = ((((src) << (shift)) | ((src) >> (8-(shift)))) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src << orig_shift;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_16_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = ((((src) << (shift)) | ((src) >> (16-(shift)))) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src >> (8-shift);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_32_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned long src = *r_dst;
 unsigned int res = (((shift) < 32 ? (src) << (shift) : 0) | ((32-(shift)) < 32 ? (src) >> (32-(shift)) : 0));

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src >> (24-shift);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_8_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int shift = orig_shift & 7;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = ((((src) << (shift)) | ((src) >> (8-(shift)))) & 0xff);

 if(orig_shift != 0)
 {
  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

  if(shift != 0)
  {
   *r_dst = ((*r_dst) & ~0xff) | res;
   m68ki_cpu.c_flag = src << shift;
   m68ki_cpu.n_flag = (res);
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }
  m68ki_cpu.c_flag = (src & 1)<<8;
  m68ki_cpu.n_flag = (src);
  m68ki_cpu.not_z_flag = src;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = (src);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_16_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int shift = orig_shift & 15;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = ((((((src) << (shift)) | ((src) >> (16-(shift)))) & 0xffff)) & 0xffff);

 if(orig_shift != 0)
 {
  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

  if(shift != 0)
  {
   *r_dst = ((*r_dst) & ~0xffff) | res;
   m68ki_cpu.c_flag = (src << shift) >> 8;
   m68ki_cpu.n_flag = ((res)>>8);
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }
  m68ki_cpu.c_flag = (src & 1)<<8;
  m68ki_cpu.n_flag = ((src)>>8);
  m68ki_cpu.not_z_flag = src;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = ((src)>>8);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_32_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int shift = orig_shift & 31;
 unsigned long src = *r_dst;
 unsigned int res = (((shift) < 32 ? (src) << (shift) : 0) | ((32-(shift)) < 32 ? (src) >> (32-(shift)) : 0));

 if(orig_shift != 0)
 {
  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

  *r_dst = res;

  m68ki_cpu.c_flag = (src >> (32 - shift)) << 8;
  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = ((src)>>24);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((((src) << (1)) | ((src) >> (16-(1)))) & 0xffff)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((((src) << (1)) | ((src) >> (16-(1)))) & 0xffff)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((((src) << (1)) | ((src) >> (16-(1)))) & 0xffff)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((((src) << (1)) | ((src) >> (16-(1)))) & 0xffff)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((((src) << (1)) | ((src) >> (16-(1)))) & 0xffff)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((((src) << (1)) | ((src) >> (16-(1)))) & 0xffff)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rol_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((((((src) << (1)) | ((src) >> (16-(1)))) & 0xffff)) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = src >> 7;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_8_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 8)) >> (shift)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 8)) << (9-(shift))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res;
 res = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_16_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (shift)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (17-(shift))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_32_s(void)
{
# 3339 "obj/m68kopnz.c"
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = *r_dst;
 unsigned int res = (((((shift) < 32 ? (src) >> (shift) : 0) | ((33-(shift)) < 32 ? (src) << (33-(shift)) : 0)) & ~(1 << (32 - shift))) | (((m68ki_cpu.x_flag>>8)&1) << (32 - shift)));
 unsigned int new_x_flag = src & (1 << (shift - 1));

 *r_dst = res;

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (new_x_flag != 0)<<8;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;


}


void m68k_op_roxr_8_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;

 if(orig_shift != 0)
 {
  unsigned int shift = orig_shift % 9;
  unsigned int src = ((*r_dst) & 0xff);
  unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 8)) >> (shift)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 8)) << (9-(shift))));

  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

  m68ki_cpu.c_flag = m68ki_cpu.x_flag = res;
  res = ((res) & 0xff);

  *r_dst = ((*r_dst) & ~0xff) | res;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = m68ki_cpu.x_flag;
 m68ki_cpu.n_flag = (*r_dst);
 m68ki_cpu.not_z_flag = ((*r_dst) & 0xff);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_16_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;

 if(orig_shift != 0)
 {
  unsigned int shift = orig_shift % 17;
  unsigned int src = ((*r_dst) & 0xffff);
  unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (shift)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (17-(shift))));

  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

  m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
  res = ((res) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = m68ki_cpu.x_flag;
 m68ki_cpu.n_flag = ((*r_dst)>>8);
 m68ki_cpu.not_z_flag = ((*r_dst) & 0xffff);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_32_r(void)
{
# 3450 "obj/m68kopnz.c"
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int shift = orig_shift % 33;
 unsigned int src = *r_dst;
 unsigned int res = (((((shift) < 32 ? (src) >> (shift) : 0) | ((33-(shift)) < 32 ? (src) << (33-(shift)) : 0)) & ~(1 << (32 - shift))) | (((m68ki_cpu.x_flag>>8)&1) << (32 - shift)));
 unsigned int new_x_flag = src & (1 << (shift - 1));

 if(orig_shift != 0)
  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

 if(shift != 0)
 {
  *r_dst = res;
  m68ki_cpu.x_flag = (new_x_flag != 0)<<8;
 }
 else
  res = src;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;


}


void m68k_op_roxr_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxr_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_8_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 8)) << (shift)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 8)) >> (9-(shift))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res;
 res = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_16_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (shift)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (17-(shift))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_32_s(void)
{
# 3653 "obj/m68kopnz.c"
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = *r_dst;
 unsigned int res = (((((shift) < 32 ? (src) << (shift) : 0) | ((33-(shift)) < 32 ? (src) >> (33-(shift)) : 0)) & ~(1 << (shift - 1))) | (((m68ki_cpu.x_flag>>8)&1) << (shift - 1)));
 unsigned int new_x_flag = src & (1 << (32 - shift));

 *r_dst = res;

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = (new_x_flag != 0)<<8;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;


}


void m68k_op_roxl_8_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;


 if(orig_shift != 0)
 {
  unsigned int shift = orig_shift % 9;
  unsigned int src = ((*r_dst) & 0xff);
  unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 8)) << (shift)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 8)) >> (9-(shift))));

  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

  m68ki_cpu.c_flag = m68ki_cpu.x_flag = res;
  res = ((res) & 0xff);

  *r_dst = ((*r_dst) & ~0xff) | res;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = m68ki_cpu.x_flag;
 m68ki_cpu.n_flag = (*r_dst);
 m68ki_cpu.not_z_flag = ((*r_dst) & 0xff);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_16_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;

 if(orig_shift != 0)
 {
  unsigned int shift = orig_shift % 17;
  unsigned int src = ((*r_dst) & 0xffff);
  unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (shift)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (17-(shift))));

  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

  m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
  res = ((res) & 0xffff);

  *r_dst = ((*r_dst) & ~0xffff) | res;
  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  return;
 }

 m68ki_cpu.c_flag = m68ki_cpu.x_flag;
 m68ki_cpu.n_flag = ((*r_dst)>>8);
 m68ki_cpu.not_z_flag = ((*r_dst) & 0xffff);
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_32_r(void)
{
# 3765 "obj/m68kopnz.c"
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int orig_shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int shift = orig_shift % 33;
 unsigned int src = *r_dst;
 unsigned int res = (((((shift) < 32 ? (src) << (shift) : 0) | ((33-(shift)) < 32 ? (src) >> (33-(shift)) : 0)) & ~(1 << (shift - 1))) | (((m68ki_cpu.x_flag>>8)&1) << (shift - 1)));
 unsigned int new_x_flag = src & (1 << (32 - shift));

 if(orig_shift != 0)
  m68ki_remaining_cycles -= (orig_shift<<m68ki_cpu.cyc_shift);

 if(shift != 0)
 {
  *r_dst = res;
  m68ki_cpu.x_flag = (new_x_flag != 0)<<8;
 }
 else
  res = src;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag;
 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;


}


void m68k_op_roxl_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_roxl_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = (((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) << (1)) | ((src | (((m68ki_cpu.x_flag>>8)&1) << 16)) >> (17-(1))));

 m68ki_cpu.c_flag = m68ki_cpu.x_flag = res >> 8;
 res = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_rtd_32(void)
{
 if(0)
 {
  unsigned int new_pc = m68ki_pull_32();

  ;
  (m68ki_cpu.dar+8)[7] = ((m68ki_cpu.dar+8)[7] + (signed short)(m68ki_read_imm_16()));
  m68ki_jump(new_pc);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_rte_32(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr;
  unsigned int new_pc;
  unsigned int format_word;

  ;

  if(1)
  {
   new_sr = m68ki_pull_16();
   new_pc = m68ki_pull_32();
   m68ki_jump(new_pc);
   m68ki_set_sr(new_sr);

   m68ki_cpu.instr_mode = 0;
   m68ki_cpu.run_mode = 0;

   return;
  }

  if(0)
  {
   format_word = m68ki_read_16_fc((m68ki_cpu.dar+8)[7]+6, m68ki_cpu.s_flag | 1) >> 12;
   if(format_word == 0)
   {
    new_sr = m68ki_pull_16();
    new_pc = m68ki_pull_32();
    m68ki_fake_pull_16();
    m68ki_jump(new_pc);
    m68ki_set_sr(new_sr);
    m68ki_cpu.instr_mode = 0;
    m68ki_cpu.run_mode = 0;
    return;
   }
   m68ki_cpu.instr_mode = 0;
   m68ki_cpu.run_mode = 0;

   m68ki_exception_format_error();
   return;
  }


rte_loop:
  format_word = m68ki_read_16_fc((m68ki_cpu.dar+8)[7]+6, m68ki_cpu.s_flag | 1) >> 12;
  switch(format_word)
  {
   case 0:
    new_sr = m68ki_pull_16();
    new_pc = m68ki_pull_32();
    m68ki_fake_pull_16();
    m68ki_jump(new_pc);
    m68ki_set_sr(new_sr);
    m68ki_cpu.instr_mode = 0;
    m68ki_cpu.run_mode = 0;
    return;
   case 1:
    new_sr = m68ki_pull_16();
    m68ki_fake_pull_32();
    m68ki_fake_pull_16();
    m68ki_set_sr_noint(new_sr);
    goto rte_loop;
   case 2:
    new_sr = m68ki_pull_16();
    new_pc = m68ki_pull_32();
    m68ki_fake_pull_16();
    m68ki_fake_pull_32();
    m68ki_jump(new_pc);
    m68ki_set_sr(new_sr);
    m68ki_cpu.instr_mode = 0;
    m68ki_cpu.run_mode = 0;
    return;
  }

  m68ki_cpu.instr_mode = 0;
  m68ki_cpu.run_mode = 0;
  m68ki_exception_format_error();
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_rtm_32(void)
{
 if(0)
 {
  ;
 

                                                       ;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_rtr_32(void)
{
 ;
 m68ki_set_ccr(m68ki_pull_16());
 m68ki_jump(m68ki_pull_32());
}


void m68k_op_rts_32(void)
{
 ;
 m68ki_jump(m68ki_pull_32());
}


void m68k_op_sbcd_8_rr(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int dst = *r_dst;
 unsigned int res = ((dst) & 0x0f) - ((src) & 0x0f) - ((m68ki_cpu.x_flag>>8)&1);


 m68ki_cpu.v_flag = 0;

 if(res > 9)
  res -= 6;
 res += ((dst) & 0xf0) - ((src) & 0xf0);
 if(res > 0x99)
 {
  res += 0xa0;
  m68ki_cpu.x_flag = m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.n_flag = 0x80;
 }
 else
  m68ki_cpu.n_flag = m68ki_cpu.x_flag = m68ki_cpu.c_flag = 0;

 res = ((res) & 0xff);



 m68ki_cpu.not_z_flag |= res;

 *r_dst = ((*r_dst) & ~0xff) | res;
}


void m68k_op_sbcd_8_mm_ax7(void)
{
 unsigned int src = OPER_AY_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((dst) & 0x0f) - ((src) & 0x0f) - ((m68ki_cpu.x_flag>>8)&1);


 m68ki_cpu.v_flag = 0;

 if(res > 9)
  res -= 6;
 res += ((dst) & 0xf0) - ((src) & 0xf0);
 if(res > 0x99)
 {
  res += 0xa0;
  m68ki_cpu.x_flag = m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.n_flag = 0x80;
 }
 else
  m68ki_cpu.n_flag = m68ki_cpu.x_flag = m68ki_cpu.c_flag = 0;

 res = ((res) & 0xff);



 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_sbcd_8_mm_ay7(void)
{
 unsigned int src = OPER_A7_PD_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((dst) & 0x0f) - ((src) & 0x0f) - ((m68ki_cpu.x_flag>>8)&1);


 m68ki_cpu.v_flag = 0;

 if(res > 9)
  res -= 6;
 res += ((dst) & 0xf0) - ((src) & 0xf0);
 if(res > 0x99)
 {
  res += 0xa0;
  m68ki_cpu.x_flag = m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.n_flag = 0x80;
 }
 else
  m68ki_cpu.n_flag = m68ki_cpu.x_flag = m68ki_cpu.c_flag = 0;

 res = ((res) & 0xff);



 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_sbcd_8_mm_axy7(void)
{
 unsigned int src = OPER_A7_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((dst) & 0x0f) - ((src) & 0x0f) - ((m68ki_cpu.x_flag>>8)&1);


 m68ki_cpu.v_flag = 0;

 if(res > 9)
  res -= 6;
 res += ((dst) & 0xf0) - ((src) & 0xf0);
 if(res > 0x99)
 {
  res += 0xa0;
  m68ki_cpu.x_flag = m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.n_flag = 0x80;
 }
 else
  m68ki_cpu.n_flag = m68ki_cpu.x_flag = m68ki_cpu.c_flag = 0;

 res = ((res) & 0xff);



 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_sbcd_8_mm(void)
{
 unsigned int src = OPER_AY_PD_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((dst) & 0x0f) - ((src) & 0x0f) - ((m68ki_cpu.x_flag>>8)&1);


 m68ki_cpu.v_flag = 0;

 if(res > 9)
  res -= 6;
 res += ((dst) & 0xf0) - ((src) & 0xf0);
 if(res > 0x99)
 {
  res += 0xa0;
  m68ki_cpu.x_flag = m68ki_cpu.c_flag = 0x100;
  m68ki_cpu.n_flag = 0x80;
 }
 else
  m68ki_cpu.n_flag = m68ki_cpu.x_flag = m68ki_cpu.c_flag = 0;

 res = ((res) & 0xff);



 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_st_8_d(void)
{
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
}


void m68k_op_st_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, 0xff);
}


void m68k_op_st_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, 0xff);
}


void m68k_op_st_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, 0xff);
}


void m68k_op_st_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, 0xff);
}


void m68k_op_st_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, 0xff);
}


void m68k_op_st_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, 0xff);
}


void m68k_op_st_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, 0xff);
}


void m68k_op_st_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, 0xff);
}


void m68k_op_st_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, 0xff);
}


void m68k_op_sf_8_d(void)
{
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_sf_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, 0);
}


void m68k_op_sf_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, 0);
}


void m68k_op_sf_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, 0);
}


void m68k_op_sf_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, 0);
}


void m68k_op_sf_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, 0);
}


void m68k_op_sf_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, 0);
}


void m68k_op_sf_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, 0);
}


void m68k_op_sf_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, 0);
}


void m68k_op_sf_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, 0);
}


void m68k_op_shi_8_d(void)
{
 if(((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_sls_8_d(void)
{
 if(((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_scc_8_d(void)
{
 if((!(m68ki_cpu.c_flag&0x100)))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_scs_8_d(void)
{
 if((m68ki_cpu.c_flag&0x100))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_sne_8_d(void)
{
 if(m68ki_cpu.not_z_flag)
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_seq_8_d(void)
{
 if((!m68ki_cpu.not_z_flag))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_svc_8_d(void)
{
 if((!(m68ki_cpu.v_flag&0x80)))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_svs_8_d(void)
{
 if((m68ki_cpu.v_flag&0x80))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_spl_8_d(void)
{
 if((!(m68ki_cpu.n_flag&0x80)))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_smi_8_d(void)
{
 if((m68ki_cpu.n_flag&0x80))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_sge_8_d(void)
{
 if((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_slt_8_d(void)
{
 if(((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_sgt_8_d(void)
{
 if(((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_sle_8_d(void)
{
 if((((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)))
 {
  (m68ki_cpu.dar[m68ki_cpu.ir & 7]) |= 0xff;
  return;
 }
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;
}


void m68k_op_shi_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, ((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_shi_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, ((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_shi_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, ((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_shi_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, ((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_shi_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, ((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_shi_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, ((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_shi_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, ((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_shi_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, ((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_shi_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, ((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_sls_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, ((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sls_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, ((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sls_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, ((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sls_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, ((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sls_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, ((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sls_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, ((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sls_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, ((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sls_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, ((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sls_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, ((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_scc_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.c_flag&0x100)) ? 0xff : 0);
}


void m68k_op_scc_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.c_flag&0x100)) ? 0xff : 0);
}


void m68k_op_scc_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.c_flag&0x100)) ? 0xff : 0);
}


void m68k_op_scc_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.c_flag&0x100)) ? 0xff : 0);
}


void m68k_op_scc_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.c_flag&0x100)) ? 0xff : 0);
}


void m68k_op_scc_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.c_flag&0x100)) ? 0xff : 0);
}


void m68k_op_scc_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.c_flag&0x100)) ? 0xff : 0);
}


void m68k_op_scc_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.c_flag&0x100)) ? 0xff : 0);
}


void m68k_op_scc_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.c_flag&0x100)) ? 0xff : 0);
}


void m68k_op_scs_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, (m68ki_cpu.c_flag&0x100) ? 0xff : 0);
}


void m68k_op_scs_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, (m68ki_cpu.c_flag&0x100) ? 0xff : 0);
}


void m68k_op_scs_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, (m68ki_cpu.c_flag&0x100) ? 0xff : 0);
}


void m68k_op_scs_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (m68ki_cpu.c_flag&0x100) ? 0xff : 0);
}


void m68k_op_scs_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, (m68ki_cpu.c_flag&0x100) ? 0xff : 0);
}


void m68k_op_scs_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, (m68ki_cpu.c_flag&0x100) ? 0xff : 0);
}


void m68k_op_scs_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (m68ki_cpu.c_flag&0x100) ? 0xff : 0);
}


void m68k_op_scs_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, (m68ki_cpu.c_flag&0x100) ? 0xff : 0);
}


void m68k_op_scs_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, (m68ki_cpu.c_flag&0x100) ? 0xff : 0);
}


void m68k_op_sne_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag ? 0xff : 0);
}


void m68k_op_sne_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag ? 0xff : 0);
}


void m68k_op_sne_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag ? 0xff : 0);
}


void m68k_op_sne_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag ? 0xff : 0);
}


void m68k_op_sne_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag ? 0xff : 0);
}


void m68k_op_sne_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag ? 0xff : 0);
}


void m68k_op_sne_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag ? 0xff : 0);
}


void m68k_op_sne_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag ? 0xff : 0);
}


void m68k_op_sne_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag ? 0xff : 0);
}


void m68k_op_seq_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, (!m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_seq_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, (!m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_seq_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, (!m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_seq_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (!m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_seq_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, (!m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_seq_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, (!m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_seq_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (!m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_seq_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, (!m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_seq_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, (!m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_svc_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.v_flag&0x80)) ? 0xff : 0);
}


void m68k_op_svc_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.v_flag&0x80)) ? 0xff : 0);
}


void m68k_op_svc_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.v_flag&0x80)) ? 0xff : 0);
}


void m68k_op_svc_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.v_flag&0x80)) ? 0xff : 0);
}


void m68k_op_svc_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.v_flag&0x80)) ? 0xff : 0);
}


void m68k_op_svc_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.v_flag&0x80)) ? 0xff : 0);
}


void m68k_op_svc_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.v_flag&0x80)) ? 0xff : 0);
}


void m68k_op_svc_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.v_flag&0x80)) ? 0xff : 0);
}


void m68k_op_svc_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.v_flag&0x80)) ? 0xff : 0);
}


void m68k_op_svs_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, (m68ki_cpu.v_flag&0x80) ? 0xff : 0);
}


void m68k_op_svs_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, (m68ki_cpu.v_flag&0x80) ? 0xff : 0);
}


void m68k_op_svs_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, (m68ki_cpu.v_flag&0x80) ? 0xff : 0);
}


void m68k_op_svs_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (m68ki_cpu.v_flag&0x80) ? 0xff : 0);
}


void m68k_op_svs_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, (m68ki_cpu.v_flag&0x80) ? 0xff : 0);
}


void m68k_op_svs_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, (m68ki_cpu.v_flag&0x80) ? 0xff : 0);
}


void m68k_op_svs_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (m68ki_cpu.v_flag&0x80) ? 0xff : 0);
}


void m68k_op_svs_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, (m68ki_cpu.v_flag&0x80) ? 0xff : 0);
}


void m68k_op_svs_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, (m68ki_cpu.v_flag&0x80) ? 0xff : 0);
}


void m68k_op_spl_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.n_flag&0x80)) ? 0xff : 0);
}


void m68k_op_spl_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.n_flag&0x80)) ? 0xff : 0);
}


void m68k_op_spl_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.n_flag&0x80)) ? 0xff : 0);
}


void m68k_op_spl_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.n_flag&0x80)) ? 0xff : 0);
}


void m68k_op_spl_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.n_flag&0x80)) ? 0xff : 0);
}


void m68k_op_spl_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.n_flag&0x80)) ? 0xff : 0);
}


void m68k_op_spl_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.n_flag&0x80)) ? 0xff : 0);
}


void m68k_op_spl_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.n_flag&0x80)) ? 0xff : 0);
}


void m68k_op_spl_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, (!(m68ki_cpu.n_flag&0x80)) ? 0xff : 0);
}


void m68k_op_smi_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, (m68ki_cpu.n_flag&0x80) ? 0xff : 0);
}


void m68k_op_smi_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, (m68ki_cpu.n_flag&0x80) ? 0xff : 0);
}


void m68k_op_smi_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, (m68ki_cpu.n_flag&0x80) ? 0xff : 0);
}


void m68k_op_smi_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (m68ki_cpu.n_flag&0x80) ? 0xff : 0);
}


void m68k_op_smi_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, (m68ki_cpu.n_flag&0x80) ? 0xff : 0);
}


void m68k_op_smi_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, (m68ki_cpu.n_flag&0x80) ? 0xff : 0);
}


void m68k_op_smi_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (m68ki_cpu.n_flag&0x80) ? 0xff : 0);
}


void m68k_op_smi_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, (m68ki_cpu.n_flag&0x80) ? 0xff : 0);
}


void m68k_op_smi_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, (m68ki_cpu.n_flag&0x80) ? 0xff : 0);
}


void m68k_op_sge_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, (!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) ? 0xff : 0);
}


void m68k_op_sge_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, (!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) ? 0xff : 0);
}


void m68k_op_sge_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, (!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) ? 0xff : 0);
}


void m68k_op_sge_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) ? 0xff : 0);
}


void m68k_op_sge_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, (!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) ? 0xff : 0);
}


void m68k_op_sge_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, (!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) ? 0xff : 0);
}


void m68k_op_sge_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) ? 0xff : 0);
}


void m68k_op_sge_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, (!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) ? 0xff : 0);
}


void m68k_op_sge_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, (!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) ? 0xff : 0);
}


void m68k_op_slt_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, ((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) ? 0xff : 0);
}


void m68k_op_slt_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, ((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) ? 0xff : 0);
}


void m68k_op_slt_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, ((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) ? 0xff : 0);
}


void m68k_op_slt_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, ((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) ? 0xff : 0);
}


void m68k_op_slt_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, ((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) ? 0xff : 0);
}


void m68k_op_slt_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, ((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) ? 0xff : 0);
}


void m68k_op_slt_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, ((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) ? 0xff : 0);
}


void m68k_op_slt_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, ((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) ? 0xff : 0);
}


void m68k_op_slt_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, ((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) ? 0xff : 0);
}


void m68k_op_sgt_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, ((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_sgt_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, ((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_sgt_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, ((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_sgt_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, ((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_sgt_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, ((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_sgt_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, ((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_sgt_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, ((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_sgt_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, ((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_sgt_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, ((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag) ? 0xff : 0);
}


void m68k_op_sle_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, (((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sle_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, (((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sle_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, (((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sle_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sle_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, (((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sle_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, (((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sle_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, (((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sle_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, (((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_sle_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, (((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)) ? 0xff : 0);
}


void m68k_op_stop(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int new_sr = m68ki_read_imm_16();
  ;
  m68ki_cpu.stopped |= 1;
  m68ki_set_sr(new_sr);
  m68ki_remaining_cycles = 0;
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_sub_8_er_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_ai(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_AI_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_pi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PI_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_pi7(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_A7_PI_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_pd(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PD_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_pd7(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_A7_PD_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_di(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_DI_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_ix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_IX_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_aw(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AW_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_al(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AL_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_pcdi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCDI_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_pcix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCIX_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_er_i(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_a(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_ai(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_AI_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_pi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PI_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_pd(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PD_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_di(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_DI_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_ix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_IX_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_aw(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AW_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_al(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AL_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_pcdi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCDI_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_pcix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCIX_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_16_er_i(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_a(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_ai(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_AI_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_pi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PI_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_pd(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PD_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_di(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_DI_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_ix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_IX_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_aw(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AW_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_al(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AL_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_pcdi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCDI_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_pcix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCIX_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_32_er_i(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_sub_8_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_8_re_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_8_re_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_8_re_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_8_re_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_8_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_8_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_8_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_8_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_16_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_16_re_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_16_re_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_16_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_16_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_16_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_16_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_32_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_32_re_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_32_re_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_32_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_32_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_32_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_sub_32_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_suba_16_d(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)((m68ki_cpu.dar[m68ki_cpu.ir & 7])));
}


void m68k_op_suba_16_a(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])));
}


void m68k_op_suba_16_ai(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(OPER_AY_AI_16()));
}


void m68k_op_suba_16_pi(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(OPER_AY_PI_16()));
}


void m68k_op_suba_16_pd(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(OPER_AY_PD_16()));
}


void m68k_op_suba_16_di(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(OPER_AY_DI_16()));
}


void m68k_op_suba_16_ix(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(OPER_AY_IX_16()));
}


void m68k_op_suba_16_aw(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(OPER_AW_16()));
}


void m68k_op_suba_16_al(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(OPER_AL_16()));
}


void m68k_op_suba_16_pcdi(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(OPER_PCDI_16()));
}


void m68k_op_suba_16_pcix(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(OPER_PCIX_16()));
}


void m68k_op_suba_16_i(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (signed short)(m68ki_read_imm_16()));
}


void m68k_op_suba_32_d(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - (m68ki_cpu.dar[m68ki_cpu.ir & 7]));
}


void m68k_op_suba_32_a(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
}


void m68k_op_suba_32_ai(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - OPER_AY_AI_32());
}


void m68k_op_suba_32_pi(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - OPER_AY_PI_32());
}


void m68k_op_suba_32_pd(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - OPER_AY_PD_32());
}


void m68k_op_suba_32_di(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - OPER_AY_DI_32());
}


void m68k_op_suba_32_ix(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - OPER_AY_IX_32());
}


void m68k_op_suba_32_aw(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - OPER_AW_32());
}


void m68k_op_suba_32_al(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - OPER_AL_32());
}


void m68k_op_suba_32_pcdi(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - OPER_PCDI_32());
}


void m68k_op_suba_32_pcix(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - OPER_PCIX_32());
}


void m68k_op_suba_32_i(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst - m68ki_read_imm_32());
}


void m68k_op_subi_8_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_subi_8_ai(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_8_pi(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_8_pi7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_8_pd(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_8_pd7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_8_di(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_8_ix(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_8_aw(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_8_al(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_subi_16_ai(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_16_pi(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_16_pd(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_16_di(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_16_ix(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_16_aw(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_16_al(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_32_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_subi_32_ai(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_32_pi(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_32_pd(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_32_di(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_32_ix(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_32_aw(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subi_32_al(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_8_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_subq_8_ai(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_8_pi(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_8_pi7(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_8_pd(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_8_pd7(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_8_di(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_8_ix(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_8_aw(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_8_al(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_subq_16_a(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

 *r_dst = (*r_dst - ((((m68ki_cpu.ir >> 9) - 1) & 7) + 1));
}


void m68k_op_subq_16_ai(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_16_pi(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_16_pd(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_16_di(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_16_ix(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_16_aw(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_16_al(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_32_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int dst = *r_dst;
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_subq_32_a(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

 *r_dst = (*r_dst - ((((m68ki_cpu.ir >> 9) - 1) & 7) + 1));
}


void m68k_op_subq_32_ai(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_32_pi(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_32_pd(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_32_di(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_32_ix(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_32_aw(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subq_32_al(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_subx_8_rr(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = dst - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 *r_dst = ((*r_dst) & ~0xff) | res;
}


void m68k_op_subx_16_rr(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = dst - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 *r_dst = ((*r_dst) & ~0xffff) | res;
}


void m68k_op_subx_32_rr(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int dst = *r_dst;
 unsigned int res = dst - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 *r_dst = res;
}


void m68k_op_subx_8_mm_ax7(void)
{
 unsigned int src = OPER_AY_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_subx_8_mm_ay7(void)
{
 unsigned int src = OPER_A7_PD_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_subx_8_mm_axy7(void)
{
 unsigned int src = OPER_A7_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_subx_8_mm(void)
{
 unsigned int src = OPER_AY_PD_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_subx_16_mm(void)
{
 unsigned int src = OPER_AY_PD_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_subx_32_mm(void)
{
 unsigned int src = OPER_AY_PD_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = dst - src - ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_swap_32(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);

 m68ki_cpu.not_z_flag = (*r_dst<<16);
 *r_dst = (*r_dst>>16) | m68ki_cpu.not_z_flag;

 m68ki_cpu.not_z_flag = *r_dst;
 m68ki_cpu.n_flag = ((*r_dst)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_tas_8_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);

 m68ki_cpu.not_z_flag = ((*r_dst) & 0xff);
 m68ki_cpu.n_flag = (*r_dst);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 *r_dst |= 0x80;
}


void m68k_op_tas_8_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = dst;
 m68ki_cpu.n_flag = (dst);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, dst | 0x80);
}


void m68k_op_tas_8_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = dst;
 m68ki_cpu.n_flag = (dst);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, dst | 0x80);
}


void m68k_op_tas_8_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = dst;
 m68ki_cpu.n_flag = (dst);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, dst | 0x80);
}


void m68k_op_tas_8_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = dst;
 m68ki_cpu.n_flag = (dst);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, dst | 0x80);
}


void m68k_op_tas_8_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = dst;
 m68ki_cpu.n_flag = (dst);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, dst | 0x80);
}


void m68k_op_tas_8_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = dst;
 m68ki_cpu.n_flag = (dst);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, dst | 0x80);
}


void m68k_op_tas_8_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = dst;
 m68ki_cpu.n_flag = (dst);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, dst | 0x80);
}


void m68k_op_tas_8_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = dst;
 m68ki_cpu.n_flag = (dst);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, dst | 0x80);
}


void m68k_op_tas_8_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = dst;
 m68ki_cpu.n_flag = (dst);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, dst | 0x80);
}


void m68k_op_trap(void)
{

 m68ki_exception_trapN(32 + (m68ki_cpu.ir & 0xf));
}


void m68k_op_trapt(void)
{
 if(0)
 {
  m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapt_16(void)
{
 if(0)
 {
  m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapt_32(void)
{
 if(0)
 {
  m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapf(void)
{
 if(0)
 {
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapf_16(void)
{
 if(0)
 {
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapf_32(void)
{
 if(0)
 {
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_traphi(void)
{
 if(0)
 {
  if(((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapls(void)
{
 if(0)
 {
  if(((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapcc(void)
{
 if(0)
 {
  if((!(m68ki_cpu.c_flag&0x100)))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapcs(void)
{
 if(0)
 {
  if((m68ki_cpu.c_flag&0x100))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapne(void)
{
 if(0)
 {
  if(m68ki_cpu.not_z_flag)
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapeq(void)
{
 if(0)
 {
  if((!m68ki_cpu.not_z_flag))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapvc(void)
{
 if(0)
 {
  if((!(m68ki_cpu.v_flag&0x80)))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapvs(void)
{
 if(0)
 {
  if((m68ki_cpu.v_flag&0x80))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trappl(void)
{
 if(0)
 {
  if((!(m68ki_cpu.n_flag&0x80)))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapmi(void)
{
 if(0)
 {
  if((m68ki_cpu.n_flag&0x80))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapge(void)
{
 if(0)
 {
  if((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_traplt(void)
{
 if(0)
 {
  if(((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapgt(void)
{
 if(0)
 {
  if(((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_traple(void)
{
 if(0)
 {
  if((((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)))
   m68ki_exception_trap(7);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_traphi_16(void)
{
 if(0)
 {
  if(((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapls_16(void)
{
 if(0)
 {
  if(((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapcc_16(void)
{
 if(0)
 {
  if((!(m68ki_cpu.c_flag&0x100)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapcs_16(void)
{
 if(0)
 {
  if((m68ki_cpu.c_flag&0x100))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapne_16(void)
{
 if(0)
 {
  if(m68ki_cpu.not_z_flag)
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapeq_16(void)
{
 if(0)
 {
  if((!m68ki_cpu.not_z_flag))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapvc_16(void)
{
 if(0)
 {
  if((!(m68ki_cpu.v_flag&0x80)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapvs_16(void)
{
 if(0)
 {
  if((m68ki_cpu.v_flag&0x80))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trappl_16(void)
{
 if(0)
 {
  if((!(m68ki_cpu.n_flag&0x80)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapmi_16(void)
{
 if(0)
 {
  if((m68ki_cpu.n_flag&0x80))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapge_16(void)
{
 if(0)
 {
  if((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_traplt_16(void)
{
 if(0)
 {
  if(((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapgt_16(void)
{
 if(0)
 {
  if(((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_traple_16(void)
{
 if(0)
 {
  if((((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_traphi_32(void)
{
 if(0)
 {
  if(((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapls_32(void)
{
 if(0)
 {
  if(((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapcc_32(void)
{
 if(0)
 {
  if((!(m68ki_cpu.c_flag&0x100)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapcs_32(void)
{
 if(0)
 {
  if((m68ki_cpu.c_flag&0x100))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapne_32(void)
{
 if(0)
 {
  if(m68ki_cpu.not_z_flag)
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapeq_32(void)
{
 if(0)
 {
  if((!m68ki_cpu.not_z_flag))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapvc_32(void)
{
 if(0)
 {
  if((!(m68ki_cpu.v_flag&0x80)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapvs_32(void)
{
 if(0)
 {
  if((m68ki_cpu.v_flag&0x80))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trappl_32(void)
{
 if(0)
 {
  if((!(m68ki_cpu.n_flag&0x80)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapmi_32(void)
{
 if(0)
 {
  if((m68ki_cpu.n_flag&0x80))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapge_32(void)
{
 if(0)
 {
  if((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_traplt_32(void)
{
 if(0)
 {
  if(((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapgt_32(void)
{
 if(0)
 {
  if(((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_traple_32(void)
{
 if(0)
 {
  if((((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)))
  {
   m68ki_exception_trap(7);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_trapv(void)
{
 if((!(m68ki_cpu.v_flag&0x80)))
 {
  return;
 }
 m68ki_exception_trap(7);
}


void m68k_op_tst_8_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_8_ai(void)
{
 unsigned int res = OPER_AY_AI_8();

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_8_pi(void)
{
 unsigned int res = OPER_AY_PI_8();

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_8_pi7(void)
{
 unsigned int res = OPER_A7_PI_8();

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_8_pd(void)
{
 unsigned int res = OPER_AY_PD_8();

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_8_pd7(void)
{
 unsigned int res = OPER_A7_PD_8();

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_8_di(void)
{
 unsigned int res = OPER_AY_DI_8();

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_8_ix(void)
{
 unsigned int res = OPER_AY_IX_8();

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_8_aw(void)
{
 unsigned int res = OPER_AW_8();

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_8_al(void)
{
 unsigned int res = OPER_AL_8();

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_8_pcdi(void)
{
 if(0)
 {
  unsigned int res = OPER_PCDI_8();

  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_tst_8_pcix(void)
{
 if(0)
 {
  unsigned int res = OPER_PCIX_8();

  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_tst_8_i(void)
{
 if(0)
 {
  unsigned int res = ((m68ki_read_imm_16()) & 0xff);

  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_tst_16_d(void)
{
 unsigned int res = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_16_a(void)
{
 if(0)
 {
  unsigned int res = (signed short)(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));

  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_tst_16_ai(void)
{
 unsigned int res = OPER_AY_AI_16();

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_16_pi(void)
{
 unsigned int res = OPER_AY_PI_16();

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_16_pd(void)
{
 unsigned int res = OPER_AY_PD_16();

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_16_di(void)
{
 unsigned int res = OPER_AY_DI_16();

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_16_ix(void)
{
 unsigned int res = OPER_AY_IX_16();

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_16_aw(void)
{
 unsigned int res = OPER_AW_16();

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_16_al(void)
{
 unsigned int res = OPER_AL_16();

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_16_pcdi(void)
{
 if(0)
 {
  unsigned int res = OPER_PCDI_16();

  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_tst_16_pcix(void)
{
 if(0)
 {
  unsigned int res = OPER_PCIX_16();

  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_tst_16_i(void)
{
 if(0)
 {
  unsigned int res = m68ki_read_imm_16();

  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_tst_32_d(void)
{
 unsigned int res = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_32_a(void)
{
 if(0)
 {
  unsigned int res = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_tst_32_ai(void)
{
 unsigned int res = OPER_AY_AI_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_32_pi(void)
{
 unsigned int res = OPER_AY_PI_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_32_pd(void)
{
 unsigned int res = OPER_AY_PD_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_32_di(void)
{
 unsigned int res = OPER_AY_DI_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_32_ix(void)
{
 unsigned int res = OPER_AY_IX_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_32_aw(void)
{
 unsigned int res = OPER_AW_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_32_al(void)
{
 unsigned int res = OPER_AL_32();

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
}


void m68k_op_tst_32_pcdi(void)
{
 if(0)
 {
  unsigned int res = OPER_PCDI_32();

  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_tst_32_pcix(void)
{
 if(0)
 {
  unsigned int res = OPER_PCIX_32();

  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_tst_32_i(void)
{
 if(0)
 {
  unsigned int res = m68ki_read_imm_32();

  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = res;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_unlk_32_a7(void)
{
 (m68ki_cpu.dar+8)[7] = m68ki_read_32_fc((m68ki_cpu.dar+8)[7], m68ki_cpu.s_flag | 1);
}


void m68k_op_unlk_32(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

 (m68ki_cpu.dar+8)[7] = *r_dst;
 *r_dst = m68ki_pull_32();
}


void m68k_op_unpk_16_rr(void)
{
 if(0)
 {

  unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);

  *r_dst = ((*r_dst) & ~0xffff) | (((((src << 4) & 0x0f00) | (src & 0x000f)) + m68ki_read_imm_16()) & 0xffff);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_unpk_16_mm_ax7(void)
{
 if(0)
 {

  unsigned int src = OPER_AY_PD_8();
  unsigned int ea_dst;

  src = (((src << 4) & 0x0f00) | (src & 0x000f)) + m68ki_read_imm_16();
  ea_dst = ((m68ki_cpu.dar+8)[7]-=2);
  m68ki_write_8_fc (ea_dst, m68ki_cpu.s_flag | 1, (src >> 8) & 0xff);
  ea_dst = ((m68ki_cpu.dar+8)[7]-=2);
  m68ki_write_8_fc (ea_dst, m68ki_cpu.s_flag | 1, src & 0xff);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_unpk_16_mm_ay7(void)
{
 if(0)
 {

  unsigned int src = OPER_A7_PD_8();
  unsigned int ea_dst;

  src = (((src << 4) & 0x0f00) | (src & 0x000f)) + m68ki_read_imm_16();
  ea_dst = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
  m68ki_write_8_fc (ea_dst, m68ki_cpu.s_flag | 1, (src >> 8) & 0xff);
  ea_dst = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
  m68ki_write_8_fc (ea_dst, m68ki_cpu.s_flag | 1, src & 0xff);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_unpk_16_mm_axy7(void)
{
 if(0)
 {
  unsigned int src = OPER_A7_PD_8();
  unsigned int ea_dst;

  src = (((src << 4) & 0x0f00) | (src & 0x000f)) + m68ki_read_imm_16();
  ea_dst = ((m68ki_cpu.dar+8)[7]-=2);
  m68ki_write_8_fc (ea_dst, m68ki_cpu.s_flag | 1, (src >> 8) & 0xff);
  ea_dst = ((m68ki_cpu.dar+8)[7]-=2);
  m68ki_write_8_fc (ea_dst, m68ki_cpu.s_flag | 1, src & 0xff);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_unpk_16_mm(void)
{
 if(0)
 {

  unsigned int src = OPER_AY_PD_8();
  unsigned int ea_dst;

  src = (((src << 4) & 0x0f00) | (src & 0x000f)) + m68ki_read_imm_16();
  ea_dst = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
  m68ki_write_8_fc (ea_dst, m68ki_cpu.s_flag | 1, (src >> 8) & 0xff);
  ea_dst = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
  m68ki_write_8_fc (ea_dst, m68ki_cpu.s_flag | 1, src & 0xff);
  return;
 }
 m68ki_exception_illegal();
}
