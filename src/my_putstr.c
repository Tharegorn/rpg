/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "rpg.h"

void my_putstr(char *s)
{
    write(1, s, my_strlen(s));
}
