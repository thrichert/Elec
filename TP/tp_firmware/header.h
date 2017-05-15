/* 
 * File:   header.h
 * Author: bocal
 *
 * Created on April 3, 2017, 2:05 PM
 */

#ifndef HEADER_H
#define	HEADER_H

typedef unsigned char	u8;
typedef unsigned short	u16;
typedef unsigned int	u32;

typedef signed char	s8;
typedef signed short	s16;
typedef signed int	s32;

typedef enum	e_bool
{
	FALSE,
	TRUE
}		t_bool;

typedef enum	e_io
{
	OUTPUT,
	INPUT
}		t_io;

typedef enum	e_state
{
	LOW,
	HIGH
};


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* HEADER_H */

