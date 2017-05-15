/* 
 * File:   main.c
 * Author: bocal
 *
 * Created on April 18, 2017, 3:33 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <math.h>
#include "header.h"


#define PI 3.141592
#define COUNTERMAX 300
/*
 * 
 */


void __attribute__((vector(_TIMER_2_VECTOR), interrupt(IPL1AUTO))) Timer2_Handler(void)
{
    LATFbits.LATF1 ^= 1;
    IFS0CLR = 0x0100;
    PR2++;
}

int main(void)
{
    s16     counter = 0;
    s16     reference;
    u8      exclusion = FALSE;

    TRISFbits.TRISF1 = OUTPUT;
    TRISDbits.TRISD8 = INPUT;
    LATFbits.LATF1 = LOW;

    T2CON = 0;
    TMR2 = 0;
    PR2 = 1;
    INTCON = 0;
    IEC0 = 0;

    T2CONbits.TCKPS = 0;
    IPC2bits.T2IP = 1;
    IPC2bits.T2IS = 0;
    IFS0bits.T2IF = 0; // set bits interrupt status flag to CLEAR
    IEC0bits.T2IE = 1; //set bits interrupt control to ON

    T2CONbits.ON = 1; //set bits timer to ON
    INTCONbits.MVEC = 1; //set bits multivector to ON


/*    while (1)
    {
        reference = 0.5 * COUNTERMAX*(1 - sin(PI/COUNTERMAX * counter - PI/2));
        if (counter >= reference)
            LATFbits.LATF1 ^= HIGH;

        if (counter <= 0)
            exclusion = FALSE;
        else if (counter >= COUNTERMAX)
            exclusion = TRUE;
     
        if (exclusion == TRUE)
            counter--;
        else if (exclusion == FALSE)
            counter++;
    }
*/    return (EXIT_SUCCESS);
}

