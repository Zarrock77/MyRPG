/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** back to menu
*/

#include "game.h"

void handle_back_click(void *game_ptr)
{
    game_t *game = game_ptr;

    game->pause->is_visible = sfFalse;
    game->options->is_visible = sfFalse;
    game->menu->is_visible = sfTrue;
}
