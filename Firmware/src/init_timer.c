#include "robin.h"
#include <xc.h>

void	init_timer(void)
{
	T2CONbits.ON = 0;
	T2CONbits.T32 = 1;
	T2CONbits.TCS = 0;
	T2CONbits.TCKPS = 
	TMR2 = 0;
	PR2 = 62500;
}
