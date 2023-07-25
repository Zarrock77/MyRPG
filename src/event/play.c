/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** Play button clicked handler
*/

#include "game.h"

void handle_play_click(void *game_ptr)
{
    game_t *game = game_ptr;

    game->menu->is_visible = sfFalse;
    game->map->is_visible = sfTrue;
}
