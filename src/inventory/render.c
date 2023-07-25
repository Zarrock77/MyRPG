/*
** EPITECH PROJECT, 2023
** my_rpg1
** File description:
** render
*/

#include <stdio.h>
#include "game.h"

void render_inventory(void *game_ptr)
{
    game_t *game = game_ptr;

    player_t *player = game->player;

    sfVector2f pos = (sfVector2f){ game->player->x * 32, game->player->y * 32 };

    int width = sfRenderWindow_getSize(game->window).x == 1920 ? 210 : 25;
    int height = sfRenderWindow_getSize(game->window).y == 1080 ? 260 : 210;

    sfSprite_setScale(game->inventory->background->sprite,
        (sfVector2f){ 1.3, 1.3 });
    sfSprite_setPosition(game->inventory->background->sprite,
        (sfVector2f){ pos.x + width,
            pos.y - height });

    sfRenderWindow_drawSprite(game->window,
        game->inventory->background->sprite, NULL);

    render_items(game_ptr);
}
