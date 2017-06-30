#include "robin.h"

/*
** Finite-State-Machine to drive Robin modules :
**	- intqueue : FIFO structure of module interrupts
**	- robinstate : state with action to commit
*/

static t_input		g_input[] = 
{
	{I2C_RD, &read_i2c},
	{END_INT, NULL},
};

static	t_module	g_module[] =
{
	{BLUETOOTH, &bluetooth},
	{LED, &led},
	{END_ROBIN, NULL},
};


// Actions :
// - inform soap
// - inform elec
// - open/close pompe peristaltique
// - open/close EV
// - flash LED
@

int			main(void)
{

	//check for called by WDT interrupt

	if (RCON & 0x14)
		asm volatile("eret");

	int		i = -1;
	int		j;

	Configure_All();
	robin = READY;	
	intqueue[++i] = EMPTY;

	// init PIC32:
	//	- ADC
	//	- UART
	//	- I2C
	//	- WDT
	
	// init EV
	
	// check available module

	// init modules
	
	// sensor calibration	

	while (1)
	{
		while (intqueue[i] != EMPTY)
		{
			//intqueue to get robin state
	
			j = -1;
			while (g_input[++j].intflag != END_INT)
				if (intqueue[i] == g_input[j].intflag)
					robin = g_input[j].read();

			//action to commit

			intqueue[i--] = 0;
			j = -1;
			while (g_module[++j].robinstate != END_ROBIN)
				if (robin == g_module[j].robinstate)
					g_module[j].module();
		}
		// going to sleep
		sleep(1);
	}
	return (0);
}
