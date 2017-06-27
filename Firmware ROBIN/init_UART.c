#include "xc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#pragma config FNOSC = PRIPLL // oscillator selection bits --> primary oscillator
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
 
}
