/*
** prompt_shop.c for prompt_shop.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu May 11 09:12:36 2017 AIZPURUA Victor Hugo
** Last update Sun May 14 22:36:56 2017 PAREDES Alejandra
*/

#include	<stdlib.h>
#include	"midgar.h"

static const    t_prompt_shop   g_prompt_shop[] = {
  {"mushroom", &buy_mushroom},
  {"box", &buy_magic_box},
  {"exit", &exit_game},
  {NULL, NULL}
};

int		prompt_shop(t_matrix *matrix)
{
  char		*command;

  matrix->quit_prompt = 0;
  while (matrix->quit_prompt == 0)
    {
      my_putstr("shop_prompt?~> ");
      command = readLine();
      if (command == NULL)
	my_putstr("[ERROR] Thats not an option! Type mushroom or box to buy \
some. You can also type exit if you are done here\n");
      else
	prompt_shop_cont(matrix, command);
      free(command);
      if (matrix->team->actif != NULL)
	prompt_oob(matrix);
    }
  return (1);
}

void		prompt_shop_cont(t_matrix *matrix, char *command)
{
  int		i;

  i = 0;
  while (g_prompt_shop[i].order != NULL)
    {
      if (my_strcmp(command, g_prompt_shop[i].order) == 0)
	{
	  g_prompt_shop[i].f(matrix);
	  return ;
	}
      i = i + 1;
    }
  my_putstr("[ERROR] Thats not an option! Type mushroom or box to buy \
some. You can also type exit if you are done here\n");
}

int		buy_mushroom(t_matrix *matrix)
{
  if (matrix->player->money < 30)
    {
      my_putstr("You dont have enough money you lil bitch!");
      return (0);
    }
  matrix->player->money -= 30;
  matrix->player->mushroom += 1;
  my_putstr("You bought a mushroom, you now have ");
  my_put_nbr(matrix->player->mushroom);
  my_putstr(" mushrooms and ");
  my_put_nbr(matrix->player->money);
  my_putstr(" rupees\n");
  return (1);
}

int		buy_magic_box(t_matrix *matrix)
{
  if (matrix->player->money < 90)
    {
      my_putstr("You dont have enough money you lil bitch!");
      return (0);
    }
  matrix->player->money -= 90;
  matrix->player->magic_box += 1;
  my_putstr("You bought a magic box, you now have ");
  my_put_nbr(matrix->player->magic_box);
  my_putstr(" magic boxes and ");
  my_put_nbr(matrix->player->money);
  my_putstr(" rupees\n");
  return (1);
}

int		exit_game(t_matrix *matrix)
{
  matrix->quit_prompt = 1;
  return (-1);
}
