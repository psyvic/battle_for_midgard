/*
** my_strcat.c for my_strcat in /home/vic/Desktop/piscine/C/C_jour_4/aizpur_v/my_strcat
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Sun Mar 26 18:10:52 2017 AIZPURUA Victor Hugo
** Last update Sun Mar 26 20:11:11 2017 AIZPURUA Victor Hugo
*/

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str1[i])
    i++;
  while (str2[j])
    {
      str1[i] = str2[j];
      i++;
      j++;
    }
  str1[i] = '\0';
  return (str1);
}
