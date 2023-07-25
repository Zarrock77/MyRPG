/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** render
*/

#include "engine/button.h"

void render_buttons(sfRenderWindow *window, button_t *head)
{
    button_t *temp = head;

    while (temp != NULL) {
        if (temp->is_visible) {
            sfRenderWindow_drawRectangleShape(window, temp->background, NULL);
            sfRenderWindow_drawText(window, temp->text, NULL);
        }
        temp = temp->next;
    }
}
