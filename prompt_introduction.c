/*
** prompt_introduction.c for prompt_introduction.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 14:49:06 2017 AIZPURUA Victor Hugo
** Last update Fri May 12 15:31:27 2017 AIZPURUA Victor Hugo
*/

#include	<stdlib.h>
#include	"midgar.h"

static const	t_capture_prompt   g_capture_prompt[] = {
  {"magic_catch", &magic_catch},
  {"help_me!", &help_me},
  {"shop", &prompt_shop},
  {"quit", &quit},
  {NULL, NULL}
};

void		capture_prompt(t_matrix *matrix)
{
  char		*command;
  int		bool;

  bool = 0;
  while (bool == 0)
    {
      my_putstr("intro_prompt?~> ");
      command = readLine();
      if (command == NULL)
	my_putstr("[ERROR] Thats not an option! \n");
      else
	bool = capture_prompt_cont(matrix, command);
      free(command);
    }
}

int		capture_prompt_cont(t_matrix *matrix, char *command)
{
  int		bool;
  int		i;

  i = 0;
  bool = 0;
  while (g_capture_prompt[i].order != NULL)
    {
      if (my_strcmp(command, g_capture_prompt[i].order) == 0)
	{
	  g_capture_prompt[i].f(matrix);
	  bool = 1;
	}
      i = i + 1;
    }
  if (bool == 0)
    my_putstr("[ERROR] Thats not an option! \n");
  return (bool);
}

void		magic_catch(t_matrix *matrix)
{
  int rnd;

  if (!matrix->player->magic_box)
    {
      my_putstr("You dont have any magic boxes left!\n");
      return;
    }
  rnd = rand() % CATCH_PROB;
  if (rnd == 1)
    {
      matrix->player->magic_box = matrix->player->magic_box - 1;
      matrix->team->first = matrix->creature;
      matrix->team->actif = matrix->creature;
      matrix->team->last = matrix->creature;
      matrix->creature = NULL;
      matrix->team->nb_creatures = matrix->team->nb_creatures + 1;
      my_putstr("You captured the ");
      my_putstr(matrix->team->first->name);
      my_putstr("\n");
      prompt_oob(matrix);
    }
  else
    {
      matrix->player->magic_box = matrix->player->magic_box - 1;
      my_putstr("You failed to catch the ");
      my_putstr(matrix->creature->name);
      my_putstr("\n It chases you like crazy, forcing you to escape.\n");
      free (matrix->creature);
      get_creature();
    }
}

void		help_me(t_matrix *matrix)
{
  my_putstr("You run like a pussy from the ");
  my_putstr(matrix->creature->name);
  my_putstr("\n You escaped safely.\n");
  free(matrix->creature);
  get_creature();
}

void		quit(t_matrix *matrix)
{
  matrix->quit = 1;
  my_putstr("\033[34mQuitting game!\n");
}
