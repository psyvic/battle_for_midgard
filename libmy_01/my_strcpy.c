/*
** my_strcpy.c for my_strcpy in /home/vic/Desktop/piscine/C/C_jour_4/aizpur_v
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu Mar 23 17:00:40 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 11:10:26 2017 AIZPURUA Victor Hugo
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
