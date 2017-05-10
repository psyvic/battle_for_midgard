/*
** my_strncat.c for my_strncat in /home/vic/Desktop/piscine/C/C_jour_4/aizpur_v
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Sun Mar 26 18:40:42 2017 AIZPURUA Victor Hugo
** Last update Fri Mar 31 18:21:54 2017 AIZPURUA Victor Hugo
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	j;
  int	i;

  i = 0;
  j = 0;
  while (dest[i])
    i = i + 1;
  while (src[j] && j < nb)
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}
