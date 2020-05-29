/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** anim_player
*/
#include "rpg.h"

void left_anim(global_t *g, win_t *w)
{
    int i = g->rect.left;

    if (g->player_pos.x >= 300) {
        g->player_pos.y -= 2;
    }
    if (g->player_pos.x >= 100)
        g->player_pos.x -= 10;
    if (i >= 120)
        g->rect.left = 0;
    g->rect.left += 43.25;
    if (g->player_pos.x >= 600 && g->player_pos.x <= 1800) {
        g->player_pos.y += 0.5;
        g->player_scale.x -= 0.01;
        g->player_scale.y -= 0.01;
    }
    sfSprite_setTextureRect(g->player, g->rect);
    sfSprite_setScale(g->player, g->player_scale);
    sfSprite_setPosition(g->player, g->player_pos);
    sfRenderWindow_drawSprite(w->win, g->player, NULL);
}

void right_anim(global_t *g, win_t *w)
{
    int i = g->rekt.left;

    if (g->player_pos.x >= 300 && g->player_pos.x <= 1800) {
        g->player_pos.y += 2;
    }
    if (g->player_pos.x <= 1800)
        g->player_pos.x += 10;
    if (i >= 120)
        g->rekt.left = 0;
    g->rekt.left += 43;
    if (g->player_pos.x >= 600 && g->player_pos.x <= 1800) {
        g->player_pos.y -= 0.5;
        g->player_scale.x += 0.01;
        g->player_scale.y += 0.01;
    }
    sfSprite_setTextureRect(g->player, g->rekt);
    sfSprite_setScale(g->player, g->player_scale);
    sfSprite_setPosition(g->player, g->player_pos);
    sfRenderWindow_drawSprite(w->win, g->player, NULL);
}