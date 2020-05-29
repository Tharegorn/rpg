/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_two.c
*/

#include "rpg.h"

void init_menu_three(menu_t *m)
{
    m->prev = sfRectangleShape_create();
    sfRectangleShape_setSize(m->prev, (sfVector2f) {100, 73});
    sfRectangleShape_setPosition(m->prev, (sfVector2f) { 1820, 0});
    sfRectangleShape_setTexture(m->prev,
    sfTexture_createFromFile("files/prev.png", NULL), sfTrue);
    m->exit = sfRectangleShape_create();
    sfRectangleShape_setSize(m->exit, (sfVector2f) {300, 127});
    sfRectangleShape_setPosition(m->exit, (sfVector2f) {1620, 953});
    sfRectangleShape_setTexture(m->exit,
    sfTexture_createFromFile("files/exit.png", NULL), sfTrue);
    m->home = sfRectangleShape_create();
    sfRectangleShape_setSize(m->home, (sfVector2f) { 298, 133});
    sfRectangleShape_setOrigin(m->home, (sfVector2f) { 0, 0});
    sfRectangleShape_setTexture(m->home,
    sfTexture_createFromFile("files/home.png", NULL), sfTrue);
}