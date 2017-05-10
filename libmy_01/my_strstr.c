/*
** my_strstr.c for my_strstr in /home/vic/Desktop/piscine/C/C_jour_4/aizpur_v
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Sun Mar 26 19:21:02 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 11:09:53 2017 AIZPURUA Victor Hugo
*/

char	 *my_strstr(char *str, char *to_find)
{
  int    i;
  int    j;
  int    start;

  i = 0;
  j = 0;
  start = 0;
  while (str[i] && to_find[j])
    {
      if (str[i] == to_find[j])
	{
	  if (j == 0)
	      start = i;
	  j = j + 1;
	}
      else
	  j = 0;
      i = i + 1;
    }
  if (to_find[j] == '\0')
    return (&str[start]);
  else
    return (0);
}
