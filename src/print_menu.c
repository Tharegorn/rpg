/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_menu.c
*/

#include "rpg.h"

void draw_text_menu(menu_t *m, win_t *w)
{
    sfRenderWindow_drawText(w->win, m->tplay, NULL);
    sfRenderWindow_drawText(w->win, m->thowto, NULL);
    sfRenderWindow_drawText(w->win, m->tsettings, NULL);
    sfRenderWindow_drawText(w->win, m->texit, NULL);
}

void draw_rect_menu(menu_t *m, win_t *w)
{
    sfRenderWindow_drawRectangleShape(w->win, m->rplay, NULL);
    sfRenderWindow_drawRectangleShape(w->win, m->rhowto, NULL);
    sfRenderWindow_drawRectangleShape(w->win, m->rsettings, NULL);
    sfRenderWindow_drawRectangleShape(w->win, m->rquit, NULL);
}