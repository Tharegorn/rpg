/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** file_errors.c
*/

#include "rpg.h"

int options(char **tab, char *str)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], str) == 0) {
            return (i);
        }
    }
    return -84;
}

void error_in_file()
{
    my_putstr("\033[33m");
    my_putstr("Syntax error in file : ");
    my_putstr("\033[1m");
    my_putstr("options.txt\n");
    my_putstr("\033[0m");
}

void not_dir()
{
    my_putstr("\033[31m");
    my_putstr("ERROR :");
    my_putstr("\033[33m");
    my_putstr(" Impossible to find file : ");
    my_putstr("\033[1m");
    my_putstr("options.txt\n");
    my_putstr("\033[0m");
}