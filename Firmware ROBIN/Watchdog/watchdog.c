#include <xc.h>

/*void	ConfigureWatchdog(void)
{
	//check FWDTEN configuration bit, if it is set the WDT is always enabled
	if (DEVCFG1bits.FWDTEN != 1)
		WDTCONbits.ON = 1;
}

void	Delay_16ms(void)
{	

	//set WDT prescaler	
	DEVCFG1bits.WDTPS = 100;

	//choose idle as power saving mode
	OSCCONbits.SLPEN = 0;
	asm volatile ("wait");

 
int	other_main(void)
{
	int	timer;

	timer = 100000;
    LATFbits.LATF1 = 0;
	if (RCON & 0x14)
	{
		LATFbits.LATF1 = 1;
		asm volatile("eret");
	}
	TRISFbits.TRISF1 = 0;
    LATFbits.LATF1 = 1;
	ConfigureWatchdog();
	Delay_16ms();
    while (1);
}*/

/*void     Config(void)
{
    int     timer;
    
    timer = 100000;
    TRISFbits.TRISF1 = 0;
    LATFbits.LATF1 = 0;
    // sample code to determine the cause of a WDT event
    // Unlock the OSCCON register
    SYSKEY = 0x12345678; //write invalid key to force lock
    SYSKEY = 0xAA996655; //write Key1 to SYSKEY
    SYSKEY = 0x556699AA; //write Key2 to SYSKEY
    // OSCCON is now unlocked
    OSCCONSET = 0x10; // set power save mode to Sleep
    // Alternate relock code in ?C?
    SYSKEY = 0x0;
    // OSCCON is relocked
    WDTCONSET = 0x8000; //Enable WDT
    while (1)
    {
        WDTCONSET = 0x01; // service the WDT
        LATFbits.LATF1 = 1;
        asm volatile ("wait"); // put device into selected power save mode
        LATFbits.LATF1 = 0;
        break;
        // code execution will resume here after wake
    }
}*/

/*void    Config(void)
{
    // Enable WDT
//    WDTCONbits.ON = 1;
    DEVCFG1bits.WDTPS = 1010;
    
    
}*/

/*int     main(void)
{
    // The following code fragment is at the top of the device start-up code
    if ( RCON & 0x18 )
    {
        // The WDT caused a wake from sleep
        LATFbits.LATF1 = 1;
        asm volatile ("eret"); // return from interrupt
    }
    if ( RCON & 0x14 )
    {
        // The WDT caused a wake from idle
        LATFbits.LATF1 = 1;
        asm volatile ("eret"); // return from interrupt
    }
    if ( RCON & 0x10 )
    {
        LATFbits.LATF1 = 1;
        asm volatile ("eret");
    }
        // WDT timed-out
    Config();
    while (1);
}*/

#pragma config WDTPS = PS1024

int         main(void)
{
    int     timer;
    
    if (RCONbits.SLEEP)
    {
        TRISFbits.TRISF1 = 0;
        LATFbits.LATF1 = 1;
        asm volatile ("eret");
    }
    
    if (RCONbits.IDLE)
   {
//        TRISFbits.TRISF1 = 0;
        LATFbits.LATF1 = 1;
        asm volatile ("eret");
    }

    TRISFbits.TRISF1 = 0;
    LATFbits.LATF1 = 0;
    
    WDTCONbits.WDTCLR = 1;
    WDTCONbits.ON = 1;
    
    SYSKEY = 0;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
    
    OSCCONCLR = 0x10;
//    OSCCONSET = 0x10;
//    OSCCONbits.SLPEN = 1;
    
    SYSKEY = 0x0;
    asm volatile ("wait");
    while (1);
}