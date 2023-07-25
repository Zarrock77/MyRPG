/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** registrar
*/

#include "engine/button.h"

void register_button(button_t **head, button_t *button)
{
    button_t *temp = *head;

    if (temp == NULL) {
        *head = button;

        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = button;
}
