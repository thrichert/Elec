author: bocal
*
* Created on March 31, 2017, 6:06 PM
*/

#include <xc.h>

void timer2_init()
{
	//LATFbits.LATF1 = 0;
	T2CON = 0; // Stops the Timer2 and resets the control register
	TMR2 = 0;
	PR2 = 62500; //65535
	INTCON = 0;
	IEC0 = 0;
	T2CONbits.TCKPS = 4; // Set prescaler 1:4, internal clock, 16bits
	// 8Mhz / (4 x presc x 16bit) = 8Mhz/(4x16x0xFFFF)
	IPC2bits.T2IP = 1; // set priority
	IPC2bits.T2IS = 0; // set subpriority
	IFS0bits.T2IF = 0; //Clear the timer interrupt status flag
	IEC0bits.T2IE = 1; // enable interrupt control

	T2CONbits.ON = 1; // start timer
	INTCONbits.MVEC = 1; // multivector --> Interrupt controller configured for multi vectored mode
}

void button_init()
{
	IEC0bits.INT1IE = 0; // disable interrupt control
	//INTCONbits.INT1EP = 0;// clear the bit for falling edge trigger
	//IFS0bits.INT1IF = 0; //Clear the timer interrupt status flag
	IPC1bits.INT1IP = 1; // set priority
	IPC1bits.INT1IS = 0; // set subpriority
	IFS0bits.INT1IF = 0; //Clear the timer interrupt status flag
	IEC0bits.INT1IE = 1; // enable interrupt control

	//INTCONbits.MVEC = 1; // multivector --> Interrupt controller configured for multi vectored mode
}

void __attribute__((vector(_TIMER_2_VECTOR), interrupt(IPL1AUTO))) T2(void)
{
	LATFbits.LATF1 ^= 1;
	IFS0bits.T2IF = 0; // Clear the timer interrupt status flag
}

void __attribute__((vector(7), interrupt(IPL1AUTO))) B2(void)
{
	if (!PORTDbits.RD8 && PR2 >= 3906)
		PR2 /= 2;
	if (PR2 < 3905)
		PR2 = 62500;
	IFS0bits.INT1IF = 0; // Clear the timer interrupt status flag
	TMR2 = 0; //reset TMR2 pour eviter bug
}

int main(void) {

	TRISFbits.TRISF1 = 0;
	TRISDbits.TRISD8 = 1; // set button input -->  PORTDbits.RD8 = 1 (by default) et 0 when
	__builtin_disable_interrupts();
	timer2_init();
	button_init();
	__builtin_enable_interrupts();
	while (1);
}
