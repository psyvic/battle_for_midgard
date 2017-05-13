/*
** prompt_fight.c for prompt_fight.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu May 11 13:19:41 2017 AIZPURUA Victor Hugo
** Last update Sat May 13 15:06:54 2017 PAREDES Alejandra
*/
#include	<stdlib.h>
#include	<stdio.h>
#include	"midgar.h"

const    t_prompt_fight	   g_prompt_fight[] = {
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
    
    matrix->creature = get_creature();
    while (matrix->creature != NULL)
      {
	my_putstr("fight_prompt?~> ");
	command = readLine();
	if (command == NULL)
	  {
	    my_putstr("[ERROR] Thats not an option! \
type slash, fire, gamble, rest, magic catch or run\n");
	  }
	else
	  if (!prompt_fight_cont(matrix, command))
	    continue;
	free(command);
	printf("the name of the enemy is %s and the name of the chosen creature is %s\n", matrix->creature->name, matrix->team->actif->name);
	if (matrix->creature != NULL && matrix->team->actif != NULL)
	  {
	    printf("now is the turn of the enemy\n");
	    enemy_attack(matrix);
	  }
      }
    return;
}

int            prompt_fight_cont(t_matrix *matrix, char *command)
{
    int           i;
    int		enough_pm;
    
    i = 0;
    while (g_prompt_fight[i].order != NULL)
      {
	if (my_strcmp(command, g_prompt_fight[i].order) == 0)
	  {
	    enough_pm = g_prompt_fight[i].f			\
	      (matrix->team->actif, matrix->creature, matrix);
	    if (enough_pm == 0)
	      {
		my_putstr("You dont have enough MP ASSHOLE\n");
		return (0);
	      }
	    return (1);
	  }
	i = i + 1;
      }
    my_putstr("[ERROR] Thats not an option! \
type slash, fire, gamble, rest, magic catch or run\n");
    return (0);
}
/*Cuando la funcion regresa 0 es porque no suficiente PM para hacer el ataque*/
int		slash(t_creature *attacker, t_creature *defenser,\
		      t_matrix *matrix)
{
  (void) matrix;
  if (attacker->pm < 3)
    return (0);
  attacker->pm = attacker->pm - 3;
  defenser->pv = defenser->pv - 15; 
  if (attacker->is_savage == 1)
    {
      my_putstr("You use Slash woooooow!\n");
      my_putstr("The attack take 3 pts from your pm. Now you have ");
      my_put_nbr(matrix->team->actif->pm);
      my_putstr(" point of magic left\n");
      my_putstr("He loses 15 pv and now he has ");
      my_put_nbr(matrix->creature->pv);
      my_putstr(" health point\n");
    }
  else
    {
      my_putstr("The enemy used slashhhh!\n");
      my_putstr("The attack take 3 pts from his pm. Now he has ");
      my_put_nbr(matrix->creature->pm);
      my_putstr(" point of magic left\n");
      my_putstr("You lose 15 pv and now you have ");
      my_put_nbr(matrix->team->actif->pv);
      my_putstr(" health point\n");
    }
  return (1);
}

int		fire(t_creature *attacker, t_creature *defenser,\
		     t_matrix *matrix)
{
  (void) matrix;
  if (attacker->pm < 7)
    return (0);
  my_putstr("You use Fire woooooow!\n");
  attacker->pm = attacker->pm - 7;
  defenser->pv = defenser->pv -30;
  if (attacker->is_savage == 1)
    {
      my_putstr("You use The Magic Fire!\n");
      my_putstr("The attack take 7 pts from your PM. Now you have ");
      my_put_nbr(matrix->team->actif->pm);
      my_putstr(" point of magic left\n");
      my_putstr("He loses 30 pv and now he has ");
      my_put_nbr(matrix->creature->pv);
      my_putstr(" health point\n");
    }
  else
    {
      my_putstr("The enemy uses The Magic Fire!\n");
      my_putstr("The attack take 7 pts from his PM. Now he has ");
      my_put_nbr(matrix->creature->pm);
      my_putstr(" point of magic left\n");
      my_putstr("You lose 30 pv and now you have ");
      my_put_nbr(matrix->team->actif->pv);
      my_putstr(" health point\n");
    }
  return (1);
}

int		gamble(t_creature *attacker, t_creature *defenser,\
		       t_matrix *matrix)
{
  int           rnd;
  
  my_putstr("Gamble woooooow!\n");
  rnd = rand() % MONSTER;
  if (rnd == 0)
    {
      rnd = rand() % GAMBLE;
      my_putstr("The gamble attack bounces back to your monster\n He suffers ");
      attacker->pv = attacker->pv - rnd;
    }
  else
    {
      rnd = rand() % GAMBLE;
      my_putstr("The gamble attacks the enemy\n He suffers ");
      defenser->pv = defenser->pv - rnd;
      my_put_nbr(rnd);
      my_putstr(" points of damage\n");
    }
  destroy_creature(matrix);
  return (1);
}
