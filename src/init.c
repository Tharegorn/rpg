/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "rpg.h"

void init_menu_two(menu_t *m)
{
    m->mmusic = sfMusic_createFromFile("sounds/menu.ogg");
    sfMusic_setLoop(m->mmusic, sfTrue);
    sfMusic_setVolume(m->mmusic, 100);
    m->tplay = create_font(m->tplay, "PLAY", 170, 200);
    m->thowto = create_font(m->thowto, "HOW TO", 170, 400);
    m->tsettings = create_font(m->tsettings, "SETTINGS", 170, 600);
    m->texit = create_font(m->texit, "EXIT", 170, 800);
    m->fontsettings = sfSprite_create();
    sfSprite_setTexture(m->fontsettings, sfTexture_createFromFile("files/sans.png", NULL), sfTrue);
    sfSprite_setPosition(m->fontsettings, (sfVector2f) {0, 0});
    sfSprite_setScale(m->fontsettings, (sfVector2f) {2, 2});
    m->fontmenu = sfSprite_create();
    sfSprite_setTexture(m->fontmenu, sfTexture_createFromFile("files/menu.png", NULL), sfTrue);
    sfSprite_setPosition(m->fontmenu, (sfVector2f) {0, 0});
    sfSprite_setScale(m->fontmenu, (sfVector2f) {1.54, 1.54});
}
void init_menu(menu_t *m)
{
    m->rplay = sfRectangleShape_create();
    sfRectangleShape_setPosition(m->rplay, (sfVector2f) {170, 220});
    sfRectangleShape_setSize(m->rplay, (sfVector2f) { 210, 50});
    sfRectangleShape_setFillColor(m->rplay, sfTransparent);
    m->rquit = sfRectangleShape_create();
    sfRectangleShape_setPosition(m->rquit, (sfVector2f) {170, 820});
    sfRectangleShape_setSize(m->rquit, (sfVector2f) { 183, 50});
    sfRectangleShape_setFillColor(m->rquit, sfTransparent);
    m->rsettings = sfRectangleShape_create();
    sfRectangleShape_setPosition(m->rsettings, (sfVector2f) {170, 620});
    sfRectangleShape_setSize(m->rsettings, (sfVector2f) { 410, 50});
    sfRectangleShape_setFillColor(m->rsettings, sfTransparent);
    m->rhowto = sfRectangleShape_create();
    sfRectangleShape_setPosition(m->rhowto, (sfVector2f) {170, 420});
    sfRectangleShape_setSize(m->rhowto, (sfVector2f) { 310, 50});
    sfRectangleShape_setFillColor(m->rhowto, sfTransparent);
    init_menu_two(m);
}