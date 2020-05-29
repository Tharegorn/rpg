/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** boss_event.c
*/

#include "rpg.h"

void buttons(global_t *g)
{
    if (g->boss->hp <= g->p->dmg) {
        g->boss->hp = 0;
        g->scene = 12;
    }
    g->boss->hp -= g->p->dmg;
    if (boss_farming() == 1)
        g->boss->hp += 300;
    else if (g->p->hp <= 250) {
        g->p->hp = 0;
        g->scene = 11;
    }
    else
        g->p->hp -= 250;
}

void boss_fight(global_t *g, sfVector2i vect)
{
    if (button_is_clicked(g->boss->atk, vect) == 1) {
        buttons(g);
    }
    if (button_is_clicked(g->boss->healrec, vect) == 1) {
        g->p->hp += 50;
        if (boss_farming() == 1)
            g->boss->hp += 300;
        else if (g->p->hp <= 250) {
            g->p->hp = 0;
            g->scene = 12;
        }
        else
            g->p->hp -= 250;
    }
}

void left(win_t *w, global_t *g)
{
    int i = g->boss->rekt.left;

    if (g->boss->topmap.left <= 0)
        g->boss->topmap.left = 1920;
    g->boss->topmap.left -= 10;
    if (i >= 120)
        g->boss->rekt.left = 0;
    g->boss->rekt.left += 43.25;
    sfSprite_setTextureRect(g->boss->player, g->boss->rekt);
    sfRenderWindow_drawSprite(w->win, g->boss->player, NULL);
}

void right(win_t *w, global_t *g)
{
    int i = g->boss->rekt.left;

    if (g->boss->topmap.left >= 1920)
        g->boss->topmap.left = 0;
    g->boss->topmap.left += 10;
    if (i >= 120)
        g->boss->rekt.left = 0;
    g->boss->rekt.left += 43.25;
    sfSprite_setTextureRect(g->boss->player, g->boss->rekt);
    sfRenderWindow_drawSprite(w->win, g->boss->player, NULL);
}

void boss_event(win_t *w, global_t *g)
{
    sfEvent event;
    sfVector2i vect = sfMouse_getPositionRenderWindow(w->win);

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            sfSprite_setTexture(g->boss->player,
            sfTexture_createFromFile("files/sans_left.png", NULL), sfTrue);
            left(w, g);
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            sfSprite_setTexture(g->boss->player,
            sfTexture_createFromFile("files/sans_right.png", NULL), sfTrue);
            right(w, g);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            g->prev = 10;
            g->scene = 1;
        }
        if (event.type == sfEvtMouseButtonReleased)
            boss_fight(g, vect);
    }
}