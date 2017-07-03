#include <xc.h>

int     ADCValue;

void    ConfigureADC(void)
{
    AD1PCFG = 0xFFFB; // all PORTB = Digital; RB2 analog
 AD1CON1 = 0x0040; // SSRC bit = 010 implies GP TMR3
// compare ends sampling and starts
// converting.
 AD1CHS = 0x00020000; // Connect RB2/AN2 as CH0 input
// in this example RB2/AN2 is the input
 AD1CSSL = 0;
 AD1CON3 = 0x0000; // Sample time is TMR3, TAD = internal TPB * 2
 AD1CON2 = 0x0004; // Interrupt after 2 conversions
 // set TMR3 to time out every 125 ms
 TMR3= 0;
 PR3= 62499;
 T3CON = 0x8010;
 AD1CON1SET = 0x8000; // turn ON the ADC
 AD1CON1SET = 0x0004; // start auto sampling every 125 mSecs
 while (1) // repeat continuously
 {
     while (!IFS1 & 0x0002){}; // conversion done?
     ADCValue = ADC1BUF0; // yes then get first ADC value
     if (ADC1BUF0)
         LATFbits.LATF1 = 1;
     IFS1CLR = 0x0002; // clear ADIF
     //LATFbits.LATF1 = 0;
 } // repeat
}

int main()
{
   TRISFbits.TRISF1 = 0;
    LATFbits.LATF1 = 0;
    __builtin_disable_interrupts();
    ConfigureADC();
    __builtin_enable_interrupts();
}

