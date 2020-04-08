/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** game.c
*/

#include "rpg.h"

void left_rect(global_t *g)
{
    int i = g->rect.left;

    sfSprite_setPosition(g->background, (sfVector2f) { g->player_x += 20, g->player_y});
    if (i == 0) {
        sfSprite_setTextureRect(g->player, g->rect);
        g->rect.left += 30;
    } else {
        if (i > 150)
            g->rect.left = 0;
        g->rect.left += 40;
        g->rect.top = 150;
        sfSprite_setTextureRect(g->player, g->rect);
    }
}

void right_rect(global_t *g)
{
    int i = g->rect.left;

    sfSprite_setPosition(g->background, (sfVector2f) { g->player_x -= 20, g->player_y});
    if (i == 0) {
        sfSprite_setTextureRect(g->player, g->rect);
        g->rect.left += 30;
    } else {
        if (i > 150)
            g->rect.left = 0;
        g->rect.left += 40;
        g->rect.top = 75;
        sfSprite_setTextureRect(g->player, g->rect);
    }
}

void event_game(win_t *w, global_t *g)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(w->win);
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            left_rect(g);
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            right_rect(g);
    }
}

void game_functions(global_t *g, win_t *w)
{
    event_game(w, g);
    sfRenderWindow_drawSprite(w->win, g->background, NULL);
    sfRenderWindow_drawSprite(w->win, g->player, NULL);
}