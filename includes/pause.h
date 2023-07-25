/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** pause
*/

#ifndef PAUSE_H_

    #define PAUSE_H_

    #include "engine/button.h"

    typedef struct pause_s {
        sfBool is_visible;
        sfText *title;
        sfView *view;
        button_t *buttons;
    } pause_t;

    void create_pause(void *game_ptr);

    void handle_back_click(void *game_ptr);

    void handle_cancel_click(void *game_ptr);

    void handle_pause_escape_event(void *game_ptr, sfEvent event);

    void render_pause(void *game_ptr);

    void destroy_pause(pause_t *pause);

#endif
