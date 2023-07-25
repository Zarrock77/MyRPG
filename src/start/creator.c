/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** creator
*/

#include "start.h"
#include "engine/image.h"
#include "game.h"

void create_start(void *game_ptr)
{
    game_t *game = game_ptr;
    image_t *start =
    create_image("assets/Sprites/start.png", (sfVector2f){0, 0}, game->window);
    start->clock = sfClock_create();
    start->rect.top = 0;
    start->rect.height = 160;
    start->rect.left = 240;
    start->rect.width = 240;
    float texture_height = (float)sfTexture_getSize(start->texture).y;
    float width = sfRenderWindow_getSize(game->window).x;
    float height = sfRenderWindow_getSize(game->window).y;
    float scale = height / texture_height;
    sfSprite_setScale(start->sprite, (sfVector2f){scale, scale});
    float x = (width - (240 * scale)) / 2;
    float y = (height - (160 * scale)) / 2;
    sfSprite_setPosition(start->sprite, (sfVector2f){x, y});
    sfSprite_setTextureRect(start->sprite, start->rect);
    start->is_visible = sfTrue;
    game->start = start;
}

void move_rect(sfSprite *sprite, sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left == max_value)
        rect->left = 0;
    sfSprite_setTextureRect(sprite, *rect);
}

void clock_move_start(image_t *start)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(start->clock)) > 100) {
        move_rect(start->sprite, &start->rect, 240, 9360);
        sfClock_restart(start->clock);
    }
}
