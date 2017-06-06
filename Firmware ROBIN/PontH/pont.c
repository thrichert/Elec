void	ConfigureHBridge(void)
{
	TRISRbits.TRIS1 = 1;
	TRISRbits.TRIS2 = 1;
}

void	OpenEV(void)
{
	//reverse EV
	LATRbits.LAT1 = 0;
	LATRbits.LAT2 = 1;
	Delay_16ms();
	LATRbits.LAT1 = 0;
	LATRbits.LAT2 = 0;

//	PH = 1;
//	EN = 1;
//	Wait();
//	PH = 0;
//	EN = 0;
}

void	CloseEV(void)
{
	//forward EV
	LAT1bits.LAT1 = 1:
	LAT2bits.LAT2 = 1;
	Delay_16ms();
	LAT1bits.LAT1 = 0;
	LAT2bits.LAT2 = 0;

//	PH = 1; //reverse
//	EN = 0; 
//	Wait();
//	PH = 0;
//	EN = 0;
}

int	main(void)
{
	while (1)
	{
		if (flag_user_eau == 1 || DFT > 86400)
		{
			if (!EV)
				OpenEV();
			StartComfortTimer();
			StartSecurityTimer();	
		}
		if (flag_user_eau == 0 && (flag_comfort_timer == 1 
			|| flag_security_timer == 1 || user_soap == 1))
		{
			CloseEV();
			StartDFtimer();
		}
	}
}
