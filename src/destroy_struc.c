/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_struc.c
*/

#include "rpg.h"

void destroy_game(global_t *g)
{
    sfMusic_destroy(g->font_music);
    sfSprite_destroy(g->world);
    sfSprite_destroy(g->mob_one);
    sfSprite_destroy(g->mob_two);
    sfSprite_destroy(g->mob_three);
    sfSprite_destroy(g->mob_four);
    sfSprite_destroy(g->shop);
    sfSprite_destroy(g->player);
    sfSprite_destroy(g->background);
    sfText_destroy(g->xp);
    sfText_destroy(g->press);
    sfText_destroy(g->droid);
    sfText_destroy(g->ozef);
    sfText_destroy(g->apple);
    sfText_destroy(g->golem);
    sfRectangleShape_destroy(g->fight);
    sfRectangleShape_destroy(g->prev_mob);
    sfRectangleShape_destroy(g->next);
    sfRectangleShape_destroy(g->alpha);
    sfView_destroy(g->view);
}

void destroy_boss(global_t *g)
{
    sfRectangleShape_destroy(g->boss->atk);
    sfRectangleShape_destroy(g->boss->healrec);
    sfText_destroy(g->boss->bosslife);
    sfText_destroy(g->boss->playerlife);
    sfText_destroy(g->boss->playerdmg);
    sfSprite_destroy(g->boss->swin);
    sfSprite_destroy(g->boss->slose);
    sfSprite_destroy(g->boss->back);
    sfSprite_destroy(g->boss->front);
    sfSprite_destroy(g->boss->player);
    sfSprite_destroy(g->boss->boss);
    sfClock_destroy(g->boss->clock);
    sfSprite_destroy(g->boss->layout);
    free(g->boss);
}

void destroy_mob(global_t *g)
{
    sfSprite_destroy(g->mob->win);
    sfSprite_destroy(g->mob->lose);
    sfText_destroy(g->mob->life);
    sfText_destroy(g->mob->mob_name);
    sfText_destroy(g->mob->ttl);
    free(g->mob);
}

void destroy_player(global_t *g)
{
    sfText_destroy(g->p->player_name);
    sfText_destroy(g->p->life);
    sfText_destroy(g->p->ttl);
    sfText_destroy(g->p->perc);
    sfText_destroy(g->p->nb_armor);
    sfText_destroy(g->p->nb_dmg);
    sfText_destroy(g->p->nb_xp);
    sfText_destroy(g->p->tp_text);
    sfText_destroy(g->p->dmg_text);
    sfText_destroy(g->p->life_text);
    sfText_destroy(g->p->xp_text);
    sfText_destroy(g->p->armor_text);
    sfSprite_destroy(g->p->inventory);
    sfSprite_destroy(g->p->xp_log);
    sfSprite_destroy(g->p->dmg_log);
    sfSprite_destroy(g->p->armor_log);
    free(g->p->stats);
    free(g->p);
}

void destroy_menu(menu_t *m)
{
    sfRectangleShape_destroy(m->home);
    sfRectangleShape_destroy(m->rplay);
    sfRectangleShape_destroy(m->rquit);
    sfRectangleShape_destroy(m->rsettings);
    sfRectangleShape_destroy(m->rhowto);
    sfRectangleShape_destroy(m->exit);
    sfRectangleShape_destroy(m->prev);
    sfRectangleShape_destroy(m->one);
    sfRectangleShape_destroy(m->two);
    sfRectangleShape_destroy(m->three);
    sfRectangleShape_destroy(m->four);
    sfRectangleShape_destroy(m->five);
    sfRectangleShape_destroy(m->six);
    sfRectangleShape_destroy(m->seven);
    sfRectangleShape_destroy(m->height);
    sfRectangleShape_destroy(m->nine);
    sfRectangleShape_destroy(m->ten);
    sfMusic_destroy(m->mmusic);
    sfSprite_destroy(m->fontmenu);
    sfSprite_destroy(m->fontsettings);
}