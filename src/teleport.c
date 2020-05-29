/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** teleport.c
*/

#include "rpg.h"

void check_mouse(win_t *w, global_t *g)
{
    sfVector2i vect;

    vect = sfMouse_getPositionRenderWindow(w->win);
    if ((vect.x >= 505 && vect.x <= 975) && (vect.y >= 400 && vect.y <= 566)) {
        init_mob_one(g);
        g->prev = 3;
        g->scene = 4;
    } else if ((vect.x >= 985 && vect.x <= 1460)
    && (vect.y >= 400 && vect.y <= 566)) {
        if (g->finish == 1)
            g->scene = 10;
        if (g->finish != 1)
            g->tele = 0;
    } else {
        g->tele = 0;
    }
}