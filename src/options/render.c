/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** options render
*/

#include "game.h"

void render_options(void *game_ptr)
{
    game_t *game = game_ptr;

    render_buttons(game->window, game->options->buttons);

    sfRenderWindow_drawText(game->window, game->options->title, NULL);
}
