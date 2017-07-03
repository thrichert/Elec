#include <xc.h>

char	check_EV(void)
{
	int	ADCValue;

	// Start Timer3
	T3CONbits.TON = 1;

	// Start ADC
	AD1CON1bits.ON = 1;

	// Start sampling
	AD1CON1bits.ASAM = 1;

	while (1)
	{
		// Check if ADC1 is interrupted
		while (!IFS1bits.AD1IF & 0x2){};
	
		// Get 1st word ADC1 buffer
		ADCValue = ADC1BUF0;
		if (ADC1BUF0)
	    		LATFbits.LATF1 = 1;
		// Clear AD1 interrupt flag
		IFS1bits.AD1IF = 0;
	}
	return (ADCValue);
}
