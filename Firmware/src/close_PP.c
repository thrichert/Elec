#include "robin.h"
#include <xc.h>

void	close_PP(void)
{
	int count;

	NSLEEP_PP = 1;
	count = 0;
	while (count++ < 5000);
	PH_PP = 0;
	EN_PP = 1;
	count = 0;
	while(count++ < 10000);
	EN_PP = 0;
	count = 0;
	NSLEEP_PP = 0;
}
