/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** settings.c
*/

#include "rpg.h"

void modif_volume(menu_t *m, sfVector2i vect)
{
    if (button_is_clicked(m->one, vect) == 1)
        m->volume = 10;
    if (button_is_clicked(m->two, vect) == 1)
    m->volume = 20;
    if (button_is_clicked(m->three, vect) == 1)
    m->volume = 30;
    if (button_is_clicked(m->four, vect) == 1)
    m->volume = 40;
    if (button_is_clicked(m->five, vect) == 1)
    m->volume = 50;
    if (button_is_clicked(m->six, vect) == 1)
    m->volume = 60;
    if (button_is_clicked(m->seven, vect) == 1)
    m->volume = 70;
    if (button_is_clicked(m->height, vect) == 1)
    m->volume = 80;
    if (button_is_clicked(m->nine, vect) == 1)
    m->volume = 90;
    if (button_is_clicked(m->ten, vect) == 1)
    m->volume = 100;

}

void print_volume(win_t *w, menu_t *m)
{
    if (m->volume >= 100)
        sfRenderWindow_drawRectangleShape(w->win, m->ten, NULL);
    if (m->volume >= 90)
        sfRenderWindow_drawRectangleShape(w->win, m->nine, NULL);
    if (m->volume >= 80)
        sfRenderWindow_drawRectangleShape(w->win, m->height, NULL);
    if (m->volume >= 70)
        sfRenderWindow_drawRectangleShape(w->win, m->seven, NULL);
    if (m->volume >= 60)
        sfRenderWindow_drawRectangleShape(w->win, m->six, NULL);
    if (m->volume >= 50)
        sfRenderWindow_drawRectangleShape(w->win, m->five, NULL);
    if (m->volume >= 40)
        sfRenderWindow_drawRectangleShape(w->win, m->four, NULL);
    if (m->volume >= 30)
        sfRenderWindow_drawRectangleShape(w->win, m->three, NULL);
    if (m->volume >= 20)
        sfRenderWindow_drawRectangleShape(w->win, m->two, NULL);
    if (m->volume >= 10)
        sfRenderWindow_drawRectangleShape(w->win, m->one, NULL);
}

void settings_event(win_t *w, global_t *g, menu_t *m)
{
    sfEvent event;
    sfWindow *actual = NULL;
    sfVector2i vect;

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            g->scene = 0;
        }
        if (event.type == sfEvtMouseButtonReleased) {
            vect = sfMouse_getPosition(actual);
            modif_volume(m, vect);
        }
    }
    sfWindow_destroy(actual);
}

void settings(win_t *w, global_t *g, menu_t *m)
{
    sfMusic_setVolume(m->mmusic, m->volume);
    sfMusic_setVolume(g->font_music, g->volume);
    settings_event(w, g, m);
    sfRenderWindow_drawSprite(w->win, m->fontmenu, NULL);
    sfRenderWindow_drawSprite(w->win, m->fontsettings, NULL);
    print_volume(w, m);
}