/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_strdup.c
*/

#include "rpg.h"

char *my_strdup(char *s)
{
    int len = my_strlen(s);
    char *res = malloc(sizeof(char) * (len));

    for (int i = 0; i != len; i++) {
        res[i] = s[i];
    }
    res[len] = '\0';
    return (res);
}