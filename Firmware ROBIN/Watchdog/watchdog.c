void	ConfigureWatchdog(void)
{
	//check FWDTEN configuration bit, if it is set the WDT is always enabled
	if (DEVCFG1bits.FWDEN != 1)
		WDTCONbits.ON = 1;
}

void	Delay_16ms(void)
{	

	//set WDT prescaler	
	DEVCFG1bits.WDTPS = 100;

	//choose idle as power saving mode
	OSCONbits.SLPEN = 0;
	asm volatile ("wait");
}

/* in main
**	if (RCON & 0x14)
**		asm volatile("eret");		
**
