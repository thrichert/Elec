/* 
 * File:   main_tp1.c
 * Author: bocal
 *
 * Created on April 1, 2017, 7:14 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "firmware1.h"
/*
 * 
 */
int main(void) {


    /*
     *      1/ Commande de la LED par le bouton (a.k.a Hello World!)
     *
     *   Une pression sur le bouton allume la led
     *   Une autre pression sur le bouton éteint la led
     *
     */
    u32 var = 0;
    // Button on RD8
    TRISDbits.TRISD8 = 1; // pin set as INPUT
    // LED RF1
    TRISFbits.TRISF1 = 0; // pin set as OUTPUT
    PORTFbits.RF1 = 0; // set pin level to LOW ==> led off;
    while(1)
    {
        if (!PORTDbits.RD8) // BUT is connected throught PULL_UP resistor ==> PORTDbits.RD8 = 1 (by default) ; 0 when pressed
        {
            if (!PORTFbits.RF1)
                PORTFbits.RF1 = 1;
            else
                PORTFbits.RF1 = 0;
            while (var < 0x88FF) // stupid temporisation 
                var++;
            var = 0;
        }
    }

/*
 *
 *       2/ Clignotement de la LED
 *
 *  La led clignotte au rythme d'un changement d'état par seconde (0.5Hz, 1s on/1s off).
 *  Une pression sur le bouton multiplie par deux le rythme de clignotement. Arrivé à 8Hz, une pression sur le bouton remet le rythme à 0.5Hz.
 *
 *  La "séquence" sera donc : 0.5Hz, 1Hz, 2Hz, 4Hz, 8hZ, 0.5Hz, 1Hz, ...
 *
 */

    return (EXIT_SUCCESS);
}

