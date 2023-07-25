/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** render
*/

#include "game.h"

void render_menu(void *game_ptr)
{
    game_t *game = game_ptr;

    sfRenderWindow_drawSprite(
        game->window, game->menu->background->sprite, NULL);

    render_buttons(game->window, game->menu->buttons);
}
