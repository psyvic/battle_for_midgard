/*
** prompt_oob.c for prompt_oob.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 17:47:34 2017 AIZPURUA Victor Hugo
** Last update Sun May 14 21:42:30 2017 PAREDES Alejandra
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"midgar.h"

static const    t_prompt_oob   g_prompt_oob[] = {
  {"team", &team},
  {"choose", &choose_monster},
  {"mushroom", &mushroom},
  {"shop", &prompt_shop},
  {"fight", &prompt_fight},
  {"quit", &exit_game},
  {NULL, NULL}
};

int		prompt_oob(t_matrix *matrix)
{
  char		*command;

  while (matrix->quit_prompt == 0 && matrix->team->first != NULL)
    {
      my_putstr("oob_prompt?~> ");
      command = readLine();
      if (command == NULL)
	my_putstr("[ERROR] Thats not an option! Type team, choose, mushroom, \
shop, fight, quit to play\n");
      else if (prompt_oob_cont(matrix, command) == 0)
	return (0);
      free(command);
    }
  return (-1);
}

int		prompt_oob_cont(t_matrix *matrix, char *command)
{
  int		i;

  i = 0;
  while (g_prompt_oob[i].order != NULL)
    {
      if (my_strcmp(command, g_prompt_oob[i].order) == 0)
	{
	  if (g_prompt_oob[i].f(matrix) == 0)
	    return (0);
	  return (1);
	}
      i = i + 1;
    }
  my_putstr("[ERROR] Thats not an option! Type team, choose, mushroom, \
shop, fight, quit to play\n");
  return (0);
}

int		team(t_matrix *matrix)
{
  if (matrix->team->first == NULL)
    {
      my_putstr("You dont have any monsters on your team\n");
      return (0);
    }
  team_cont(matrix);
  return (1);
}

void		team_cont(t_matrix *matrix)
{
  t_creature	*temp;
  int		team_number;

  team_number = 1;
  temp = matrix->team->first;
  while (temp != NULL)
    {
      my_put_nbr(team_number);
      my_putstr("\n Creature name: ");
      my_putstr(temp->name);
      if (temp == matrix->team->actif)
	my_putstr(" (Chosen monster)");
      my_putstr("\n Level: ");
      my_put_nbr(temp->lvl);
      my_putstr("\n Health Points (HP): ");
      my_put_nbr(temp->pv);
      my_putstr("\n Magic Points (MP): ");
      my_put_nbr(temp->pm);
      my_putstr("\n\n");
      temp = temp->next;
      team_number = team_number + 1;
    }
}

int		choose_monster(t_matrix *matrix)
{
  t_creature	*temp;
  int		i;
  int		choice;

  team(matrix);
  matrix->team->actif = NULL;
  while (matrix->team->actif == NULL)
    {
      my_putstr("Which monster do you want to choose? Pick a number ~> ");
      choice = my_getnbr(readLine());
      if (choice >= 0 && choice <= matrix->team->nb_creatures)
	{
	  temp = matrix->team->first;
	  for (i = 1; i < choice; i++)
	    temp = temp->next;
	  matrix->team->actif = temp;
	}
      else
	my_putstr("The monster member doesnt exist\n");
    }
  return (1);
}
