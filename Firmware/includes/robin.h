#ifndef ROBIN_H
# define ROBIN_H

#define NSLEEP_EV		LATEbits.LATE0
#define PH_EV			LATEbits.LATE1
#define EN_EV			LATEbits.LATE2

#define NSLEEP_PP		LATEbits.LATE3
#define PH_PP			LATEbits.LATE4
#define EN_PP			LATEbits.LATE5

#define NSLEEP_EV_CONFIG	TRISEbits.TRISE0
#define PH_EV_CONFIG		TRISEbits.TRISE1
#define EN_EV_CONFIG		TRISEbits.TRISE2

#define NSLEEP_PP_CONFIG	TRISEbits.TRISE3
#define PH_PP_CONFIG		TRISEbits.TRISE4
#define EN_PP_CONFIG		TRISEbits.TRISE5

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
void	init_EV(void);
void	init_PP(void);
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
