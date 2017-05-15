/* 
 * File:   main.c
 * Author: crh
 * 
 *  Board : PIC32 ETHERNET STARTUP KIT
 *  PIC32MX795F512L
 *
 * configuration primaire et test de l'i2c
 * 
 * Created on 1 avril 2017, 23:56
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

void mConfigI2C(void)
{
    I2C2BRG = 0x02F;
    I2C2CONbits.DISSLW = 1; 
    I2C2CONbits.STREN = 1;  
    I2C2CONbits.RCEN = 1;
    I2C2CONbits.ON = 1; 
}

void mStartI2C2(void)
{
    I2C2CONbits.SEN = 1;
    while(I2C2CONbits.SEN){}
}

void mAckI2C2(void)
{
    I2C2CONbits.ACKDT = 0;
    I2C2CONbits.ACKEN = 1;
    while(I2C2CONbits.ACKEN){} 
}

void mNAckI2C2(void)
{
    I2C2CONbits.ACKDT = 1;
    I2C2CONbits.ACKEN = 1;
    while(I2C2CONbits.ACKEN){} 
}

void mStopI2C2(void)
{
    I2C2CONbits.PEN = 1;
    while(I2C2CONbits.PEN){} 
}

char mWriteByteI2C2(char DOUT)
{
    //Load data into transmit register
    I2C2TRN=DOUT;
    while(I2C2STATbits.TRSTAT){}
    //Recover Ack/Nack
    if(I2C2STATbits.ACKSTAT == 1)
    {return(1);}
    else
    {return(0);}
    //return 1 for acked, 0 for nacked
}

char mReadByteI2C2(char ack)
{
    I2C2CONbits.RCEN = 1;
    while(I2C2CONbits.RCEN){}
    //Reception is started, send ack/nack after read
    if(ack == 0)
    {mNAckI2C2();}
    else
    {mAckI2C2();}
    //Reception should be complete - pull out data	
 	return(I2C2RCV);
}

int main(void) {

    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    unsigned char data = 0;

    LATD = 0x00;
    
    mConfigI2C();
    //i2c start
    mStartI2C2();
    //i2c write
    mWriteByteI2C2(0x52); // 0x052 = vl51l0x adresse [WRITE]
    mWriteByteI2C2(0xC0); // 0xC0 = original register value is 0xEE
    mStopI2C2();
    
    mStartI2C2();
    mWriteByteI2C2(0x53); // 0x053 = vl51l0x adresse [READ]
    data = mReadByteI2C2(1); // 1 : send an Ack 

    if (data == 0xEE)
    {
        LATD = 0x04; // green led
    }
    else
    {
        LATD = 0x01; // red led
    }
    while (1);
    return (EXIT_SUCCESS);
}

