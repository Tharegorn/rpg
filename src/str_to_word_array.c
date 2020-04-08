/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** str_to_word_array
*/
#include <stdio.h>
#include <stdlib.h>

int clean_str(char c)
{
    if (c >= 11)
        return 1;
    else
        return 0;
}

int nb_word(char const *str)
{
    int i = 0;
    int words = 0;

    while (str[i] != '\0') {
        if (clean_str(str[i]) == 1)
            words++;
        for (; clean_str(str[i]) == 1 && str[i] != '\0'; i++);
        if (str[i] != '\0')
            i++;
    }
    return words;
}

int len_word(char const *str, int j)
{
    int len = 0;

    for (; clean_str(str[j]) == 1; j++, len++);
    return len;
}

char **str_warray(char const *str)
{
    char **array = malloc(sizeof(char *) * (nb_word(str) + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (; i != nb_word(str); i++) {
        k = 0;
        for (; clean_str(str[j]) == 0; j++);
        array[i] = malloc(sizeof(char) * (len_word(str, j) + 1));
        for (; clean_str(str[j]) == 1; k++, j++)
            array[i][k] = str[j];
        array[i][k] = '\0';
    }
    array[i] = NULL;
    return array;
}