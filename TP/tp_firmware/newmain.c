#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <math.h>
#include "header.h"

volatile s32 counter = 32000;
volatile s8 period = 0;

void timer3_init()
{
	T3CON = 0; // Stops the Timer2 and resets the control register
	TMR3 = 0;
	PR3 = 65535; //65535
	INTCON = 0;
	IEC0 = 0;
	T3CONbits.TCKPS = 0; // Set prescaler 1:4, internal clock, 16bits
	// 8Mhz / (4 x presc x 16bit) = 8Mhz/(4x16x0xFFFF)
	IPC3bits.T3IP = 2; // set priority
	IPC3bits.T3IS = 0; // set subpriority
	IFS0bits.T3IF = 0; //Clear the timer interrupt status flag
	IEC0bits.T3IE = 1; // enable interrupt control

        T3CONbits.ON = 1; // start timer
}

void __attribute__((vector(_TIMER_3_VECTOR), interrupt(IPL2AUTO))) T2(void)
{

    T2CON = 0;
    TMR2 = counter;

    if (counter >= 0)
        period = 0;
    else if (counter <= 0)
        period = 1;

    if (period == 0)
        counter -= 100;
    else if (period == 1)
        counter += 100;

    PR2 = 65535;
    INTCON = 0;
    IEC0 = 0;
    T2CONbits.TCKPS = 0;
    IPC2bits.T2IP = 3;
    IPC2bits.T2IS = 0;
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1;

    T2CONbits.ON = 1;

    IFS0bits.T3IF = 0;
}

void __attribute__((vector(_TIMER_2_VECTOR), interrupt(IPL3AUTO))) T3(void)
{
    LATFbits.LATF1 = 1;
    IFS0bits.T2IF = 0;
}
/*
void button_init()
{
	IEC0bits.INT1IE = 0; // disable interrupt control
	//INTCONbits.INT1EP = 0;// clear the bit for falling edge trigger
	//IFS0bits.INT1IF = 0; //Clear the timer interrupt status flag
	IPC1bits.INT1IP = 2; // set priority
	IPC1bits.INT1IS = 0; // set subpriority
	IFS0bits.INT1IF = 0; //Clear the timer interrupt status flag
	IEC0bits.INT1IE = 1; // enable interrupt control
}
*/

int main(void) {
        s16     counter = 0;
        s16     reference;
        u8      exclusion = FALSE;


	TRISFbits.TRISF1 = 0;
	TRISDbits.TRISD8 = 1; // set button input -->  PORTDbits.RD8 = 1 (by default) et 0 when
	__builtin_disable_interrupts();
//	button_init();
        timer3_init();
	INTCONbits.MVEC = 1; // multivector --> Interrupt controller configured for multi vectored mode
        __builtin_enable_interrupts();
        LATFbits.LATF1 = 0;
        while (1)
        {

        }
}