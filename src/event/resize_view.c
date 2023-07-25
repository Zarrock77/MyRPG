/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** resize_view
*/

#include"game.h"

void create_resized_view(game_t *game)
{
    sfView *new1 = create_view(game->window, game->map->c1->round_scale,
        (sfVector2f){game->player->x * 32 + 16, game->player->y * 32});
    sfView *new2 = create_view(game->window, game->map->c2->round_scale,
        (sfVector2f){game->player->x * 32 + 16, game->player->y * 32});
    game->map->c1->view = new1;
    game->map->c2->view = new2;
}
