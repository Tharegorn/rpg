/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** get_volume.c
*/

#include "rpg.h"

int get_tabb(char **tab, char *str)
{
    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], str) == 0) {
            return (i);
        }
    }
    return (0);
}

int check_param(char **tab, char *str)
{
    int line = get_tabb(tab, str);
    int a = 0;
    int n = 0;
    char *stock = malloc(sizeof(char) * 4);

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
    return (my_atoi(stock));
}

int get_volume(void)
{
    int fd = open("options.txt", O_RDONLY);
    char *content = malloc(sizeof(char) * 200);
    char **tab = NULL;

    read(fd, content, 200);
    tab = str_warray(content);
    free(content);
    return (check_param(tab, "volume="));
}
