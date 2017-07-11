#include "robin.h"
#include <xc.h>

// authorize WDT
#pragma	config WDTCONT = ON
#pragma config WDTPS = PS1024

// setting SYSCLK and PBCLK ?
#pragma config POSCMOD = EC

#pragma config FNOSC = PRIPLL // oscillator selection bits --> primary oscillator
#pragma config FPBDIV = DIV_1  

//set Primary oscillator on external clock
#pragma config POSCMOD = EC

// set SYSCLK on Primary oscillator without Phase-Locked Loop
#pragma config FNOSC = PRI

// set PBCLK on SYSCLK divided by 2
#pragma config FPBDIV = DIV_2



//

