/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** image
*/

#ifndef ENGINE_IMAGE_H_

    #define ENGINE_IMAGE_H_

    #include <stdlib.h>
    #include <SFML/Graphics.h>

    typedef struct image_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f position;
        sfBool is_visible;
        sfIntRect rect;
        float texture_width;
        float texture_height;
        sfVector2f scale;
        float round_scale;
        sfVector2f scale_rect;
        float round_scale_rect;
        sfView *view;
        sfClock *clock;
        int x;
        int y;

        struct image_s *next;
    } image_t;

    image_t *create_image(const char *path,
    sfVector2f position, sfRenderWindow *window);
    sfVector2f get_scale_rect(sfIntRect rect, sfRenderWindow *window);
    sfVector2f get_scale(sfTexture *texture, sfRenderWindow *window);
    float get_round_scale(sfVector2f scale);

    void register_image(image_t **head, image_t *image);

    void destroy_image(image_t *image);

#endif
