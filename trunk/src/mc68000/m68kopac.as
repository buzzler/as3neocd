private	function m68k_op_1010():void
{
	m68ki_exception_1010();
}
private	function m68k_op_1111():void
{
	switch (m68ki_cpu.ir)
	{
		case 0xfabe: neogeo_exit(); break;
		case 0xfabf: img_display=1; cdrom_load_files(); break;
		case 0xfac0: img_display=0; cdrom_load_files(); break;
		case 0xfac1: neogeo_upload(); break;
		case 0xfac2: neogeo_prio_switch(); break;
		case 0xfac3: neogeo_cdda_control(); break;
		default: m68ki_exception_1111(); break;
	}
}
private	function m68k_op_abcd_8_rr():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7];
	var dst:uint = m68ki_cpu.dar[r_dst];
	var res:uint = (src & 0x0f) + (dst & 0x0f) + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.v_flag = ~res;
	
	if(res > 9)
	{
		res += 6;
	}
	res += (src & 0xf0) + (dst & 0xf0);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res > 0x99) << 8;
	if(m68ki_cpu.c_flag)
	{
		res -= 0xa0;
	}
	
	m68ki_cpu.v_flag &= res;
	m68ki_cpu.n_flag = res;
	
	res &= 0xff;
	m68ki_cpu.not_z_flag |= res;
	m68ki_cpu.dar[r_dst] = dst & ~0xff | res;
}

private	function m68k_op_abcd_8_mm_ax7():void
{
	var src:uint = OPER_AY_PD_8();
	var ea:uint = (m68ki_cpu.dar[15]-=2);
	var dst:uint = m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = (src & 0x0f) + (dst & 0x0f) + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.v_flag = ~res;
	
	if(res > 9)
	{
		res += 6;
	}
	res += (src & 0xf0) + (dst & 0xf0);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res > 0x99) << 8;
	if(m68ki_cpu.c_flag)
	{
		res -= 0xa0;
	}
	
	m68ki_cpu.v_flag &= res;
	m68ki_cpu.n_flag = res;
	
	res &= 0xff;
	m68ki_cpu.not_z_flag |= res;
	m68ki_write_8_fc(ea, m68ki_cpu.s_flag | 1, res);
}

private	function m68k_op_abcd_8_mm_ay7():void
{
	var src:uint = OPER_A7_PD_8();
	var ea:uint = (--(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]));
	var dst:uint = m68ki_read_8_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = (src & 0x0f) + (dst & 0x0f) + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.v_flag = ~res;
	
	if(res > 9)
	{
		res += 6;
	}
	res += (src & 0xf0) + (dst & 0xf0);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res > 0x99) << 8;
	if(m68ki_cpu.c_flag)
	{
		res -= 0xa0;
	}
	
	m68ki_cpu.v_flag &= res;
	m68ki_cpu.n_flag = res;
	
	res &= & 0xff;
	m68ki_cpu.not_z_flag |= res;
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}
private	function m68k_op_abcd_8_mm_axy7():void
{
	var src:uint = OPER_A7_PD_8();
	var ea:uint = (m68ki_cpu.dar[15]-=2);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = ((src) & 0x0f) + ((dst) & 0x0f) + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.v_flag = ~res;
	
	if(res > 9)
	{
		res += 6;
	}
	res += (src & 0xf0) + (dst & 0xf0);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res > 0x99) << 8;
	if(m68ki_cpu.c_flag)
	{
		res -= 0xa0;
	}
	
	m68ki_cpu.v_flag &= res;
	m68ki_cpu.n_flag = res;
	
	res &= 0xff;
	m68ki_cpu.not_z_flag |= res;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}

private	function m68k_op_abcd_8_mm():void
{
	var src:uint = OPER_AY_PD_8();
	var ea:uint = (--(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 + 8]));
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = ((src) & 0x0f) + ((dst) & 0x0f) + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.v_flag = ~res;
	
	if(res > 9)
	{
		res += 6;
	}
	res += (src & 0xf0) + (dst & 0xf0);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res > 0x99) << 8;
	if(m68ki_cpu.c_flag)
	{
		res -= 0xa0;
	}
	
	m68ki_cpu.v_flag &= res;
	m68ki_cpu.n_flag = res;
	
	res &= 0xff;
	m68ki_cpu.not_z_flag |= res;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}

