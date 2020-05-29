/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_placement
*/
#include "rpg.h"

void reset_rekt(double width, double height, global_t *g)
{
    g->rect.left = 0;
    g->rect.top = 0;
    g->rect.width = width;
    g->rect.height = height;
}

void change_player_texture(char *filename, global_t *g)
{
    sfSprite_setTexture(g->player,
    sfTexture_createFromFile(filename, NULL), sfTrue);
}