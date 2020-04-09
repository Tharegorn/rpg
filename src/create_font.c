/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_font.c
*/

#include "rpg.h"

sfText *create_font(sfText *text, char *str, int x, int y)
{
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setPosition(text, (sfVector2f) {x, y});
    sfText_setFont(text, sfFont_createFromFile("fonts/rev.otf"));
    sfText_setCharacterSize(text, 70);
    return (text);
}