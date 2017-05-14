/*
** print_utils.c for  in /home/ale1/Desktop/piscine/BattleforMidgard/aizpur_v/introduction
** 
** Made by PAREDES Alejandra
** Login   <parede_h@etna-alternance.net>
** 
** Started on  Sat May 13 22:49:28 2017 PAREDES Alejandra
** Last update Sun May 14 20:06:47 2017 PAREDES Alejandra
*/
#include	<stdlib.h>
#include	<stdio.h>
#include	"midgar.h"


void		print_dmg(int dmg, int pv_lost, t_creature *attacker, t_creature *defenser)
{
  my_putstr("The attack take ");
  my_put_nbr(dmg);
  my_putstr(" pts from ");
  print_creature_name(attacker, LOWER);
  my_putstr(" pm. Now he has ");
  my_put_nbr(attacker->pm);
  my_putstr(" point of magic left\n");

  print_creature_name(defenser, UPPER);
  my_putstr(" lose ");
  my_put_nbr(pv_lost);
  my_putstr(" pv and now he has ");
  my_put_nbr(defenser->pv);
  my_putstr(" health point\n");  
}

void		print_creature_name(t_creature *creature, int maj)
{
  if (creature->is_savage == 0)
    {
      if (maj == UPPER)
	my_putstr("His ");
      else
	my_putstr("his ");
    }
  else
    {
      if (maj == UPPER)
	my_putstr("Your ");
      else
	my_putstr("your ");
    }
  my_putstr(creature->name);
}
