void cdrom_load_files(void);
void neogeo_cdda_control(void);
void neogeo_prio_switch(void);
void neogeo_upload(void);

extern int img_display;






void m68k_op_1010(void)
{
 m68ki_exception_1010();
}


void m68k_op_1111(void)
{
 switch (m68ki_cpu.ir) {
 case 0xfabe: neogeo_exit(); break;
 case 0xfabf: img_display=1; cdrom_load_files(); break;
 case 0xfac0: img_display=0; cdrom_load_files(); break;
 case 0xfac1: neogeo_upload(); break;
 case 0xfac2: neogeo_prio_switch(); break;
 case 0xfac3: neogeo_cdda_control(); break;
 default: m68ki_exception_1111(); break;
 }
}


void m68k_op_abcd_8_rr(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int dst = *r_dst;
 unsigned int res = ((src) & 0x0f) + ((dst) & 0x0f) + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.v_flag = ~res;

 if(res > 9)
  res += 6;
 res += ((src) & 0xf0) + ((dst) & 0xf0);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res > 0x99) << 8;
 if(m68ki_cpu.c_flag)
  res -= 0xa0;

 m68ki_cpu.v_flag &= res;
 m68ki_cpu.n_flag = (res);

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 *r_dst = ((*r_dst) & ~0xff) | res;
}


void m68k_op_abcd_8_mm_ax7(void)
{
 unsigned int src = OPER_AY_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src) & 0x0f) + ((dst) & 0x0f) + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.v_flag = ~res;

 if(res > 9)
  res += 6;
 res += ((src) & 0xf0) + ((dst) & 0xf0);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res > 0x99) << 8;
 if(m68ki_cpu.c_flag)
  res -= 0xa0;

 m68ki_cpu.v_flag &= res;
 m68ki_cpu.n_flag = (res);

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_abcd_8_mm_ay7(void)
{
 unsigned int src = OPER_A7_PD_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src) & 0x0f) + ((dst) & 0x0f) + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.v_flag = ~res;

 if(res > 9)
  res += 6;
 res += ((src) & 0xf0) + ((dst) & 0xf0);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res > 0x99) << 8;
 if(m68ki_cpu.c_flag)
  res -= 0xa0;

 m68ki_cpu.v_flag &= res;
 m68ki_cpu.n_flag = (res);

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_abcd_8_mm_axy7(void)
{
 unsigned int src = OPER_A7_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src) & 0x0f) + ((dst) & 0x0f) + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.v_flag = ~res;

 if(res > 9)
  res += 6;
 res += ((src) & 0xf0) + ((dst) & 0xf0);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res > 0x99) << 8;
 if(m68ki_cpu.c_flag)
  res -= 0xa0;

 m68ki_cpu.v_flag &= res;
 m68ki_cpu.n_flag = (res);

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_abcd_8_mm(void)
{
 unsigned int src = OPER_AY_PD_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src) & 0x0f) + ((dst) & 0x0f) + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.v_flag = ~res;

 if(res > 9)
  res += 6;
 res += ((src) & 0xf0) + ((dst) & 0xf0);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res > 0x99) << 8;
 if(m68ki_cpu.c_flag)
  res -= 0xa0;

 m68ki_cpu.v_flag &= res;
 m68ki_cpu.n_flag = (res);

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_add_8_er_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_ai(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_AI_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_pi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PI_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_pi7(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_A7_PI_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_pd(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PD_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_pd7(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_A7_PD_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_di(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_DI_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_ix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_IX_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_aw(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AW_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_al(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AL_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_pcdi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCDI_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_pcix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCIX_8();
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_er_i(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_a(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_ai(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_AI_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_pi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PI_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_pd(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PD_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_di(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_DI_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_ix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_IX_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_aw(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AW_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_al(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AL_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_pcdi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCDI_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_pcix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCIX_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_16_er_i(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_a(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_ai(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_AI_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_pi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PI_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_pd(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_PD_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_di(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_DI_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_ix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AY_IX_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_aw(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AW_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_al(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_AL_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_pcdi(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCDI_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_pcix(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = OPER_PCIX_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_32_er_i(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_add_8_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_8_re_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_8_re_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_8_re_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_8_re_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_8_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_8_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_8_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_8_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_16_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_16_re_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_16_re_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_16_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_16_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_16_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_16_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_32_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_32_re_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_32_re_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_32_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_32_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_32_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_add_32_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_adda_16_d(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)((m68ki_cpu.dar[m68ki_cpu.ir & 7])));
}


void m68k_op_adda_16_a(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])));
}


void m68k_op_adda_16_ai(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(OPER_AY_AI_16()));
}


void m68k_op_adda_16_pi(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(OPER_AY_PI_16()));
}


void m68k_op_adda_16_pd(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(OPER_AY_PD_16()));
}


void m68k_op_adda_16_di(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(OPER_AY_DI_16()));
}


void m68k_op_adda_16_ix(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(OPER_AY_IX_16()));
}


void m68k_op_adda_16_aw(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(OPER_AW_16()));
}


void m68k_op_adda_16_al(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(OPER_AL_16()));
}


void m68k_op_adda_16_pcdi(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(OPER_PCDI_16()));
}


void m68k_op_adda_16_pcix(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(OPER_PCIX_16()));
}


void m68k_op_adda_16_i(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (signed short)(m68ki_read_imm_16()));
}


void m68k_op_adda_32_d(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + (m68ki_cpu.dar[m68ki_cpu.ir & 7]));
}


void m68k_op_adda_32_a(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
}


void m68k_op_adda_32_ai(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + OPER_AY_AI_32());
}


void m68k_op_adda_32_pi(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + OPER_AY_PI_32());
}


void m68k_op_adda_32_pd(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + OPER_AY_PD_32());
}


void m68k_op_adda_32_di(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + OPER_AY_DI_32());
}


void m68k_op_adda_32_ix(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + OPER_AY_IX_32());
}


void m68k_op_adda_32_aw(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + OPER_AW_32());
}


void m68k_op_adda_32_al(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + OPER_AL_32());
}


void m68k_op_adda_32_pcdi(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + OPER_PCDI_32());
}


void m68k_op_adda_32_pcix(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + OPER_PCIX_32());
}


void m68k_op_adda_32_i(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);

 *r_dst = (*r_dst + m68ki_read_imm_32());
}


