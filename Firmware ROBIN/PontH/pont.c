void	ConfigureHBridge(void)
{
	TRISbits.TRIS = 1;
	TRISbits.TRIS = 1;
}

void	OpenEV(void)
{
	LATbits.LAT = 1;
	LATbits.LAT = 1;
	//SecondPinHigh
	//Watchdog
	LATbits.LAT = 0;
	LATbits.LAT = 0;

//	PH = 1;
//	EN = 1;
//	Wait();
//	PH = 0;
//	EN = 0;
}

void	CloseEV(void)
{
	LATbits.LAT = 1: //reverse
	LATbits.LAT = 0;
	//Watchdog
	LATbits.LAT = 0;
	LATbits.LAT = 0;

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
