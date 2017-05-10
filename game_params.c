/*
** game_params.c for game_params.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 11:45:01 2017 AIZPURUA Victor Hugo
** Last update Wed May 10 14:06:35 2017 AIZPURUA Victor Hugo
*/

#include                "introduction.h"
#include		<stdlib.h>

t_matrix		*create_matrix()
{
  t_matrix		*matrix;

  my_putstr("CREATING GAME PARAMETERS...\n");
  matrix = malloc(sizeof(t_matrix));
  if (matrix == NULL)
    {
      my_putstr("Error creating game parameters\n");
      return (NULL);
    }
  matrix->team = NULL;
  matrix->player = NULL;
  matrix->creature = NULL;
  my_putstr("Game mechanics created succesfully!\n");
  return (matrix);
}

int			create_team(t_matrix *matrix)
{
  t_team		*team;

  team = malloc(sizeof(t_team));
  if (team == NULL)
    return (-1);
  matrix->team = team;
  team->first = NULL;
  team->last = NULL;
  team->nb_creatures = 0;
  return (0);
}

int			create_player(t_matrix *matrix)
{
  t_player		*player;

  player = malloc(sizeof(t_player));
  if (player == NULL)
    return (-1);
  matrix->player = player;
  player->name = NULL;
  player->money = 420;
  player->magic_box = 5;
  return (0);
}
