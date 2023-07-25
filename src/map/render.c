/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** render_view
*/

#include "map.h"

void render_c1(sfRenderWindow *window, map_t *map)
{
    sfRenderWindow_setView(window, map->c1->view);
    sfRenderWindow_drawSprite(window, map->c1->sprite, NULL);
}

void render_c2(sfRenderWindow *window, map_t *map)
{
    sfRenderWindow_setView(window, map->c2->view);
    sfRenderWindow_drawSprite(window, map->c2->sprite, NULL);
}

void render_png(sfRenderWindow *window, image_t *png)
{
    sfRenderWindow_drawSprite(window ,png->sprite, NULL);
}
