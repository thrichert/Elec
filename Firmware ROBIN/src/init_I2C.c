#include "robin.h"
#include <xc.h>

void init_i2c(void)
{
	//Clean interrupt flag for I2C Master Event
	IFS1bits.I2C2MIF = 0;

	//Set priority
    	IPC8bits.I2C2IP = 4;

	//Enable interrupt for I2C Master Event
    	IEC1bits.I2C2MIE = 1;
    
	// Set I2C baudrate to 100khz
    	I2C2BRG = 0x02f;
	
	// Enable clock stretching
	I2C2CONbits.STREN = 1; 

	// Enable receive
    	I2C2CONbits.RCEN = 1;

	//Enable I2C
    	I2C2CONbits.ON = 1; 
}
