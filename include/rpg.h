/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>

#ifndef structures
#define structures

typedef struct boss
{
    int hp;
    int dmg;
    int heal;

    sfRectangleShape *atk;
    sfRectangleShape *healrec;
    sfText *bosslife;
    sfText *playerlife;
    sfText *playerdmg;
    sfSprite *swin;
    sfSprite *slose;
    sfSprite *back;
    sfSprite *front;
    sfSprite *boss;
    sfSprite *player;
    sfSprite *layout;
    sfClock *clock;
    sfIntRect rekt;
    sfIntRect topmap;
    sfIntRect rect;


} boss_t;

typedef struct player_stats
{
    sfText *player_name;
    sfText *life;
    sfText *ttl;
    sfText *perc;

    //badges
    sfSprite *inventory;
    sfSprite *xp_log;
    sfSprite *dmg_log;
    sfSprite *armor_log;
    sfText *nb_xp;
    sfText *nb_dmg;
    sfText *nb_armor;

    //Stats
    sfText *xp_text;
    sfText *life_text;
    sfText *dmg_text;
    sfText *tp_text;
    sfText *armor_text;
    int xp;
    int chance;
    int tp;
    int *stats;
    int hp;
    int armor;
    int dmg;
} player_t;

typedef struct mob_stats
{
    sfSprite *win;
    sfSprite *lose;
    sfText *mob_name;
    sfText *ttl;
    sfText *life;
    int xp;
    int tp;
    int hp;
    int armor;
    int dmg;

} mob_t;

typedef struct win
{
    sfRenderWindow *win;
} win_t;

typedef struct menus
{
    sfRectangleShape *home;
    sfRectangleShape *rplay;
    sfRectangleShape *rquit;
    sfRectangleShape *rsettings;
    sfRectangleShape *rhowto;
    sfRectangleShape *exit;
    sfRectangleShape *prev;
    sfRectangleShape *one;
    sfRectangleShape *two;
    sfRectangleShape *three;
    sfRectangleShape *four;
    sfRectangleShape *five;
    sfRectangleShape *six;
    sfRectangleShape *seven;
    sfRectangleShape *height;
    sfRectangleShape *nine;
    sfRectangleShape *ten;
    sfMusic *mmusic;
    sfSprite *howto;
    sfSprite *fontsettings;
    sfSprite *fontmenu;
    int volume;
} menu_t;

typedef struct global_game
{
    sfView *view;
    sfIntRect rect;
    sfIntRect rekt;

    sfMusic *font_music;
    sfSprite *world;
    sfSprite *mob_one;
    sfSprite *mob_two;
    sfSprite *mob_three;
    sfSprite *mob_four;
    sfSprite *shop;
    sfSprite *player;
    sfSprite *background;
    sfText *xp;
    sfText *press;
    sfText *droid;
    sfText *ozef;
    sfText *apple;
    sfText *golem;
    sfRectangleShape *fight;
    sfRectangleShape *prev_mob;
    sfRectangleShape *next;
    sfRectangleShape *alpha;
    sfVector2f player_pos;
    sfVector2f player_scale;
    int finish;
    int a;
    int b;
    int c;
    int d;
    int ttl_boost;
    int tele;
    int volume;
    int scene;
    int prev;
    int active;
    int i;

    boss_t *boss;
    player_t *p;
    mob_t *mob;
} global_t;

void how_to(win_t *w, menu_t *m, global_t *g);
void view(global_t *g);
void check_tele(win_t *w, global_t *g);
void win_end(win_t *w, global_t *g);
void lose_end(win_t *w, global_t *g);
int boss_farming(void);
void boss(win_t *w, global_t *g);
void win(win_t *w, global_t *g);
void lose(win_t *w, global_t *g);
void select_shop(global_t *g);
void check_shop(win_t *w, global_t *g);
int pnj(global_t *g);
void reset_rekt(double width, double height, global_t *g);
void change_player_texture(char *filename, global_t *g);
void right_anim(global_t *g, win_t *w);
void left_anim(global_t *g, win_t *w);
int battle_farming(global_t *g);
void mob_one(win_t *w, global_t *g);
void mob_two(win_t *w, global_t *g);
void mob_three(win_t *w, global_t *g);
void mob_four(win_t *w, global_t *g);
void game_functions(global_t *g, win_t *w);

//destoy

void destroy(menu_t *m, win_t *w, global_t *g);
void destroy_game(global_t *g);
void destroy_boss(global_t *g);
void destroy_mob(global_t *g);
void destroy_player(global_t *g);
void destroy_menu(menu_t *m);

//events
void boss_event(win_t *w, global_t *g);
void player_check_mouse(sfVector2i vect, global_t *g);
void check_position(global_t *g);
void launch_fight(global_t *g, sfVector2i vect);
void check_mouse(win_t *w, global_t *g);
void scene_selector(win_t *w, menu_t *m, global_t *g);
void settings(win_t *w, global_t *g, menu_t *m);
void event_menu(menu_t *m, win_t *w, global_t *g);

// init
void init_boss(global_t *g);
void init_gamefour(global_t *g);
void initializer(menu_t *m, global_t *g);
void init_player_stats(global_t *g);
void init_menu_three(menu_t *m);
void init_mob_one(global_t *g);
void init_mob_two(global_t *g);
void init_mob_three(global_t *g);
void init_mob_four(global_t *g);
int get_volume(void);
int check_params(char **tab, char *str);
void not_dir(void);
void error_in_file(void);
void init_game(global_t *g, int volume);
sfText *create_font(sfText *text, char *str, int x, int y);
void init_menu(menu_t *m);
sfRenderWindow *createwin(sfRenderWindow *w);

//  lib
char *my_itoa(int nb);
char *my_strcat(char *s1, char *s2);
char *my_strdup(char *s);
int my_atoi(char *s);
int options(char **tab, char *str);
char **str_warray(char const *str);
int my_strcmp(char *s, char *str);
int my_strlen(char *s);
void my_putstr(char *s);
int button_is_clicked(sfRectangleShape *rect, sfVector2i click_pos);



//print
void print_databoss(win_t *w, global_t *g);
void print_quest(win_t *w, global_t *g);
void print_stats(win_t *w, global_t *g);
void draw_mob_layout(win_t *w, global_t *g);
void player_draw_stat(win_t *w, global_t *g);
void draw_rect_menu(menu_t *m, win_t *w);
void menu(menu_t *m, win_t *w, global_t *g);

void print_help(void);

#endif