##
## Makefile for Makefile in /home/vic/Desktop/piscine/C/libmy_01
## 
## Made by AIZPURUA Victor Hugo
## Login   <aizpur_v@etna-alternance.net>
## 
## Started on  Sat Apr  1 07:46:15 2017 AIZPURUA Victor Hugo
## Last update Mon Apr 10 18:05:10 2017 AIZPURUA Victor Hugo
##

CC   = gcc
SRC  = my_putchar.c   \
       my_put_nbr.c   \
       my_getnbr.c    \
       my_putstr.c    \
       my_swap.c      \
       my_strlen.c    \
       my_strcpy.c    \
       my_strncpy.c   \
       my_strcmp.c    \
       my_strcat.c    \
       my_strncat.c   \
       my_strdup.c    

OBJ  = $(SRC:.c=.o)
RM   = rm -f
CFLAGS = -W -Wall -ansi -L. -pedantic -Werror -Wextra
LIB  = libmy.a


$(LIB):		$(OBJ)
		ar r $(LIB) $(OBJ)
		ranlib $(LIB)

all:		$(LIB)
clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(LIB)
re:		fclean all
.PHONY:		all clean fclean re
