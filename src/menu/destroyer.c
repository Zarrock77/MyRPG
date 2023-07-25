/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** destroyer
*/

#include "menu.h"

void destroy_menu(menu_t *menu)
{
    destroy_image(menu->background);
    destroy_buttons(menu->buttons);
    free(menu);
}
