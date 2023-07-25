/*
** EPITECH PROJECT, 2023
** my-rpg
** File description:
** destroyer
*/

#include "game.h"

void destroy_dialog(dialog_t *dialog)
{
    destroy_image(dialog->background);
    free(dialog);
}
