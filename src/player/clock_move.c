/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** clock_move
*/

#include "player.h"

void move_rect_player(sfSprite *sprite, sfIntRect *rect,
    int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left == max_value)
        rect->left = 0;
    sfSprite_setTextureRect(sprite, *rect);
}

void clock_move_player(player_t *player)
{
    if (sfTime_asMilliseconds(
        sfClock_getElapsedTime(player->img->clock)) > 200) {
        move_rect_player(player->img->sprite, &player->img->rect, 64, 256);
        sfClock_restart(player->img->clock);
    }
}
