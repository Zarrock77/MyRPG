/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** image
*/

#include "engine/image.h"

sfVector2f get_scale(sfTexture *texture, sfRenderWindow *window)
{
    float texture_width = (float)sfTexture_getSize(texture).x;
    float texture_height = (float)sfTexture_getSize(texture).y;
    float width = sfRenderWindow_getSize(window).x;
    float height = sfRenderWindow_getSize(window).y;
    float scale_x = width / texture_width;
    float scale_y = height / texture_height;
    return (sfVector2f) {scale_x, scale_y};
}

sfVector2f get_scale_rect(sfIntRect rect, sfRenderWindow *window)
{
    float rect_width = (float)rect.width;
    float rect_height = (float)rect.height;
    float width = sfRenderWindow_getSize(window).x;
    float height = sfRenderWindow_getSize(window).y;
    float scale_x = width / rect_width;
    float scale_y = height / rect_height;
    return (sfVector2f){scale_x, scale_y};
}

float get_round_scale(sfVector2f scale)
{
    return (scale.x < scale.y) ? scale.x : scale.y;
}

image_t *create_image(const char *path,
sfVector2f position, sfRenderWindow *window)
{
    image_t *image = malloc(sizeof(image_t));

    image->sprite = sfSprite_create();
    image->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(image->sprite, image->texture, sfFalse);
    image->position = position;
    sfSprite_setPosition(image->sprite, position);
    image->is_visible = sfTrue;

    image->texture_width = (float)sfTexture_getSize(image->texture).x;
    image->texture_height = (float)sfTexture_getSize(image->texture).y;

    image->rect =
        (sfIntRect){0.f, 0.f, image->texture_width, image->texture_height};

    image->scale = get_scale(image->texture, window);
    image->scale_rect = get_scale_rect(image->rect, window);
    image->round_scale = get_round_scale(image->scale);
    image->round_scale_rect = get_round_scale(image->scale_rect);
    return image;
}
