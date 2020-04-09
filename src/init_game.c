/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_game.c
*/

#include "rpg.h"

void init_game(global_t *g)
{
    g->rect.left = 10;
    g->rect.top = 0;
    g->rect.height = 75;
    g->rect.width = 50;
    g->back_rect.left = 0;
    g->back_rect.top = 0;
    g->back_rect.width = 3840;
    g->back_rect.height = 2160;
    g->player_x = 0;
    g->player_y = 0;
    g->tele = 0;
    g->font_music = sfMusic_createFromFile("sounds/game.ogg");
    sfMusic_setLoop(g->font_music, sfTrue);
    g->world = sfSprite_create();
    sfSprite_setTexture(g->world, sfTexture_createFromFile("files/world.png", NULL), sfTrue);
    sfSprite_setPosition(g->world, (sfVector2f) { 500, 400});
    sfSprite_setScale(g->world, (sfVector2f) { 0.5, 0.5});
    g->player = sfSprite_create();
    sfSprite_setTexture(g->player, sfTexture_createFromFile("files/sans.png", NULL), sfTrue);
    sfSprite_setTextureRect(g->player, g->rect);
    sfSprite_setScale(g->player, (sfVector2f) { 2, 2});
    g->background = sfSprite_create();
    sfSprite_setTexture(g->background, sfTexture_createFromFile("files/back_game.jpg", NULL), sfTrue);
    sfSprite_setScale(g->background, (sfVector2f) {0.5, 0.5});
    sfSprite_setTextureRect(g->background, g->back_rect);
}