void m68k_op_addi_8_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_addi_8_ai(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_8_pi(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_8_pi7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_8_pd(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_8_pd7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_8_di(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_8_ix(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_8_aw(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_8_al(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_addi_16_ai(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_16_pi(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_16_pd(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_16_di(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_16_ix(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_16_aw(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_16_al(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_32_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_addi_32_ai(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_32_pi(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_32_pd(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_32_di(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_32_ix(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_32_aw(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addi_32_al(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_8_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | m68ki_cpu.not_z_flag;
}


void m68k_op_addq_8_ai(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_8_pi(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_8_pi7(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_8_pd(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_8_pd7(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_8_di(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_8_ix(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_8_aw(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_8_al(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_16_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | m68ki_cpu.not_z_flag;
}


void m68k_op_addq_16_a(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

 *r_dst = (*r_dst + (((m68ki_cpu.ir >> 9) - 1) & 7) + 1);
}


void m68k_op_addq_16_ai(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_16_pi(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_16_pd(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_16_di(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_16_ix(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_16_aw(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_16_al(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_32_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int dst = *r_dst;
 unsigned int res = src + dst;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 *r_dst = m68ki_cpu.not_z_flag;
}


void m68k_op_addq_32_a(void)
{
 unsigned int* r_dst = &((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

 *r_dst = (*r_dst + (((m68ki_cpu.ir >> 9) - 1) & 7) + 1);
}


void m68k_op_addq_32_ai(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;


 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_32_pi(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;


 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_32_pd(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;


 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_32_di(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;


 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_32_ix(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;


 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_32_aw(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;


 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addq_32_al(void)
{
 unsigned int src = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int ea = m68ki_read_imm_32();
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst;


 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
 m68ki_cpu.not_z_flag = (res);

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_addx_8_rr(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int dst = ((*r_dst) & 0xff);
 unsigned int res = src + dst + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 *r_dst = ((*r_dst) & ~0xff) | res;
}


void m68k_op_addx_16_rr(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int dst = ((*r_dst) & 0xffff);
 unsigned int res = src + dst + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 *r_dst = ((*r_dst) & ~0xffff) | res;
}


void m68k_op_addx_32_rr(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int dst = *r_dst;
 unsigned int res = src + dst + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 *r_dst = res;
}


void m68k_op_addx_8_mm_ax7(void)
{
 unsigned int src = OPER_AY_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_addx_8_mm_ay7(void)
{
 unsigned int src = OPER_A7_PD_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_addx_8_mm_axy7(void)
{
 unsigned int src = OPER_A7_PD_8();
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_addx_8_mm(void)
{
 unsigned int src = OPER_AY_PD_8();
 unsigned int ea = (--((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]));
 unsigned int dst = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.v_flag = ((src^res) & (dst^res));
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res);

 res = ((res) & 0xff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_addx_16_mm(void)
{
 unsigned int src = OPER_AY_PD_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=2);
 unsigned int dst = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((res)>>8);

 res = ((res) & 0xffff);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_addx_32_mm(void)
{
 unsigned int src = OPER_AY_PD_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7])-=4);
 unsigned int dst = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src + dst + ((m68ki_cpu.x_flag>>8)&1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);

 res = (res);
 m68ki_cpu.not_z_flag |= res;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_and_8_er_d(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= ((m68ki_cpu.dar[m68ki_cpu.ir & 7]) | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_ai(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_AI_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_pi(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_PI_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_pi7(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_A7_PI_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_pd(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_PD_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_pd7(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_A7_PD_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_di(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_DI_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_ix(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_IX_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_aw(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AW_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_al(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AL_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_pcdi(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_PCDI_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_pcix(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_PCIX_8() | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_er_i(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (((m68ki_read_imm_16()) & 0xff) | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_d(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= ((m68ki_cpu.dar[m68ki_cpu.ir & 7]) | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_ai(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_AI_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_pi(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_PI_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_pd(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_PD_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_di(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_DI_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_ix(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_IX_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_aw(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AW_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_al(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AL_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_pcdi(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_PCDI_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_pcix(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_PCIX_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_16_er_i(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (m68ki_read_imm_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_d(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (m68ki_cpu.dar[m68ki_cpu.ir & 7]);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_ai(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= OPER_AY_AI_32();

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_pi(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= OPER_AY_PI_32();

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_pd(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= OPER_AY_PD_32();

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_di(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= OPER_AY_DI_32();

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_ix(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= OPER_AY_IX_32();

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_aw(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= OPER_AW_32();

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_al(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= OPER_AL_32();

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_pcdi(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= OPER_PCDI_32();

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_pcix(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= OPER_PCIX_32();

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_32_er_i(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= m68ki_read_imm_32();

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_and_8_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_8_re_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_8_re_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_8_re_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_8_re_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_8_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_8_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_8_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_8_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xff);

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_16_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_16_re_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_16_re_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_16_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_16_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_16_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_16_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.not_z_flag = ((res) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}


void m68k_op_and_32_re_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_and_32_re_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_and_32_re_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_and_32_re_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_and_32_re_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_and_32_re_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_and_32_re_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_8_d(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= (((m68ki_read_imm_16()) & 0xff) | 0xffffff00)) & 0xff);

 m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_andi_8_ai(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = src & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_8_pi(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int res = src & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_8_pi7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int res = src & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_8_pd(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = src & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_8_pd7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int res = src & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_8_di(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = src & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_8_ix(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = src & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_8_aw(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = src & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_8_al(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = src & m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_16_d(void)
{
 m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= (m68ki_read_imm_16() | 0xffff0000)) & 0xffff);

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_andi_16_ai(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = src & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_16_pi(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int res = src & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_16_pd(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int res = src & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_16_di(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = src & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_16_ix(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = src & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_16_aw(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = src & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_16_al(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = src & m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_32_d(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= (m68ki_read_imm_32());

 m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>24);
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_andi_32_ai(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int res = src & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_32_pi(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
 unsigned int res = src & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_32_pd(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
 unsigned int res = src & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_32_di(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int res = src & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_32_ix(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int res = src & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_32_aw(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int res = src & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_32_al(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int ea = m68ki_read_imm_32();
 unsigned int res = src & m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.v_flag = 0;

 m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}


void m68k_op_andi_16_toc(void)
{
 m68ki_set_ccr((((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8)) & m68ki_read_imm_16());
}


void m68k_op_andi_16_tos(void)
{
 if(m68ki_cpu.s_flag)
 {
  unsigned int src = m68ki_read_imm_16();
  ;
  m68ki_set_sr(( m68ki_cpu.t1_flag | m68ki_cpu.t0_flag | (m68ki_cpu.s_flag << 11) | (m68ki_cpu.m_flag << 11) | m68ki_cpu.int_mask | (((m68ki_cpu.x_flag&0x100) >> 4) | ((m68ki_cpu.n_flag&0x80) >> 4) | ((!m68ki_cpu.not_z_flag) << 2) | ((m68ki_cpu.v_flag&0x80) >> 6) | ((m68ki_cpu.c_flag&0x100) >> 8))) & src);
  return;
 }
 m68ki_exception_privilege_violation();
}


void m68k_op_asr_8_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = src >> shift;

 if(((src) & 0x80))
  res |= m68ki_shift_8_table[shift];

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << (9-shift);
}


void m68k_op_asr_16_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = src >> shift;

 if(((src) & 0x8000))
  res |= m68ki_shift_16_table[shift];

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << (9-shift);
}


void m68k_op_asr_32_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = *r_dst;
 unsigned int res = src >> shift;

 if(((src) & 0x80000000))
  res |= m68ki_shift_32_table[shift];

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << (9-shift);
}


void m68k_op_asr_8_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = src >> shift;

 if(shift != 0)
 {
  m68ki_remaining_cycles -= (shift<<m68ki_cpu.cyc_shift);

  if(shift < 8)
  {
   if(((src) & 0x80))
    res |= m68ki_shift_8_table[shift];

   *r_dst = ((*r_dst) & ~0xff) | res;

   m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << (9-shift);
   m68ki_cpu.n_flag = (res);
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }

  if(((src) & 0x80))
  {
   *r_dst |= 0xff;
   m68ki_cpu.c_flag = 0x100;
   m68ki_cpu.x_flag = 0x100;
   m68ki_cpu.n_flag = 0x80;
   m68ki_cpu.not_z_flag = 0xffffffff;
   m68ki_cpu.v_flag = 0;
   return;
  }

  *r_dst &= 0xffffff00;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
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


void m68k_op_asr_16_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = src >> shift;

 if(shift != 0)
 {
  m68ki_remaining_cycles -= (shift<<m68ki_cpu.cyc_shift);

  if(shift < 16)
  {
   if(((src) & 0x8000))
    res |= m68ki_shift_16_table[shift];

   *r_dst = ((*r_dst) & ~0xffff) | res;

   m68ki_cpu.c_flag = m68ki_cpu.x_flag = (src >> (shift - 1))<<8;
   m68ki_cpu.n_flag = ((res)>>8);
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }

  if(((src) & 0x8000))
  {
   *r_dst |= 0xffff;
   m68ki_cpu.c_flag = 0x100;
   m68ki_cpu.x_flag = 0x100;
   m68ki_cpu.n_flag = 0x80;
   m68ki_cpu.not_z_flag = 0xffffffff;
   m68ki_cpu.v_flag = 0;
   return;
  }

  *r_dst &= 0xffff0000;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
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


void m68k_op_asr_32_r(void)
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
   if(((src) & 0x80000000))
    res |= m68ki_shift_32_table[shift];

   *r_dst = res;

   m68ki_cpu.c_flag = m68ki_cpu.x_flag = (src >> (shift - 1))<<8;
   m68ki_cpu.n_flag = ((res)>>24);
   m68ki_cpu.not_z_flag = res;
   m68ki_cpu.v_flag = 0;
   return;
  }

  if(((src) & 0x80000000))
  {
   *r_dst = 0xffffffff;
   m68ki_cpu.c_flag = 0x100;
   m68ki_cpu.x_flag = 0x100;
   m68ki_cpu.n_flag = 0x80;
   m68ki_cpu.not_z_flag = 0xffffffff;
   m68ki_cpu.v_flag = 0;
   return;
  }

  *r_dst = 0;
  m68ki_cpu.c_flag = 0;
  m68ki_cpu.x_flag = 0;
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


void m68k_op_asr_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 if(((src) & 0x8000))
  res |= 0x8000;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
}


void m68k_op_asr_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 if(((src) & 0x8000))
  res |= 0x8000;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
}


void m68k_op_asr_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 if(((src) & 0x8000))
  res |= 0x8000;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
}


void m68k_op_asr_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 if(((src) & 0x8000))
  res |= 0x8000;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
}


void m68k_op_asr_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 if(((src) & 0x8000))
  res |= 0x8000;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
}


void m68k_op_asr_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 if(((src) & 0x8000))
  res |= 0x8000;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
}


void m68k_op_asr_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = src >> 1;

 if(((src) & 0x8000))
  res |= 0x8000;

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = m68ki_cpu.x_flag = src << 8;
}


void m68k_op_asl_8_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = ((src << shift) & 0xff);

 *r_dst = ((*r_dst) & ~0xff) | res;

 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << shift;
 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = res;
 src &= m68ki_shift_8_table[shift + 1];
 m68ki_cpu.v_flag = (!(src == 0 || (src == m68ki_shift_8_table[shift + 1] && shift < 8)))<<7;
}


void m68k_op_asl_16_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = ((src << shift) & 0xffff);

 *r_dst = ((*r_dst) & ~0xffff) | res;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> (8-shift);
 src &= m68ki_shift_16_table[shift + 1];
 m68ki_cpu.v_flag = (!(src == 0 || src == m68ki_shift_16_table[shift + 1]))<<7;
}


void m68k_op_asl_32_s(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
 unsigned int src = *r_dst;
 unsigned int res = (src << shift);

 *r_dst = res;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> (24-shift);
 src &= m68ki_shift_32_table[shift + 1];
 m68ki_cpu.v_flag = (!(src == 0 || src == m68ki_shift_32_table[shift + 1]))<<7;
}


void m68k_op_asl_8_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int src = ((*r_dst) & 0xff);
 unsigned int res = ((src << shift) & 0xff);

 if(shift != 0)
 {
  m68ki_remaining_cycles -= (shift<<m68ki_cpu.cyc_shift);

  if(shift < 8)
  {
   *r_dst = ((*r_dst) & ~0xff) | res;
   m68ki_cpu.x_flag = m68ki_cpu.c_flag = src << shift;
   m68ki_cpu.n_flag = (res);
   m68ki_cpu.not_z_flag = res;
   src &= m68ki_shift_8_table[shift + 1];
   m68ki_cpu.v_flag = (!(src == 0 || src == m68ki_shift_8_table[shift + 1]))<<7;
   return;
  }

  *r_dst &= 0xffffff00;
  m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((shift == 8 ? src & 1 : 0))<<8;
  m68ki_cpu.n_flag = 0;
  m68ki_cpu.not_z_flag = 0;
  m68ki_cpu.v_flag = (!(src == 0))<<7;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = (src);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_asl_16_r(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int shift = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x3f;
 unsigned int src = ((*r_dst) & 0xffff);
 unsigned int res = ((src << shift) & 0xffff);

 if(shift != 0)
 {
  m68ki_remaining_cycles -= (shift<<m68ki_cpu.cyc_shift);

  if(shift < 16)
  {
   *r_dst = ((*r_dst) & ~0xffff) | res;
   m68ki_cpu.x_flag = m68ki_cpu.c_flag = (src << shift) >> 8;
   m68ki_cpu.n_flag = ((res)>>8);
   m68ki_cpu.not_z_flag = res;
   src &= m68ki_shift_16_table[shift + 1];
   m68ki_cpu.v_flag = (!(src == 0 || src == m68ki_shift_16_table[shift + 1]))<<7;
   return;
  }

  *r_dst &= 0xffff0000;
  m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((shift == 16 ? src & 1 : 0))<<8;
  m68ki_cpu.n_flag = 0;
  m68ki_cpu.not_z_flag = 0;
  m68ki_cpu.v_flag = (!(src == 0))<<7;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = ((src)>>8);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_asl_32_r(void)
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
   src &= m68ki_shift_32_table[shift + 1];
   m68ki_cpu.v_flag = (!(src == 0 || src == m68ki_shift_32_table[shift + 1]))<<7;
   return;
  }

  *r_dst = 0;
  m68ki_cpu.x_flag = m68ki_cpu.c_flag = ((shift == 32 ? src & 1 : 0))<<8;
  m68ki_cpu.n_flag = 0;
  m68ki_cpu.not_z_flag = 0;
  m68ki_cpu.v_flag = (!(src == 0))<<7;
  return;
 }

 m68ki_cpu.c_flag = 0;
 m68ki_cpu.n_flag = ((src)>>24);
 m68ki_cpu.not_z_flag = src;
 m68ki_cpu.v_flag = 0;
}


void m68k_op_asl_16_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 src &= 0xc000;
 m68ki_cpu.v_flag = (!(src == 0 || src == 0xc000))<<7;
}


void m68k_op_asl_16_pi(void)
{
 unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 src &= 0xc000;
 m68ki_cpu.v_flag = (!(src == 0 || src == 0xc000))<<7;
}


void m68k_op_asl_16_pd(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 src &= 0xc000;
 m68ki_cpu.v_flag = (!(src == 0 || src == 0xc000))<<7;
}


void m68k_op_asl_16_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 src &= 0xc000;
 m68ki_cpu.v_flag = (!(src == 0 || src == 0xc000))<<7;
}


void m68k_op_asl_16_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 src &= 0xc000;
 m68ki_cpu.v_flag = (!(src == 0 || src == 0xc000))<<7;
}


void m68k_op_asl_16_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 src &= 0xc000;
 m68ki_cpu.v_flag = (!(src == 0 || src == 0xc000))<<7;
}


void m68k_op_asl_16_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
 unsigned int res = ((src << 1) & 0xffff);

 m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = res;
 m68ki_cpu.x_flag = m68ki_cpu.c_flag = src >> 7;
 src &= 0xc000;
 m68ki_cpu.v_flag = (!(src == 0 || src == 0xc000))<<7;
}


void m68k_op_bhi_8(void)
{
 if(((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bls_8(void)
{
 if(((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bcc_8(void)
{
 if((!(m68ki_cpu.c_flag&0x100)))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bcs_8(void)
{
 if((m68ki_cpu.c_flag&0x100))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bne_8(void)
{
 if(m68ki_cpu.not_z_flag)
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_beq_8(void)
{
 if((!m68ki_cpu.not_z_flag))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bvc_8(void)
{
 if((!(m68ki_cpu.v_flag&0x80)))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bvs_8(void)
{
 if((m68ki_cpu.v_flag&0x80))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bpl_8(void)
{
 if((!(m68ki_cpu.n_flag&0x80)))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bmi_8(void)
{
 if((m68ki_cpu.n_flag&0x80))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bge_8(void)
{
 if((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_blt_8(void)
{
 if(((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bgt_8(void)
{
 if(((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_ble_8(void)
{
 if((((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)))
 {
  ;
  m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
  return;
 }
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_b);
}


void m68k_op_bhi_16(void)
{
 if(((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bls_16(void)
{
 if(((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bcc_16(void)
{
 if((!(m68ki_cpu.c_flag&0x100)))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bcs_16(void)
{
 if((m68ki_cpu.c_flag&0x100))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bne_16(void)
{
 if(m68ki_cpu.not_z_flag)
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_beq_16(void)
{
 if((!m68ki_cpu.not_z_flag))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bvc_16(void)
{
 if((!(m68ki_cpu.v_flag&0x80)))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bvs_16(void)
{
 if((m68ki_cpu.v_flag&0x80))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bpl_16(void)
{
 if((!(m68ki_cpu.n_flag&0x80)))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bmi_16(void)
{
 if((m68ki_cpu.n_flag&0x80))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bge_16(void)
{
 if((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_blt_16(void)
{
 if(((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bgt_16(void)
{
 if(((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_ble_16(void)
{
 if((((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)))
 {
  unsigned int offset = m68ki_read_imm_16();
  m68ki_cpu.pc -= 2;
  ;
  m68ki_branch_16(offset);
  return;
 }
 m68ki_cpu.pc += 2;
 m68ki_remaining_cycles -= (m68ki_cpu.cyc_bcc_notake_w);
}


void m68k_op_bhi_32(void)
{
 if(0)
 {
  if(((!(m68ki_cpu.c_flag&0x100)) && m68ki_cpu.not_z_flag))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bls_32(void)
{
 if(0)
 {
  if(((m68ki_cpu.c_flag&0x100) || (!m68ki_cpu.not_z_flag)))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bcc_32(void)
{
 if(0)
 {
  if((!(m68ki_cpu.c_flag&0x100)))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bcs_32(void)
{
 if(0)
 {
  if((m68ki_cpu.c_flag&0x100))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bne_32(void)
{
 if(0)
 {
  if(m68ki_cpu.not_z_flag)
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_beq_32(void)
{
 if(0)
 {
  if((!m68ki_cpu.not_z_flag))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bvc_32(void)
{
 if(0)
 {
  if((!(m68ki_cpu.v_flag&0x80)))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bvs_32(void)
{
 if(0)
 {
  if((m68ki_cpu.v_flag&0x80))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bpl_32(void)
{
 if(0)
 {
  if((!(m68ki_cpu.n_flag&0x80)))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bmi_32(void)
{
 if(0)
 {
  if((m68ki_cpu.n_flag&0x80))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bge_32(void)
{
 if(0)
 {
  if((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_blt_32(void)
{
 if(0)
 {
  if(((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bgt_32(void)
{
 if(0)
 {
  if(((!((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80)) && m68ki_cpu.not_z_flag))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_ble_32(void)
{
 if(0)
 {
  if((((m68ki_cpu.n_flag^m68ki_cpu.v_flag)&0x80) || (!m68ki_cpu.not_z_flag)))
  {
   unsigned int offset = m68ki_read_imm_32();
   m68ki_cpu.pc -= 4;
   ;
   m68ki_branch_32(offset);
   return;
  }
  m68ki_cpu.pc += 4;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bchg_32_r_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x1f);

 m68ki_cpu.not_z_flag = *r_dst & mask;
 *r_dst ^= mask;
}


void m68k_op_bchg_8_r_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_r_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_r_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_r_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_r_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_r_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_r_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_r_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_r_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_32_s_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 0x1f);

 m68ki_cpu.not_z_flag = *r_dst & mask;
 *r_dst ^= mask;
}


void m68k_op_bchg_8_s_ai(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_s_pi(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_s_pi7(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_s_pd(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_s_pd7(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_s_di(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_s_ix(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_s_aw(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bchg_8_s_al(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src ^ mask);
}


void m68k_op_bclr_32_r_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x1f);

 m68ki_cpu.not_z_flag = *r_dst & mask;
 *r_dst &= ~mask;
}


void m68k_op_bclr_8_r_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_r_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_r_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_r_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_r_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_r_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_r_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_r_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_r_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_32_s_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 0x1f);

 m68ki_cpu.not_z_flag = *r_dst & mask;
 *r_dst &= ~mask;
}


void m68k_op_bclr_8_s_ai(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_s_pi(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_s_pi7(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_s_pd(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_s_pd7(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_s_di(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_s_ix(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_s_aw(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bclr_8_s_al(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src & ~mask);
}


void m68k_op_bfchg_32_d(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int* data = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned long mask;


  if(((word2) & 0x00000800))
   offset = m68ki_cpu.dar[offset&7];
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];

  offset &= 31;
  width = ((width-1) & 31) + 1;

  mask = (0xffffffff << (32 - width));
  mask = (((offset) < 32 ? (mask) >> (offset) : 0) | ((32-(offset)) < 32 ? (mask) << (32-(offset)) : 0));

  m68ki_cpu.n_flag = ((*data<<offset)>>24);
  m68ki_cpu.not_z_flag = *data & mask;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  *data ^= mask;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfchg_32_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long ^ mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte ^ mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfchg_32_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long ^ mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte ^ mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfchg_32_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long ^ mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte ^ mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfchg_32_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = (signed short)(m68ki_read_imm_16());


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long ^ mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte ^ mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfchg_32_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_read_imm_32();


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long ^ mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte ^ mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfclr_32_d(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int* data = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned long mask;


  if(((word2) & 0x00000800))
   offset = m68ki_cpu.dar[offset&7];
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  offset &= 31;
  width = ((width-1) & 31) + 1;


  mask = (0xffffffff << (32 - width));
  mask = (((offset) < 32 ? (mask) >> (offset) : 0) | ((32-(offset)) < 32 ? (mask) << (32-(offset)) : 0));

  m68ki_cpu.n_flag = ((*data<<offset)>>24);
  m68ki_cpu.not_z_flag = *data & mask;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  *data &= ~mask;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfclr_32_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long & ~mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte & ~mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfclr_32_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long & ~mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte & ~mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfclr_32_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long & ~mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte & ~mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfclr_32_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = (signed short)(m68ki_read_imm_16());


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long & ~mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte & ~mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfclr_32_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_read_imm_32();


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long & ~mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte & ~mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfexts_32_d(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned long data = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);


  if(((word2) & 0x00000800))
   offset = m68ki_cpu.dar[offset&7];
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];

  offset &= 31;
  width = ((width-1) & 31) + 1;

  data = (((offset) < 32 ? (data) << (offset) : 0) | ((32-(offset)) < 32 ? (data) >> (32-(offset)) : 0));
  m68ki_cpu.n_flag = ((data)>>24);
  data = (signed long)(data) >> (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2>>12)&7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfexts_32_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data = (signed long)(data) >> (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfexts_32_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data = (signed long)(data) >> (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfexts_32_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data = (signed long)(data) >> (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfexts_32_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = (signed short)(m68ki_read_imm_16());


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data = (signed long)(data) >> (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfexts_32_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = m68ki_read_imm_32();


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data = (signed long)(data) >> (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfexts_32_pcdi(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = m68ki_get_ea_pcdi();


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data = (signed long)(data) >> (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfexts_32_pcix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = m68ki_get_ea_pcix();


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);

  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data = (signed long)(data) >> (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfextu_32_d(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned long data = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);


  if(((word2) & 0x00000800))
   offset = m68ki_cpu.dar[offset&7];
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];

  offset &= 31;
  width = ((width-1) & 31) + 1;

  data = (((offset) < 32 ? (data) << (offset) : 0) | ((32-(offset)) < 32 ? (data) >> (32-(offset)) : 0));
  m68ki_cpu.n_flag = ((data)>>24);
  data >>= 32 - width;

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2>>12)&7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfextu_32_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);


  if(((word2) & 0x00000800))
  offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfextu_32_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));


  if(((word2) & 0x00000800))
  offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfextu_32_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));


  if(((word2) & 0x00000800))
  offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfextu_32_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = (signed short)(m68ki_read_imm_16());


  if(((word2) & 0x00000800))
  offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfextu_32_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = m68ki_read_imm_32();


  if(((word2) & 0x00000800))
  offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfextu_32_pcdi(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = m68ki_get_ea_pcdi();


  if(((word2) & 0x00000800))
  offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfextu_32_pcix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int data;
  unsigned int ea = m68ki_get_ea_pcix();


  if(((word2) & 0x00000800))
  offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<offset);

  if((offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_cpu.dar[(word2 >> 12) & 7] = data;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfffo_32_d(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned long data = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned int bit;


  if(((word2) & 0x00000800))
   offset = m68ki_cpu.dar[offset&7];
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];

  offset &= 31;
  width = ((width-1) & 31) + 1;

  data = (((offset) < 32 ? (data) << (offset) : 0) | ((32-(offset)) < 32 ? (data) >> (32-(offset)) : 0));
  m68ki_cpu.n_flag = ((data)>>24);
  data >>= 32 - width;

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  for(bit = 1<<(width-1);bit && !(data & bit);bit>>= 1)
   offset++;

  m68ki_cpu.dar[(word2>>12)&7] = offset;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfffo_32_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  signed int local_offset;
  unsigned int width = word2;
  unsigned int data;
  unsigned int bit;
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  local_offset = offset % 8;
  if(local_offset < 0)
  {
   local_offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<local_offset);

  if((local_offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << local_offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  for(bit = 1<<(width-1);bit && !(data & bit);bit>>= 1)
   offset++;

  m68ki_cpu.dar[(word2>>12)&7] = offset;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfffo_32_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  signed int local_offset;
  unsigned int width = word2;
  unsigned int data;
  unsigned int bit;
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  local_offset = offset % 8;
  if(local_offset < 0)
  {
   local_offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<local_offset);

  if((local_offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << local_offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  for(bit = 1<<(width-1);bit && !(data & bit);bit>>= 1)
   offset++;

  m68ki_cpu.dar[(word2>>12)&7] = offset;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfffo_32_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  signed int local_offset;
  unsigned int width = word2;
  unsigned int data;
  unsigned int bit;
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  local_offset = offset % 8;
  if(local_offset < 0)
  {
   local_offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<local_offset);

  if((local_offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << local_offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  for(bit = 1<<(width-1);bit && !(data & bit);bit>>= 1)
   offset++;

  m68ki_cpu.dar[(word2>>12)&7] = offset;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfffo_32_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  signed int local_offset;
  unsigned int width = word2;
  unsigned int data;
  unsigned int bit;
  unsigned int ea = (signed short)(m68ki_read_imm_16());


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  local_offset = offset % 8;
  if(local_offset < 0)
  {
   local_offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<local_offset);

  if((local_offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << local_offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  for(bit = 1<<(width-1);bit && !(data & bit);bit>>= 1)
   offset++;

  m68ki_cpu.dar[(word2>>12)&7] = offset;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfffo_32_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  signed int local_offset;
  unsigned int width = word2;
  unsigned int data;
  unsigned int bit;
  unsigned int ea = m68ki_read_imm_32();


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  local_offset = offset % 8;
  if(local_offset < 0)
  {
   local_offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<local_offset);

  if((local_offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << local_offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  for(bit = 1<<(width-1);bit && !(data & bit);bit>>= 1)
   offset++;

  m68ki_cpu.dar[(word2>>12)&7] = offset;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfffo_32_pcdi(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  signed int local_offset;
  unsigned int width = word2;
  unsigned int data;
  unsigned int bit;
  unsigned int ea = m68ki_get_ea_pcdi();


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  local_offset = offset % 8;
  if(local_offset < 0)
  {
   local_offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<local_offset);

  if((local_offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << local_offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  for(bit = 1<<(width-1);bit && !(data & bit);bit>>= 1)
   offset++;

  m68ki_cpu.dar[(word2>>12)&7] = offset;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfffo_32_pcix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  signed int local_offset;
  unsigned int width = word2;
  unsigned int data;
  unsigned int bit;
  unsigned int ea = m68ki_get_ea_pcix();


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  local_offset = offset % 8;
  if(local_offset < 0)
  {
   local_offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  data = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  data = (data<<local_offset);

  if((local_offset+width) > 32)
   data |= (m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1) << local_offset) >> 8;

  m68ki_cpu.n_flag = ((data)>>24);
  data >>= (32 - width);

  m68ki_cpu.not_z_flag = data;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  for(bit = 1<<(width-1);bit && !(data & bit);bit>>= 1)
   offset++;

  m68ki_cpu.dar[(word2>>12)&7] = offset;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfins_32_d(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int* data = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned long mask;
  unsigned long insert = m68ki_cpu.dar[(word2>>12)&7];


  if(((word2) & 0x00000800))
   offset = m68ki_cpu.dar[offset&7];
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  offset &= 31;
  width = ((width-1) & 31) + 1;


  mask = (0xffffffff << (32 - width));
  mask = (((offset) < 32 ? (mask) >> (offset) : 0) | ((32-(offset)) < 32 ? (mask) << (32-(offset)) : 0));

  insert = (insert << (32 - width));
  m68ki_cpu.n_flag = ((insert)>>24);
  m68ki_cpu.not_z_flag = insert;
  insert = (((offset) < 32 ? (insert) >> (offset) : 0) | ((32-(offset)) < 32 ? (insert) << (32-(offset)) : 0));

  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  *data &= ~mask;
  *data |= insert;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfins_32_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int insert_base = m68ki_cpu.dar[(word2>>12)&7];
  unsigned int insert_long;
  unsigned int insert_byte;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  insert_base = (insert_base << (32 - width));
  m68ki_cpu.n_flag = ((insert_base)>>24);
  m68ki_cpu.not_z_flag = insert_base;
  insert_long = insert_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, (data_long & ~mask_long) | insert_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   insert_byte = ((insert_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, (data_byte & ~mask_byte) | insert_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfins_32_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int insert_base = m68ki_cpu.dar[(word2>>12)&7];
  unsigned int insert_long;
  unsigned int insert_byte;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  insert_base = (insert_base << (32 - width));
  m68ki_cpu.n_flag = ((insert_base)>>24);
  m68ki_cpu.not_z_flag = insert_base;
  insert_long = insert_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, (data_long & ~mask_long) | insert_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   insert_byte = ((insert_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, (data_byte & ~mask_byte) | insert_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfins_32_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int insert_base = m68ki_cpu.dar[(word2>>12)&7];
  unsigned int insert_long;
  unsigned int insert_byte;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  insert_base = (insert_base << (32 - width));
  m68ki_cpu.n_flag = ((insert_base)>>24);
  m68ki_cpu.not_z_flag = insert_base;
  insert_long = insert_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, (data_long & ~mask_long) | insert_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   insert_byte = ((insert_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, (data_byte & ~mask_byte) | insert_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfins_32_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int insert_base = m68ki_cpu.dar[(word2>>12)&7];
  unsigned int insert_long;
  unsigned int insert_byte;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = (signed short)(m68ki_read_imm_16());


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  insert_base = (insert_base << (32 - width));
  m68ki_cpu.n_flag = ((insert_base)>>24);
  m68ki_cpu.not_z_flag = insert_base;
  insert_long = insert_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, (data_long & ~mask_long) | insert_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   insert_byte = ((insert_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, (data_byte & ~mask_byte) | insert_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfins_32_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int insert_base = m68ki_cpu.dar[(word2>>12)&7];
  unsigned int insert_long;
  unsigned int insert_byte;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_read_imm_32();


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;

  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  insert_base = (insert_base << (32 - width));
  m68ki_cpu.n_flag = ((insert_base)>>24);
  m68ki_cpu.not_z_flag = insert_base;
  insert_long = insert_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, (data_long & ~mask_long) | insert_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   insert_byte = ((insert_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, (data_byte & ~mask_byte) | insert_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfset_32_d(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int* data = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned long mask;


  if(((word2) & 0x00000800))
   offset = m68ki_cpu.dar[offset&7];
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  offset &= 31;
  width = ((width-1) & 31) + 1;


  mask = (0xffffffff << (32 - width));
  mask = (((offset) < 32 ? (mask) >> (offset) : 0) | ((32-(offset)) < 32 ? (mask) << (32-(offset)) : 0));

  m68ki_cpu.n_flag = ((*data<<offset)>>24);
  m68ki_cpu.not_z_flag = *data & mask;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  *data |= mask;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfset_32_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long | mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte | mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfset_32_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long | mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte | mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfset_32_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long | mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte | mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfset_32_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = (signed short)(m68ki_read_imm_16());


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long | mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte | mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bfset_32_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_read_imm_32();


  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long << offset)>>24);
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, data_long | mask_long);

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
   m68ki_write_8_fc (ea+4, m68ki_cpu.s_flag | 1, data_byte | mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bftst_32_d(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int* data = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
  unsigned long mask;


  if(((word2) & 0x00000800))
   offset = m68ki_cpu.dar[offset&7];
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  offset &= 31;
  width = ((width-1) & 31) + 1;


  mask = (0xffffffff << (32 - width));
  mask = (((offset) < 32 ? (mask) >> (offset) : 0) | ((32-(offset)) < 32 ? (mask) << (32-(offset)) : 0));

  m68ki_cpu.n_flag = ((*data<<offset)>>24);
  m68ki_cpu.not_z_flag = *data & mask;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bftst_32_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long & (0x80000000 >> offset))<<offset)>>24;
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bftst_32_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));

  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long & (0x80000000 >> offset))<<offset)>>24;
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bftst_32_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));

  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long & (0x80000000 >> offset))<<offset)>>24;
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bftst_32_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = (signed short)(m68ki_read_imm_16());

  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long & (0x80000000 >> offset))<<offset)>>24;
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bftst_32_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_read_imm_32();

  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long & (0x80000000 >> offset))<<offset)>>24;
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bftst_32_pcdi(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_get_ea_pcdi();

  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long & (0x80000000 >> offset))<<offset)>>24;
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bftst_32_pcix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  signed int offset = (word2>>6)&31;
  unsigned int width = word2;
  unsigned int mask_base;
  unsigned int data_long;
  unsigned int mask_long;
  unsigned int data_byte = 0;
  unsigned int mask_byte = 0;
  unsigned int ea = m68ki_get_ea_pcix();

  if(((word2) & 0x00000800))
   offset = (signed long)(m68ki_cpu.dar[offset&7]);
  if(((word2) & 0x00000020))
   width = m68ki_cpu.dar[width&7];


  ea += offset / 8;
  offset %= 8;
  if(offset < 0)
  {
   offset += 8;
   ea--;
  }
  width = ((width-1) & 31) + 1;


  mask_base = (0xffffffff << (32 - width));
  mask_long = mask_base >> offset;

  data_long = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  m68ki_cpu.n_flag = ((data_long & (0x80000000 >> offset))<<offset)>>24;
  m68ki_cpu.not_z_flag = data_long & mask_long;
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if((width + offset) > 32)
  {
   mask_byte = ((mask_base) & 0xff);
   data_byte = m68ki_read_8_fc (ea+4, m68ki_cpu.s_flag | 1);
   m68ki_cpu.not_z_flag |= (data_byte & mask_byte);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bkpt(void)
{
 if(0)
 {
  ;
 }
 m68ki_exception_illegal();
}


void m68k_op_bra_8(void)
{
 ;
 m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
 if(m68ki_cpu.pc == m68ki_cpu.ppc)
  m68ki_remaining_cycles = 0;
}


void m68k_op_bra_16(void)
{
 unsigned int offset = m68ki_read_imm_16();
 m68ki_cpu.pc -= 2;
 ;
 m68ki_branch_16(offset);
 if(m68ki_cpu.pc == m68ki_cpu.ppc)
  m68ki_remaining_cycles = 0;
}


void m68k_op_bra_32(void)
{
 if(0)
 {
  unsigned int offset = m68ki_read_imm_32();
  m68ki_cpu.pc -= 4;
  ;
  m68ki_branch_32(offset);
  if(m68ki_cpu.pc == m68ki_cpu.ppc)
   m68ki_remaining_cycles = 0;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_bset_32_r_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x1f);

 m68ki_cpu.not_z_flag = *r_dst & mask;
 *r_dst |= mask;
}


void m68k_op_bset_8_r_ai(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_r_pi(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_r_pi7(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_r_pd(void)
{
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_r_pd7(void)
{
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_r_di(void)
{
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_r_ix(void)
{
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_r_aw(void)
{
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_r_al(void)
{
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
 unsigned int mask = 1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_32_s_d(void)
{
 unsigned int* r_dst = &(m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 0x1f);

 m68ki_cpu.not_z_flag = *r_dst & mask;
 *r_dst |= mask;
}


void m68k_op_bset_8_s_ai(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_s_pi(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_s_pi7(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_s_pd(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_s_pd7(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_s_di(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_s_ix(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_s_aw(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = (signed short)(m68ki_read_imm_16());
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bset_8_s_al(void)
{
 unsigned int mask = 1 << (((m68ki_read_imm_16()) & 0xff) & 7);
 unsigned int ea = m68ki_read_imm_32();
 unsigned int src = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);

 m68ki_cpu.not_z_flag = src & mask;
 m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, src | mask);
}


void m68k_op_bsr_8(void)
{
 ;
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_branch_8(((m68ki_cpu.ir) & 0xff));
}


void m68k_op_bsr_16(void)
{
 unsigned int offset = m68ki_read_imm_16();
 ;
 m68ki_push_32(m68ki_cpu.pc);
 m68ki_cpu.pc -= 2;
 m68ki_branch_16(offset);
}


void m68k_op_bsr_32(void)
{
 if(0)
 {
  unsigned int offset = m68ki_read_imm_32();
  ;
  m68ki_push_32(m68ki_cpu.pc);
  m68ki_cpu.pc -= 4;
  m68ki_branch_32(offset);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_btst_32_r_d(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[m68ki_cpu.ir & 7]) & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 0x1f));
}


void m68k_op_btst_8_r_ai(void)
{
 m68ki_cpu.not_z_flag = OPER_AY_AI_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_pi(void)
{
 m68ki_cpu.not_z_flag = OPER_AY_PI_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_pi7(void)
{
 m68ki_cpu.not_z_flag = OPER_A7_PI_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_pd(void)
{
 m68ki_cpu.not_z_flag = OPER_AY_PD_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_pd7(void)
{
 m68ki_cpu.not_z_flag = OPER_A7_PD_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_di(void)
{
 m68ki_cpu.not_z_flag = OPER_AY_DI_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_ix(void)
{
 m68ki_cpu.not_z_flag = OPER_AY_IX_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_aw(void)
{
 m68ki_cpu.not_z_flag = OPER_AW_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_al(void)
{
 m68ki_cpu.not_z_flag = OPER_AL_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_pcdi(void)
{
 m68ki_cpu.not_z_flag = OPER_PCDI_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_pcix(void)
{
 m68ki_cpu.not_z_flag = OPER_PCIX_8() & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_8_r_i(void)
{
 m68ki_cpu.not_z_flag = ((m68ki_read_imm_16()) & 0xff) & (1 << ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) & 7));
}


void m68k_op_btst_32_s_d(void)
{
 m68ki_cpu.not_z_flag = (m68ki_cpu.dar[m68ki_cpu.ir & 7]) & (1 << (((m68ki_read_imm_16()) & 0xff) & 0x1f));
}


void m68k_op_btst_8_s_ai(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_AY_AI_8() & (1 << bit);
}


void m68k_op_btst_8_s_pi(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_AY_PI_8() & (1 << bit);
}


void m68k_op_btst_8_s_pi7(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_A7_PI_8() & (1 << bit);
}


void m68k_op_btst_8_s_pd(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_AY_PD_8() & (1 << bit);
}


void m68k_op_btst_8_s_pd7(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_A7_PD_8() & (1 << bit);
}


void m68k_op_btst_8_s_di(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_AY_DI_8() & (1 << bit);
}


void m68k_op_btst_8_s_ix(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_AY_IX_8() & (1 << bit);
}


void m68k_op_btst_8_s_aw(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_AW_8() & (1 << bit);
}


void m68k_op_btst_8_s_al(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_AL_8() & (1 << bit);
}


void m68k_op_btst_8_s_pcdi(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_PCDI_8() & (1 << bit);
}


void m68k_op_btst_8_s_pcix(void)
{
 unsigned int bit = ((m68ki_read_imm_16()) & 0xff) & 7;

 m68ki_cpu.not_z_flag = OPER_PCIX_8() & (1 << bit);
}


void m68k_op_callm_32_ai(void)
{

 if(0)
 {
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);

  ;
  m68ki_cpu.pc += 2;
(void)ea;
 

                                                       ;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_callm_32_di(void)
{

 if(0)
 {
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));

  ;
  m68ki_cpu.pc += 2;
(void)ea;
 

                                                       ;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_callm_32_ix(void)
{

 if(0)
 {
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));

  ;
  m68ki_cpu.pc += 2;
(void)ea;
 

                                                       ;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_callm_32_aw(void)
{

 if(0)
 {
  unsigned int ea = (signed short)(m68ki_read_imm_16());

  ;
  m68ki_cpu.pc += 2;
(void)ea;
 

                                                       ;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_callm_32_al(void)
{

 if(0)
 {
  unsigned int ea = m68ki_read_imm_32();

  ;
  m68ki_cpu.pc += 2;
(void)ea;
 

                                                       ;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_callm_32_pcdi(void)
{

 if(0)
 {
  unsigned int ea = m68ki_get_ea_pcdi();

  ;
  m68ki_cpu.pc += 2;
(void)ea;
 

                                                       ;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_callm_32_pcix(void)
{

 if(0)
 {
  unsigned int ea = m68ki_get_ea_pcix();

  ;
  m68ki_cpu.pc += 2;
(void)ea;
 

                                                       ;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_8_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
  unsigned int dest = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xff);

  ;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((*compare^dest) & (res^dest));
  m68ki_cpu.c_flag = (res);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_8_pi(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++);
  unsigned int dest = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xff);

  ;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((*compare^dest) & (res^dest));
  m68ki_cpu.c_flag = (res);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_8_pi7(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (((m68ki_cpu.dar+8)[7]+=2)-2);
  unsigned int dest = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xff);

  ;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((*compare^dest) & (res^dest));
  m68ki_cpu.c_flag = (res);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_8_pd(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  unsigned int dest = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xff);

  ;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((*compare^dest) & (res^dest));
  m68ki_cpu.c_flag = (res);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_8_pd7(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = ((m68ki_cpu.dar+8)[7]-=2);
  unsigned int dest = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xff);

  ;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((*compare^dest) & (res^dest));
  m68ki_cpu.c_flag = (res);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_8_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
  unsigned int dest = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xff);

  ;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((*compare^dest) & (res^dest));
  m68ki_cpu.c_flag = (res);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_8_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  unsigned int dest = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xff);

  ;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((*compare^dest) & (res^dest));
  m68ki_cpu.c_flag = (res);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_8_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (signed short)(m68ki_read_imm_16());
  unsigned int dest = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xff);

  ;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((*compare^dest) & (res^dest));
  m68ki_cpu.c_flag = (res);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_8_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = m68ki_read_imm_32();
  unsigned int dest = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xff);

  ;
  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((*compare^dest) & (res^dest));
  m68ki_cpu.c_flag = (res);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_16_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
  unsigned int dest = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xffff);

  ;
  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = ((res) & 0xffff);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>8);
  m68ki_cpu.c_flag = ((res)>>8);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xffff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xffff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_16_pi(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2);
  unsigned int dest = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xffff);

  ;
  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = ((res) & 0xffff);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>8);
  m68ki_cpu.c_flag = ((res)>>8);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xffff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xffff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_16_pd(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2);
  unsigned int dest = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xffff);

  ;
  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = ((res) & 0xffff);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>8);
  m68ki_cpu.c_flag = ((res)>>8);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xffff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xffff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_16_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
  unsigned int dest = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xffff);

  ;
  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = ((res) & 0xffff);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>8);
  m68ki_cpu.c_flag = ((res)>>8);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xffff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xffff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_16_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  unsigned int dest = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xffff);

  ;
  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = ((res) & 0xffff);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>8);
  m68ki_cpu.c_flag = ((res)>>8);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xffff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xffff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_16_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (signed short)(m68ki_read_imm_16());
  unsigned int dest = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xffff);

  ;
  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = ((res) & 0xffff);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>8);
  m68ki_cpu.c_flag = ((res)>>8);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xffff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xffff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_16_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = m68ki_read_imm_32();
  unsigned int dest = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - ((*compare) & 0xffff);

  ;
  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = ((res) & 0xffff);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>8);
  m68ki_cpu.c_flag = ((res)>>8);

  if(m68ki_cpu.not_z_flag)
   *compare = ((*compare) & ~0xffff) | dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, ((m68ki_cpu.dar[(word2 >> 6) & 7]) & 0xffff));
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_32_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
  unsigned int dest = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - *compare;

  ;
  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = (res);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>24);
  m68ki_cpu.c_flag = (((*compare & res) | (~dest & (*compare | res)))>>23);

  if(m68ki_cpu.not_z_flag)
   *compare = dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 6) & 7]);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_32_pi(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4);
  unsigned int dest = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - *compare;

  ;
  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = (res);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>24);
  m68ki_cpu.c_flag = (((*compare & res) | (~dest & (*compare | res)))>>23);

  if(m68ki_cpu.not_z_flag)
   *compare = dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 6) & 7]);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_32_pd(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4);
  unsigned int dest = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - *compare;

  ;
  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = (res);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>24);
  m68ki_cpu.c_flag = (((*compare & res) | (~dest & (*compare | res)))>>23);

  if(m68ki_cpu.not_z_flag)
   *compare = dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 6) & 7]);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_32_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
  unsigned int dest = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - *compare;

  ;
  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = (res);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>24);
  m68ki_cpu.c_flag = (((*compare & res) | (~dest & (*compare | res)))>>23);

  if(m68ki_cpu.not_z_flag)
   *compare = dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 6) & 7]);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_32_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  unsigned int dest = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - *compare;

  ;
  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = (res);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>24);
  m68ki_cpu.c_flag = (((*compare & res) | (~dest & (*compare | res)))>>23);

  if(m68ki_cpu.not_z_flag)
   *compare = dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 6) & 7]);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_32_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = (signed short)(m68ki_read_imm_16());
  unsigned int dest = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - *compare;

  ;
  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = (res);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>24);
  m68ki_cpu.c_flag = (((*compare & res) | (~dest & (*compare | res)))>>23);

  if(m68ki_cpu.not_z_flag)
   *compare = dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 6) & 7]);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas_32_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int ea = m68ki_read_imm_32();
  unsigned int dest = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int* compare = &m68ki_cpu.dar[word2 & 7];
  unsigned int res = dest - *compare;

  ;
  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = (res);
  m68ki_cpu.v_flag = (((*compare^dest) & (res^dest))>>24);
  m68ki_cpu.c_flag = (((*compare & res) | (~dest & (*compare | res)))>>23);

  if(m68ki_cpu.not_z_flag)
   *compare = dest;
  else
  {
   m68ki_remaining_cycles -= (3);
   m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 6) & 7]);
  }
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas2_16(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_32();
  unsigned int* compare1 = &m68ki_cpu.dar[(word2 >> 16) & 7];
  unsigned int ea1 = m68ki_cpu.dar[(word2 >> 28) & 15];
  unsigned int dest1 = m68ki_read_16_fc(ea1, m68ki_cpu.s_flag | 1);
  unsigned int res1 = dest1 - ((*compare1) & 0xffff);
  unsigned int* compare2 = &m68ki_cpu.dar[word2 & 7];
  unsigned int ea2 = m68ki_cpu.dar[(word2 >> 12) & 15];
  unsigned int dest2 = m68ki_read_16_fc(ea2, m68ki_cpu.s_flag | 1);
  unsigned int res2;

  ;
  m68ki_cpu.n_flag = ((res1)>>8);
  m68ki_cpu.not_z_flag = ((res1) & 0xffff);
  m68ki_cpu.v_flag = (((*compare1^dest1) & (res1^dest1))>>8);
  m68ki_cpu.c_flag = ((res1)>>8);

  if((!m68ki_cpu.not_z_flag))
  {
   res2 = dest2 - ((*compare2) & 0xffff);

   m68ki_cpu.n_flag = ((res2)>>8);
   m68ki_cpu.not_z_flag = ((res2) & 0xffff);
   m68ki_cpu.v_flag = (((*compare2^dest2) & (res2^dest2))>>8);
   m68ki_cpu.c_flag = ((res2)>>8);

   if((!m68ki_cpu.not_z_flag))
   {
    m68ki_remaining_cycles -= (3);
    m68ki_write_16_fc(ea1, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 22) & 7]);
    m68ki_write_16_fc(ea2, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 6) & 7]);
    return;
   }
  }
  *compare1 = ((word2) & 0x80000000) ? (signed short)(dest1) : ((*compare1) & ~0xffff) | dest1;
  *compare2 = ((word2) & 0x00008000) ? (signed short)(dest2) : ((*compare2) & ~0xffff) | dest2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cas2_32(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_32();
  unsigned int* compare1 = &m68ki_cpu.dar[(word2 >> 16) & 7];
  unsigned int ea1 = m68ki_cpu.dar[(word2 >> 28) & 15];
  unsigned int dest1 = m68ki_read_32_fc(ea1, m68ki_cpu.s_flag | 1);
  unsigned int res1 = dest1 - *compare1;
  unsigned int* compare2 = &m68ki_cpu.dar[word2 & 7];
  unsigned int ea2 = m68ki_cpu.dar[(word2 >> 12) & 15];
  unsigned int dest2 = m68ki_read_32_fc(ea2, m68ki_cpu.s_flag | 1);
  unsigned int res2;

  ;
  m68ki_cpu.n_flag = ((res1)>>24);
  m68ki_cpu.not_z_flag = (res1);
  m68ki_cpu.v_flag = (((*compare1^dest1) & (res1^dest1))>>24);
  m68ki_cpu.c_flag = (((*compare1 & res1) | (~dest1 & (*compare1 | res1)))>>23);

  if((!m68ki_cpu.not_z_flag))
  {
   res2 = dest2 - *compare2;

   m68ki_cpu.n_flag = ((res2)>>24);
   m68ki_cpu.not_z_flag = (res2);
   m68ki_cpu.v_flag = (((*compare2^dest2) & (res2^dest2))>>24);
   m68ki_cpu.c_flag = (((*compare2 & res2) | (~dest2 & (*compare2 | res2)))>>23);

   if((!m68ki_cpu.not_z_flag))
   {
    m68ki_remaining_cycles -= (3);
    m68ki_write_32_fc(ea1, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 22) & 7]);
    m68ki_write_32_fc(ea2, m68ki_cpu.s_flag | 1, m68ki_cpu.dar[(word2 >> 6) & 7]);
    return;
   }
  }
  *compare1 = dest1;
  *compare2 = dest2;
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_16_d(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)((m68ki_cpu.dar[m68ki_cpu.ir & 7]));

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_16_ai(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)(OPER_AY_AI_16());

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_16_pi(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)(OPER_AY_PI_16());

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_16_pd(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)(OPER_AY_PD_16());

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_16_di(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)(OPER_AY_DI_16());

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_16_ix(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)(OPER_AY_IX_16());

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_16_aw(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)(OPER_AW_16());

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_16_al(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)(OPER_AL_16());

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_16_pcdi(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)(OPER_PCDI_16());

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_16_pcix(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)(OPER_PCIX_16());

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_16_i(void)
{
 signed int src = (signed short)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
 signed int bound = (signed short)(m68ki_read_imm_16());

 m68ki_cpu.not_z_flag = ((src) & 0xffff);
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;

 if(src >= 0 && src <= bound)
 {
  return;
 }
 m68ki_cpu.n_flag = (src < 0)<<7;
 m68ki_exception_trap(6);
}


void m68k_op_chk_32_d(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)((m68ki_cpu.dar[m68ki_cpu.ir & 7]));

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_32_ai(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)(OPER_AY_AI_32());

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_32_pi(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)(OPER_AY_PI_32());

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_32_pd(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)(OPER_AY_PD_32());

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_32_di(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)(OPER_AY_DI_32());

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_32_ix(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)(OPER_AY_IX_32());

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_32_aw(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)(OPER_AW_32());

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_32_al(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)(OPER_AL_32());

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_32_pcdi(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)(OPER_PCDI_32());

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_32_pcix(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)(OPER_PCIX_32());

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk_32_i(void)
{
 if(0)
 {
  signed int src = (signed long)((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]));
  signed int bound = (signed long)(m68ki_read_imm_32());

  m68ki_cpu.not_z_flag = (src);
  m68ki_cpu.v_flag = 0;
  m68ki_cpu.c_flag = 0;

  if(src >= 0 && src <= bound)
  {
   return;
  }
  m68ki_cpu.n_flag = (src < 0)<<7;
  m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_8_pcdi(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xff;
  unsigned int ea = m68ki_get_ea_pcdi();
  unsigned int lower_bound = m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 2);
  unsigned int upper_bound = m68ki_read_8_fc(ea + 1, m68ki_cpu.s_flag | 2);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed char)(compare) - (signed char)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_8_pcix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xff;
  unsigned int ea = m68ki_get_ea_pcix();
  unsigned int lower_bound = m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 2);
  unsigned int upper_bound = m68ki_read_8_fc(ea + 1, m68ki_cpu.s_flag | 2);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed char)(compare) - (signed char)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_8_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xff;
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
  unsigned int lower_bound = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_8_fc (ea + 1, m68ki_cpu.s_flag | 1);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed char)(compare) - (signed char)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_8_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xff;
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
  unsigned int lower_bound = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_8_fc (ea + 1, m68ki_cpu.s_flag | 1);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed char)(compare) - (signed char)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_8_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xff;
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  unsigned int lower_bound = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_8_fc (ea + 1, m68ki_cpu.s_flag | 1);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed char)(compare) - (signed char)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_8_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xff;
  unsigned int ea = (signed short)(m68ki_read_imm_16());
  unsigned int lower_bound = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_8_fc (ea + 1, m68ki_cpu.s_flag | 1);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed char)(compare) - (signed char)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_8_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xff;
  unsigned int ea = m68ki_read_imm_32();
  unsigned int lower_bound = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_8_fc (ea + 1, m68ki_cpu.s_flag | 1);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed char)(compare) - (signed char)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_16_pcdi(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xffff;
  unsigned int ea = m68ki_get_ea_pcdi();
  unsigned int lower_bound = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 2);
  unsigned int upper_bound = m68ki_read_16_fc(ea + 2, m68ki_cpu.s_flag | 2);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(compare) - (signed short)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(upper_bound) - (signed short)(compare);
  else
   m68ki_cpu.c_flag = upper_bound - compare;
  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_16_pcix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xffff;
  unsigned int ea = m68ki_get_ea_pcix();
  unsigned int lower_bound = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 2);
  unsigned int upper_bound = m68ki_read_16_fc(ea + 2, m68ki_cpu.s_flag | 2);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(compare) - (signed short)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(upper_bound) - (signed short)(compare);
  else
   m68ki_cpu.c_flag = upper_bound - compare;
  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_16_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xffff;
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
  unsigned int lower_bound = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_16_fc(ea + 2, m68ki_cpu.s_flag | 1);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(compare) - (signed short)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;

  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }
  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(upper_bound) - (signed short)(compare);
  else
   m68ki_cpu.c_flag = upper_bound - compare;

  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_16_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xffff;
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
  unsigned int lower_bound = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_16_fc(ea + 2, m68ki_cpu.s_flag | 1);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(compare) - (signed short)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;

  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }
  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(upper_bound) - (signed short)(compare);
  else
   m68ki_cpu.c_flag = upper_bound - compare;

  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_16_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xffff;
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  unsigned int lower_bound = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_16_fc(ea + 2, m68ki_cpu.s_flag | 1);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(compare) - (signed short)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;

  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }
  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(upper_bound) - (signed short)(compare);
  else
   m68ki_cpu.c_flag = upper_bound - compare;

  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_16_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xffff;
  unsigned int ea = (signed short)(m68ki_read_imm_16());
  unsigned int lower_bound = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_16_fc(ea + 2, m68ki_cpu.s_flag | 1);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(compare) - (signed short)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;

  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }
  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(upper_bound) - (signed short)(compare);
  else
   m68ki_cpu.c_flag = upper_bound - compare;

  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_16_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15]&0xffff;
  unsigned int ea = m68ki_read_imm_32();
  unsigned int lower_bound = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_16_fc(ea + 2, m68ki_cpu.s_flag | 1);

  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(compare) - (signed short)(lower_bound);
  else
   m68ki_cpu.c_flag = compare - lower_bound;

  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }
  if(!((word2) & 0x00008000))
   m68ki_cpu.c_flag = (signed short)(upper_bound) - (signed short)(compare);
  else
   m68ki_cpu.c_flag = upper_bound - compare;

  m68ki_cpu.c_flag = ((m68ki_cpu.c_flag)>>8);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_32_pcdi(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15];
  unsigned int ea = m68ki_get_ea_pcdi();
  unsigned int lower_bound = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 2);
  unsigned int upper_bound = m68ki_read_32_fc(ea + 4, m68ki_cpu.s_flag | 2);

  m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = (((lower_bound & m68ki_cpu.c_flag) | (~compare & (lower_bound | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  m68ki_cpu.c_flag = (((compare & m68ki_cpu.c_flag) | (~upper_bound & (compare | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_32_pcix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15];
  unsigned int ea = m68ki_get_ea_pcix();
  unsigned int lower_bound = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 2);
  unsigned int upper_bound = m68ki_read_32_fc(ea + 4, m68ki_cpu.s_flag | 2);

  m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = (((lower_bound & m68ki_cpu.c_flag) | (~compare & (lower_bound | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  m68ki_cpu.c_flag = (((compare & m68ki_cpu.c_flag) | (~upper_bound & (compare | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_32_ai(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15];
  unsigned int ea = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
  unsigned int lower_bound = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_32_fc(ea + 4, m68ki_cpu.s_flag | 1);

  m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = (((lower_bound & m68ki_cpu.c_flag) | (~compare & (lower_bound | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  m68ki_cpu.c_flag = (((compare & m68ki_cpu.c_flag) | (~upper_bound & (compare | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_32_di(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15];
  unsigned int ea = (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16()));
  unsigned int lower_bound = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_32_fc(ea + 4, m68ki_cpu.s_flag | 1);

  m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = (((lower_bound & m68ki_cpu.c_flag) | (~compare & (lower_bound | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  m68ki_cpu.c_flag = (((compare & m68ki_cpu.c_flag) | (~upper_bound & (compare | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_32_ix(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15];
  unsigned int ea = m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
  unsigned int lower_bound = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_32_fc(ea + 4, m68ki_cpu.s_flag | 1);

  m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = (((lower_bound & m68ki_cpu.c_flag) | (~compare & (lower_bound | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  m68ki_cpu.c_flag = (((compare & m68ki_cpu.c_flag) | (~upper_bound & (compare | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_32_aw(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15];
  unsigned int ea = (signed short)(m68ki_read_imm_16());
  unsigned int lower_bound = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_32_fc(ea + 4, m68ki_cpu.s_flag | 1);

  m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = (((lower_bound & m68ki_cpu.c_flag) | (~compare & (lower_bound | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  m68ki_cpu.c_flag = (((compare & m68ki_cpu.c_flag) | (~upper_bound & (compare | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_chk2cmp2_32_al(void)
{
 if(0)
 {
  unsigned int word2 = m68ki_read_imm_16();
  unsigned int compare = m68ki_cpu.dar[(word2 >> 12) & 15];
  unsigned int ea = m68ki_read_imm_32();
  unsigned int lower_bound = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
  unsigned int upper_bound = m68ki_read_32_fc(ea + 4, m68ki_cpu.s_flag | 1);

  m68ki_cpu.c_flag = compare - lower_bound;
  m68ki_cpu.not_z_flag = !((upper_bound==compare) | (lower_bound==compare));
  m68ki_cpu.c_flag = (((lower_bound & m68ki_cpu.c_flag) | (~compare & (lower_bound | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100))
  {
   if(((word2) & 0x00000800))
    m68ki_exception_trap(6);
   return;
  }

  m68ki_cpu.c_flag = upper_bound - compare;
  m68ki_cpu.c_flag = (((compare & m68ki_cpu.c_flag) | (~upper_bound & (compare | m68ki_cpu.c_flag)))>>23);
  if((m68ki_cpu.c_flag&0x100) && ((word2) & 0x00000800))
    m68ki_exception_trap(6);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_clr_8_d(void)
{
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffffff00;

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_8_ai(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_8_pi(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])++), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_8_pi7(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[7]+=2)-2), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_8_pd(void)
{
 m68ki_write_8_fc ((--((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_8_pd7(void)
{
 m68ki_write_8_fc (((m68ki_cpu.dar+8)[7]-=2), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_8_di(void)
{
 m68ki_write_8_fc ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_8_ix(void)
{
 m68ki_write_8_fc (m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_8_aw(void)
{
 m68ki_write_8_fc ((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_8_al(void)
{
 m68ki_write_8_fc (m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_16_d(void)
{
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) &= 0xffff0000;

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_16_ai(void)
{
 m68ki_write_16_fc(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_16_pi(void)
{
 m68ki_write_16_fc(((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=2)-2), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_16_pd(void)
{
 m68ki_write_16_fc((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=2), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_16_di(void)
{
 m68ki_write_16_fc((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_16_ix(void)
{
 m68ki_write_16_fc(m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_16_aw(void)
{
 m68ki_write_16_fc((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_16_al(void)
{
 m68ki_write_16_fc(m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_32_d(void)
{
 (m68ki_cpu.dar[m68ki_cpu.ir & 7]) = 0;

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_32_ai(void)
{
 m68ki_write_32_fc(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_32_pi(void)
{
 m68ki_write_32_fc(((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+=4)-4), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_32_pd(void)
{
 m68ki_write_32_fc((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])-=4), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_32_di(void)
{
 m68ki_write_32_fc((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])+(signed short)(m68ki_read_imm_16())), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_32_ix(void)
{
 m68ki_write_32_fc(m68ki_get_ea_ix(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_32_aw(void)
{
 m68ki_write_32_fc((signed short)(m68ki_read_imm_16()), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_clr_32_al(void)
{
 m68ki_write_32_fc(m68ki_read_imm_32(), m68ki_cpu.s_flag | 1, 0);

 m68ki_cpu.n_flag = 0;
 m68ki_cpu.v_flag = 0;
 m68ki_cpu.c_flag = 0;
 m68ki_cpu.not_z_flag = 0;
}


void m68k_op_cmp_8_d(void)
{
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_ai(void)
{
 unsigned int src = OPER_AY_AI_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_pi(void)
{
 unsigned int src = OPER_AY_PI_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_pi7(void)
{
 unsigned int src = OPER_A7_PI_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_pd(void)
{
 unsigned int src = OPER_AY_PD_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_pd7(void)
{
 unsigned int src = OPER_A7_PD_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_di(void)
{
 unsigned int src = OPER_AY_DI_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_ix(void)
{
 unsigned int src = OPER_AY_IX_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_aw(void)
{
 unsigned int src = OPER_AW_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_al(void)
{
 unsigned int src = OPER_AL_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_pcdi(void)
{
 unsigned int src = OPER_PCDI_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_pcix(void)
{
 unsigned int src = OPER_PCIX_8();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_8_i(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmp_16_d(void)
{
 unsigned int src = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_a(void)
{
 unsigned int src = ((((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_ai(void)
{
 unsigned int src = OPER_AY_AI_16();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_pi(void)
{
 unsigned int src = OPER_AY_PI_16();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_pd(void)
{
 unsigned int src = OPER_AY_PD_16();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_di(void)
{
 unsigned int src = OPER_AY_DI_16();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_ix(void)
{
 unsigned int src = OPER_AY_IX_16();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_aw(void)
{
 unsigned int src = OPER_AW_16();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_al(void)
{
 unsigned int src = OPER_AL_16();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_pcdi(void)
{
 unsigned int src = OPER_PCDI_16();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_pcix(void)
{
 unsigned int src = OPER_PCIX_16();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_16_i(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmp_32_d(void)
{
 unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_a(void)
{
 unsigned int src = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_ai(void)
{
 unsigned int src = OPER_AY_AI_32();
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_pi(void)
{
 unsigned int src = OPER_AY_PI_32();
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_pd(void)
{
 unsigned int src = OPER_AY_PD_32();
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_di(void)
{
 unsigned int src = OPER_AY_DI_32();
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_ix(void)
{
 unsigned int src = OPER_AY_IX_32();
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_aw(void)
{
 unsigned int src = OPER_AW_32();
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_al(void)
{
 unsigned int src = OPER_AL_32();
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_pcdi(void)
{
 unsigned int src = OPER_PCDI_32();
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_pcix(void)
{
 unsigned int src = OPER_PCIX_32();
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmp_32_i(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_d(void)
{
 unsigned int src = (signed short)((m68ki_cpu.dar[m68ki_cpu.ir & 7]));
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_a(void)
{
 unsigned int src = (signed short)(((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]));
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_ai(void)
{
 unsigned int src = (signed short)(OPER_AY_AI_16());
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_pi(void)
{
 unsigned int src = (signed short)(OPER_AY_PI_16());
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_pd(void)
{
 unsigned int src = (signed short)(OPER_AY_PD_16());
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_di(void)
{
 unsigned int src = (signed short)(OPER_AY_DI_16());
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_ix(void)
{
 unsigned int src = (signed short)(OPER_AY_IX_16());
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_aw(void)
{
 unsigned int src = (signed short)(OPER_AW_16());
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_al(void)
{
 unsigned int src = (signed short)(OPER_AL_16());
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_pcdi(void)
{
 unsigned int src = (signed short)(OPER_PCDI_16());
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_pcix(void)
{
 unsigned int src = (signed short)(OPER_PCIX_16());
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_16_i(void)
{
 unsigned int src = (signed short)(m68ki_read_imm_16());
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_d(void)
{
 unsigned int src = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_a(void)
{
 unsigned int src = ((m68ki_cpu.dar+8)[m68ki_cpu.ir & 7]);
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_ai(void)
{
 unsigned int src = OPER_AY_AI_32();
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_pi(void)
{
 unsigned int src = OPER_AY_PI_32();
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_pd(void)
{
 unsigned int src = OPER_AY_PD_32();
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_di(void)
{
 unsigned int src = OPER_AY_DI_32();
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_ix(void)
{
 unsigned int src = OPER_AY_IX_32();
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_aw(void)
{
 unsigned int src = OPER_AW_32();
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_al(void)
{
 unsigned int src = OPER_AL_32();
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_pcdi(void)
{
 unsigned int src = OPER_PCDI_32();
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_pcix(void)
{
 unsigned int src = OPER_PCIX_32();
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpa_32_i(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = ((m68ki_cpu.dar+8)[(m68ki_cpu.ir >> 9) & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpi_8_d(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpi_8_ai(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = OPER_AY_AI_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpi_8_pi(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = OPER_AY_PI_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpi_8_pi7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = OPER_A7_PI_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpi_8_pd(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = OPER_AY_PD_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpi_8_pd7(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = OPER_A7_PD_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpi_8_di(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = OPER_AY_DI_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpi_8_ix(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = OPER_AY_IX_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpi_8_aw(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = OPER_AW_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpi_8_al(void)
{
 unsigned int src = ((m68ki_read_imm_16()) & 0xff);
 unsigned int dst = OPER_AL_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpi_8_pcdi(void)
{
 if(0)
 {
  unsigned int src = ((m68ki_read_imm_16()) & 0xff);
  unsigned int dst = OPER_PCDI_8();
  unsigned int res = dst - src;

  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((src^dst) & (res^dst));
  m68ki_cpu.c_flag = (res);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cmpi_8_pcix(void)
{
 if(0)
 {
  unsigned int src = ((m68ki_read_imm_16()) & 0xff);
  unsigned int dst = OPER_PCIX_8();
  unsigned int res = dst - src;

  m68ki_cpu.n_flag = (res);
  m68ki_cpu.not_z_flag = ((res) & 0xff);
  m68ki_cpu.v_flag = ((src^dst) & (res^dst));
  m68ki_cpu.c_flag = (res);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cmpi_16_d(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmpi_16_ai(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = OPER_AY_AI_16();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmpi_16_pi(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = OPER_AY_PI_16();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmpi_16_pd(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = OPER_AY_PD_16();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmpi_16_di(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = OPER_AY_DI_16();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmpi_16_ix(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = OPER_AY_IX_16();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmpi_16_aw(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = OPER_AW_16();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmpi_16_al(void)
{
 unsigned int src = m68ki_read_imm_16();
 unsigned int dst = OPER_AL_16();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmpi_16_pcdi(void)
{
 if(0)
 {
  unsigned int src = m68ki_read_imm_16();
  unsigned int dst = OPER_PCDI_16();
  unsigned int res = dst - src;

  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = ((res) & 0xffff);
  m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
  m68ki_cpu.c_flag = ((res)>>8);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cmpi_16_pcix(void)
{
 if(0)
 {
  unsigned int src = m68ki_read_imm_16();
  unsigned int dst = OPER_PCIX_16();
  unsigned int res = dst - src;

  m68ki_cpu.n_flag = ((res)>>8);
  m68ki_cpu.not_z_flag = ((res) & 0xffff);
  m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
  m68ki_cpu.c_flag = ((res)>>8);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cmpi_32_d(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpi_32_ai(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = OPER_AY_AI_32();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpi_32_pi(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = OPER_AY_PI_32();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpi_32_pd(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = OPER_AY_PD_32();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpi_32_di(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = OPER_AY_DI_32();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpi_32_ix(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = OPER_AY_IX_32();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpi_32_aw(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = OPER_AW_32();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpi_32_al(void)
{
 unsigned int src = m68ki_read_imm_32();
 unsigned int dst = OPER_AL_32();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cmpi_32_pcdi(void)
{
 if(0)
 {
  unsigned int src = m68ki_read_imm_32();
  unsigned int dst = OPER_PCDI_32();
  unsigned int res = dst - src;

  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = (res);
  m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
  m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cmpi_32_pcix(void)
{
 if(0)
 {
  unsigned int src = m68ki_read_imm_32();
  unsigned int dst = OPER_PCIX_32();
  unsigned int res = dst - src;

  m68ki_cpu.n_flag = ((res)>>24);
  m68ki_cpu.not_z_flag = (res);
  m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
  m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
  return;
 }
 m68ki_exception_illegal();
}


void m68k_op_cmpm_8_ax7(void)
{
 unsigned int src = OPER_AY_PI_8();
 unsigned int dst = OPER_A7_PI_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpm_8_ay7(void)
{
 unsigned int src = OPER_A7_PI_8();
 unsigned int dst = OPER_AX_PI_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpm_8_axy7(void)
{
 unsigned int src = OPER_A7_PI_8();
 unsigned int dst = OPER_A7_PI_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpm_8(void)
{
 unsigned int src = OPER_AY_PI_8();
 unsigned int dst = OPER_AX_PI_8();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = (res);
 m68ki_cpu.not_z_flag = ((res) & 0xff);
 m68ki_cpu.v_flag = ((src^dst) & (res^dst));
 m68ki_cpu.c_flag = (res);
}


void m68k_op_cmpm_16(void)
{
 unsigned int src = OPER_AY_PI_16();
 unsigned int dst = OPER_AX_PI_16();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>8);
 m68ki_cpu.not_z_flag = ((res) & 0xffff);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>8);
 m68ki_cpu.c_flag = ((res)>>8);
}


void m68k_op_cmpm_32(void)
{
 unsigned int src = OPER_AY_PI_32();
 unsigned int dst = OPER_AX_PI_32();
 unsigned int res = dst - src;

 m68ki_cpu.n_flag = ((res)>>24);
 m68ki_cpu.not_z_flag = (res);
 m68ki_cpu.v_flag = (((src^dst) & (res^dst))>>24);
 m68ki_cpu.c_flag = (((src & res) | (~dst & (src | res)))>>23);
}


void m68k_op_cpdbcc_32(void)
{
 if(0)
 {
 

                                                       ;
  return;
 }
 m68ki_exception_1111();
}


void m68k_op_cpgen_32(void)
{
 if(0)
 {
 

                                                       ;
  return;
 }
 m68ki_exception_1111();
}


void m68k_op_cpscc_32(void)
{
 if(0)
 {
 

                                                       ;
  return;
 }
 m68ki_exception_1111();
}


void m68k_op_cptrapcc_32(void)
{
 if(0)
 {
 

                                                       ;
  return;
 }
 m68ki_exception_1111();
}
