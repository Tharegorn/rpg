/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_strcmp.c
*/

#include "rpg.h"

int my_strcmp(char *s, char *str)
{
    int start = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (s[i] != str[i])
            start++;
    }
    if (start == 0)
        return (0);
    else
        return (1);
}