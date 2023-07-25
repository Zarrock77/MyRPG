/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** destroy_loader
*/

#include "game.h"
#include "fullscreen_loader.h"

void destroy_loader(LoadingData data, sfFont *font)
{
    sfRectangleShape_destroy(data.loading_bar_bg);
    sfRectangleShape_destroy(data.loading_bar);
    sfText_destroy(data.text);
    sfFont_destroy(font);
    sfRenderWindow_destroy(data.window);
    sfClock_destroy(data.clock);
}
