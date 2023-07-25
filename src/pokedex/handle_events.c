/*
** EPITECH PROJECT, 2023
** TEST
** File description:
** handle_events
*/

#include "pokedex.h"

static bool is_escape_key_pressed(sfEvent event)
{
    return event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape;
}

static bool is_arrow_key_pressed(sfEvent event)
{
    return event.type == sfEvtKeyPressed &&
    (event.key.code == sfKeyUp || event.key.code == sfKeyDown);
}

static void handle_arrow_key_event(sfEvent event, int *current_pokemon)
{
    int direction = (event.key.code == sfKeyUp) ? -1 : 1;

    *current_pokemon += direction;
    if (*current_pokemon < 0) {
        *current_pokemon = 0;
    } else if (*current_pokemon >= POKEMONS_NB) {
        *current_pokemon = POKEMONS_NB - 1;
    }
}

void handle_events(sfRenderWindow *window,
int *current_pokemon, pokedex_t *dex, sfEvent event)
{
    handle_arrow_key_event(event, current_pokemon);
    update_display(dex, *current_pokemon);
}
