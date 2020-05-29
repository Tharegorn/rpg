/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** scene_selector.c
*/

#include "rpg.h"

void scene_selectortwo(win_t *w, menu_t *m, global_t *g)
{
    if (g->scene == 9)
        lose(w, g);
    if (g->scene == 10)
        boss(w, g);
    if (g->scene == 11)
        lose_end(w, g);
    if (g->scene == 12)
        win_end(w, g);
    if (g->scene == 13)
        how_to(w, m, g);
}

void scene_selector(win_t *w, menu_t *m, global_t *g)
{
    if (g->scene == 0)
        menu(m, w, g);
    if (g->scene == 1)
        settings(w, g, m);
    if (g->scene == 3)
        game_functions(g, w);
    if (g->scene == 4)
        mob_one(w, g);
    if (g->scene == 5)
        mob_two(w, g);
    if (g->scene == 6)
        mob_three(w, g);
    if (g->scene == 7)
        mob_four(w, g);
    if (g->scene == 8)
        win(w, g);
    scene_selectortwo(w, m, g);
}