/*
** prompt_fight.c for prompt_fight.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu May 11 13:19:41 2017 AIZPURUA Victor Hugo
** Last update Fri May 12 14:21:00 2017 PAREDES Alejandra
*/

#include	<stdlib.h>
#include	"midgar.h"

static const    t_prompt_fight   g_prompt_fight[] = {
  {"slash", &slash},
  {"fire", &fire},
  {"gamble", &gamble},
  {"rest", &rest},
  {"magic catch", &magic_catch_combat},
  {"run", &run},
  {NULL, NULL}
  };

void		prompt_fight(t_matrix *matrix)
{
  char          *command;
  int           bool;

  bool = 0;
  while (bool == 0 && matrix->creature != NULL)
    {
      my_putstr("fight_prompt?~> ");
      command = readLine();
      if (command == NULL)
	my_putstr("[ERROR] Thats not an option! \n");
      else
	prompt_fight_cont(matrix, command);
      free(command);
    }
}

void            prompt_fight_cont(t_matrix *matrix, char *command)
{
  int           bool;
  int           i;

  i = 0;
  bool = 0;
  while (g_prompt_fight[i].order != NULL)
    {
      if (my_strcmp(command, g_prompt_fight[i].order) == 0)
	{
	  g_prompt_fight[i].f(matrix);
	  bool = 1;
	}
      i = i + 1;
    }
  if (bool == 0)
    my_putstr("[ERROR] Thats not an option! \n");
}

void		slash(t_matrix *matrix)
{
  matrix = matrix;
  my_putstr("\033[34mSlash woooooow!\n");
}

void		fire(t_matrix *matrix)
{
  matrix = matrix;
  my_putstr("\033[34mFire woooooow!\n");
}

void		gamble(t_matrix *matrix)
{
  matrix = matrix;
  my_putstr("\033[34mGamble woooooow!\n");
}

void            rest(t_matrix *matrix)
{
  matrix = matrix;
  my_putstr("\033[34mRest wooooow!\n");
}

void		run(t_matrix *matrix)
{
  matrix = matrix;
  my_putstr("\033[34mMagic Catch combat woooooow!\n");
}
