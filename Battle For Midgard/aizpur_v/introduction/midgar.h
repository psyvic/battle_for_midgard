/*
** midgar.h for midgar.h in /home/vic/Desktop/piscine/C/midgar/aizpur_v/introduction
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri May 12 15:19:12 2017 AIZPURUA Victor Hugo
** Last update Sat May 13 19:15:47 2017 AIZPURUA Victor Hugo
*/

#ifndef			_MIDGAR_H_
#define			_MIDGAR_H_
#define                 NBCREA 5
#define                 CATCH_PROB 3
#define			RUPEES 31
#define			MONSTER 2
#define			GAMBLE 21
#define			MUSHROOM 11

struct			s_player
{
  char			*name;
  int			money;
  int			mushroom;
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
  int			is_savage;
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
  int                 (*f)(t_creature *attacker, t_creature *defenser, t_matrix *matrix);
};
typedef struct         s_prompt_fight t_prompt_fight;

struct			s_prompt_shop
{
  char			*order;
  void                   (*f)(t_matrix *matrix);
};
typedef struct		s_prompt_shop t_prompt_shop;

char			*readLine();
void			my_putchar(char c);
void			my_putstr(char *str);
int			my_strcmp(char *s1, char *s2);
void			my_put_nbr(int n);
char			*my_strdup(const char *str);
int			my_getnbr(char *str);
t_matrix                *create_matrix();
int	                create_team(t_matrix *matrix);
int		        create_player(t_matrix *matrix);
t_creature              *get_creature();
void			capture_prompt(t_matrix *matrix);
void			magic_catch(t_matrix *matrix);
void			help_me(t_matrix *matrix);
void			quit(t_matrix *matrix);
void			prompt_oob(t_matrix *matrix);
void			prompt_oob_cont(t_matrix *matrix, char *command);
void			team(t_matrix *matrix);
void			team_cont(t_matrix *matrix);
void			choose_monster(t_matrix *matrix);
void			mushroom(t_matrix *matrix);
void			prompt_fight(t_matrix *matrix);
int			prompt_fight_cont(t_matrix *matrix, char *command);
void			prompt_shop(t_matrix *matrix);
void			prompt_shop_cont(t_matrix *matrix, char *command);
void			buy_mushroom(t_matrix *matrix);
void			buy_magic_box(t_matrix *matrix);
void			exit_shop(t_matrix *matrix);
int			slash(t_creature *, t_creature *, t_matrix *);
int			fire(t_creature *, t_creature *,  t_matrix *);
int			gamble(t_creature *, t_creature *,  t_matrix *);
int			rest(t_creature *, t_creature *,  t_matrix *);
int			magic_catch_combat(t_creature *, t_creature *,\
					   t_matrix *);
int			run(t_creature *, t_creature *,  t_matrix *);
void			add_creature_to_team(t_matrix *matrix, \
					     t_creature *creature);
void			destroy_creature(t_matrix *matrix);
void			enemy_defeated(t_matrix *matrix);
void			del_creature_from_team(t_matrix *matrix);
void			del_prob(t_matrix *matrix);
void			enemy_attack(t_matrix *);
void			instructions(t_matrix *);
void			my_putstr_color(char *color, char *str);
extern const		t_prompt_fight g_prompt_fight[];
void			level_up(t_matrix *matrix);

#endif			/* !_MIDGAR_H_ */
