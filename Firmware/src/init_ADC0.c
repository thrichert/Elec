#include <xc.h>
#include "robin.h"

void    init_ADC0(void)
{
	//doubt

	// Configure PORT B as ANALOG
	AD0PCFGbits.PCFG2 = 0;

	// Set Timer3 period as conversion start
	AD0CON1bits.SSRC = 10;

	// Configure RB3 as SHA input
	AD0CHSbits.CH0SA = 101;

	// Configure no ANx for input scan
	AD0CSSLbits.CSSL = 0;

	// Set TAD as internal TPB * 2
	AD0CON3bits.ADCS = 0;

	// Set interrupt after 2 conversions
	AD0CON2bits.SMPI = 1;
}
