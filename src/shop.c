/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** shop.c
*/

#include "rpg.h"

void select_shop(global_t *g)
{
    if (g->p->xp >= 150) {
        g->p->xp -= 150;
        if (g->tele == 2) {
            g->p->stats[0] += 1;
            g->p->dmg += 50;
        }
        if (g->tele == 3) {
            g->p->stats[1] += 1;
            g->p->armor += 50;
        }
        if (g->tele == 5) {
            g->p->stats[2] += 1;
            g->p->hp += 50;
        }
    }
}

void check_shop(win_t *w, global_t *g)
{
    sfVector2i vect = sfMouse_getPositionRenderWindow(w->win);

    if (vect.x >= 750 && vect.x <= 1250 && vect.y >= 190
    && vect.y <= 750 && g->tele != 6) {
        if (vect.x >= 868 && vect.x <= 1037 && vect.y >= 620 && vect.y <= 652) {
            select_shop(g);
        }
    } else if (g->tele == 6) {
        player_check_mouse(vect, g);
    } else
        g->tele = 0;
}

int pnj(global_t *g)
{
    if (g->player_pos.x >= 744 && g->player_pos.x <= 921)
        return (1);
    if (g->player_pos.x >= 1074 && g->player_pos.x <= 1197)
        return (2);
    if (g->player_pos.x >= 1308 && g->player_pos.x <= 1468)
        return (3);
    if (g->player_pos.x >= 1611 && g->player_pos.x <= 1804)
        return (4);
    return (0);
}

void check_positiontwo(int pos, global_t *g)
{
    if (pos == 3) {
        sfText_setString(g->droid, my_itoa(g->a));
        sfText_setString(g->ozef, my_itoa(g->b));
        sfText_setString(g->apple, my_itoa(g->c));
        sfText_setString(g->golem, my_itoa(g->d));
        sfSprite_setPosition(g->shop, (sfVector2f) { 650, 50});
        sfSprite_setTexture(g->shop,
        sfTexture_createFromFile("files/quest.png", NULL), sfTrue);
        g->tele = 4;
    }
    if (pos == 4) {
        sfSprite_setPosition(g->shop, (sfVector2f) { 750, 190});
        sfSprite_setTexture(g->shop,
        sfTexture_createFromFile("files/life_shop.png", NULL), sfTrue);
        g->tele = 5;
    }
}

void check_position(global_t *g)
{
    int pos = pnj(g);

    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (pos == 1) {
            sfSprite_setPosition(g->shop, (sfVector2f) { 750, 190});
            sfSprite_setTexture(g->shop,
            sfTexture_createFromFile("files/dmg_shop.png", NULL), sfTrue);
            g->tele = 2;
        }
        if (pos == 2) {
            sfSprite_setPosition(g->shop, (sfVector2f) { 750, 190});
            sfSprite_setTexture(g->shop,
            sfTexture_createFromFile("files/armor_shop.png", NULL), sfTrue);
            g->tele = 3;
        }
        check_positiontwo(pos, g);
    }
}