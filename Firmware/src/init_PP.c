#include <xc.h>
#include "robin.h"

void	init_PP(void)
{
    NSLEEP_PP_CONFIG = 0;
    PH_PP_CONFIG = 0;
    EN_PP_CONFIG = 0;
}
