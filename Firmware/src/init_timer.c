#include "robin.h"
#include <xc.h>

void	init_timer(void)
{
	T1CON = 0;
	TMR2 = 0;	
	PR2 = 62500;
}
