/* 
 * File:   I2C.c
 * Author: crh
 *
 * Created on May 29, 2017, 1:03 PM
 */

#include "I2C.h"
#include <sys/attribs.h>
#include <xc.h>
#include "main.h"
/*
 * 
 */

u8 i2c_state;                       //
u8 i2c_R_W;                         //
u8 i2c_read_buf[I2C_BUFF_SIZE] = {0};   //
u8 i2c_read_buf_index = 0;              //
u8 i2c_read_buf_size = 0;               //
u8 i2c_write_buf[I2C_BUFF_SIZE] = {0};  //
u8 i2c_write_buf_index = 0;             //
u8 i2c_write_buf_size = 0;              //


i2c_read_callback i2c_read_callback_fct = NULL;

void i2c_start(void)
{
    I2C2CONbits.SEN = 1;
}

void i2c_ack(void)
{
    I2C2CONbits.ACKDT = 0;
    I2C2CONbits.ACKEN = 1;
}

void i2c_nack(void)
{
    I2C2CONbits.ACKDT = 1;
    I2C2CONbits.ACKEN = 1;
}

void i2c_stop(void)
{
    I2C2CONbits.PEN = 1;
}

/* reset_i2c()
 *
 *  send 9 clock ticks to reset ships
 * /!\ this is valid for I2C2 only
 * Pins RF5 is used here
 * 
 * for I2C1 change for RG2
 */
void reset_i2c(void)
{
    u8   i;
    u16  cpt;
    
    TRISFbits.TRISF5 = 0x0;       // set as output
    i = 0;
    LATFbits.LATF5 = 0;            // set low
    while(i < 18)                 
    {
        LATFbits.LATF5 = !LATFbits.LATF5; // switch state
        ++i;
        cpt = 0;
        while (++cpt < 2000);
    }
}

void i2c_append(u8 data)
{
    i2c_write_buf[i2c_write_buf_index++] = data;
}

void i2c_write(u8 slave, u8 cmd, u8 *buf, u8 buf_size)
{
    u16 i;
    
    if (i2c_state == I2C_IDLE)
    {
        i2c_append(slave);
        i2c_append(cmd);
        if (buf && buf_size)
        {
            i = 0;
            while (i < buf_size)
                i2c_append(buf[i++]);
        }
        i2c_R_W = I2C_WRITE;
        i2c_state = I2C_WRITE;
        i2c_start();
    }
}

void init_i2c(void)
{
    IFS1bits.I2C2MIF = 0;   // reset flag
    IPC8bits.I2C2IP = 4;    // arbitraire
    IEC1bits.I2C2MIE = 1;   // interrupt enable 
    I2C2BRG = 0x02f;        // Baudrate 100khz
    I2C2CONbits.STREN = 1;  // clock stretch enable
    I2C2CONbits.RCEN = 1;   // receive enable
    I2C2CONbits.ON = 1;     // module online
    reset_i2c();
    i2c_state = I2C_IDLE;
}


/* i2c_w_sm()
 * i2c write state machine:
 *   load a byte to send through i2c2 perif (I2C2TRN register)
 *  - while in transmission ---> continue
 *  - when byte is transmit load another byte from buf
 *  - when all byte are transmit : send a stop condition.
 */

void i2c_w_sm(void)
{
    switch (i2c_state)
    {
        case I2C_WRITE: 
            if (I2C2STATbits.TRSTAT) // Master TRansmit in progress ..
                break ;              // continue...
            if (i2c_write_buf_index < i2c_write_buf_size)   // if data has to be send
                I2C2TRN = i2c_write_buf[i2c_write_buf_index++];  // load data in transmit register
            else
                i2c_state = I2C_STOP;
            break ;
        case I2C_STOP: // send a stop condition.
            i2c_stop();
            i2c_state = I2C_IDLE;
            // flush buf ?
            break ;
    }       
}

void i2c_read(u8 slave, u8 cmd, u8 buf_size, i2c_read_callback fct)
{
    i2c_append(slave);
    i2c_append(cmd);
    i2c_read_callback_fct = fct;
    i2c_R_W = I2C_READ;
    i2c_state = I2C_W_ADDR_W;
    i2c_read_buf_size = size;
    i2c_start();
 }

/* i2c_r_sm()
 * i2c read state machine:
 */

void i2c_r_sm()
{
    switch (i2c_state)
    {
        case I2C_W_ADDR_W:
            I2C2TRN = i2c_write_buf[0]; // send slave addr
            i2c_state = I2C_W_REG;
            break ;
        case I2C_W_REG:
            I2C2TRN = i2c_write_buf[1]; // send register to read;
            i2c_state = I2C_RESTART;
            break ;
        case I2C_RESTART:
            I2C2CONbits.RSEN = 1; // initialize restart condition
            i2c_state = I2C_W_ADDR_R;
            break ;
        case I2C_W_ADDR_R:
            I2C2TRN = i2c_write_buf[0] | 1; // set last bit to one [READING]
            i2c_state = I2C_R_BYTE;
            break ;
        case I2C_R_BYTE:
            if (i2c_read_buf_index < i2c_read_buf_size)
                i2c_state = I2C_READ_ACK;
            else
                i2c_state = I2C_READ_NACK;
            I2C2CONbits.RCEN = 1; // enable receive 
            break ;
        case I2C_READ_ACK:
            if (I2C2STATbits.RBF) // receive buffer full
            {
                i2c_read_buf[i2c_read_buf_index] = I2C2RCV;
                i2c_ack();
                i2c_state = I2C_R_BYTE;
            }
            break;
        case I2C_READ_NACK:
            if (I2C2STATbits.RBF) // receive buffer full
            {
                i2c_read_buf[i2c_read_buf_index] = I2C2RCV;
                i2c_nack();
                i2c_stop();
                i2c_write_buf_index = 0;
                i2c_write_buf_size = 0;
                i2c_read_buf_index = 0;
                i2c_read_buf_size = 0;
                i2c_state = I2C_CALLBACK_FCT;
            }
        case I2C_CALLBACK_FCT:
            if (i2c_read)
                (*i2c_read)(i2c_read_buf);
            i2c_read = NULL;
            i2c_state = I2C_IDLE;
            break ;
    }
}

void __ISR(_I2C_2_VECTOR, IPL4AUTO) I2C2_INT_Handler(void)
{
    IFS1bits.I2C2MIF = 0; // reset interrupt flag
    if (i2c_R_W == I2C_WRITE)
        i2c_w_sm(); // i2c write state machine
    else
        i2c_r_sm(); // i2c read state machine
}