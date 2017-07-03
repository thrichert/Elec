#ifndef ROBIN_H
# define ROBIN_H


char	user_water;
char	user_soap;

int	security_timer;
int	comfort_timer;
int	flush_timer;

char	security_state;
char	info;


void	init_ADC();
void	init_HBridge();
void	init_UART();	

void	configure_all(void);
void	timer_check(void);
void	ask_sensors(void);
void	service(void);
void	inform(void);
void	soap(void);
char	check_soap(void);
void	water(void);
void	led(char *msg);
void	bluetooth(char *msg);
void	goto_sleep(void);

#endif
