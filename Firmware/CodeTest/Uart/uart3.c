#include "xc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
void    ConfigOsc(void)
{
    OSCCONbits.PBDIV = 1;
    //set Primary Oscillator as default oscillator
    DEVCFG1bits.FNOSC = 1;
    // set Primary Oscillator mode
    DEVCFG1bits.POSCMOD = 1;
}
 */
#pragma config FNOSC = PRIPLL // oscillator selection bits --> primary oscillator
//#pragma config FPLLIDIV = DIV_2
#pragma config FPBDIV = DIV_1  

void	OpenUART(void)
{
    
#define PBUS_CLOCK   (8000000ul)
 
 // Macro to calculate Baud Rate config register value
 // Asumes that BRGH = 1 will be used
 #define UBRG(baud) (((PBUS_CLOCK)/16/(baud)-1))
 #define UART1_BAUD           9600
 // Configure & Initialize UART2
//U1BRG = 9600;
U1MODE = 0x8000; // enable UART for 8 bit data no parity 1 stop bit
U1STA = 0x1400; //enable transmit and receive

 //U1MODEbits.UARTEN = 1;             // Enable UART2, 8N1
 U1STAbits.URXEN = 1;               // Enable UART2 RX pin
 U1STAbits.UTXEN = 1;  
 //U1MODEbits.PDSEL = 0;
 //U1MODEbits.STSEL = 0;

// Enable UART2 TX pin
 U1MODEbits.BRGH = 0;               // Set High speed mode
 U1BRG = UBRG(UART1_BAUD);          // Configure Baud Rate
 
    /*
    OSCCONbits.PBDIV = 11;
	//set standard speed mode
	U1MODEbits.BRGH = 0;
	//configure Baud rate
	U1BRG = ((4000000/9600)/16) 

	// set data format as 8-bit data, no parity
	U1MODEbits.PDSEL = 0;
	// set 1 Stop bit
	U1MODEbits.STSEL = 0;

	//enable transmitter
	U1STAbits.UTXEN = 1;
	//clear interrupt transmit
	U1STAbits.UTXISEL = 10;

	//enable receiver
	U1STAbits.URXEN = 1;
	//clear interrupt receive
	U1STAbits.URXISEL = 10;

	// enable UART module
	U1MODEbits.ON = 1;
     */
}

int		WriteUART(char *buffer)
{
	int	i = 0;

	if (U1STAbits.UTXBF == 1)
		return 1;
	while (i++ < 8 && *buffer)
		U1TXREG = *buffer++;
}

char	ReadUART(char buffer[])
{
	int	i = 0;

	while (DataRdyUART())
		buffer[i++] = U1RXREG;
}

void		UARTSendBreak(void)
{
	if (U1STAbits.TRMT != 1)
		return (1);
	U1STAbits.UTXBRK = 1;
	U1TXREG = 0x10;
	U1TXREG = 0x50;
}

void		CloseUART(void)
{
	U1MODEbits.ON = 0;
}

int			DataRdyUART()
{
	if (U1STAbits.URXDA == 1)
		return (1);
}

int         main()
{
    char    *buffer = "123456789";
    
    TRISFbits.TRISF1 = 0;
    LATFbits.LATF1 = 1;
   // ConfigOsc();
    OpenUART();
    WriteUART(buffer);
    WriteUART(buffer);
    WriteUART(buffer);
    WriteUART(buffer);
    WriteUART(buffer);
    while (1){};
    return (0);
}
