#include <xc.h>
#include "robin.h"

void    init_ADC(void)
{
    // Configure PORT B as ANALOG
    AD1PCFGbits.PCFG2 = 0;

    // Set Timer3 period as conversion start
    AD1CON1bits.SSRC = 10;

    // Configure RB2 as SHA input
    AD1CHSbits.CH0SA = 100;

    // Configure no ANx for input scan
    AD1CSSLbits.CSSL = 0;

    // Set TAD as internal TPB * 2
    AD1CON3bits.ADCS = 0;

    // Set interrupt after 2 conversions
    AD1CON2bits.SMPI = 1;

    //Set TMR3 period to 125ms
    TMR3 = 0;
    PR3 = 62499;
    T3CONbits.TCKPS = 1;
}
