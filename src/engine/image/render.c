/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** render
*/

#include "image.h"

void render_images(sfRenderWindow *window, image_t *head)
{
    image_t *temp = head;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(window, temp->sprite, NULL);
        temp = temp->next;
    }
}
