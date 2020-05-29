/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** stats.c
*/

#include "rpg.h"

void print_p_stats(win_t *w, global_t *g)
{
    sfText_setString(g->p->life_text, my_itoa(g->p->hp));
    sfText_setString(g->p->xp_text, my_itoa(g->p->xp));
    sfText_setString(g->p->dmg_text, my_itoa(g->p->dmg));
    sfText_setString(g->p->tp_text, my_itoa(g->p->dmg + g->p->armor));
    sfText_setString(g->p->armor_text, my_itoa(g->p->armor));
    sfRenderWindow_drawText(w->win, g->p->xp_text, NULL);
    sfRenderWindow_drawText(w->win, g->p->dmg_text, NULL);
    sfRenderWindow_drawText(w->win, g->p->armor_text, NULL);
    sfRenderWindow_drawText(w->win, g->p->life_text, NULL);
    sfRenderWindow_drawText(w->win, g->p->tp_text, NULL);
}

void print_stats(win_t *w, global_t *g)
{
    player_t *p = g->p;

    sfRenderWindow_drawSprite(w->win, p->inventory, NULL);
    print_p_stats(w, g);
    if (p->stats[0] != 0) {
        sfText_setString(p->nb_dmg, my_itoa(p->stats[0]));
        sfRenderWindow_drawSprite(w->win, p->dmg_log, NULL);
        sfRenderWindow_drawText(w->win, p->nb_dmg, NULL);
    }
    if (p->stats[1] != 0) {
        sfText_setString(p->nb_armor, my_itoa(p->stats[1]));
        sfRenderWindow_drawSprite(w->win, p->armor_log, NULL);
        sfRenderWindow_drawText(w->win, p->nb_armor, NULL);
    }
    if (p->stats[2] != 0) {
        sfText_setString(p->nb_xp, my_itoa(p->stats[2]));
        sfRenderWindow_drawSprite(w->win, p->xp_log, NULL);
        sfRenderWindow_drawText(w->win, p->nb_xp, NULL);
    }
}