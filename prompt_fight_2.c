/*
** prompt_fight_2.c for prompt_fight_2.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu May 11 14:12:55 2017 AIZPURUA Victor Hugo
** Last update Sat May 13 13:51:31 2017 PAREDES Alejandra
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
  my_putstr("Resting, you recover 10 MP\n");
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
/*para el magic catch especialmente necesito saber si es el player quien ataca. Ahi entra is_savage, una nueva variable en t_creature para verificar, si esta en el equipo es porque ya no es savage*/

int		magic_catch_combat(t_creature *attacker, t_creature *defenser,\
				   t_matrix *matrix)
{
  int		rnd;
  int		delta_pv;

  delta_pv = defenser->pvmax - defenser->pv;
  if (attacker->is_savage == 1 && matrix->player->magic_box < 1)
    {
      my_putstr("You dont have any magic boxes left!\n");
      my_putstr("\t\tnow the system will print not enough PV. PENDING\n");
      return (0);
    }
  if (attacker->is_savage == 1)
    matrix->player->magic_box -= 1;
  rnd = rand() % defenser->pvmax;
  my_putstr("random number para capturar es ");/* test */
  my_put_nbr(rnd);/* test */
  my_putstr("\n");/* test */
  my_putstr("y delta_pv number es ");/* test */
  my_put_nbr(delta_pv);/* test */
  my_putstr(", Delta debe ser igual o menor de random para capturar\n");/* test */
  if (rnd <= delta_pv)
    {
      if (defenser->is_savage == 0)
	add_creature_to_team(matrix, defenser);
      else
	my_putstr("the enemy got your creature");
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
      creature->is_savage ^= 1;
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

