# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 00:35:24 by ariard            #+#    #+#              #
#    Updated: 2017/06/23 17:08:43 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	firmware		

CC		=	gcc
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g
D_FLAGS		=	

DELTA		=	$$(echo "$$(tput cols)-47"|bc)


LIBS		=	
SRC_DIR		=	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SERV_OBJ	=	$(OBJ_DIR)server.o
CLI_OBJ		=	$(OBJ_DIR)cli/client.o

SRC_BASE	=	\
ask_sensors.c\
check_soap.c\
config.c\
configure_all.c\
goto_sleep.c\
inform.c\
init_ADC.c\
init_HBrdige.c\
init_I2C.c\
init_UART.c\
init_WDT.c\
main.c\
service.c\
soap.c\
timer_check.c\
water.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
OBJS		:=	$(filter-out $(SERV_OBJ), $(OBJS))
OBJS		:=	$(filter-out $(CLI_OBJ), $(OBJS))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all :
	@make -j $(NAME)

firmware : $(OBJ_DIR) $(OBJS) $(SERV_OBJ)
	@ $(CC) $(OBJS) -o $@ \
		-I $(INC_DIR) \
		$(LIBS) $(SERV_OBJ) $(FLAGS)
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $@ \033[0m\033[K\n"


$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) $(D_FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)\

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@printf "\r\033[38;5;202m✖ clean $(NAME).\033[0m\033[K\n"


fclean:			clean fcleanlib
	@rm -f $(NAME)
	@printf "\r\033[38;5;196m❌ fclean $(NAME).\033[0m\033[K\n"


re:				fclean all

.PHONY :		fclean clean re 

-include $(OBJS:.o=.d)
