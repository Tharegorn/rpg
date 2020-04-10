/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu.c
*/

#include "rpg.h"

void check_pos_menu(menu_t *m, sfVector2i vect, sfRenderWindow *w, global_t *g)
{
    if (button_is_clicked(m->rplay, vect) == 1) {
        sfMusic_stop(m->mmusic);
        sfMusic_play(g->font_music);
        g->scene = 3;
    }
    if (button_is_clicked(m->rquit, vect) == 1) {
        sfRenderWindow_close(w);
    }
    if (button_is_clicked(m->rhowto, vect) == 1) {
    }
    if (button_is_clicked(m->rsettings, vect) == 1) {
        g->scene = 1;
    }
}

void event_menu(menu_t *m, win_t *w, global_t *g)
{
    sfEvent event;
    sfVector2i vect;

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        if (event.type == sfEvtMouseButtonReleased) {
            vect = sfMouse_getPositionRenderWindow(w->win);
            check_pos_menu(m, vect, w->win, g);
        }
    }
}

void menu(menu_t *m, win_t *w, global_t *g)
{
    sfRenderWindow_drawSprite(w->win, m->fontmenu, NULL);
    draw_text_menu(m, w);
    draw_rect_menu(m, w);
    event_menu(m, w, g);
}