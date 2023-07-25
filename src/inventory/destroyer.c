/*
** EPITECH PROJECT, 2023
** my_rpg1
** File description:
** destroyer
*/

#include "game.h"

void destroy_inventory(inventory_t *inventory)
{
    destroy_image(inventory->background);
    destroy_items(inventory->items);
    free(inventory);
}
