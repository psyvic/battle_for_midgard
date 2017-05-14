/*
** enemy.c for  in //home/ale1/Desktop/piscine/BattleforMidgard/aizpur_v/introduction
** 
** Made by PAREDES Alejandra
** Login   <parede_h@etna-alternance.net>
** 
** Started on  Fri May 12 11:54:44 2017 PAREDES Alejandra
** Last update Sun May 14 20:44:44 2017 PAREDES Alejandra
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"midgar.h"

void		enemy_attack(t_matrix *matrix)
{
  int		attack;
  int		i;
  
  i = 0;
  attack = rand() % 4;
  while (i < 6)
    {
      if (attack == i)
	{
	  g_prompt_fight[i].f(matrix->creature, matrix->team->actif, matrix);
	  return;
	}
      i++;
    }
}

