/*
** prompt_fight_2.c for prompt_fight_2.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu May 11 14:12:55 2017 AIZPURUA Victor Hugo
** Last update Sun May 14 20:54:23 2017 PAREDES Alejandra
*/

#include	<stdlib.h>
#include	"midgar.h"

int            rest(t_creature *attacker, t_creature *defenser,\
				   t_matrix *matrix)
{
  (void) defenser;
  (void) matrix;
  my_putstr("mp before resting: ");
  my_put_nbr(attacker->pm);
  my_putstr("\n");
  my_putstr("Resting, the creature recovers 10 MP\n");
  attacker->pm = attacker->pm + 10;
  if (attacker->pm > attacker->pmmax)
    attacker->pm = attacker->pmmax;
  my_putstr("mp after resting: ");
  my_put_nbr(attacker->pm);
  my_putstr("\n");
  return (1);
}

int            run(t_creature *attacker, t_creature *defenser,\
				   t_matrix *matrix)
{
  (void) attacker;
  (void) matrix;
  my_putstr("You run from battle like a woos!\n");
  free(defenser);
  defenser = NULL;
  return (1);
}

int		magic_catch_combat(t_creature *attacker, t_creature *defenser,\
				   t_matrix *matrix)
{
  int		rnd;
  int		delta_pv;

  my_putstr_color("red", "Trying to CATCH the creature\n");
  delta_pv = defenser->pvmax - defenser->pv;
  if (attacker->is_savage == 1 && matrix->player->magic_box < 1)
    {
      my_putstr("You dont have any magic boxes left!\n");
      return (0);
    }
  if (attacker->is_savage == 1)
    matrix->player->magic_box -= 1;
  rnd = rand() % defenser->pvmax;
  if (rnd <= delta_pv)
    {
      if (defenser->is_savage == 0)
	  add_creature_to_team(matrix, defenser);
      else
	my_putstr("the enemy got your creature\n");
    }  
  else
    {
      my_putstr("You failed to catch the ");
      my_putstr(matrix->creature->name);
      my_putstr("\n");
    }
  return (1);
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
  matrix->team->first->is_savage ^= 1;
  matrix->creature = NULL;
  matrix->team->first->prev = NULL;
  matrix->team->nb_creatures = matrix->team->nb_creatures + 1;
  my_putstr("You captured the ");
  my_putstr(matrix->team->first->name);
  my_putstr("\n");
  level_up(matrix);
}

void		level_up(t_matrix *matrix)
{
  matrix->team->first->lvl = matrix->team->first->lvl + 1;
  matrix->team->first->pvmax = matrix->team->first->pvmax * 2;
  matrix->team->first->pmmax = matrix->team->first->pmmax * 2;
  matrix->team->first->pv = matrix->team->first->pvmax;
  matrix->team->first->pm = matrix->team->first->pmmax;
  my_putstr("Your new monster has lvled up! He is now lvl ");
  my_put_nbr(matrix->team->first->lvl);
  my_putstr("\nPV ");
  my_put_nbr(matrix->team->first->pv);
  my_putstr("\nPM ");
  my_put_nbr(matrix->team->first->pm);
  my_putstr("\n");
}
