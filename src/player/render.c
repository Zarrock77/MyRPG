/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** render
*/

#include "game.h"


float absolute_value(float num)
{
    if (num < 0) {
        return -num;
    } else {
        return num;
    }
}

void verif_move(void *game_ptr, sfVector2f pos)
{
    game_t *game = game_ptr;
    if (game->player->direction.x != 0 || game->player->direction.y != 0) {
        clock_move_player(game->player);
        game->player->in_mouv = sfTrue;
    }
    if (absolute_value(pos.x - game->player->last.x) > 32 ||
        absolute_value(pos.y - game->player->last.y) > 32) {
        game->player->direction = (sfVector2f) {0, 0};
        game->player->in_mouv = sfFalse;
    }
}

void render_player(void *game_ptr)
{
    game_t *game = game_ptr;
    sfTime deltaTime = sfClock_restart(game->player->clock);
    float elapsedTime = sfTime_asSeconds(deltaTime);
    float speed = 64.0f;
    sfVector2f offset = {game->player->direction.x * speed * elapsedTime,
        game->player->direction.y * speed * elapsedTime};
    sfSprite_move(game->player->img->sprite, offset);
    sfVector2f pos = sfSprite_getPosition(game->player->img->sprite);
    sfView_setCenter(game->map->c1->view, (sfVector2f){pos.x + 16, pos.y + 16});
    sfView_setCenter(game->map->c2->view, (sfVector2f){pos.x + 16, pos.y + 16});
    verif_move(game_ptr, pos);
    if (game->player->in_fight == sfTrue && game->player->in_mouv == sfFalse) {
        game->map->is_visible = sfFalse;
        game->scene->is_visible = sfTrue;
        set_wild_scene(game);
        return;
    }
    sfRenderWindow_drawSprite(game->window, game->player->img->sprite, NULL);
}
