#ifndef ROBIN_H
# define ROBIN_H

# include <stdio.h>
# include <unistd.h>

int		intqueue[1000];

int		robin;

enum		e_robinstate
{
	READY = 0,
	BLUETOOTH,
	SENSOR_FP1,
	SENSOR_FP2,
	SENSOR_LEVEL,
	SENSOR_POWER,
	LED,
	END_ROBIN
};

typedef enum e_robinstate		t_robinstate;

enum	e_intflag
{
	EMPTY = 0,
	UART_RD,
	I2C_RD,
	END_INT,
};

typedef enum e_intflag			t_intflag;

struct s_input
{
	t_intflag	intflag;
	int		(*read)(void);
};

typedef struct s_input			t_input;

struct s_module
{
	t_robinstate	robinstate;
	void		(*module)();
};

typedef struct s_module			t_module;

int	read_i2c(void);
int	read_uart(void);
void	bluetooth(void);
void	sensor_fp1(void);
void	sensor_fp2(void);
void	sensor_level(void);
void	sensor_power(void);
void	led(void);

	
#endif
