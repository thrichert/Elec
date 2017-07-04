#include "robin.h"
#include <xc.h>

void	close_EV(void)
{
	int	count;

	NSLEEP_EV = 1;
	count = 0;
	while (count++ < 5000);
	PH_EV = 0;
	EN_EV = 1;
	count = 0;
	while(count++ < 10000);
	EN_EV = 0;
	count = 0;
	NSLEEP_EV = 0;
}
