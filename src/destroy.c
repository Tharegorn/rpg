/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy.c
*/

#include "rpg.h"

void destroy(menu_t *m, win_t *w, global_t *g)
{
    sfSprite_destroy(m->howto);
    destroy_menu(m);
    free(m);
    sfRenderWindow_destroy(w->win);
    free(w);
    destroy_mob(g);
    destroy_player(g);
    destroy_boss(g);
    destroy_game(g);
    free(g);
}