#ifndef			_INTRODUCTION_H_
#define			_INTRODUCTION_H_

#define                 NBCREA 5

struct			s_player
{
  char			*name;
  int			money;
  int			magic_box;
};
typedef struct		s_player t_player;

struct			s_creature
{
  char                  *name;
  int                   lvl;
  int                   pv;
  int                   pvmax;
  int                   pm;
  int                   pmmax;
  struct s_creature     *next;
  struct s_creature     *prev;
};
typedef struct		s_creature t_creature;

struct			s_team
{
  t_creature		*first;
  t_creature		*last;
  int			nb_creatures;
};
typedef struct		s_team t_team;


struct			s_matrix
{
  t_team		*team;
  t_player              *player;
  t_creature		*creature;
  
};
typedef struct		s_matrix t_matrix;

void			my_putchar(char c);
void			my_putstr(char *str);
void			my_putstr_color(const char *color, const char *str);
int			my_strcmp(char *s1, char *s2);
void			my_put_nbr(int n);
char			*my_strdup(const char *str);
t_matrix                *create_matrix();
int	                create_team(t_matrix *matrix);
int		        create_player(t_matrix *matrix);
t_creature              *get_creature();



#endif