private	function m68k_op_add_8_er_d():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7] & 0xff;
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_ai():void
{
	var r_dst:uint = m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7];
	var src:uint = OPER_AY_AI_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_pi():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_PI_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_pi7():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_A7_PI_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_pd():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_PD_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_pd7():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_A7_PD_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_di():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_DI_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_ix():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_IX_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_aw():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AW_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_al():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AL_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_pcdi():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_PCDI_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_pcix():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_PCIX_8();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_er_i():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_d():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = (m68ki_cpu.dar[m68ki_cpu.ir & 7] & 0xffff);
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_a():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = (((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]) & 0xffff);
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_ai():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_AI_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_pi():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_PI_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_pd():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_PD_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_di():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_DI_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_ix():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_IX_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_aw():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AW_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_al():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AL_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_pcdi():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_PCDI_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_pcix():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_PCIX_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_16_er_i():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = m68ki_read_imm_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_d():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_a():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = (m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_ai():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_AI_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_pi():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_PI_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_pd():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_PD_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_di():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_DI_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_ix():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AY_IX_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_aw():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AW_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_al():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_AL_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_pcdi():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_PCDI_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_pcix():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = OPER_PCIX_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_32_er_i():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = m68ki_read_imm_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_add_8_re_ai():void
{
	var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_8_re_pi():void
{
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]++);
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_8_re_pi7():void
{
	var ea:uint = ((m68ki_cpu.dar[15]+=2)-2);
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_8_re_pd():void
{
	var ea:uint = (--(m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_8_re_pd7():void
{
	var ea:uint = (m68ki_cpu.dar[15]-=2);
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_8_re_di():void
{
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+(m68ki_read_imm_16() as int));
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_8_re_ix():void
{
	var ea:uint = m68ki_get_ea_ix((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_8_re_aw():void
{
	var ea:uint = m68ki_read_imm_16() as int;
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_8_re_al():void
{
	var ea:uint = m68ki_read_imm_32();
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xff);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}




private function m68k_op_add_16_re_ai():void
{
	var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_16_re_pi():void
{
	var ea:uint = (((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+=2)-2);
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_16_re_pd():void
{
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]-=2);
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_16_re_di():void
{
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+(m68ki_read_imm_16() as int));
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_16_re_ix():void
{
	var ea:uint = m68ki_get_ea_ix((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_16_re_aw():void
{
	var ea:uint = m68ki_read_imm_16() as int;
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_16_re_al():void
{
	var ea:uint = m68ki_read_imm_32();
	var src:uint = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7])) & 0xffff);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_32_re_ai():void
{
	var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
	var src:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_32_re_pi():void
{
	var ea:uint = (((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+=4)-4);
	var src:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_32_re_pd():void
{
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]-=4);
	var src:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_32_re_di():void
{
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+(m68ki_read_imm_16() as int));
	var src:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_32_re_ix():void
{
	var ea:uint = m68ki_get_ea_ix((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var src:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_32_re_aw():void
{
	var ea:uint = m68ki_read_imm_16() as int;
	var src:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_add_32_re_al():void
{
	var ea:uint = m68ki_read_imm_32();
	var src:uint = (m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_adda_16_d():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += m68ki_cpu.dar[m68ki_cpu.ir & 7] as int;
}

private function m68k_op_adda_16_a():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8] as int;
}

private function m68k_op_adda_16_ai():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AY_AI_16() as int;
}

private function m68k_op_adda_16_pi():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AY_PI_16() as int;
}

private function m68k_op_adda_16_pd():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AY_PD_16() as int;
}

private function m68k_op_adda_16_di():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AY_DI_16() as int;
}

private function m68k_op_adda_16_ix():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AY_IX_16() as int;
}

private function m68k_op_adda_16_aw():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AW_16() as int;
}

private function m68k_op_adda_16_al():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AL_16() as int;
}

private function m68k_op_adda_16_pcdi():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_PCDI_16() as int;
}

private function m68k_op_adda_16_pcix():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_PCIX_16() as int;
}

private function m68k_op_adda_16_i():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += m68ki_read_imm_16() as int;
}

private function m68k_op_adda_32_d():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += m68ki_cpu.dar[m68ki_cpu.ir & 7];
}

private function m68k_op_adda_32_a():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
}

private function m68k_op_adda_32_ai():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AY_AI_32();
}

private function m68k_op_adda_32_pi():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AY_PI_32();
}

private function m68k_op_adda_32_pd():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AY_PD_32();
}

private function m68k_op_adda_32_di():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AY_DI_32();
}

private function m68k_op_adda_32_ix():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AY_IX_32();
}

