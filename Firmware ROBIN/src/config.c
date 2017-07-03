#include <xc.h>

// authorize WDT
#pragma	config WDTCONT = ON
#pragma config WDTPS = PS1024

// setting SYSCLK and PBCLK ?
#pragma config POSCMOD = EC

#pragma config FNOSC = PRIPLL // oscillator selection bits --> primary oscillator
#pragma config FPBDIV = DIV_1  

//

