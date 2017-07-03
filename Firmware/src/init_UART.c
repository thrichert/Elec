#include <xc.h>
#include "robin.h"

/* Calculate Baud Rate Config register */

#define PBUS_CLOCK	(8000000ul)
#define UBRG(baud) 	(((PBUS_CLOCK)/16/(baud)-1))
#define UART1_BAUD	9600

void	OpenUART(void)
{
	//Config UART format as 8 bit data no parity
	U1MODEbits.PDSEL = 1;

	//Enable receiver and transmitter
 	U1STAbits.URXEN = 1;               
	U1STAbits.UTXEN = 1;  

	// Config UART in High speed mode
	U1MODEbits.BRGH = 0;               

	//Configure Baud Rate
	U1BRG = UBRG(UART1_BAUD);          
}
