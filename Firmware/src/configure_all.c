#include "robin.h"
#include <xc.h>

void	configure_all(void)
{
	init_ADC0();
	init_ADC1();
	init_UART();
	init_WDT();
	init_I2C();
	init_EV();
	init_PP();

	open_EV();
	close_EV();

	open_PP();
	close_PP();
	//sensor calibration
	
	user_water = 0;
	user_soap = 0;
	security_timer = 0;
	comfort_timer = 0;
	flush_timer = 0;
	security_state = 0;
	info = 0;
}
