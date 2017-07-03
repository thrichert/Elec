/* 
 * File:   main.c
 * Author: crh
 *
 * Created on May 29, 2017, 1:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <proc/p32mx795f512l.h>
#include "I2C.h"
#include "main.h"
/*
 * 
 */

void config_io(void)
{
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    LATD = 0;
}

void config_perif(void)
{
    __asm("di");
    config_io();
    init_i2c();
    INTCONbits.MVEC = 1;
    __asm("ei");
}

int main(void) {
    config_perif();

    while (1)
    {

    }

    return (EXIT_SUCCESS);
}



