/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu.c
*/

#include "rpg.h"

void hover_mode(menu_t *m, sfVector2i vect)
{
    if (button_is_clicked(m->rplay, vect) == 1)
        sfRectangleShape_setPosition(m->rplay, (sfVector2f) {170, 225});
    else
        sfRectangleShape_setPosition(m->rplay, (sfVector2f) {170, 220});
    if (button_is_clicked(m->rquit, vect) == 1)
        sfRectangleShape_setPosition(m->rquit, (sfVector2f) {170, 825});
    else
        sfRectangleShape_setPosition(m->rquit, (sfVector2f) {170, 820});
    if (button_is_clicked(m->rsettings, vect) == 1)
        sfRectangleShape_setPosition(m->rsettings, (sfVector2f) {170, 625});
    else
        sfRectangleShape_setPosition(m->rsettings, (sfVector2f) {170, 620});
    if (button_is_clicked(m->rhowto, vect) == 1)
        sfRectangleShape_setPosition(m->rhowto, (sfVector2f) {170, 425});
    else
        sfRectangleShape_setPosition(m->rhowto, (sfVector2f) {170, 420});
}

void check_pos_menu(menu_t *m, sfVector2i vect, sfRenderWindow *w, global_t *g)
{
    if (button_is_clicked(m->rplay, vect) == 1) {
        sfMusic_stop(m->mmusic);
        sfMusic_play(g->font_music);
        g->prev = 0;
        g->scene = 3;
    }
    if (button_is_clicked(m->rquit, vect) == 1) {
        sfRenderWindow_close(w);
    }
    if (button_is_clicked(m->rhowto, vect) == 1) {
        g->scene = 13;
        g->prev = 0;
    }
    if (button_is_clicked(m->rsettings, vect) == 1) {
        g->prev = 0;
        g->scene = 1;
    }
}

void event_menu(menu_t *m, win_t *w, global_t *g)
{
    sfEvent event;
    sfVector2i vect = sfMouse_getPositionRenderWindow(w->win);

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        hover_mode(m, vect);
        if (event.type == sfEvtMouseButtonReleased) {
            check_pos_menu(m, vect, w->win, g);
        }
        if (event.type == sfEvtTextEntered) {
            write(1, &event.text.unicode, 1);
        }
    }
}

void menu(menu_t *m, win_t *w, global_t *g)
{
    event_menu(m, w, g);
    sfRenderWindow_drawSprite(w->win, m->fontmenu, NULL);
    draw_rect_menu(m, w);
}