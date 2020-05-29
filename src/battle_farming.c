/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** battle_farming.c
*/

#include "rpg.h"

int boss_farming(void)
{
    int stk = rand()%4;

    if (stk == 0)
        return 1;
    return 0;
}

int battle_farming(global_t *g)
{
    int stk = rand()%101;

    if (stk >= 0 && stk <= g->p->chance)
        return (1);
    else
        return (0);
}