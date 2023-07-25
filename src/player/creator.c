/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** creator
*/

#include "game.h"
#include "engine/image.h"
#include "player.h"

void create_player(void *game_ptr)
{
    game_t *game = game_ptr;
    player_t *player = malloc(sizeof(player_t));
    player->x = 79;
    player->y = 108;
    image_t *img = create_image("assets/Characters/main_character.png",
                    (sfVector2f){79 * 32 + 16, 108 * 32}, game->window);
    img->rect = (sfIntRect){0, 64, 64, 64};
    sfSprite_setTextureRect(img->sprite, img->rect);
    img->clock = sfClock_create();
    player->img = img;
    player->clock = sfClock_create();
    player->direction = (sfVector2f) {0, 0};
    player->in_mouv = sfFalse;
    player->in_fight = sfFalse;
    player->last = (sfVector2f){79 * 32 + 16, 108 * 32};
    game->player = player;
}