private function m68k_op_adda_32_aw():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AW_32();
}

private function m68k_op_adda_32_al():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_AL_32();
}

private function m68k_op_adda_32_pcdi():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_PCDI_32();
}

private function m68k_op_adda_32_pcix():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += OPER_PCIX_32();
}

private function m68k_op_adda_32_i():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7 + 8;
	m68ki_cpu.dar[r_dst] += m68ki_read_imm_32();
}

private function m68k_op_addi_8_d():void
{
	var r_dst:uint = m68ki_cpu.ir & 7;
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_addi_8_ai():void
{
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_8_pi():void
{
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]++);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_8_pi7():void
{
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var ea:uint = ((m68ki_cpu.dar[15]+=2)-2);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_8_pd():void
{
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var ea:uint = (--(m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_8_pd7():void
{
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var ea:uint = (m68ki_cpu.dar[15]-=2);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}
private function m68k_op_addi_8_di():void
{
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8])+(m68ki_read_imm_16() as int));
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}
private function m68k_op_addi_8_ix():void
{
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var ea:uint = m68ki_get_ea_ix((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}
private function m68k_op_addi_8_aw():void
{
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var ea:uint = m68ki_read_imm_16() as int;
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}
private function m68k_op_addi_8_al():void
{
	var src:uint = (m68ki_read_imm_16() & 0xff);
	var ea:uint = m68ki_read_imm_32();
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_16_d():void
{
	var r_dst:uint = m68ki_cpu.ir & 7;
	var src:uint = m68ki_read_imm_16();
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_addi_16_ai():void
{
	var src:uint = m68ki_read_imm_16();
	var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_16_pi():void
{
	var src:uint = m68ki_read_imm_16();
	var ea:uint = (((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+=2)-2);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_16_pd():void
{
	var src:uint = m68ki_read_imm_16();
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]-=2);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_16_di():void
{
	var src:uint = m68ki_read_imm_16();
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+(m68ki_read_imm_16() as int));
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_16_ix():void
{
	var src:uint = m68ki_read_imm_16();
	var ea:uint = m68ki_get_ea_ix((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_16_aw():void
{
	var src:uint = m68ki_read_imm_16();
	var ea:uint = m68ki_read_imm_16() as int;
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_16_al():void
{
	var src:uint = m68ki_read_imm_16();
	var ea:uint = m68ki_read_imm_32();
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_32_d():void
{
	var r_dst:uint = m68ki_cpu.ir & 7;
	var r_dst:uint = m68ki_cpu.ir & 7;
	var src:uint = m68ki_read_imm_32();
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_addi_32_ai():void
{
	var src:uint = m68ki_read_imm_32();
	var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_32_pi():void
{
	var src:uint = m68ki_read_imm_32();
	var ea:uint = (((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+=4)-4);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_32_pd():void
{
	var src:uint = m68ki_read_imm_32();
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]-=4);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_32_di():void
{
	var src:uint = m68ki_read_imm_32();
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+(m68ki_read_imm_16() as int));
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_32_ix():void
{
	var src:uint = m68ki_read_imm_32();
	var ea:uint = m68ki_get_ea_ix((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_32_aw():void
{
	var src:uint = m68ki_read_imm_32();
	var ea:uint = m68ki_read_imm_16() as int;
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addi_32_al():void
{
	var src:uint = m68ki_read_imm_32();
	var ea:uint = m68ki_read_imm_32();
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_8_d():void
{
	var r_dst:uint = m68ki_cpu.ir & 7;
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_addq_8_ai():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_8_pi():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]++);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_8_pi7():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = ((m68ki_cpu.dar[15]+=2)-2);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_8_pd():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = (--(m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_8_pd7():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = (m68ki_cpu.dar[15]-=2);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_8_di():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+(m68ki_read_imm_16() as int));
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_8_ix():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_get_ea_ix((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_8_aw():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_read_imm_16() as int;
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_8_al():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_read_imm_32();
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	m68ki_cpu.not_z_flag = res & 0xff;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}
private function m68k_op_addq_16_d():void
{
	var r_dst:uint = m68ki_cpu.ir & 7;
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_cpu.dar[r_dst] = (dst & ~0xffff) | m68ki_cpu.not_z_flag;
}

private function m68k_op_addq_16_a():void
{
	var r_dst:uint = m68ki_cpu.ir & 7 + 8;
	m68ki_cpu.dar[r_dst] += ((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
}

private function m68k_op_addq_16_ai():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_16_pi():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = (((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+=2)-2);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_16_pd():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]-=2);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_16_di():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+(m68ki_read_imm_16() as int));
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_16_ix():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_get_ea_ix((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_16_aw():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_read_imm_16() as int;
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_16_al():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_read_imm_32();
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	m68ki_cpu.not_z_flag = ((res) & 0xffff);
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_32_d():void
{
	var r_dst:uint = m68ki_cpu.ir & 7;
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var dst:uint = *r_dst;
	var res:uint = src + dst;
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_cpu.dar[r_dst] = m68ki_cpu.not_z_flag;
}

private function m68k_op_addq_32_a():void
{
	var r_dst:uint = m68ki_cpu.ir & 7 + 8;
	m68ki_cpu.dar[r_dst] += ((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
}

private function m68k_op_addq_32_ai():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8];
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_32_pi():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = (((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+=4)-4);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_32_pd():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]-=4);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_32_di():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = ((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]+(m68ki_read_imm_16() as int));
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_32_ix():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_get_ea_ix((m68ki_cpu.dar[m68ki_cpu.ir & 7 + 8]);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_32_aw():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_read_imm_16() as int;
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addq_32_al():void
{
	var src:uint = (((m68ki_cpu.ir >> 9) - 1) & 7) + 1;
	var ea:uint = m68ki_read_imm_32();
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst;
	
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	m68ki_cpu.not_z_flag = res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, m68ki_cpu.not_z_flag);
}

private function m68k_op_addx_8_rr():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xff);
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xff;
	var res:uint = src + dst + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	
	res &= 0xff;
	m68ki_cpu.not_z_flag |= res;
	
	m68ki_cpu.dar[r_dst] = 
	*r_dst = ((*r_dst) & ~0xff) | res;
}

private function m68k_op_addx_16_rr():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = (((m68ki_cpu.dar[m68ki_cpu.ir & 7])) & 0xffff);
	var dst:uint = m68ki_cpu.dar[r_dst] & 0xffff;
	var res:uint = src + dst + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	
	res = ((res) & 0xffff);
	m68ki_cpu.not_z_flag |= res;
	
	*r_dst = ((*r_dst) & ~0xffff) | res;
}

private function m68k_op_addx_32_rr():void
{
	var r_dst:uint = (m68ki_cpu.ir >> 9) & 7;
	var src:uint = (m68ki_cpu.dar[m68ki_cpu.ir & 7]);
	var dst:uint = *r_dst;
	var res:uint = src + dst + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	
	
	m68ki_cpu.not_z_flag |= res;
	
	*r_dst = res;
}

private function m68k_op_addx_8_mm_ax7():void
{
	var src:uint = OPER_AY_PD_8();
	var ea:uint = (m68ki_cpu.dar[15]-=2);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	
	res &= 0xff;
	m68ki_cpu.not_z_flag |= res;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}

private function m68k_op_addx_8_mm_ay7():void
{
	var src:uint = OPER_A7_PD_8();
	var ea:uint = (--(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 +8 ]));
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	
	res &= 0xff;
	m68ki_cpu.not_z_flag |= res;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}

private function m68k_op_addx_8_mm_axy7():void
{
	var src:uint = OPER_A7_PD_8();
	var ea:uint = (m68ki_cpu.dar[15]-=2);
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	
	res &= 0xff;
	m68ki_cpu.not_z_flag |= res;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}

private function m68k_op_addx_8_mm():void
{
	var src:uint = OPER_AY_PD_8();
	var ea:uint = (--(m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 +8 ]));
	var dst:uint = m68ki_read_8_fc (ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.n_flag = res;
	m68ki_cpu.v_flag = ((src^res) & (dst^res));
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = res;
	
	res &= 0xff;
	m68ki_cpu.not_z_flag |= res;
	
	m68ki_write_8_fc (ea, m68ki_cpu.s_flag | 1, res);
}

private function m68k_op_addx_16_mm():void
{
	var src:uint = OPER_AY_PD_16();
	var ea:uint = ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 +8 ])-=2);
	var dst:uint = m68ki_read_16_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.n_flag = (res>>8);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>8);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (res>>8);
	
	res = ((res) & 0xffff);
	m68ki_cpu.not_z_flag |= res;
	
	m68ki_write_16_fc(ea, m68ki_cpu.s_flag | 1, res);
}

private function m68k_op_addx_32_mm():void
{
	var src:uint = OPER_AY_PD_32();
	var ea:uint = ((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7 +8 ])-=4);
	var dst:uint = m68ki_read_32_fc(ea, m68ki_cpu.s_flag | 1);
	var res:uint = src + dst + ((m68ki_cpu.x_flag>>8)&1);
	
	m68ki_cpu.n_flag = (res>>24);
	m68ki_cpu.v_flag = (((src^res) & (dst^res))>>24);
	m68ki_cpu.x_flag = m68ki_cpu.c_flag = (((src & dst) | (~res & (src | dst)))>>23);
	
	
	m68ki_cpu.not_z_flag |= res;
	
	m68ki_write_32_fc(ea, m68ki_cpu.s_flag | 1, res);
}

private function m68k_op_and_8_er_d():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= ((m68ki_cpu.dar[m68ki_cpu.ir & 7]) | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_ai():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_AI_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_pi():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_PI_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_pi7():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_A7_PI_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_pd():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_PD_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_pd7():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_A7_PD_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_di():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_DI_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_ix():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_IX_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_aw():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AW_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_al():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AL_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_pcdi():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_PCDI_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_pcix():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_PCIX_8() | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_8_er_i():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= ((m68ki_read_imm_16() & 0xff) | 0xffffff00)) & 0xff);
	
	m68ki_cpu.n_flag = (m68ki_cpu.not_z_flag);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_16_er_d():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= ((m68ki_cpu.dar[m68ki_cpu.ir & 7]) | 0xffff0000)) & 0xffff);
	
	m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_16_er_ai():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_AI_16() | 0xffff0000)) & 0xffff);
	
	m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_16_er_pi():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_PI_16() | 0xffff0000)) & 0xffff);
	
	m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_16_er_pd():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_PD_16() | 0xffff0000)) & 0xffff);
	
	m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_16_er_di():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_DI_16() | 0xffff0000)) & 0xffff);
	
	m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_16_er_ix():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AY_IX_16() | 0xffff0000)) & 0xffff);
	
	m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}

private function m68k_op_and_16_er_aw():void
{
	m68ki_cpu.not_z_flag = (((m68ki_cpu.dar[(m68ki_cpu.ir >> 9) & 7]) &= (OPER_AW_16() | 0xffff0000)) & 0xffff);
	
	m68ki_cpu.n_flag = ((m68ki_cpu.not_z_flag)>>8);
	m68ki_cpu.c_flag = 0;
	m68ki_cpu.v_flag = 0;
}
