/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "rpg.h"

sfRectangleShape *rec(sfRectangleShape *rect, sfVector2f pos, sfVector2f size)
{
    rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    return (rect);
}

void fill_color(menu_t *m)
{
    sfRectangleShape_setFillColor(m->one, sfColor_fromRGB(0, 128, 0));
    sfRectangleShape_setFillColor(m->two, sfColor_fromRGB(50, 205, 50));
    sfRectangleShape_setFillColor(m->three, sfColor_fromRGB(173, 255, 47));
    sfRectangleShape_setFillColor(m->four, sfColor_fromRGB(230, 255, 10));
    sfRectangleShape_setFillColor(m->five, sfColor_fromRGB(255, 255, 0));
    sfRectangleShape_setFillColor(m->six, sfColor_fromRGB(255, 215, 0));
    sfRectangleShape_setFillColor(m->seven, sfColor_fromRGB(255, 200, 0));
    sfRectangleShape_setFillColor(m->height, sfColor_fromRGB(255, 165, 0));
    sfRectangleShape_setFillColor(m->nine, sfColor_fromRGB(255, 140, 0));
    sfRectangleShape_setFillColor(m->ten, sfColor_fromRGB(255, 0, 0));
    init_menu_three(m);
}

void init_volume_one(menu_t *m)
{
    m->one = rec(m->one, (sfVector2f) { 903, 610}, (sfVector2f) {68, 20});
    m->two = rec(m->two, (sfVector2f) { 971, 590}, (sfVector2f) {68, 40});
    m->three = rec(m->three,
    (sfVector2f) { 1039, 570}, (sfVector2f) {68, 60});
    m->four = rec(m->four, (sfVector2f) { 1107, 550}, (sfVector2f) {68, 80});
    m->five = rec(m->five, (sfVector2f) { 1175, 530}, (sfVector2f) {68, 100});
    m->six = rec(m->six, (sfVector2f) { 1243, 510}, (sfVector2f) {68, 120});
    m->seven = rec(m->seven, (sfVector2f)
    { 1311, 490}, (sfVector2f) {68, 140});
    m->height = rec(m->height,
    (sfVector2f) { 1379, 470}, (sfVector2f) {68, 160});
    m->nine = rec(m->nine, (sfVector2f) { 1447, 450}, (sfVector2f) {68, 180});
    m->ten = rec(m->ten, (sfVector2f) { 1515, 430}, (sfVector2f) {68, 200});
    m->howto = sfSprite_create();
    sfSprite_setPosition(m->howto, (sfVector2f) { 0, 0});
    sfSprite_setTexture(m->howto,
    sfTexture_createFromFile("files/how_to_page.png", NULL), sfTrue);
    fill_color(m);
}

void init_menu_two(menu_t *m)
{
    m->volume = get_volume();
    m->mmusic = sfMusic_createFromFile("sounds/menu.ogg");
    sfMusic_setLoop(m->mmusic, sfTrue);
    sfMusic_setVolume(m->mmusic, m->volume);
    m->fontsettings = sfSprite_create();
    sfSprite_setTexture(m->fontsettings,
    sfTexture_createFromFile("files/setting.png", NULL), sfTrue);
    sfSprite_setPosition(m->fontsettings, (sfVector2f) {300, 50});
    m->fontmenu = sfSprite_create();
    sfSprite_setTexture(m->fontmenu,
    sfTexture_createFromFile("files/menu.png", NULL), sfTrue);
    sfSprite_setPosition(m->fontmenu, (sfVector2f) {0, 0});
    sfSprite_setScale(m->fontmenu, (sfVector2f) {1.54, 1.54});
    m->rhowto = sfRectangleShape_create();
    sfRectangleShape_setPosition(m->rhowto, (sfVector2f) {170, 420});
    sfRectangleShape_setSize(m->rhowto, (sfVector2f) { 310, 50});
    sfRectangleShape_setTexture(m->rhowto,
    sfTexture_createFromFile("files/howto.png", NULL), sfTrue);
    init_volume_one(m);
}

void init_menu(menu_t *m)
{
    m->rplay = sfRectangleShape_create();
    sfRectangleShape_setPosition(m->rplay, (sfVector2f) {170, 220});
    sfRectangleShape_setSize(m->rplay, (sfVector2f) { 210, 50});
    sfRectangleShape_setTexture(m->rplay,
    sfTexture_createFromFile("files/play.png", NULL), sfTrue);
    m->rquit = sfRectangleShape_create();
    sfRectangleShape_setPosition(m->rquit, (sfVector2f) {170, 820});
    sfRectangleShape_setSize(m->rquit, (sfVector2f) { 183, 50});
    sfRectangleShape_setTexture(m->rquit,
    sfTexture_createFromFile("files/exit_text.png", NULL), sfTrue);
    m->rsettings = sfRectangleShape_create();
    sfRectangleShape_setPosition(m->rsettings, (sfVector2f) {170, 620});
    sfRectangleShape_setSize(m->rsettings, (sfVector2f) { 410, 50});
    sfRectangleShape_setTexture(m->rsettings,
    sfTexture_createFromFile("files/settings.png", NULL), sfTrue);
    init_menu_two(m);
}