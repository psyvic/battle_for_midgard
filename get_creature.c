/*
** get_creature.c for getcreature.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 10:18:08 2017 AIZPURUA Victor Hugo
** Last update Sat May 13 11:45:22 2017 PAREDES Alejandra
*/
#include		<stdlib.h>
#include		<string.h>
#include		<time.h>
#include                "midgar.h"

static t_creature	g_creatures[] =
  {
    {"Koopa", 1, 10, 10, 20, 20, 0, NULL, NULL},
    {"Bob bomb", 1, 10, 10, 20, 20, 0, NULL, NULL},
    {"Yoshi", 1, 10, 10, 20, 20, 0, NULL, NULL},
    {"Maskas", 1, 10, 10, 20, 20, 0, NULL, NULL},
    {"Kucco", 1, 10, 10, 20, 20, 0, NULL, NULL},
    {NULL, 0, 0, 0, 0, 0, 0, NULL, NULL}
  };

t_creature		*get_creature()
{
  int			rnd;
  t_creature		*crea;

  rnd = rand() % NBCREA;
  if ((crea = malloc(sizeof(t_creature))) == NULL)
    return (NULL);
  crea->name = my_strdup(g_creatures[rnd].name);
  if (!crea->name)
    return (NULL);
  crea->lvl = g_creatures[rnd].lvl;
  crea->pv = g_creatures[rnd].pv;
  crea->pvmax = g_creatures[rnd].pvmax;
  crea->pm = g_creatures[rnd].pm;
  crea->pmmax = g_creatures[rnd].pmmax;
  crea->is_savage = g_creatures[rnd].is_savage;
  crea->prev = NULL;
  crea->next = NULL;
  my_putstr("You found a big wild ");
  my_putstr(crea->name);
  my_putstr("\n");
  my_putstr("PV ");
  my_put_nbr(crea->pv);
  my_putstr("\n");
  my_putstr("PM ");
  my_put_nbr(crea->pm);
  my_putstr("\n");
  return (crea);
}
