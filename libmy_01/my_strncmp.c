/*
** my_strncmp.c for my_strncmp in /home/vic/Desktop/piscine/C/C_jour_4/aizpur_v
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu Mar 23 22:56:25 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 11:11:08 2017 AIZPURUA Victor Hugo
*/

int  my_strncmp(char *s1, char *s2, int n)
{
  int i;

  i = 0;
  while (i <= n)
    {
      if (*s1 > *s2)
	  return (1);
      else if (*s1 < *s2)
	  return (-1);
      else if ((*s1 == *s2) && (*s1 == '\0') && (*s2 == '\0'))
	  return (0);
      s1 = s1 + 1;
      s2 = s2 + 1;
      i = i + 1;
    }
  return (*s1 - *s2);
}
