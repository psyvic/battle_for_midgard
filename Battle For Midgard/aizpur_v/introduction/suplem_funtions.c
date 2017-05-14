/*
** suplem_funtions.c for  in /home/ale1/Desktop/piscine/BattleforMidgard/aizpur_v/introduction
** 
** Made by PAREDES Alejandra
** Login   <parede_h@etna-alternance.net>
** 
** Started on  Sat May 13 21:59:00 2017 PAREDES Alejandra
** Last update Sun May 14 21:18:49 2017 PAREDES Alejandra
*/

#include	<stdlib.h>
#include	"midgar.h"

int		damage_points(int attack, int pv)
{
  if (attack > pv)
      return (0);
  else
      return (pv - attack);
}

int		is_dead(t_matrix *matrix)
{
  if (matrix->creature == NULL || matrix->creature->pv < 1)
    {
      my_putstr_color("yellow", "[CONGRATULATIONS!]\n");
      enemy_defeated(matrix);
      return (1);
    }
  else if (matrix->team->actif == NULL || matrix->team->actif->pv < 1)
    {
      destroy_creature(matrix);
      /* if (matrix->team->first == NULL) */
      /* 	capture_prompt(matrix); */
      return (1);
    }
  return (0);
}
