/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** mob_three.c
*/

#include "rpg.h"

void init_mob_three(global_t *g)
{
    mob_t *m = g->mob;

    g->p->tp = g->p->armor + g->p->dmg;
    m->hp = 200;
    m->dmg = 200;
    m->armor = 200;
    m->xp = 150;
    m->tp = m->dmg + m->armor;
    sfText_setString(m->life, my_itoa(m->hp));
    sfText_setString(m->ttl, my_itoa(m->tp));
    sfText_setString(m->mob_name, "APPLE");
    g->p->chance = 100.0 - (((double)m->tp *
    (50.0 / 100.0))/ (double)g->p->tp * 100.0);
}

void mouse_mob_three(global_t *g, sfVector2i vect)
{
    if (button_is_clicked(g->next, vect) == 1) {
        init_mob_four(g);
        g->prev = 6;
        g->scene = 7;
    }
    if (button_is_clicked(g->prev_mob, vect) == 1) {
        init_mob_two(g);
        g->prev = 6;
        g->scene = 5;
    }
    launch_fight(g, vect);
}

void event_mob_three(win_t *w, global_t *g)
{
    sfEvent event;
    sfVector2i vect = sfMouse_getPositionRenderWindow(w->win);

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            g->prev = 6;
            g->scene = 1;
        }
        if (event.type == sfEvtMouseButtonReleased) {
            mouse_mob_three(g, vect);
        }
    }
}

void mob_three(win_t *w, global_t *g)
{
    event_mob_three(w, g);
    sfRenderWindow_drawSprite(w->win, g->mob_three, NULL);
    draw_mob_layout(w, g);
}