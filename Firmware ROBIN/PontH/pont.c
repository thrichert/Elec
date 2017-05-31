void	ConfigurePontH(void)
{
	TRISxbits.TRISFx = 0;
	TRISxbits/TRISFx = 0;
}

void	Wakeup_Hbridge(void)
{
	;
}

void	Sleep_Hbridge(void)
{
	;
}

void	TransmitPulsation(void)
{
	CloseBridge;
	TimeMicroSecs;
	OpenBridge;
}
