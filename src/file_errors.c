/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** file_errors.c
*/

#include "rpg.h"

int get_tab(char **tab, char *str)
{
    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], str) == 0) {
            return (i);
        }
    }
    return (0);
}

int check_params(char **tab, char *str)
{
    int line = get_tab(tab, str);
    int a = 0;
    int n = 0;
    char *stock = malloc(sizeof (char) * 4);

    for (int j = 0; tab[line][j]; j++) {
        if (tab[line][j] == '=')
            n = j + 1;
        if (n != 0) {
            stock[a] = tab[line][n];
            a++;
            n++;
        }
    }
    stock[a] = '\0';
    if (my_atoi(stock) > 100 || my_atoi(stock) < 0)
        return (-84);
    free(stock);
    return (1);
}

int options(char **tab, char *str)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], str) == 0) {
            return (i);
        }
    }
    return -84;
}

void error_in_file(void)
{
    my_putstr("\033[33m");
    my_putstr("Syntax error in file : ");
    my_putstr("\033[1m");
    my_putstr("options.txt\n");
    my_putstr("\033[0m");
}

void not_dir(void)
{
    my_putstr("\033[31m");
    my_putstr("ERROR :");
    my_putstr("\033[33m");
    my_putstr(" Impossible to find file : ");
    my_putstr("\033[1m");
    my_putstr("options.txt\n");
    my_putstr("\033[0m");
}