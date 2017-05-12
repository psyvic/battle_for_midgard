/*
** prompt_fight_3.c for prompt_fight_3.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri May 12 10:28:25 2017 AIZPURUA Victor Hugo
** Last update Fri May 12 15:12:32 2017 AIZPURUA Victor Hugo
*/

#include	<stdlib.h>
#include	"midgar.h"

void		destroy_creature(t_matrix *matrix)
{
  if (matrix->team->actif->pv <= 0)
    del_creature_from_team(matrix);
  enemy_defeated(matrix);
}

void		del_creature_from_team(t_matrix *matrix)
{
  my_putstr("Your monster has been defeated!\n");
  if ((matrix->team->first != NULL) && (matrix->team->last != NULL))
    {
      del_prob(matrix);
      free(matrix->team->actif);
      matrix->team->actif = NULL;
      matrix->team->nb_creatures = matrix->team->nb_creatures - 1;
    }
}

void		del_prob(t_matrix *matrix)
{
  if (matrix->team->first == matrix->team->actif &&
      matrix->team->last != matrix->team->actif)
    {
      matrix->team->actif->next->prev = NULL;
      matrix->team->first = matrix->team->first->next;
    }
  else if (matrix->team->last == matrix->team->actif &&
	   matrix->team->first != matrix->team->actif)
    {
      matrix->team->actif->prev->next = NULL;
      matrix->team->last = matrix->team->actif->prev;
    }
  else if ((matrix->team->first == matrix->team->actif) &&
	   (matrix->team->last == matrix->team->actif))
    {
      matrix->team->first = NULL;
      matrix->team->last = NULL;
    }
  else
    {
      matrix->team->actif->next->prev = matrix->team->actif->prev;
      matrix->team->actif->prev->next = matrix->team->actif->next;
    }
}

void            enemy_defeated(t_matrix *matrix)
{
  int           rnd;

  if (matrix->creature->pv <= 0)
    {
      free(matrix->creature);
      matrix->creature = NULL;
      my_putstr("Enemy defeated!\n");
      my_putstr("Random rupees: ");
      rnd = rand() % RUPEES;
      my_putstr("\n");
      matrix->player->money = matrix->player->money + 90 + rnd;
      my_putstr("You now have ");
      my_put_nbr(matrix->player->money);
      my_putstr("\n");
    }
}
