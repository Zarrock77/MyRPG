/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** event handler for inventory
*/

#include "game.h"

static void handle_inventory_arrow_event_condition(void *game_ptr,
                        sfEvent event)
{
    game_t *game = game_ptr;

    if (event.key.code == sfKeyUp && game->inventory->selected > -1) {
            game->inventory->selected -= 1;
        } else if (event.key.code == sfKeyDown &&
            game->inventory->selected < ITEMS_NUMBER - 1) {
            game->inventory->selected += 1;
        }
}

void handle_inventory_event(void *game_ptr, sfEvent event)
{
    game_t *game = game_ptr;

    if (game->inventory->is_visible == sfTrue) {
        handle_inventory_arrow_event_condition(game_ptr, event);
    }

    if (event.key.code == sfKeyI && game->map->is_visible == sfTrue &&
    game->player->in_mouv == sfFalse)
        game->inventory->is_visible = !game->inventory->is_visible;
}
