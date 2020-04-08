/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <string.h>

int my_strlen(char *s)
{
    int c = 0;

    if (s == NULL)
        return (0);
    for (; s[c]; c++);
    return (c);
}
