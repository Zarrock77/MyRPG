/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** start
*/

#ifndef START_H_
    #define START_H_
    #include <SFML/Graphics.h>
    #include "engine/image.h"
    #include "game.h"

    void create_start(void *game_ptr);
    void move_rect(sfSprite *sprite, sfIntRect *rect, int offset,
    int max_value);
    void clock_move_start(image_t *start);
    void render_start(sfRenderWindow *window, image_t *start);
    void destroy_start(image_t *start);

#endif /* !START_H_ */
