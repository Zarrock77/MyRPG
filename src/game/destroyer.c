/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroyer
*/

#include "game.h"

void destroy_game(game_t *game)
{
    destroy_intro(game->intro);
    destroy_start(game->start);
    destroy_menu(game->menu);
    destroy_map(game->map);
    destroy_player(game->player);
    destroy_pause(game->pause);
    destroy_dex(game->dex);
    destroy_inventory(game->inventory);
    destroy_dialog(game->dialog);
    destroy_team(game->team);
    free(game->scene);

    sfRenderWindow_destroy(game->window);
}
