/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** creator
*/

#include "game.h"
#include "item.h"

static void create_item(game_t *game, item_t *item, item_types_t type)
{
    sfVector2f default_position = (sfVector2f){ 0, 0 };

    item->name = item_names[type];
    item->text = sfText_create();
    sfText_setFillColor(item->text, sfBlack);
    sfText_setFont(item->text, game->font);
    sfText_setCharacterSize(item->text, 17);
    sfText_setPosition(item->text, default_position);
    item->icon = create_image(item_icon_paths[type], default_position,
        game->window);
    sfSprite_setScale(item->icon->sprite, (sfVector2f){ 0.09, 0.09 });
    item->count = 0;
}

item_t *create_items(void *game_ptr)
{
    game_t *game = game_ptr;

    item_t *items = malloc(sizeof(item_t) * ITEMS_NUMBER);
    *items = (item_t){ 0 };

    for (int i = 0; i < ITEMS_NUMBER; i++) {
        create_item(game, &items[i], i);
    }

    return items;
}
