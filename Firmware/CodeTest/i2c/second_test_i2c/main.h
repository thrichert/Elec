/* 
 * File:   main.h
 * Author: crh
 *
 * Created on May 29, 2017, 3:04 PM
 */

#ifndef MAIN_H
#define	MAIN_H


#define RED_LED 0x01;
#define GREEN_LED 0x04;
#define ORG_LED 0x02;

#define RED_LED_ON LATD |= RED_LED;
#define RED_LED_OFF LATD &=~ RED_LED;

#define GREEN_LED_ON LATD |= GREEN_LED;
#define GREEN_LED_OFF LATD &=~ GREEN_LED;

#define ORG_LED_ON LATD |= ORG_LED;
#define ORG_LED_OFF LATD &=~ ORG_LED;



typedef unsigned char   u8;
typedef char            s8;
typedef unsigned int    u16;
typedef int             s16;

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

