#include "robin.h"
#include <xc.h>

void	timer_check(void)
{
	if (flush_timer > 172800)
		user_water = 1;
	if (security_timer > 600)
		security_state = 1;
	if (comfort_timer >= 6 && !eau_user)
	{
		close_EV();
		comfort_timer = 0;
	}
}
