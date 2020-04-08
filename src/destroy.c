/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy.c
*/

#include "rpg.h"

void destroy(menu_t *m, win_t *w)
{
    sfRenderWindow_destroy(w->win);
    free(w);
    sfRectangleShape_destroy(m->rhowto);
    sfRectangleShape_destroy(m->rsettings);
    sfRectangleShape_destroy(m->rplay);
    sfRectangleShape_destroy(m->rquit);
    sfMusic_destroy(m->mmusic);
    free(m);
}