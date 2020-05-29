/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_boss.c
*/

#include "rpg.h"

void init_bossfour(global_t *g)
{
    g->boss->hp = 5000;
    g->boss->dmg = 150;
    g->boss->heal = 300;
    g->boss->bosslife = create_font(g->boss->bosslife,
    my_itoa(g->boss->hp), 120, 40);
    sfText_setCharacterSize(g->boss->bosslife, 50);
    g->boss->playerlife = create_font(g->boss->playerlife,
    my_itoa(g->p->hp), 1120, 905);
    g->boss->playerdmg = create_font(g->boss->playerdmg,
    my_itoa(g->p->dmg), 580, 905);
    g->boss->layout = sfSprite_create();
    sfSprite_setPosition(g->boss->layout, (sfVector2f) { 0, 0});
    sfSprite_setTexture(g->boss->layout,
    sfTexture_createFromFile("files/life_layout.png", NULL), sfTrue);
}

void init_bossthree(global_t *g)
{
    g->boss->atk = sfRectangleShape_create();
    sfRectangleShape_setPosition(g->boss->atk, (sfVector2f) {0, 947});
    sfRectangleShape_setSize(g->boss->atk, (sfVector2f) {298, 133});
    sfRectangleShape_setTexture(g->boss->atk,
    sfTexture_createFromFile("files/attack.png", NULL), sfTrue);
    g->boss->healrec = sfRectangleShape_create();
    sfRectangleShape_setPosition(g->boss->healrec, (sfVector2f) {1622, 947});
    sfRectangleShape_setSize(g->boss->healrec, (sfVector2f) {298, 133});
    sfRectangleShape_setTexture(g->boss->healrec,
    sfTexture_createFromFile("files/heal.png", NULL), sfTrue);
    g->boss->slose = sfSprite_create();
    sfSprite_setPosition(g->boss->slose, (sfVector2f) { 0, 0});
    sfSprite_setTexture(g->boss->slose,
    sfTexture_createFromFile("files/lose-end.png", NULL), sfTrue);
    g->boss->swin = sfSprite_create();
    sfSprite_setPosition(g->boss->swin, (sfVector2f) { 0, 0});
    sfSprite_setTexture(g->boss->swin,
    sfTexture_createFromFile("files/win_end.png", NULL), sfTrue);
    init_bossfour(g);
}

void init_bosstwo(global_t *g)
{
    sfSprite_setPosition(g->boss->player, (sfVector2f) {900, 850});
    sfSprite_setScale(g->boss->player, (sfVector2f) {2, 2});
    g->boss->topmap.left = 960;
    g->boss->topmap.top = 0;
    g->boss->topmap.height = 1080;
    g->boss->topmap.width = 1920;
    g->boss->back = sfSprite_create();
    sfSprite_setPosition(g->boss->back, (sfVector2f) { 0, 0});
    sfSprite_setTextureRect(g->boss->back, g->boss->topmap);
    sfSprite_setTexture(g->boss->back,
    sfTexture_createFromFile("files/back.png", NULL), sfTrue);
    g->boss->front = sfSprite_create();
    sfSprite_setPosition(g->boss->front, (sfVector2f) { 0, 0});
    sfSprite_setTextureRect(g->boss->front, g->boss->topmap);
    sfSprite_setTexture(g->boss->front,
    sfTexture_createFromFile("files/front.png", NULL), sfTrue);
    init_bossthree(g);
}

void init_boss(global_t *g)
{
    g->boss->boss = sfSprite_create();
    g->boss->rect.left = 0;
    g->boss->rect.top = 0;
    g->boss->rect.height = 632;
    g->boss->rect.width = 872;
    sfSprite_setTexture(g->boss->boss,
    sfTexture_createFromFile("files/boss.png", NULL), sfTrue);
    sfSprite_setTextureRect(g->boss->boss, g->boss->rect);
    sfSprite_setScale(g->boss->boss, (sfVector2f) {1, 1});
    sfSprite_setPosition(g->boss->boss, (sfVector2f) {500, 0});
    g->boss->clock = sfClock_create();
    g->boss->rekt.left = 0;
    g->boss->rekt.top = 0;
    g->boss->rekt.width = 43.25;
    g->boss->rekt.height = 73;
    g->boss->player = sfSprite_create();
    sfSprite_setTexture(g->boss->player,
    sfTexture_createFromFile("files/sans_right.png", NULL), sfTrue);
    sfSprite_setTextureRect(g->boss->player, g->boss->rekt);
    init_bosstwo(g);
}