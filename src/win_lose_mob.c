/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** win_lose_mob.c
*/

#include "rpg.h"

void back(global_t *g, sfVector2i vect)
{
    if (button_is_clicked(g->alpha, vect) == 1) {
        g->scene = 3;
        g->tele = 0;
    }
}

void vent(win_t *w, global_t *g)
{
    sfEvent event;
    sfVector2i vect;

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        if (event.type == sfEvtMouseButtonReleased) {
            vect = sfMouse_getPositionRenderWindow(w->win);
            back(g, vect);
        }
    }
}

void win(win_t *w, global_t *g)
{
    vent(w, g);
    sfRenderWindow_drawSprite(w->win, g->mob->win, NULL);
    sfRenderWindow_drawRectangleShape(w->win, g->alpha, NULL);
}

void lose(win_t *w, global_t *g)
{
    vent(w, g);
    sfRenderWindow_drawSprite(w->win, g->mob->lose, NULL);
    sfRenderWindow_drawRectangleShape(w->win, g->alpha, NULL);
}