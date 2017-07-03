#include "robin.h"
#include <xc.h>

void	open_EV(void)
{
	int	count;
	
	NSLEEP = 1;
	count = 0;
	while (count++ < 5000);
	PH = 1;
	EN = 1;
	count = 0;
	while (count++ < 10000);
	EN = 0;
	count = 0;
	NSLEEP = 0;
}
