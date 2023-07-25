/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** button
*/

#ifndef ENGINE_BUTTON_H_

    #define ENGINE_BUTTON_H_

    #include <stdlib.h>
    #include <SFML/Graphics.h>

    typedef struct button_s {
        sfText *text;
        sfRectangleShape *background;
        sfBool is_hovered;
        sfBool is_visible;

        void (*handle_click)(void *);

        struct button_s *next;
    } button_t;

    button_t *create_button(sfFont *font, char *text_string,
        sfVector2f position, void (*handle_click)(void *));

    void register_button(button_t **head, button_t *button);

    void render_buttons(sfRenderWindow *window, button_t *head);

    int on_hover(float x, float y, void *game_ptr, button_t *button);

    int on_click(float x, float y, void *game_ptr, button_t *button);

    void handle_button_event(
        int (*handle_event)(float, float, void *, button_t *button),
        void *game_ptr, sfVector2f mouse, button_t *buttons);

    void set_button_position(button_t *button, sfVector2f position);

    void destroy_buttons(button_t *button);

#endif
