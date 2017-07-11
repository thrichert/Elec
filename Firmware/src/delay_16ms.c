#include "robin.h"
#include <xc.h>

void	delay_16ms(void)
{
	T2CONbits.ON = 1;
	while (TMR2 <= PR2){};
	T2CONbits.ON = 0;
	TMR2 = 0;
}
