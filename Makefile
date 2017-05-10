##
## Makefile for Makefile in /home/vic/Desktop/piscine/C/libmy_01
## 
## Made by AIZPURUA Victor Hugo
## Login   <aizpur_v@etna-alternance.net>
## 
## Started on  Sat Apr  1 07:46:15 2017 AIZPURUA Victor Hugo
## Last update Wed May 10 11:53:28 2017 AIZPURUA Victor Hugo
##

CC =            gcc
NAME =          sta
SRC =           introduction.c \
		get_creature.c \
		game_params.c \

OBJ =           $(SRC:%.c=%.o)
CFLAGS =        -W -Wall -ansi -ansi -pedantic -Llibmy_01 -I.
LDFLAGS =
RM =            rm -f


$(NAME):        $(OBJ)
		make -C libmy_01
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lmy
debug:          $(OBJ)
		$(CC) -g $(OBJ) -o $(NAME) $(CFLAGS)
all:            $(NAME)
clean:
		$(RM) $(OBJ)
fclean:         clean
		$(RM) $(NAME)
re:             fclean all

.PHONY:         all clean fclear re
