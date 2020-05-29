/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** my_itoa.c
*/

#include "rpg.h"

char *my_itoa(int nb)
{
    int len;
    char *str;
    int stk;

    if (nb == 0)
        return ("0");
    stk = nb;
    len = 0;
    for (; stk > 0; stk /= 10) {
        len++;
    }
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}