#include "robin.h"
#include <xc.h>

void	inform(void)
{
	if (info & ENERGY)
		led(0);
	if (info & SOAP) 
		led(1);
	if (info & ENERGY)
		bluetooth(0);
	if (info & SOAP)
		bluetooth(1);
	if (info & ENERGY)
		//security state
	info = 0;
}
