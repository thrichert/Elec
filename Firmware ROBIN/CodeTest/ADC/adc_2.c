
#include <xc.h>

int     ADC_buf;

/*void ConfigureADC(void)
{
    // Configure LED as OUTPUT
    TRISFbits.TRISF1 = 0;
    
    //Set LED at LOW
    LATFbits.LATF1 = 0;
    
    // Configure ACDC as INPUT
    TRISBbits.TRISB2 = 1;
    
    //Configure PORT as DIGITAL
    AD1PCFGbits.PCFG2 = 1;
    
    // Set RB2 as positive input via MUX A
    AD1CHSbits.CH0SA2 = 1;
        
    // Configure output as INTEGER 32-bit
    AD1CON1bits.FORM = 100;
    
    // Auto convert trigger source selects bits
    AD1CON1bits.SSRC = 111;

    // Configure INTERNAL references for VOLTAGE
    AD1CON2bits.VCFG = 001;

    // Disable SCAN mode
    AD1CON2bits.CSCNA = 0;

    // Configure interrupt after ONE sample/convert sequence
    AD1CON2bits.SMPI = 0;

    // Configure buffer as one-16 word buffer
    AD1CON2bits.BUFM = 0;

    // Configure MUX A as input multiplexer
    AD1CON2bits.ALTS = 0;

    // Set AN0 as MUX A positive input and AN1 as MUX A negative input
    AD1CHSbits.CH0NA = 0;
    AD1CHSbits.CH0SA = 0;

    // Configure TAD as period of oscillator
    AD1CON3bits.ADRC = 1;

    // Set Auto-Sample Time as 31 TAD
    AD1CON3bits.SAMC = 11111;

    // Suspend module operation when Idle Mode
    AD1CON1bits.SIDL = 1;

    // Turning ON the ADC
    AD1CON1bits.ON = 1;

    // Configure Interrupt (priority, flag, enable)
    IPC6bits.AD1IP = 111;
    IPC6bits.AD1IS = 111;

    IFS1bits.AD1IF = 0;
    IEC1bits.AD1IE = 1;

    //Start in Auto-Sample Mode
    AD1CON1bits.ASAM = 1;
}
*/

void    ConfigureADC(void)
{
    //RB2 as ANALOG
    AD1PCFG = 0xFFFB;
    // Auto-triggering acquisition to converting transition
    AD1CON1 = 0x00E0;
    // RB2/AN2 as CH0 input
    AD1CHS = 0x00020000;

    //Sample time = 2 TAD
    AD1CSSL = 0;
    AD1CON3 = 0x0203;

    //select external VREF+ and VREF- pins
    AD1CON2 = 0x6004;

    // Configure Interrupt (priority, flag, enable)
    IPC6bits.AD1IP = 111;
    IPC6bits.AD1IS = 111;

    IFS1bits.AD1IF = 0;
    IEC1bits.AD1IE = 1;

    //turn ON
    AD1CON1bits.ADON = 1;
}

void    __attribute__((vector(27), interupt(IPL1AUTO))) ADC_Handler(void)
{
    LATFbits.LATF1 = 1;
//    ADC_buf = ADC1BUF0;
    IFS1bits.AD1IF = 0;
}

/*
int     main(void)
{
    TRISFbits.TRISF1 = 0;
    LATFbits.LATF1 = 0;

    __builtin_disable_interrupts();
    ConfigureADC();
    __builtin_enable_interrupts();
    while (1);
}*/