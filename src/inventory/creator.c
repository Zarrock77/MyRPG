/*
** EPITECH PROJECT, 2023
** my_rpg1
** File description:
** creator
*/

#include <stdio.h>
#include "game.h"

static void create_inventory_option(sfFont *font, sfText **text,
    const char *option)
{
    *text = sfText_create();

    sfText_setString(*text, option);
    sfText_setFillColor(*text, sfBlack);
    sfText_setFont(*text, font);
    sfText_setCharacterSize(*text, 17);
}

void create_inventory(void *game_ptr)
{
    game_t *game = game_ptr;

    sfVector2f default_position = (sfVector2f){ 0, 0 };

    game->inventory = malloc(sizeof(inventory_t));

    game->inventory->selected = ITEM_CANCEL;
    game->inventory->is_visible = sfFalse;
    game->inventory->background = create_image("assets/Sprites/bag.png",
        default_position, game->window);

    create_inventory_option(game->font,
        &game->inventory->selector_option, ">");
    create_inventory_option(game->font,
        &game->inventory->cancel_option, "CANCEL");

    game->inventory->items = create_items(game_ptr);
}
