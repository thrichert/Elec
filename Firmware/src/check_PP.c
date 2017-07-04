#include <xc.h>

char	check_PP(void)
{
	int	ADCValue;

	// Start Timer3
	T3CONbits.TON = 1;

	// Start ADC
	AD0CON1bits.ON = 1;

	// Start sampling
	AD0CON1bits.ASAM = 1;

	while (1)
	{
		// Check if ADC1 is interrupted
		while (!IFS1bits.AD1IF & 0x2){};
	
		// Get 1st word ADC1 buffer
		ADCValue = ADC0BUF0;
		if (ADC0BUF0)
	    		LATFbits.LATF1 = 1;
		// Clear AD1 interrupt flag
		IFS1bits.AD1IF = 0;
	}
	return (ADCValue);
}
