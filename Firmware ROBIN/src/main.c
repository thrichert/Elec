#include "robin.h"
#include <xc.h>

int	main(void)
{
	configure_all();
	while (1)
	{
		while (1)
		{
			timer_check();
			ask_sensors();
			if (user_water || user_soap)
				service();
			if (info)
				inform();
			if (!info && !user_water && !user_soap)
				break;
		}
		goto_sleep();
		flush_timer++:
		security_timer++;	
	}
	return (0);
}
