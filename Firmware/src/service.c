#include "robin.h"
#include <xc.h>

void	service(void)
{
	char	energy;
	char	soap;

	if (!security_timer)
		security_timer = 1;
	if (user_water && !(energy = check_EV))
	{
		comfort_timer = 0;
		open_EV();
	}
	else if (user_soap && !(energy = check_PP) && !(soap = check_soap))
	{
		close_EV();
		open_PP();
	}	
	else if (energy == ENERGY_EV)
		info |= ENERGY_EV;
	else if (energy == ENERGY_PP)
		info |= ENERGY_PP;
	else if (soap = SOAP)
		info |= SOAP;
}
