/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** registrar
*/

#include "image.h"

void register_image(image_t **head, image_t *image)
{
    image_t *temp = *head;

    if (temp == NULL) {
        *head = image;

        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = image;
}
