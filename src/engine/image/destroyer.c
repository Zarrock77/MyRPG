/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** destroyer
*/

#include "engine/image.h"

void destroy_image(image_t *image)
{
    if (image->sprite != NULL)
        sfSprite_destroy(image->sprite);
    if (image->texture != NULL)
        sfTexture_destroy(image->texture);
    free(image);
}
