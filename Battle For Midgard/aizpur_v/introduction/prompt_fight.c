/*
** prompt_fight.c for prompt_fight.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu May 11 13:19:41 2017 AIZPURUA Victor Hugo
*/
#include	<stdlib.h>
#include	<stdio.h>
#include	"midgar.h"

const    t_prompt_fight	   g_prompt_fight[] = {
  {"slash", &slash},
  {"fire", &fire},
  {"gamble", &gamble},
  {"catch", &magic_catch_combat},
  {"rest", &rest},
  {"run", &run},
  {NULL, NULL}
};

int		prompt_fight(t_matrix *matrix)
{
  char		*command;

  matrix->creature = get_creature();
  while (!is_dead(matrix))
    {
      my_putstr("fight_prompt?~> ");
      command = readLine();
      if (command == NULL)
	{
	  my_putstr("[ERROR] Thats not an option! \
type slash, fire, gamble, rest, catch or run\n");
	}
      else if (prompt_fight_cont(matrix, command) == 0)
	continue;
      free(command);
      if (matrix->creature && matrix->team->actif	\
	  && matrix->creature->pv > 0 && matrix->team->actif->pv > 0)
	{
	  my_putstr_color("red", "[THE ENEMY IS ATTACKING NOW]\n");
	  enemy_attack(matrix);
	}
    }
  return (1);
}
  
int		prompt_fight_cont(t_matrix *matrix, char *command)
{
  int		i;
  int		enough_pm;
  int		bool;
  
  i = 0;
  bool = 0;
  while (bool == 0 && g_prompt_fight[i].order != NULL)
    {
      if (my_strcmp(command, g_prompt_fight[i].order) == 0)
	{
	  enough_pm = g_prompt_fight[i].f			\
	    (matrix->team->actif, matrix->creature, matrix);
	  bool = 1;
	  if (enough_pm == 0)
	    {
	      my_putstr("You dont have enough MP ASSHOLE\n");
	      return (0);
	    }
	  return (1);
	}
      i = i + 1;
    }
  if (bool == 0)
    my_putstr("[ERROR] Thats not an option! \
type slash, fire, gamble, rest, magic catch or run\n");
  return (0);
}

int		slash(t_creature *attacker, t_creature *defenser,	\
		      t_matrix *matrix)
{
  int		attack;
  
  (void) matrix;
  my_putstr_color("red", "[SLASH ATTACK!]\n");
  attack = 15;
  if (attacker->pm < 3)
    return (0);
  attacker->pm -= 3;
  defenser->pv = damage_points(attack, defenser->pv);
  print_dmg(3, attack, attacker, defenser);
  return (1);
}

int		fire(t_creature *attacker, t_creature *defenser,	\
		     t_matrix *matrix)
{
  int		attack;
  
  (void) matrix;
  my_putstr_color("red", "The Magic Fire\n");
  attack = 30;
  if (attacker->pm < 7)
    return (0);
  attacker->pm -= 7;
  defenser->pv = damage_points(attack, defenser->pv);
  print_dmg(7, attack, attacker, defenser);
  return (1);
}

int		gamble(t_creature *attacker, t_creature *defenser,	\
		       t_matrix *matrix)
{
  int           rnd;
  
  (void) attacker;
  (void) defenser;
  my_putstr_color("red","[This is GAMBLE TIME!]\n");
  if ((rnd = rand() % MONSTER + 1) == 1)
    {
      rnd = rand() % GAMBLE;
      my_putstr("The gamble attack bounces back to your monster.\nHe suffers ");
      my_put_nbr(rnd);
      my_putstr(" points of damage. Now your monster has ");
      matrix->team->actif->pv = damage_points(rnd, matrix->team->actif->pv);
      my_put_nbr(matrix->team->actif->pv);
      my_putstr(" points of health.\n");
    }
  else
    {
      rnd = rand() % GAMBLE;
      my_putstr("The gamble attacks the enemy.\nHe suffers ");
      matrix->creature->pv = damage_points(rnd, matrix->creature->pv);
      my_put_nbr(rnd);
      my_putstr(" points of damage. Now he has ");
      my_put_nbr(matrix->creature->pv);
      my_putstr(" points of health.\n");
    }
  return (1);
}
