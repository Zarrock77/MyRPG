/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render
*/

#include <fcntl.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

static void render_intro_and_start(game_t *game)
{
    if (game->intro->img->is_visible == sfTrue) {
        render_intro(game);
    }
    if (game->intro->img->is_visible == sfFalse &&
    game->start->is_visible == sfTrue) {
        render_start(game->window, game->start);
    }
}

static void render_map_and_scene(game_t *game)
{
    if (game->map->is_visible == sfTrue) {
        render_c1(game->window, game->map);
        render_png(game->window, game->professeur);
        render_player(game);
        render_c2(game->window, game->map);
    }
    if (game->scene->is_visible == sfTrue) {
        render_scene(game);
    }
}

static void render_others(game_t *game)
{
    if (game->menu->is_visible == sfTrue) {
        render_menu(game);
    }
    if (game->options->is_visible == sfTrue) {
        render_options(game);
    }
    if (game->pause->is_visible == sfTrue) {
        render_pause(game);
    }
    if (game->inventory->is_visible == sfTrue) {
        render_inventory(game);
    }
    render_dialog(game);
}

static void render(game_t *game)
{
    render_intro_and_start(game);
    render_map_and_scene(game);
    render_others(game);
}

void render_game(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        handle_game_event(game->window, game);
        sfRenderWindow_clear(game->window, sfBlack);
        render(game);
        sfRenderWindow_display(game->window);
    }
}
