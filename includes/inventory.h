/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory
*/

#ifndef INVENTORY_H_

    #define INVENTORY_H_

    typedef struct inventory_s {
        sfBool is_visible;
        image_t *background;
        sfText *selector_option;
        sfText *cancel_option;
        item_types_t selected;
        item_t *items;
    } inventory_t;

    void create_inventory(void *game_ptr);

    void render_inventory(void *game_ptr);

    void handle_inventory_event(void *game_ptr, sfEvent event);

    void destroy_inventory(inventory_t *inventory);

#endif
