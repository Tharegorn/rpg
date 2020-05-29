/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_game_two.c
*/

#include "rpg.h"

void init_gameseven(global_t *g)
{
    g->droid = create_font(g->droid, "0", 800, 600);
    g->ozef = create_font(g->ozef, "0", 800, 685);
    g->apple = create_font(g->apple, "0", 800, 770);
    g->golem = create_font(g->golem, "0", 800, 865);
    sfText_setCharacterSize(g->droid, 40);
    sfText_setCharacterSize(g->ozef, 40);
    sfText_setCharacterSize(g->apple, 40);
    sfText_setCharacterSize(g->golem, 40);
    g->a = 0;
    g->b = 0;
    g->c = 0;
    g->d = 0;
    g->finish = 0;
    g->view = sfView_create();
    sfView_setCenter(g->view, (sfVector2f) {960, 540});
    sfView_setSize(g->view, (sfVector2f) {1920, 1080});
    g->active = 0;
    g->i = 0;
}

void init_gamesix(global_t *g)
{
    player_t *p = g->p;

    p->armor_log = sfSprite_create();
    sfSprite_setPosition(p->armor_log, (sfVector2f) { 1225, 265});
    sfSprite_setTexture(p->armor_log,
    sfTexture_createFromFile("files/armor_logo.png", NULL), sfTrue);
    p->nb_xp = create_font(p->nb_xp, "0", 1220, 465);
    p->nb_dmg = create_font(p->nb_dmg, "0", 1100, 320);
    p->nb_armor = create_font(p->nb_armor, "0", 1325, 320);
    sfText_setCharacterSize(p->nb_dmg, 50);
    sfText_setCharacterSize(p->nb_xp, 50);
    sfText_setCharacterSize(p->nb_armor, 50);
    sfSprite_setScale(p->dmg_log, (sfVector2f) { 1.5, 1.5});
    sfSprite_setScale(p->armor_log, (sfVector2f) { 1.5, 1.5});
    sfSprite_setScale(p->xp_log, (sfVector2f) { 1.5, 1.5});
    p->xp_text = create_font(p->xp_text, "NULL", 700, 760);
    p->dmg_text = create_font(p->dmg_text, "NULL", 700, 600);
    p->armor_text = create_font(p->armor_text, "NULL", 700, 680);
    p->tp_text = create_font(p->tp_text, "NULL", 700, 520);
    p->life_text = create_font(p->life_text, "NULL", 700, 430);
    init_gameseven(g);
}

void init_gamefive(global_t *g)
{
    player_t *p = g->p;

    p->stats = malloc(sizeof(int) * 3);
    p->stats[0] = 0;
    p->stats[1] = 0;
    p->stats[2] = 0;
    p->inventory = sfSprite_create();
    sfSprite_setPosition(p->inventory, (sfVector2f) { 500, 200});
    sfSprite_setTexture(p->inventory,
    sfTexture_createFromFile("files/stats.png", NULL), sfTrue);
    sfSprite_setScale(p->inventory, (sfVector2f) { 0.6, 0.6});
    p->xp_log = sfSprite_create();
    sfSprite_setPosition(p->xp_log, (sfVector2f) { 1118, 416});
    sfSprite_setTexture(p->xp_log,
    sfTexture_createFromFile("files/life_logo.png", NULL), sfTrue);
    p->dmg_log = sfSprite_create();
    sfSprite_setPosition(p->dmg_log, (sfVector2f) { 997, 265});
    sfSprite_setTexture(p->dmg_log,
    sfTexture_createFromFile("files/dmg_logo.png", NULL), sfTrue);
    init_gamesix(g);
}

void init_gamefour(global_t *g)
{
    g->next = sfRectangleShape_create();
    sfRectangleShape_setPosition(g->next, (sfVector2f) {1820, 540});
    sfRectangleShape_setSize(g->next, (sfVector2f) {100, 73});
    sfRectangleShape_setTexture(g->next,
    sfTexture_createFromFile("files/next.png", NULL), sfTrue);
    sfSprite_setPosition(g->player, (sfVector2f) { 100, 650});
    g->player_pos.x = 100;
    g->player_pos.y = 650;
    g->shop = sfSprite_create();
    sfSprite_setPosition(g->shop, (sfVector2f) { 750, 190});
    g->xp = create_font(g->xp, "0", 0, 0);
    g->press = create_font(g->press, "PRESS E", 0, 0);
    sfText_setCharacterSize(g->press, 40);
    init_gamefive(g);
}