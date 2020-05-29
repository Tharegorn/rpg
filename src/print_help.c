/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_help.c
*/

#include "rpg.h"

void print_help(void)
{
    my_putstr("RPG HELP\n\tUsage\nT : Open the portals\nE : Open NPC shop\n");
    my_putstr("C : Open Player inventory\nESC : Open Pause menu\n");
    my_putstr("Left arroy : move player\nRight Arrow : Move player\n");
    my_putstr("K : Speed the game\nD : Activate stuffing mode\nSpace : Turns off stuffed mode\n");
}