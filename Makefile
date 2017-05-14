##
## Makefile for Makefile in /home/vic/Desktop/piscine/C/libmy_01
## 
## Made by AIZPURUA Victor Hugo
## Login   <aizpur_v@etna-alternance.net>
## 	
## Started on  Sat Apr  1 07:46:15 2017 AIZPURUA Victor Hugo
CC =            gcc
NAME =          sta
SRC =           main.c			\
		get_creature.c		\
		my_string.c		\
		game_params.c		\
		prompt_introduction.c	\
		readline.c		\
		prompt_oob.c		\
		prompt_oob_2.c		\
		prompt_shop.c		\
		prompt_fight.c		\
		prompt_fight_2.c 	\
		enemy.c			\
		destroy_creatures.c	\
		print_utils.c		\
		suplem_funtions.c	

OBJ =		$(SRC:%.c=%.o)
CFLAGS =	-W -Wall -Wextra -Werror -ansi -ansi -pedantic -g -Llibmy_01 -I.
LDFLAGS =
RM =		rm -f


$(NAME):	$(OBJ)
		make -C libmy_01
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lmy
debug:		CFLAGS += -g
debug:		$(OBJ)
		$(CC) -g $(OBJ) -o $(NAME) $(CFLAGS)
all:		$(NAME)
clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)
re:		fclean all

.PHONY:		all clean fclear re
