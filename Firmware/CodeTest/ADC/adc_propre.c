#include <xc.h>

int     ADCValue;

int main()
{
   TRISFbits.TRISF1 = 0;
    LATFbits.LATF1 = 0;
    __builtin_disable_interrupts();
    Configure_ADC();
    __builtin_enable_interrupts();
}

void    Configure_ADC(void)
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

}
