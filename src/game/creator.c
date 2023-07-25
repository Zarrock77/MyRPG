/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** game creator
*/

#include "game.h"

static void create_sub_data(game_t *game)
{
    create_intro(game);
    create_start(game);
    create_menu(game);
    create_options(game);
    create_player(game);
    create_map(game);
    create_pause(game);
    create_dex(game);
    create_dialog(game);
    create_inventory(game);
    create_team(game);
    create_scene(game);
}

void create_game(game_t *game)
{
    game->mode = (sfVideoMode){ 1920, 1080, 32 };
    game->window =
        sfRenderWindow_create(
            game->mode, "Pokemon Amethyst",
            sfTitlebar | sfClose, NULL);
    game->font = sfFont_createFromFile("assets/minecraftia-regular.ttf");

    create_sub_data(game);
}
