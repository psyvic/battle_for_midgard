/*
** my_getbnr.c for my_getnbr in /home/vic/Desktop/piscine/C/C_jour_5/aizpur_v
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Mar 24 16:13:23 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 11:16:35 2017 AIZPURUA Victor Hugo
*/

#include <stdio.h>

void	my_putchar(char c);

int     my_getnbr(char *str)
{
  int   i;
  int temp;
  int temp_neg;

  i = 0;
  temp = 0;
  temp_neg = 1;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
	temp_neg = temp_neg * -1;
      i = i + 1;
    }
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      temp = (temp * 10) + (str[i] - 48);
      i = i + 1;
    }
  return (temp * temp_neg);
}

