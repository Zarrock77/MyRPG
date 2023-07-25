/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** menu
*/

#ifndef MENU_H_

    #define MENU_H_

    #include "engine/button.h"
    #include "engine/image.h"

    typedef struct menu_s {
        sfBool is_visible;
        image_t *background;
        button_t *buttons;
    } menu_t;

    void create_menu(void *game_ptr);
    void render_menu(void *game_ptr);
    void destroy_menu(menu_t *menu);

#endif
