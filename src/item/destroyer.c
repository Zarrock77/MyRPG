/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** item destroyer
*/

#include "engine/image.h"
#include "item.h"

static void destroy_item(item_t *item)
{
    sfText_destroy(item->text);
}

void destroy_items(item_t *items)
{
    for (int i = 0; i < ITEMS_NUMBER; i++) {
        destroy_item(&items[i]);
    }

    free(items);
}
