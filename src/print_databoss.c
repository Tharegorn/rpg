/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_databoss.c
*/

#include "rpg.h"

void print_databoss(win_t *w, global_t *g)
{
    sfText_setString(g->boss->bosslife, my_itoa(g->boss->hp));
    sfText_setString(g->boss->playerlife, my_itoa(g->p->hp));
    sfText_setString(g->boss->playerdmg, my_itoa(g->p->dmg));
    sfRenderWindow_drawText(w->win, g->boss->bosslife, NULL);
    sfRenderWindow_drawText(w->win, g->boss->playerdmg, NULL);
    sfRenderWindow_drawText(w->win, g->boss->playerlife, NULL);
    sfRenderWindow_drawRectangleShape(w->win, g->boss->atk, NULL);
    sfRenderWindow_drawRectangleShape(w->win, g->boss->healrec, NULL);
}