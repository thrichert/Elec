#include "robin.h"
#include <xc.h>

void	open_EV(void)
{
	NSLEEP_EV = 1;
	delay_16ms();
	PH_EV = 1;
	EN_EV = 1;
	delay_16ms();
	EN_EV = 0;
	NSLEEP_EV = 0;
}
