#include "robin.h"
#include <xc.h>

void	inform(void)
{
	if (info & ENERGY_EV)
		led(ENERGY_EV);
	if (info & ENERGY_PP)
		led(ENERGY_PP);
	if (info & SOAP)
		led(SOAP);
	if (info & ENERGY_EV)
		bluetooth(ENERGY_EV);
	if (info & ENERGY_PP)
		bluetooth(ENERGY_PP);
	if (info & SOAP)
		blueooth(SOAP);
	if (info & ENERGY_EV)
		//security state
	info = 0;
}
