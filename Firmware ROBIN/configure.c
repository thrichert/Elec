#include "robin.h"
#include <xc.h>

void	Configure_All(void)
{
	init_ADC();
	init_UART();
	init_WDT();
	init_I2C();
	init_HBridge();

	init_EV();

	// check available module
	
	if (flags & BLUETOOTH)
		init_BL();
	
	configure_sensor();
}
