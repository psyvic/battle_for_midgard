/* my_put_nbr.c for my_put_nbr in /home/vic/Desktop/piscine/C/C_jour_5/aizpur_v
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Mar 24 09:25:33 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 11:13:03 2017 AIZPURUA Victor Hugo
*/

void    my_putchar(char c);

void    my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}

int	my_nb_len(int n)
{
  int	num_chiffres;

  num_chiffres = 0;
  if (n < 0)
    n = -n;
  if (n > 0)
    {
      while (n != 0)
	{
	  n = n/10;
	  num_chiffres = num_chiffres + 1;
	}
    }
  else
    num_chiffres = 1;
  return (num_chiffres);
}

void	my_put_nbr(int n)
{
  int	puissance;
  int	index;
  int	temp;

  puissance = index = 1;
  temp = 0;
  if (n < 0)
    {
      my_putchar('-');
      n = n * (-1);
    }
  if ( n == -2147483648)
    my_putstr("2147483648");
  while (index < my_nb_len(n))
    {
      puissance = puissance * 10;
      index = index + 1;
    }
  while (index > 0)
    {
      temp = (n / puissance) % 10;
      my_putchar('0' + temp);
      index = index - 1;
      puissance = puissance / 10;
    }
}
