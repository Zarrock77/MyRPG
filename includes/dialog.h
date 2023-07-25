/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dialog
*/

#ifndef DIALOG_H_

    #define DIALOG_H_

    #include <SFML/Graphics.h>

    typedef struct dialog_s {
        sfBool is_visible;
        sfBool is_asking;
        image_t *background;
        sfText *ask_text;
        sfText *text;
        const char **message;
    } dialog_t;

    static const char *welcome_message[] = {
        "Hello, I hope you slept well.",
        "It's time for you to go get your arena badges.",
        "To begin, here's your Pokemon and your Pokedex",
        "You can access your bag if you press [I].",
        NULL };

    void create_dialog(void *game_ptr);

    void render_dialog(void *game_ptr);

    void handle_dialog_event(void *game_ptr, sfEvent event);

    void destroy_dialog(dialog_t *dialog);

#endif
