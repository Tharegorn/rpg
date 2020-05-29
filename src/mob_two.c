/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** mob_two.c
*/

#include "rpg.h"

void init_mob_two(global_t *g)
{
    mob_t *m = g->mob;

    g->p->tp = g->p->armor + g->p->dmg;
    m->hp = 150;
    m->dmg = 150;
    m->armor = 150;
    m->xp = 100;
    m->tp = m->dmg + m->armor;
    sfText_setString(m->life, my_itoa(m->hp));
    sfText_setString(m->ttl, my_itoa(m->tp));
    sfText_setString(m->mob_name, "OZEF");
    g->p->chance = 100.0 - (((double)m->tp *
    (50.0 / 100.0))/ (double)g->p->tp * 100.0);
}

void mouse_mob_two(global_t *g, sfVector2i vect)
{
    if (button_is_clicked(g->next, vect) == 1) {
        init_mob_three(g);
        g->prev = 5;
        g->scene = 6;
    }
    if (button_is_clicked(g->prev_mob, vect) == 1) {
        init_mob_one(g);
        g->prev = 5;
        g->scene = 4;
    }
    launch_fight(g, vect);
}

void event_mob_two(win_t *w, global_t *g)
{
    sfEvent event;
    sfVector2i vect = sfMouse_getPositionRenderWindow(w->win);

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            g->prev = 5;
            g->scene = 1;
        }
        if (event.type == sfEvtMouseButtonReleased) {
            mouse_mob_two(g, vect);
        }
    }
}

void mob_two(win_t *w, global_t *g)
{
    event_mob_two(w, g);
    sfRenderWindow_drawSprite(w->win, g->mob_two, NULL);
    draw_mob_layout(w, g);
}