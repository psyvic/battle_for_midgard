/*
** prompt_oob.c for prompt_oob.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 17:47:34 2017 AIZPURUA Victor Hugo
** Last update Thu May 11 10:52:20 2017 AIZPURUA Victor Hugo
*/

#include	<stdlib.h>
#include	"midgar.h"

static const    t_prompt_oob   g_prompt_oob[] = {
  {"team", &team},
  {"choose_monster", &choose_monster},
  {"shop", &prompt_shop},
  {"lets_fight", &prompt_fight},
  {"quit", &quit},
  {NULL, NULL}
};

void		prompt_oob(t_matrix *matrix)
{
  char		*command;
  int		bool;

  bool = 0;
  while (bool == 0)
    {
      my_putstr("oob_prompt?~> ");
      command = readLine();
      if (command == NULL)
	my_putstr("[ERROR] Thats not an option! \n");
      else
	prompt_oob_cont(matrix, command);
      free(command);
    }
}

void		prompt_oob_cont(t_matrix *matrix, char *command)
{
  int		bool;
  int		i;

  i = 0;
  bool = 0;
  while (g_prompt_oob[i].order != NULL)
    {
      if (my_strcmp(command, g_prompt_oob[i].order) == 0)
	{
	  g_prompt_oob[i].f(matrix);
	  bool = 1;
	}
      i = i + 1;
    }
  if (bool == 0)
    my_putstr("[ERROR] Thats not an option! \n");
}

void		team(t_matrix *matrix)
{
  t_creature	*temp;

  temp = matrix->team->first;
  while (temp != NULL)
    {
      my_putstr("Creature name: ");
      my_putstr(temp->name);
      my_putstr("\nLevel: ");
      my_put_nbr(temp->lvl);
      my_putstr("\n Health Points (HP): ");
      my_put_nbr(temp->pv);
      my_putstr("\n Magic Points (MP): ");
      my_put_nbr(temp->pm);
      my_putstr("\n\n");
      temp = temp->next;
    }
}
