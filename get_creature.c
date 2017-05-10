/*
** get_creature.c for getcreature.c in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Wed May 10 10:18:08 2017 AIZPURUA Victor Hugo
** Last update Wed May 10 14:32:52 2017 AIZPURUA Victor Hugo
*/
#include		<stdlib.h>
#include		<string.h>
#include		<time.h>
#include                "introduction.h"

static t_creature	g_creatures[] =
  {
    {"Koopa", 1, 10, 10, 20, 20},
    {"Bob bomb", 1, 10, 10, 20, 20},
    {"Yoshi", 1, 10, 10, 20, 20},
    {"Maskas", 1, 10, 10, 20, 20},
    {"Kucco", 1, 10, 10, 20, 20},
    {NULL, 0, 0, 0, 0, 0}
  };

t_creature		*get_creature()
{
  int			rnd;
  t_creature		*crea;

  rnd = rand() % NBCREA;
  if ((crea = malloc(sizeof(t_creature))) == NULL)
    return (NULL);
  crea->name = strdup(g_creatures[rnd].name);
  if (!crea->name)
    return (NULL);
  crea->lvl = g_creatures[rnd].lvl;
  crea->pv = g_creatures[rnd].pv;
  crea->pvmax = g_creatures[rnd].pvmax;
  crea->pm = g_creatures[rnd].pm;
  crea->pmmax = g_creatures[rnd].pmmax;
  crea->prev = NULL;
  crea->next = NULL;
  return (crea);
}
