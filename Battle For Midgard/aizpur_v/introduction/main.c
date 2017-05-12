/*
** introduction.c for introduction.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 10:11:23 2017 AIZPURUA Victor Hugo
** Last update Fri May 12 17:18:03 2017 AIZPURUA Victor Hugo
*/

#include <time.h>
#include <stdlib.h>
#include "midgar.h"

int main()
{
  t_matrix *matrix;

  srand(time(NULL));
  matrix = create_matrix();
  create_team(matrix);
  create_player(matrix);
  matrix->creature = get_creature();
  while (matrix->quit != 1)
    {
      capture_prompt(matrix);
    }
  return (0);
}
