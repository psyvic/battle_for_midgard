/*
** Ce fichier contient les fonctions de bases pour gérer des strings (les chaines de caractères).
**
** my_putchar vous permet d'afficher un caractère sour la sortie standard.
** 
** my_strlen renvoie la taille d'une string.
**
** my_putstr vous permet d'afficher une string sur la sortie standard.
**
** my_strcmp vous permet de comparer deux strings si ces strings sont égales alors
** la fonction renvoie 0.
**
** my_strdup vous permet d'allouer dynamiquement une chaine de caractères et de copier la valeur de
** la chaine passé en paramètre et de renvoyer cette chaine.
**
** my_putstr_color vous permet d'afficher une string sur la sortie standard de la couleur souhaitée.
** les couleurs disponibles pour cette fonction sont rouge (red), vert (green), jaune (yellow),
** bleu (blue), violet (magenta), et bleu cyan (cyan), elle vous permet également d'effacer
** tout ce qui est actuellement affiché à l'écran (clear) avant d'afficher votre chaine de caractères.
*/
#include		<stdlib.h>
#include		<unistd.h>
#include		"midgar.h"

char			*reset_color = "\033[0m";

struct			s_color
{
  char			*color;
  char			*unicode;
};
typedef			struct s_color	t_color;

static t_color		g_color[] =
  {
    {"clear", "\033[H\033[2J"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {NULL, NULL}
  };

void			my_putstr_color(char *color, char *str)
{
  int			i;

  i = 0;
  while (g_color[i].color != NULL && (my_strcmp(g_color[i].color, color) != 0))
    i++;
  if (g_color[i].color == NULL)
    {
      my_putstr(str);
      return;
    }
  my_putstr(g_color[i].unicode);
  my_putstr(str);
  my_putstr(reset_color);
}
