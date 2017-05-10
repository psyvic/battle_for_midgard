/*
** my_strncpy.c for my_strncpy in /home/vic/Desktop/piscine/C/C_jour_4/aizpur_v
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu Mar 23 21:08:01 2017 AIZPURUA Victor Hugo
** Last update Sun Mar 26 20:06:52 2017 AIZPURUA Victor Hugo
*/

char  *my_strncpy(char *dest, char *src, int n)
{
  int i;

  i = 0;
  while (n > 0 && *(src + i))
    {
      *(dest + i) = *(src + i);
      i = i + 1;
      --n;
    }
  if (n > 0)
    *(dest + i) = '\0';
  return (dest);
}
