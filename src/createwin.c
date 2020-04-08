/*
** EPITECH PROJECT, 2019
** MUL_my_defender_bootstrap_2019
** File description:
** createwin.c
*/

#include "rpg.h"

sfRenderWindow *createwin(sfRenderWindow *w)
{
    sfVideoMode params = {1920, 1080, 32};
    char s[7] = "My_rpg";

    w = sfRenderWindow_create(params, s, sfFullscreen, NULL);
    return (w);
}