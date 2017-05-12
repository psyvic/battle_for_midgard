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

  matrix->creature = get_creature();
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
  if (matrix->team->actif->pm < 3)
    {
      my_putstr("You dont have enough MP ASSHOLE\n");
      return;
    }
  my_putstr("You use Slash woooooow!\n");
  matrix->team->actif->pm = matrix->team->actif->pm - 3;
  matrix->creature->pv = matrix->creature->pv -15;
  enemy_defeated(matrix);
}

void		fire(t_matrix *matrix)
{
  if (matrix->team->actif->pm < 7)
    {
      my_putstr("You dont have enough MP ASSHOLE\n");
      return;
    }
  my_putstr("You use Fire woooooow!\n");
  matrix->team->actif->pm = matrix->team->actif->pm - 7;
  matrix->creature->pv = matrix->creature->pv -30;
  enemy_defeated(matrix);
}

void            gamble(t_matrix *matrix)
{
  int           rnd;

  my_putstr("Gamble woooooow!\n");
  rnd = rand() % MONSTER;
  if (rnd == 0)
    {
      rnd = rand() % GAMBLE;
      my_putstr("The gamble attack bounces back to your monster\n He suffers ");
      matrix->team->actif->pv = matrix->team->actif->pv - rnd;
    }
  else
    {
      rnd = rand() % GAMBLE;
      my_putstr("The gamble attacks the enemy\n He suffers ");
      matrix->creature->pv = matrix->creature->pv - rnd;
    }
  my_put_nbr(rnd);
  my_putstr(" points of damage\n");
  destroy_creature(matrix);
}
