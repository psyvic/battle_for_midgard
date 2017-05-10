/*
** my_putstr.c for my_putstr in /home/vic/Desktop/piscine/C/C_jour_3/aizpur_v/my_putstr
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed Mar 22 11:48:15 2017 AIZPURUA Victor Hugo
** Last update Wed Mar 22 12:19:13 2017 AIZPURUA Victor Hugo
*/
void	my_putchar(char c);

void    my_putstr(char *str)
{

  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}
