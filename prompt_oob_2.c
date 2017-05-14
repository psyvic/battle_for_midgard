/*
** prompt_oob_2.c for prompt_oob_2.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu May 11 01:08:21 2017 AIZPURUA Victor Hugo
** Last update Sun May 14 13:01:19 2017 PAREDES Alejandra
*/

#include        <stdlib.h>
#include        "midgar.h"

int		mushroom(t_matrix *matrix)
{
  int		rnd;

  if (matrix->player->mushroom == 0)
    {
      my_putstr("You dont have any mushrooms p'tite bite!\n");
      return (0);
    }
  matrix->player->mushroom = matrix->player->mushroom - 1;
  rnd = (rand() % MUSHROOM + 15) * matrix->team->actif->pvmax / 100;
  my_putstr("Your mushroom heals ");
  my_putstr(matrix->team->actif->name);
  my_putstr(" for ");
  my_put_nbr(rnd);
  my_putstr(" HP\n");
  matrix->team->actif->pv = matrix->team->actif->pv + rnd;
  if (matrix->team->actif->pv > matrix->team->actif->pvmax)
    matrix->team->actif->pv = matrix->team->actif->pvmax;
  return (1);
}
