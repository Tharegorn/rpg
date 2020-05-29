/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** view.c
*/

#include "rpg.h"

void view(global_t *g)
{
    sfView_setRotation(g->view, g->i);
    g->i += rand()%3;
    if (g->i >= 360)
        g->i = 0;
}