/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** game.c
*/

#include "rpg.h"

void print_press(win_t *w, global_t *g)
{
    int pos = pnj(g);

    if (pos == 1)
        sfText_setPosition(g->press, (sfVector2f) {744, 600});
    if (pos == 2)
        sfText_setPosition(g->press, (sfVector2f) {1074, 600});
    if (pos == 3)
        sfText_setPosition(g->press, (sfVector2f) {1308, 570});
    if (pos == 4)
        sfText_setPosition(g->press, (sfVector2f) {1611, 600});
    if (pos != 0 && g->tele == 0)
        sfRenderWindow_drawText(w->win, g->press, NULL);
}

void check_anim(win_t *w, global_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        change_player_texture("./files/sans_left.png", g);
        left_anim(g, w);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        change_player_texture("./files/sans_right.png", g);
        right_anim(g, w);
    }
}

void event_gametwo(win_t *w, global_t *g)
{
    if (g->tele == 0 && sfKeyboard_isKeyPressed(sfKeyC))
        g->tele = 6;
    if (g->tele == 0)
        check_position(g);
    if (g->tele == 0 && sfKeyboard_isKeyPressed(sfKeyT))
        g->tele = 1;
    if (g->tele == 0)
        check_anim(w, g);
    if (sfKeyboard_isKeyPressed(sfKeyK)) {
        g->a = 20;
        g->b = 15;
        g->c = 10;
        g->d = 5;
        g->p->xp = 10000;
    }
}

void event_game(win_t *w, global_t *g)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(w->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            g->prev = 3;
            g->scene = 1;
        }
        if (event.type == sfEvtMouseButtonReleased) {
            check_tele(w, g);
        }
        if (sfKeyboard_isKeyPressed(sfKeyD))
            g->active = 1;
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            g->active = 0;
        event_gametwo(w, g);
    }
}

void game_functions(global_t *g, win_t *w)
{
    event_game(w, g);
    sfRenderWindow_drawSprite(w->win, g->background, NULL);
    sfRenderWindow_drawSprite(w->win, g->player, NULL);
    if (g->tele == 1)
        sfRenderWindow_drawSprite(w->win, g->world, NULL);
    if (g->tele > 1 && g->tele < 6)
        sfRenderWindow_drawSprite(w->win, g->shop, NULL);
    if (g->tele == 6)
        print_stats(w, g);
    sfText_setString(g->xp, my_itoa(g->p->xp));
    sfRenderWindow_drawText(w->win, g->xp, NULL);
    print_quest(w, g);
    print_press(w, g);
    if (g->active == 1)
        view(g);
    else
        sfView_setRotation(g->view, 0);
    sfRenderWindow_setView(w->win, g->view);
}