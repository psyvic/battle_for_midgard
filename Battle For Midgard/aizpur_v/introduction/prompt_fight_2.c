/*
** prompt_fight_2.c for prompt_fight_2.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu May 11 14:12:55 2017 AIZPURUA Victor Hugo
** Last update Thu May 11 15:56:03 2017 AIZPURUA Victor Hugo
*/

#include	<stdlib.h>
#include	"midgar.h"

void		magic_catch_combat(t_matrix *matrix)
{
  int rnd;

  if (!matrix->player->magic_box)
    {
      my_putstr("You dont have any magic boxes left!\n");
      return;
    }
  matrix->player->magic_box = matrix->player->magic_box - 1;
  rnd = rand() % matrix->creature->pvmax;
  if (rnd <= matrix->creature->pv)
    {
    
      matrix->creature = NULL;
      matrix->team->nb_creatures = matrix->team->nb_creatures + 1;
      my_putstr("You captured the ");
      my_putstr(matrix->team->first->name);
      my_putstr("\n");
    }
  else
    {
      my_putstr("You failed to catch the ");
      my_putstr(matrix->creature->name);
      my_putstr("\n");
    }
}

/*void		add_creature_to_team(t_matrix *matrix, t_creature *creature)
{
  if ((ship->container->first == NULL) && (ship->container->last == NULL))
    {
      ship->container->first = freight;
      ship->container->last = freight;
      freight->next = NULL;
    }
  else
    {
      freight->next = ship->container->first;
      ship->container->first->prev = freight;
      ship->container->first = freight;
    }
  freight->prev = NULL;
  ship->container->nb_elem = ship->container->nb_elem + 1;
}

void		del_freight_to_container(t_ship *ship, t_freight *freight)
{
  if ((ship->container->first != NULL) && (ship->container->last != NULL))
    {
      del_prob(ship, freight);
      free(freight);
      ship->container->nb_elem = ship->container->nb_elem - 1;
    }
    }*/

/*int		magic_catch_combat_prob(t_matrix *matrix)
{
  int		prob;
  int		rnd;

  prob = matrix->creature->pvmax - matrix->creature->pv;
  rnd = (rand() % prob) + 1;
  return (rnd);
  }*/
