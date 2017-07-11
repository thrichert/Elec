#include "robin.h"
#include <xc.h>

void	close_PP(void)
{
	NSLEEP_PP = 1;
	delay_16ms();
	PH_PP = 0;
	EN_PP = 1;
	delay_16ms();
	EN_PP = 0;
	NSLEEP_PP = 0;
}
