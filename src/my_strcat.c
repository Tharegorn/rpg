/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_strcat.c
*/

#include "rpg.h"

char *my_strcat(char *s1, char *s2)
{
    char *dest = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int i = 0;

    for (int j = 0; s1[j] != '\0' && s1[j] != '\0'; j++) {
        dest[i] = s1[j];
        i++;
    }
    for (int j = 0; s2[j] != '\0' && s2[j] != '\0'; j++) {
        dest[i] = s2[j];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}