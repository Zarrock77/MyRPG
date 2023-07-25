/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroyer
*/

#include "pause.h"

void destroy_pause(pause_t *pause)
{
    destroy_buttons(pause->buttons);
}
