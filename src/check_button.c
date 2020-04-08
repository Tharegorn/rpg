/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** check_button.c
*/

#include "rpg.h"

int button_is_clicked(sfRectangleShape *rect, sfVector2i click_pos)
{
    sfVector2f actual = sfRectangleShape_getPosition(rect);
    sfVector2f ac = sfRectangleShape_getSize(rect);
    int max_x = actual.x + ac.x;
    int max_y = actual.y + ac.y;

    if (click_pos.x >= actual.x && click_pos.x <= max_x) {
        if (click_pos.y >= actual.y && click_pos.y <= max_y) {
            return (1);
        }
    }
    return 0;
}