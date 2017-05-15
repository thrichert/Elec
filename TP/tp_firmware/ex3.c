/* 
 * File:   main.c
 * Author: bocal
 *
 * Created on April 13, 2017, 7:32 PM
 */

#include <xc.h>
#include <plib.h>


/*
 * 
 */

void    __attribute__((vector(_TIMER_2_VECTOR), interrupt(IPL1AUTO))) Timer2_Handler(void)
{
    LATFbits.LATF1 ^= 1;
    IFS0CLR = 0x0100;
}

void    __attribute__((vector(_OUTPUT_COMPARE_1_VECTOR), interrupt(IPL1AUTO))) PWM_Handler(void)
{
    LATFbits.LATF1 ^= 1;
    IFS0CLR = 0x0040;
}

void    timer2_init()
{
    T2CON = 0; //clean Timer 2 control register
    TMR2 = 0; // set Timer2 timer register to 0
    PR2 = 62500; //set Timer2 period register to 62500
    INTCON =0; // clean interrupt control register
    IEC0 = 0; // clean interrupt enable control register

    T2CONbits.TCKPS = 4; //set bits prescaler to 4
    IPC2bits.T2IP = 1; //set bits priority to 1
    IPC2bits.T2IS = 0; // set bits subpriority to 0
    IFS0bits.T2IF = 0; // set bits interrupt status flag to CLEAR
    IEC0bits.T2IE = 1; //set bits interrupt control to ON

    T2CONbits.ON = 1; //set bits timer to ON
    INTCONbits.MVEC = 1; //set bits multivector to ON
}

/*void    pwm_init()
{
    T2CONbits.ON = 0;
    TMR2 = 0;
    PR2 = 0x3003;
    INTCON = 0;
    IEC0 = 0;
    OC1CON = 0;

    OC1R = 0x3000;
    OC1RS =0x3003;

    OC1CONbits.OCM = 0b100;
    OC1CONbits.OCTSEL = 0;

    IFS0bits.OC1IF = 0;
    IPC1bits.OC1IP = 1;
    IPC1bits.OC1IS = 1;
    IEC0bits.OC1IE = 1;

    T2CONbits.ON = 1;
    OC1CONbits.ON = 1;
}*/

int main(int argc, char** argv) {

    TRISFbits.TRISF1 = 0;
    LATFbits.LATF1 = 0;
    TRISDbits.TRISD8 = 1;

    INTEnableSystemMultiVectoredInt();

    OC1CON = 0x0000;
    OC1R = 0x0064;
    OC1RS = 0x0064;
    OC1CON = 0x0006;

    PR2 = 0x00C7;

    IFS0CLR = 0x00000100;
    IEC0SET = 0x00000100;
    IPC2SET = 0x0000001C;

    T2CONSET = 0x8000;
    OC1CONSET = 0x8000;

    while (1);

    return (EXIT_SUCCESS);
    }