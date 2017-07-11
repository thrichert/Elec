#include "robin.h"
#include <xc.h>

void	open_PP(void)
{
	NSLEEP_PP = 1;
	delay_16ms();
	PH_PP = 1;
	EN_PP = 1;
	delay_16ms();
	EN_PP = 0;
	NSLEEP_PP = 0;
}
