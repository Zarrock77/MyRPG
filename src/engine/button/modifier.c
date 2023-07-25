/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** modifier
*/

#include "engine/button.h"

void set_button_position(button_t *button, sfVector2f position)
{
    sfRectangleShape_setPosition(button->background, position);

    sfText_setPosition(button->text,
        (sfVector2f){ .x = position.x + 27, .y = position.y + 37 });
}
