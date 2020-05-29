/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** player.c
*/

#include "rpg.h"

void player_check_mouse(sfVector2i vect, global_t *g)
{
    if (vect.x >= 866 && vect.x <= 919 && vect.y >= 218 && vect.y <= 258) {
        g->tele = 0;
    }
}

void init_player_stats(global_t *g)
{
    g->p->armor = 100;
    g->p->dmg = 100;
    g->p->hp = 100;
    g->p->tp = 200;
    g->p->player_name = create_font(g->p->player_name, "Unknow", 300, 80);
    g->p->life = create_font(g->p->life, my_itoa(g->p->hp), 300, 760);
    g->p->ttl = create_font(g->p->ttl, my_itoa(g->p->tp), 300, 860);
    sfText_setColor(g->p->life, sfGreen);
    g->p->perc = create_font(g->p->perc, "Unknow", 900, 850);
    g->p->chance = 0;
}

void player_draw_stat(win_t *w, global_t *g)
{
    sfText_setString(g->p->life, my_itoa(g->p->hp));
    sfText_setString(g->p->ttl, my_itoa(g->p->armor + g->p->dmg));
    sfRenderWindow_drawText(w->win, g->p->player_name, NULL);
    sfRenderWindow_drawText(w->win, g->p->life, NULL);
    sfRenderWindow_drawText(w->win, g->p->ttl, NULL);
    if (g->p->chance < 0) {
        sfText_setPosition(g->p->perc, (sfVector2f) {760, 850});
        sfText_setString(g->p->perc, "Too low");
    } else
        sfText_setPosition(g->p->perc, (sfVector2f) {900, 850});
    sfRenderWindow_drawText(w->win, g->p->perc, NULL);
}

void draw_mob_layout(win_t *w, global_t *g)
{
    sfRenderWindow_drawRectangleShape(w->win, g->prev_mob, NULL);
    sfRenderWindow_drawRectangleShape(w->win, g->next, NULL);
    sfRenderWindow_drawText(w->win, g->mob->ttl, NULL);
    sfRenderWindow_drawText(w->win, g->mob->mob_name, NULL);
    sfRenderWindow_drawText(w->win, g->mob->life, NULL);
    sfRenderWindow_drawRectangleShape(w->win, g->fight, NULL);
    sfText_setString(g->p->perc, my_itoa(g->p->chance));
    player_draw_stat(w, g);
}