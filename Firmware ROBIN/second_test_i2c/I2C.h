/* 
 * File:   I2C.h
 * Author: crh
 *
 * Created on May 29, 2017, 1:02 PM
 */

#ifndef I2C_H
#define	I2C_H

#include "main.h"
#define I2C_BUFF_SIZE 16

enum i2c_states
{
    I2C_IDLE = 0,
    I2C_START,
    I2C_RESTART,
    I2C_STOP,    
    I2C_W_ADDR_R,
    I2C_W_ADDR_W,
    I2C_W_REG,
    I2C_W_BYTE,
    I2C_R_BYTE,
    I2C_WAIT,
    I2C_WRITE,
    I2C_READ,
    I2C_ACK,
    I2C_NACK,
    I2C_READ_ACK,
    I2C_READ_NACK,
};

typedef void (* i2c_read)(u8 *);

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

