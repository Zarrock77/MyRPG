/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** intro
*/

#ifndef INTRO_H_
    #define INTRO_H_
    #include <SFML/Graphics.h>
    #include "engine/image.h"

    typedef struct intro_s {
        image_t *img;
        int nb;
    } intro_t;

    void create_intro(void *game_ptr);
    void move_rect_intro(intro_t *intro, int offset, int max_value);
    void clock_move_intro(intro_t *intro);
    void render_intro(void *game_ptr);
    void destroy_intro(intro_t *intro);

#endif /* !INTRO_H_ */
