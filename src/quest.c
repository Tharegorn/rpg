/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest.c
*/

#include "rpg.h"

void print_quest(win_t *w, global_t *g)
{
    if (g->a == 20 && g->b == 15 && g->c == 10 && g->d == 5) {
        g->finish = 1;
    }
    if (g->tele == 4) {
        sfRenderWindow_drawText(w->win, g->droid, NULL);
        sfRenderWindow_drawText(w->win, g->ozef, NULL);
        sfRenderWindow_drawText(w->win, g->apple, NULL);
        sfRenderWindow_drawText(w->win, g->golem, NULL);
    }
}