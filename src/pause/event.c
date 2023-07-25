/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** pause events
*/

#include "game.h"

void handle_back_click(void *game_ptr)
{
    game_t *game = game_ptr;

    game->pause->is_visible = sfFalse;
    game->options->is_visible = sfFalse;
    game->dex->is_active = sfFalse;
    game->menu->is_visible = sfTrue;
}

void handle_cancel_click(void *game_ptr)
{
    game_t *game = game_ptr;

    game->pause->is_visible = sfFalse;
    game->dex->is_active = sfFalse;
    game->map->is_visible = sfTrue;
    game->map->c1->is_visible = sfTrue;
    game->map->c2->is_visible = sfTrue;
}

void handle_dex_click(void *game_ptr)
{
    game_t *game = game_ptr;

    game->dex->is_active = (game->dex->is_active == sfTrue) ? sfFalse : sfTrue;
}

void handle_pause_escape_event(void *game_ptr, sfEvent event)
{
    game_t *game = game_ptr;

    if (event.key.code == sfKeyEscape && (game->map->is_visible == sfTrue ||
    game->pause->is_visible == sfTrue) && game->player->in_mouv == sfFalse) {
        game->pause->is_visible = !game->pause->is_visible;
        game->map->is_visible = !game->map->is_visible;

        if (game->map->is_visible == sfTrue) {
            sfRenderWindow_setView(game->window, game->map->c1->view);
            sfRenderWindow_setView(game->window, game->map->c2->view);
        } else {
            sfRenderWindow_setView(game->window, game->pause->view);
        }
    }
}
