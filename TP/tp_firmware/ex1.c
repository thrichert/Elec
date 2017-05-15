/* 
 * File:   main.c
 * Author: bocal
 *
 * Created on April 3, 2017, 2:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "header.h"

/*
 * 
 */

int main(int argc, char** argv) {

    u32		exclusion = 0;

    TRISFbits.TRISF1 = OUTPUT;
    TRISDbits.TRISD8 = INPUT;
    LATFbits.LATF1 = LOW;

    while (1)
    {
	if (!PORTDbits.RD8 && !exclusion)
	{
	    LATFbits.LATF1 = HIGH;
	    while (!PORTDbits.RD8)
		exclusion = TRUE;
	}
	if (!PORTDbits.RD8 && exclusion)
	{
	    LATFbits.LATF1 = LOW;
	    while (!PORTDbits.RD8)
		exclusion = FALSE;
	}
    }
    return (EXIT_SUCCESS);


    

}
