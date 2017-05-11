#ifndef			_MIDGAR_H_
#define			_MIDGAR_H_

#define                 NBCREA 5
#define                 CATCH_PROB 3

struct			s_player
{
  char			*name;
  int			money;
  int			magic_box;
  int			mushroom;
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
  t_creature		*actif;
  int			nb_creatures;
};
typedef struct		s_team t_team;


struct			s_matrix
{
  t_team		*team;
  t_player              *player;
  t_creature		*creature;
  int                   quit;
  int			quit_prompt;
  
};
typedef struct		s_matrix t_matrix;

struct                 s_capture_prompt
{
  char                 *order;
  void                 (*f)(t_matrix *matrix);
};
typedef struct         s_capture_prompt t_capture_prompt;

struct                 s_prompt_oob
{
  char                 *order;
  void                 (*f)(t_matrix *matrix);
};
typedef struct         s_prompt_oob t_prompt_oob;

struct                 s_prompt_fight
{
  char                 *order;
  void                 (*f)(t_matrix *matrix);
};
typedef struct         s_prompt_fight t_prompt_fight;

struct                 s_prompt_shop
{
  char                 *order;
  void                 (*f)(t_matrix *matrix);
};
typedef struct         s_prompt_shop t_prompt_shop;

char			*readLine();
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
void			capture_prompt(t_matrix *matrix);
int			capture_prompt_cont(t_matrix *matrix, char *command);
void			magic_catch(t_matrix *matrix);
void			help_me(t_matrix *matrix);
void			quit(t_matrix *matrix);
void			prompt_oob(t_matrix *matrix);
void			prompt_oob_cont(t_matrix *matrix, char *command);
void			team(t_matrix *matrix);
void			choose_monster(t_matrix *matrix);
void			prompt_fight(t_matrix *matrix);
void			prompt_fight_cont(t_matrix *matrix, char *command);
void			prompt_shop(t_matrix *matrix);
void			prompt_shop_cont(t_matrix *matrix, char *command);
void			buy_mushroom(t_matrix *matrix);
void			buy_magic_box(t_matrix *matrix);
void			exit_shop(t_matrix *matrix);
void			slash(t_matrix *matrix);
void			fire(t_matrix *matrix);
void			gamble(t_matrix *matrix);
void			rest(t_matrix *matrix);
void			magic_catch_combat(t_matrix *matrix);
/*int			magic_catch_combat_prob(t_matrix *matrix);*/
void			run(t_matrix *matrix);




#endif
