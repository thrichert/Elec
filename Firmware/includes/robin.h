#ifndef ROBIN_H
# define ROBIN_H

#define NSLEEP		LATEbits.LATE1
#define PH		LATEbits.LATE2
#define EN		LATEbits.LATE3

#define	ENERGY_EV	1 << 0
#define ENERGY_PP	1 << 1
#define SOAP		1 << 2

char	user_water;
char	user_soap;

int	security_timer;
int	comfort_timer;
int	flush_timer;

char	security_state;
char	info;


void	init_ADC(void);
void	init_HBridge(void);
void	init_UART(void);
void	init_WDT(void);
void	init_I2C(void);

void	configure_all(void);
void	timer_check(void);
void	ask_sensors(void);
void	service(void);
void	inform(void);
void	led(char msg);
void	bluetooth(char msg);
void	goto_sleep(void);

char	check_soap(void);
char	check_PP(void);
void	open_PP(void);
void	close_PP(void);

char	check_EV(void);
void	open_EV(void);
void	close_EV(void);

#endif
