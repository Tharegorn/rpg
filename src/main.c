/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "rpg.h"

int check_option(char **tab)
{
    int p = 0;
    if (options(tab, "volume") == -84) {
        error_in_file();
        return (84);
    }
    if (options(tab, "window.x") == -84) {
        error_in_file();
        return (84);
    }
    if (options(tab, "window.y") == -84) {
        error_in_file();
        return (84);
    }
    return (0);
}

int check_files(void)
{
    char *file = malloc(sizeof(char) * 200);
    char **tab = NULL;
    int fd = open("options.txt", O_RDONLY);

    if (fd == -1) {
        not_dir();
        return (84);
    }
    read(fd, file, 200);
    tab = str_warray(file);
    free(file);
    if (check_option(tab) != 0)
        return (84);
    return (0);
}

void game_loop(win_t *w, menu_t *m, global_t *g)
{
    g->scene = 0;
    while (sfRenderWindow_isOpen(w->win)) {
        g->volume = m->volume;
        sfRenderWindow_clear(w->win, sfBlack);
        if (g->scene == 0)
            menu(m, w, g);
        if (g->scene == 1)
            settings(w, g, m);
        if (g->scene == 3)
            game_functions(g, w);
        sfRenderWindow_display(w->win);
    }
    destroy(m, w);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    if (check_files() == 84)
        return (84);
    win_t *w = malloc(sizeof(win_t));
    w->win = createwin(w->win);
    menu_t *m = malloc(sizeof(menu_t));
    global_t *g = malloc(sizeof(global_t));
    init_menu(m);
    init_game(g);
    sfMusic_play(m->mmusic);
    game_loop(w, m, g);
    return (0);
}
