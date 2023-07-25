/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** destroyer
*/

#include "engine/button.h"

void destroy_button(button_t *button)
{
    sfRectangleShape_destroy(button->background);
    sfText_destroy(button->text);
    free(button);
}

void destroy_buttons(button_t *head)
{
    button_t *temp = head;

    while (temp != NULL) {
        button_t *to_destroy = temp;

        temp = temp->next;

        destroy_button(to_destroy);
    }
}
