/*
** my_strdup.c for my_strdup in /home/vic/Desktop/piscine/C/libmy_01
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Mon Apr 10 17:15:45 2017 AIZPURUA Victor Hugo
** Last update Mon Apr 10 18:07:05 2017 AIZPURUA Victor Hugo
*/

#include<stdlib.h>
#include<unistd.h>

int       my_strlen(const char *str);

char      *my_strdup(const char *str)
{
  int     i;
  char    *copy;

  i = 0;
  copy = NULL;
  if ((copy = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      copy[i] = str[i];
      i++;
    }
  copy[i] = '\0';
  return (copy);
}
