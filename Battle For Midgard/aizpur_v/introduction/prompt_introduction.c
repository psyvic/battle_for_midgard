/*
** prompt_introduction.c for prompt_introduction.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 14:49:06 2017 AIZPURUA Victor Hugo
** Last update Sun May 14 20:03:43 2017 PAREDES Alejandra
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"midgar.h"

static const	t_capture_prompt   g_capture_prompt[] = {
  {"catch", &magic_catch},
  {"help", &help_me},
  {"shop", &prompt_shop},
  {"quit", &quit},
  {"instructions", &instructions},
  {NULL, NULL}
};

void		capture_prompt(t_matrix *matrix)
{
  char		*command;
  int		bool;
  int		i;

  bool = 0;
  while (bool == 0)
    {
      my_putstr("intro_prompt?~> ");
      command = readLine();
      if (command == NULL)
	{
	  my_putstr("[ERROR] Thats not an option! \n");
	}
      else for (i = 0; g_capture_prompt[i].order != NULL; i++)
	  if (my_strcmp(command, g_capture_prompt[i].order) == 0)
	    {
	      g_capture_prompt[i].f(matrix);
	      bool = 1;
	      matrix->quit_prompt = 0;
	    }
      if (bool == 0)
	my_putstr("[ERROR] Thats not an option! \n");
      free(command);
    }
}

int		instructions(t_matrix *matrix)
{
  (void) matrix;
  my_putstr("***************************************************************\n");
  my_putstr("Some tips to remember pal!\n");
  my_putstr("Type **catch** to put the creature on your team 30% of chance\n");
  my_putstr("\ntype **help** to get out of there before you become his meal\n");
  my_putstr("\nIn the mood for shopping? Type **shop** to see what you have\n");
  my_putstr("\nTired of this game? You can just **quit** whenever you want!\n");
  my_putstr("***************************************************************\n");
  return (1);
}

int		magic_catch(t_matrix *matrix)
{
  int		rnd;

  if (!matrix->player->magic_box)
    {
      my_putstr("You dont have any magic boxes left!\n");
      return (0);
    }
  matrix->player->magic_box = matrix->player->magic_box - 1;
  rnd = rand() % CATCH_PROB + 1;
  if (rnd == 1)
    {
      matrix->team->first = matrix->creature;
      matrix->team->actif = matrix->creature;
      matrix->team->last = matrix->creature;
      matrix->team->actif->is_savage ^= 1;
      matrix->creature = NULL;
      matrix->team->nb_creatures = matrix->team->nb_creatures + 1;
      my_putstr("You captured the ");
      my_putstr(matrix->team->first->name);
      my_putstr("\n");
      prompt_oob(matrix);
    }
  else
    {
      my_putstr("You failed to catch the ");
      my_putstr(matrix->creature->name);
      my_putstr("\n It chases you like crazy, forcing you to escape.\n");
      free (matrix->creature);
      matrix->creature = get_creature();
    }
  return (1);
}

int		help_me(t_matrix *matrix)
{
  my_putstr("You run like a pussy from the ");
  my_putstr(matrix->creature->name);
  my_putstr("\n You escaped safely.\n");
  free(matrix->creature);
  matrix->creature = get_creature();
  return (1);
}

int		quit(t_matrix *matrix)
{
  matrix->quit = 1;
  my_putstr("Quitting game!\n");
  return (1);
}
