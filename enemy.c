/*
** enemy.c for  in //home/ale1/Desktop/piscine/BattleforMidgard/aizpur_v/introduction
** 
** Made by PAREDES Alejandra
** Login   <parede_h@etna-alternance.net>
** 
** Started on  Fri May 12 11:54:44 2017 PAREDES Alejandra
** Last update Fri May 12 15:37:07 2017 PAREDES Alejandra
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"midgar.h"

static const    t_choose_attack g_choose_attack[] = {
  {1, &slash},
  {2, &fire},
  {3, &gamble},
  {4, &rest},
  {5, &magic_catch_combat},
  {0, NULL}
};


void		enemy_attack(t_matrix *matrix)
{
  int		attack;
  int		i;
  
  i = 0;
  attack = ((rand()% 5) + 1);
  printf("the attack number is %d \n", attack);
  if (!attack)
    my_putstr("Something went wrong");
  else
    {
      while (i < 6)
	{
	  if (attack == g_choose_attack[i].option)
	    {
	      g_choose_attack[i].a(matrix);
	      return;
	    }
	  i++;
	}
    }
}
