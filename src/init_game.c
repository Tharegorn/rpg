/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_game.c
*/

#include "rpg.h"

void init_gamethree(global_t *g)
{
    g->fight = sfRectangleShape_create();
    sfRectangleShape_setSize(g->fight, (sfVector2f) { 300, 127});
    sfRectangleShape_setPosition(g->fight, (sfVector2f) {800, 200});
    sfRectangleShape_setTexture(g->fight,
    sfTexture_createFromFile("files/fight.png", NULL), sfTrue);
    g->alpha = sfRectangleShape_create();
    sfRectangleShape_setSize(g->alpha, (sfVector2f) { 300, 127});
    sfRectangleShape_setPosition(g->alpha, (sfVector2f) {800, 600});
    sfRectangleShape_setTexture(g->alpha,
    sfTexture_createFromFile("files/back_to_alpha.png", NULL), sfTrue);
    g->prev_mob = sfRectangleShape_create();
    sfRectangleShape_setPosition(g->prev_mob, (sfVector2f) {0, 540});
    sfRectangleShape_setSize(g->prev_mob, (sfVector2f) {100, 73});
    sfRectangleShape_setTexture(g->prev_mob,
    sfTexture_createFromFile("files/prev.png", NULL), sfTrue);
    init_gamefour(g);
}

void mob_texts(global_t *g)
{
    mob_t *m = g->mob;

    m->mob_name = create_font(m->mob_name, "Unknow", 1400, 80);
    m->ttl = create_font(m->ttl, "Unknow", 1500, 860);
    m->life = create_font(m->life, "Unknow", 1500, 760);
    sfText_setColor(m->life, sfGreen);
    m->win = sfSprite_create();
    sfSprite_setTexture(m->win,
    sfTexture_createFromFile("files/win.png", NULL), sfTrue);
    sfSprite_setPosition(m->win, (sfVector2f) {0, 0});
    sfSprite_setScale(m->win, (sfVector2f) {1.2, 1});
    m->lose = sfSprite_create();
    sfSprite_setTexture(m->lose,
    sfTexture_createFromFile("files/lose.png", NULL), sfTrue);
    sfSprite_setPosition(m->lose, (sfVector2f) {0, 0});
    sfSprite_setScale(m->lose, (sfVector2f) {1.5, 1.5});
    g->p->xp = 0;
    init_gamethree(g);
}

void init_mobs(global_t *g)
{
    g->mob_one = sfSprite_create();
    sfSprite_setTexture(g->mob_one,
    sfTexture_createFromFile("files/mob_1.jpg", NULL), sfTrue);
    sfSprite_setPosition(g->mob_one, (sfVector2f) { 0, 0});
    g->mob_two = sfSprite_create();
    sfSprite_setTexture(g->mob_two,
    sfTexture_createFromFile("files/mob_2.jpg", NULL), sfTrue);
    sfSprite_setPosition(g->mob_two, (sfVector2f) { 0, 0});
    g->mob_three = sfSprite_create();
    sfSprite_setTexture(g->mob_three,
    sfTexture_createFromFile("files/mob_3.jpg", NULL), sfTrue);
    sfSprite_setPosition(g->mob_three, (sfVector2f) { 0, 0});
    g->mob_four = sfSprite_create();
    sfSprite_setTexture(g->mob_four,
    sfTexture_createFromFile("files/mob_4.jpg", NULL), sfTrue);
    sfSprite_setPosition(g->mob_four, (sfVector2f) { 0, 0});
    mob_texts(g);
}

void init_gametwo(global_t *g)
{
    g->player_scale.x = 2;
    g->player_scale.y = 2;
    g->rekt.left = 0;
    g->rekt.top = 0;
    g->rekt.width = 43;
    g->rekt.height = 73;
    sfSprite_setScale(g->world, (sfVector2f) { 0.5, 0.5});
    g->player = sfSprite_create();
    sfSprite_setTextureRect(g->player, g->rect);
    sfSprite_setScale(g->player, g->player_scale);
    g->background = sfSprite_create();
    sfSprite_setTexture(g->background,
    sfTexture_createFromFile("files/back_game.png", NULL), sfTrue);
    init_mobs(g);
}

void init_game(global_t *g, int volume)
{
    g->rect.left = 0;
    g->rect.top = 0;
    g->rect.width = 43.25;
    g->rect.height = 73;
    g->tele = 0;
    g->font_music = sfMusic_createFromFile("sounds/game.ogg");
    sfMusic_setLoop(g->font_music, sfTrue);
    sfMusic_setVolume(g->font_music, volume);
    g->world = sfSprite_create();
    sfSprite_setTexture(g->world,
    sfTexture_createFromFile("files/world.png", NULL), sfTrue);
    sfSprite_setPosition(g->world, (sfVector2f) { 500, 400});
    init_gametwo(g);
}