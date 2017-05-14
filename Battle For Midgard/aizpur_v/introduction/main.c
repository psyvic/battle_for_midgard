/*
** introduction.c for introduction.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 10:11:23 2017 AIZPURUA Victor Hugo
** Last update Sun May 14 23:14:13 2017 PAREDES Alejandra
*/

#include <time.h>
#include <stdlib.h>
#include "midgar.h"

int		main(int argc, char **argv)
{
  t_matrix	*matrix;

  if (argc != 3)
    {
      my_putstr("Welcome! please put your name after -n \n");
      my_putstr("E.g: ./sta -n Yoda\n");
      return (1);
    }
  srand(time(NULL));
  matrix = create_matrix();
  create_team(matrix);
  create_player(matrix);
  matrix->player->name = argv[2];
  matrix->creature = get_creature();
  while (matrix->quit != 1)
    {
      capture_prompt(matrix);
    }
  return (1);
}
