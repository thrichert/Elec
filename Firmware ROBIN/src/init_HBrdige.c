#include <xc.h>
#include "robin.h"

#define NSLEEP_CONFIG   TRISEbits.TRISE1
#define PH_CONFIG       TRISEbits.TRISE2
#define EN_CONFIG       TRISEbits.TRISE3

void	init_HBridge(void)
{
    NSLEEP_CONFIG = 0;
    PH_CONFIG = 0;
    EN_CONFIG = 0;
}
