/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** initializer.c
*/

#include "rpg.h"

void initializer(menu_t *m, global_t *g)
{
    init_menu(m);
    init_game(g, m->volume);
    init_player_stats(g);
    init_boss(g);
}