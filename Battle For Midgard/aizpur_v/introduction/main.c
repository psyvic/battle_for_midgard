/*
** introduction.c for introduction.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 10:11:23 2017 AIZPURUA Victor Hugo
** Last update Fri May 12 12:30:41 2017 PAREDES Alejandra
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
  matrix->team->actif = get_creature();
  matrix->team->first = matrix->team->actif;
  matrix->team->last = get_creature();
  matrix->team->first->next = matrix->team->last;
  matrix->team->last->prev = matrix->team->first;
  matrix->team->nb_creatures = 2;
  matrix->player->mushroom = 5;
  while (matrix->quit != 1)
    {
      capture_prompt(matrix);
<<<<<<< .mine
    }
  /*  prompt_oob(matrix);*/
  return (0);
=======
      }*/
  /*    prompt_oob(matrix);*/
  enemy_attack(matrix);
  return(0);
>>>>>>> .r3877
}
