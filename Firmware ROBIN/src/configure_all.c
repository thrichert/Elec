#include "robin.h"
#include <xc.h>

void	configure_all(void)
{
	init_ADC();
	init_UART();
	init_WDT()
	init_I2C()
	init_Hbridge();
	open_EV();
	close_EV();
	//sensor calibration
}
