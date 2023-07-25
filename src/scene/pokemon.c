/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** pokemon
*/

#include "game.h"

void set_trainer_pokemon(void *game_ptr, float scale)
{
    game_t *game = game_ptr;
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfSprite_setScale(game->dex->back[game->team->squad->id].sprite,
    (sfVector2f){2, 2});
    sfVector2f position = {size.x * 0.5f, size.y * 0.5f};
    sfSprite_setPosition(
        game->dex->back[game->team->squad->id].sprite, position);
}

void set_enemy_pokemon(void *game_ptr, float scale)
{
    game_t *game = game_ptr;
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfSprite_setScale(game->dex->back[game->team->squad->id].sprite,
    (sfVector2f){2, 2});
    sfVector2f position = {200 , size.y * 0.5f};
    sfSprite_setPosition(
        game->dex->front[game->scene->enemy->id].sprite, position);
}
