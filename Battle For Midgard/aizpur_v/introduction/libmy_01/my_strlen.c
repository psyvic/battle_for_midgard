/*
** my_strlen.c for my_strlen in /home/vic/Desktop/piscine/C/C_jour_3/aizpur_v/my_strlen
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed Mar 22 12:22:30 2017 AIZPURUA Victor Hugo
** Last update Wed Mar 22 12:49:31 2017 AIZPURUA Victor Hugo
*/

int	my_strlen(char *str)
{
  int	compteur;

  compteur = 0;
  while (*str != '\0')
    {
      str = str + 1;
      compteur++;
    }
  return (compteur);
}
