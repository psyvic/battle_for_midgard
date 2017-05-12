/*
** prompt_fight_2.c for prompt_fight_2.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu May 11 14:12:55 2017 AIZPURUA Victor Hugo
** Last update Fri May 12 17:30:54 2017 AIZPURUA Victor Hugo
*/

#include	<stdlib.h>
#include	"midgar.h"

void            rest(t_matrix *matrix)
{
  matrix = matrix;
  my_putstr("mp before resting: ");
  my_put_nbr(matrix->team->actif->pm);
  my_putstr("\n");
  my_putstr("Resting, you recover 10 MP\n");
  matrix->team->actif->pm = matrix->team->actif->pm + 10;
  if (matrix->team->actif->pm > matrix->team->actif->pmmax)
    matrix->team->actif->pm = matrix->team->actif->pmmax;
  my_putstr("mp after resting: ");
  my_put_nbr(matrix->team->actif->pm);
  my_putstr("\n");
}

void            run(t_matrix *matrix)
{
  my_putstr("You run from battle like a woos!\n");
  free(matrix->creature);
  matrix->creature = NULL;
}

void		magic_catch_combat(t_matrix *matrix)
{
  int		rnd;
  int		delta_pv;

  delta_pv = matrix->creature->pvmax - matrix->creature->pv;
  if (!matrix->player->magic_box)
    {
      my_putstr("You dont have any magic boxes left!\n");
      return;
    }
  matrix->player->magic_box = matrix->player->magic_box - 1;
  rnd = rand() % matrix->creature->pvmax;
  my_putstr("printf de random number para capturar ");
  my_put_nbr(rnd);
  my_putstr("\n");
  my_putstr("printf de delta_pv ");
  my_put_nbr(delta_pv);
  my_putstr(", debe ser igual o menor de random para  capturar\n");
  if (rnd <= delta_pv)
    add_creature_to_team(matrix, matrix->creature);
  else
    {
      my_putstr("You failed to catch the ");
      my_putstr(matrix->creature->name);
      my_putstr("\n");
    }
}

void		add_creature_to_team(t_matrix *matrix, t_creature *creature)
{
  if ((matrix->team->first == NULL) && (matrix->team->last == NULL))
    {
      matrix->team->first = creature;
      matrix->team->last = creature;
      creature->next = NULL;
    }
  else
    {
      creature->next = matrix->team->first;
      matrix->team->first->prev = creature;
      matrix->team->first = creature;
    }
  matrix->creature = NULL;
  creature->prev = NULL;
  matrix->team->nb_creatures = matrix->team->nb_creatures + 1;
  my_putstr("You captured the ");
  my_putstr(matrix->team->first->name);
  my_putstr("\n");
}
