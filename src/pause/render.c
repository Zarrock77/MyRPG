/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** render
*/

#include "game.h"
#include "pokedex.h"

void render_pause(void *game_ptr)
{
    game_t *game = game_ptr;

    sfRenderWindow_drawText(
        game->window, game->pause->title, NULL);

    render_buttons(game->window, game->pause->buttons);

    if (game->dex->is_active == sfTrue) {
        draw_sprites(game->window, game->dex, game->dex->current_pokemon);
    }
}
