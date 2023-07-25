/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** event
*/

#include <SFML/Graphics.h>
#include "game.h"
#include "pokedex.h"

static void handle_click_event(sfEvent event, game_t *game)
{
    sfVector2f pos = (sfVector2f){
        event.mouseButton.x, event.mouseButton.y };

    if (game->menu->is_visible == sfTrue) {
        handle_button_event(on_click,
            game, pos, game->menu->buttons);
    }
    if (game->options->is_visible == sfTrue) {
        handle_button_event(on_click,
            game, pos, game->options->buttons);
    }
    if (game->pause->is_visible == sfTrue) {
        handle_button_event(on_click,
            game, pos, game->pause->buttons);
    }
    if (game->scene->is_visible == sfTrue) {
        handle_button_event(on_click,
            game, pos, game->scene->buttons);
    }
}

static void handle_move_event(sfEvent event, game_t *game)
{
    sfVector2f pos = (sfVector2f){event.mouseMove.x, event.mouseMove.y};

    handle_button_event(on_hover, game, pos, game->menu->buttons);
    handle_button_event(on_hover, game, pos, game->options->buttons);
    handle_button_event(on_hover, game, pos, game->pause->buttons);
    handle_button_event(on_hover, game, pos, game->scene->buttons);
}

static void handle_press_event(sfEvent event, game_t *game)
{
    if (game->dex->is_active == sfTrue) {
        handle_events(game->window, &game->dex->current_pokemon,
        game->dex, event);
        update_display(game->dex, game->dex->current_pokemon);
        return;
    }
    if (game->start->is_visible == sfTrue &&
        game->intro->img->is_visible == sfFalse) {
        game->start->is_visible = sfFalse;
        game->menu->is_visible = sfTrue;
    }
    handle_pause_escape_event(game, event);
    handle_inventory_event(game, event);
    if (game->map->is_visible == sfTrue &&
        game->inventory->is_visible == sfFalse &&
        game->dialog->is_visible == sfFalse) {
        move_player(game, event);
    }
    handle_dialog_event(game, event);
}

void handle_game_event(sfRenderWindow *window, game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            handle_click_event(event, game);
        }
        if (event.type == sfEvtMouseMoved) {
            handle_move_event(event, game);
        }
        if (event.type == sfEvtKeyPressed) {
            handle_press_event(event, game);
        }
    }
}
