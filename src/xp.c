/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** xp.c
*/

#include "rpg.h"

void mob_quest(global_t *g)
{
    if (g->mob->xp == 50 && g->a < 20) {
        g->a++;
    }
    if (g->mob->xp == 100 && g->b < 15) {
        g->b++;
    }
    if (g->mob->xp == 150 && g->c < 10) {
        g->c++;
    }
    if (g->mob->xp == 300 && g->d < 5) {
        g->d++;
    }
}

void minus_xp(global_t *g)
{
    if (g->p->xp < g->mob->xp)
        g->p->xp = 0;
    else
        g->p->xp -= g->mob->xp;
}

void plus_xp(global_t *g)
{
    g->p->xp += g->mob->xp;
}

void launch_fight(global_t *g, sfVector2i vect)
{
    if (button_is_clicked(g->fight, vect) == 1) {
        if (battle_farming(g) == 1) {
            mob_quest(g);
            g->scene = 8;
            plus_xp(g);
        } else {
            g->scene = 9;
            minus_xp(g);
        }
    }
}