/*
** my_putchar.c for my_putchar in /home/vic/Desktop/aizpur_v/my_putchar
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Mon Mar 20 12:18:31 2017 AIZPURUA Victor Hugo
** Last update Mon Mar 20 12:36:44 2017 AIZPURUA Victor Hugo
*/
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
