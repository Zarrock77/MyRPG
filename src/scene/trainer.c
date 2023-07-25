/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** trainer
*/

#include "game.h"

void setup_infos_trainer(void *game_ptr, sfVector2f new)
{
    game_t *game = game_ptr;
    game->scene->trainer_pkm_infos = malloc(sizeof(infos_block_t));

    game->scene->trainer_pkm_infos->texture =
    sfTexture_createFromFile("assets/infos.png", NULL);
    game->scene->trainer_pkm_infos->sprite = sfSprite_create();
    sfSprite_setTexture(game->scene->trainer_pkm_infos->sprite,
    game->scene->trainer_pkm_infos->texture, sfFalse);
    float scale = game->scene->background->round_scale_rect;
    sfSprite_setScale(game->scene->trainer_pkm_infos->sprite,
    (sfVector2f){1 / scale, 1 / scale});
    set_trainer_infos_pos(game_ptr);
    set_trainer_pokemon(game_ptr, scale);
}

void set_trainer_infos_pos(void *game_ptr)
{
    game_t *game = game_ptr;
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfVector2f position = {size.x * 0.75f, size.y * 0.5f};
    sfSprite_setPosition(game->scene->trainer_pkm_infos->sprite, position);
}
