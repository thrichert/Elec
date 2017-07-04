#include "robin.h"
#include <xc.h>

void	init_WDT(void);
{
//    	pragma in "config.c"	
//    	WDTCONbits.ON = 1;
   
	//Unlock sequence to modify modeo on the fly
	SYSKEY = 0;
	SYSKEY = 0xAA996655;
	SYSKEY = 0x556699AA;

    	//Configure in Idle mode 
	OSCCON.SLPEN = 0;

	SYSKEY = 0x0;
}
