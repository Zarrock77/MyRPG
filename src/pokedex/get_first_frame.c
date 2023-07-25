/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** get_first_frame
*/

#include "engine.h"

sfIntRect get_first_frame(sfSprite* sprite, int num_frames_x, int num_frames_y)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.width = rect.width / num_frames_x;
    rect.height = rect.height / num_frames_y;
    return rect;
}
