/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** render
*/

#include "start.h"

void render_start(sfRenderWindow *window, image_t *start)
{
    sfRenderWindow_drawSprite(window, start->sprite, NULL);
    clock_move_start(start);
}
