/*
** my_swap.c for my_swap in /home/vic/Desktop/piscine/C/C_jour_3/aizpur_v
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed Mar 22 15:54:21 2017 AIZPURUA Victor Hugo
** Last update Sun Mar 26 19:40:08 2017 AIZPURUA Victor Hugo
*/

void	my_swap(int *a, int *b)
{
  int	temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
