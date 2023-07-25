/*
** EPITECH PROJECT, 2023
** myrpg4
** File description:
** options
*/

#ifndef OPTIONS_H_

    #define OPTIONS_H_

    typedef struct options_s {
        sfBool is_visible;
        sfText *title;
        button_t *buttons;
    } options_t;

    void create_options(void *game_ptr);

    void render_options(void *game_ptr);

#endif
