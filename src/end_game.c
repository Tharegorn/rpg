/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** end_game.c
*/

#include "rpg.h"

void check_tele(win_t *w, global_t *g)
{
    if (g->tele == 1)
        check_mouse(w, g);
    check_shop(w, g);
}

void event(win_t *w)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            sfRenderWindow_close(w->win);
        }
    }
}

void win_end(win_t *w, global_t *g)
{
    event(w);
    sfRenderWindow_drawSprite(w->win, g->boss->swin, NULL);
}

void lose_end(win_t *w, global_t *g)
{
    event(w);
    sfRenderWindow_drawSprite(w->win, g->boss->slose, NULL);
}