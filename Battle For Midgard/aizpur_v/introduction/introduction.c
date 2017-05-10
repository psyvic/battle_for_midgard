/*
** introduction.c for introduction.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 10:11:23 2017 AIZPURUA Victor Hugo
** Last update Wed May 10 15:24:20 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <time.h>
#include "midgar.h"

int main()
{
  t_matrix *matrix;

  srand (time (NULL));
  matrix = create_matrix();
  create_team(matrix);
  create_player(matrix);
  matrix->creature = get_creature();
  my_putstr("You found a big wild ");
  my_putstr(matrix->creature->name);
  my_putstr("\n");
  my_putstr("PV ");
  my_put_nbr(matrix->creature->pv);
  my_putstr("\n");
  my_putstr("PM ");
  my_put_nbr(matrix->creature->pm);
  my_putstr("\n");
  capture_prompt(matrix);
  return(0);
}
