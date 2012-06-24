import flash.net.FileReference;

private	const OPT_OFF				:uint = 0;
private	const OPT_ON				:uint = 1;
private	const OPT_SPECIFY_HANDLER	:uint = 2;
private	var M68K_COMPILE_FOR_MAME 		:uint = OPT_OFF;
private	var M68K_EMULATE_010			:uint = OPT_OFF;
private	var M68K_EMULATE_EC020			:uint = OPT_OFF;
private	var M68K_EMULATE_020			:uint = OPT_OFF;
private	var M68K_SEPARATE_READS			:uint = OPT_OFF;
private	var M68K_SIMULATE_PD_WRITES		:uint = OPT_OFF;
private	var M68K_EMULATE_INT_ACK		:uint = OPT_OFF;
private	var	M68K_INT_ACK_CALLBACK		:Function;
private	var M68K_EMULATE_BKPT_ACK		:uint = OPT_OFF;
private	var M68K_BKPT_ACK_CALLBACK		:Function;
private	var M68K_EMULATE_TRACE			:uint = OPT_OFF;
private	var M68K_EMULATE_RESET			:uint = OPT_OFF;
private	var M68K_RESET_CALLBACK			:Function;
private	var M68K_EMULATE_FC				:uint = OPT_OFF;
private	var M68K_SET_FC_CALLBACK		:Function;
private	var M68K_MONITOR_PC				:uint = OPT_OFF;
private	var M68K_SET_PC_CALLBACK		:Function;
private	var M68K_INSTRUCTION_HOOK		:uint = OPT_OFF;
private	var M68K_INSTRUCTION_CALLBACK	:Function;
private	var M68K_EMULATE_PREFETCH		:uint = OPT_OFF;
private	var M68K_EMULATE_ADDRESS_ERROR	:uint = OPT_OFF;
private	var M68K_LOG_ENABLE				:uint = OPT_OFF;
private	var M68K_LOG_1010_1111			:uint = OPT_OFF;
private	var M68K_LOG_FILEHANDLE			:FileReference;
private	var M68K_USE_64_BIT				:uint = OPT_OFF;