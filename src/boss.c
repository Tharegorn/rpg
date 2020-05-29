/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** boss.c
*/

#include "rpg.h"

void mob_animation(win_t *w, global_t *g)
{
    sfTime timer = sfMilliseconds(50);

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(g->boss->clock)) >=
    sfTime_asMilliseconds(timer)) {
        g->boss->rect.left += 872;
        if (g->boss->rect.left >= 4360) {
            g->boss->rect.left = 0;
            g->boss->rect.top += 632;
        }
        if (g->boss->rect.top >= 2528) {
            g->boss->rect.top = 0;
        }
        sfClock_restart(g->boss->clock);
    }
    sfSprite_setTextureRect(g->boss->boss, g->boss->rect);
    sfRenderWindow_drawSprite(w->win, g->boss->boss, NULL);
}

void boss(win_t *w, global_t *g)
{
    boss_event(w, g);
    sfSprite_setTextureRect(g->boss->front, g->boss->topmap);
    sfSprite_setTextureRect(g->boss->back, g->boss->topmap);
    sfRenderWindow_drawSprite(w->win, g->boss->back, NULL);
    sfRenderWindow_drawSprite(w->win, g->boss->front, NULL);
    sfRenderWindow_drawSprite(w->win, g->boss->player, NULL);
    mob_animation(w, g);
    sfRenderWindow_drawSprite(w->win, g->boss->layout, NULL);
    print_databoss(w, g);
}