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

typedef struct win
{
    sfRenderWindow *win;
} win_t;

typedef struct menus
{
    sfRectangleShape *rplay;
    sfRectangleShape *rquit;
    sfRectangleShape *rsettings;
    sfRectangleShape *rhowto;
    sfMusic *mmusic;
    sfSprite *fontsettings;
    sfSprite *fontmenu;
    sfSprite *test;
    sfText *texit;
    sfText *tplay;
    sfText *tsettings;
    sfText *thowto;
    sfRectangleShape *none;
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
    int volume;
} menu_t;

typedef struct global_game
{
    sfIntRect rect;
    sfIntRect back_rect;
    sfSprite *player;
    sfSprite *background;
    sfMusic *font_music;
    sfSprite *world;
    int tele;
    int volume;
    int player_x;
    int player_y;
    int scene;
} global_t;


void game_functions(global_t *g, win_t *w);

//destoy

void destroy(menu_t *m, win_t *w);

//events
void settings(win_t *w, global_t *g, menu_t *m);
void event_menu(menu_t *m, win_t *w, global_t *g);

// init
int get_volume(void);
int check_params(char **tab, char *str);
void not_dir(void);
void error_in_file(void);
void init_game(global_t *g);
sfText *create_font(sfText *text, char *str, int x, int y);
void init_menu(menu_t *m);
sfRenderWindow *createwin(sfRenderWindow *w);

//  lib
int options(char **tab, char *str);
char **str_warray(char const *str);
int my_strcmp(char *s, char *str);
int my_strlen(char *s);
void my_putstr(char *s);
int button_is_clicked(sfRectangleShape *rect, sfVector2i click_pos);



//print

void draw_text_menu(menu_t *m, win_t *w);
void draw_rect_menu(menu_t *m, win_t *w);
void menu(menu_t *m, win_t *w, global_t *g);

void print_help(void);

#endif