#include "robin.h"
#include <xc.h>

int	main(void)
{
	configure_all();
	while (1)
	{
		while (1)
		{
			ask_sensors();
			timer_check();
			if (user_water || user_soap)
				service();
			if (info)
				inform();
			if (!info && !user_water && !user_soap)
				break;
		}
		goto_sleep();
		flush_timer++;
		security_timer++;	
		comfort_timer++;
	}
	return (0);
}
