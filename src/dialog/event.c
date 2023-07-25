/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** event
*/

#include <SFML/Graphics.h>
#include "game.h"

static void handle_dialog_skip_event(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyEnter && game->map->is_visible == sfTrue &&
        game->dialog->is_visible == sfTrue) {
        game->dialog->is_visible = sfFalse;
    }
}

static void handle_dialog_talk_event(game_t *game, sfEvent event)
{
    if (game->dialog->is_asking == sfTrue && event.key.code == sfKeyT) {
        game->dialog->is_asking = sfFalse;
        game->dialog->is_visible = sfTrue;
    }
}

static void handle_dialog_move_event(game_t *game, sfEvent event)
{
    if (game->map->is_visible == sfTrue && game->player->x == 85 &&
        game->player->y == 115) {
        game->dialog->is_asking = sfTrue;
        game->dialog->message = welcome_message;
    }

    if (game->map->is_visible == sfTrue &&
        game->dialog->is_asking == sfTrue && (game->player->x != 85 ||
        game->player->y != 115)) {
        game->dialog->is_asking = sfFalse;
    }
}

void handle_dialog_event(void *game_ptr, sfEvent event)
{
    game_t *game = game_ptr;

    handle_dialog_move_event(game, event);
    handle_dialog_talk_event(game, event);
    handle_dialog_skip_event(game, event);
}
