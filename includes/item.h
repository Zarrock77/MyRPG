/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** item
*/

#ifndef ITEM_H_

    #define ITEM_H_

    #include <SFML/Graphics.h>
    #include "engine/image.h"

    typedef enum item_types_s {
        ITEM_CANCEL = -1,
        ITEM_POKEBALL = 0,
        ITEM_POTION = 1
    } item_types_t;

    #define ITEMS_NUMBER 2

    static const char *item_names[ITEMS_NUMBER] = {
        "Pokeball",
        "Potion" };

    static const char *item_icon_paths[ITEMS_NUMBER] = {
        "assets/Sprites/pokeball.png",
        "assets/Sprites/potion.png" };

    typedef struct item_s {
        const char *name;
        sfText *text;
        image_t *icon;
        int count;
    } item_t;

    item_t *create_items(void *game_ptr);

    void render_items(void *game_ptr);

    void destroy_items(item_t *items);

#endif
