/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** how_to.c
*/

#include "rpg.h"

void eventh(win_t *w, global_t *g)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape)){
            g->scene = 1;
            g->prev = 13;
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
    }
}

void how_to(win_t *w, menu_t *m, global_t *g)
{
    eventh(w, g);
    sfRenderWindow_drawSprite(w->win, m->howto, NULL);
}