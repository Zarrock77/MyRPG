/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** initialize_battle
*/

#include "game.h"

void render_scene(void *game_ptr)
{
    game_t *game = game_ptr;
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfView_setSize(game->scene->view,
    (sfVector2f){(float)size.x, (float)size.y});
    sfView_setCenter(game->scene->view,
    (sfVector2f){(float)size.x / 2, (float)size.y / 2});
    sfRenderWindow_setView(game->window, game->pause->view);
    sfRenderWindow_drawSprite(game->window,
    game->scene->background->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene->trainer_pkm_infos->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene->wild_pkm_infos->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->dex->back[game->team->squad->id].sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->dex->front[game->scene->enemy->id].sprite, NULL);
    render_buttons(game->window, game->scene->buttons);
    fight(game_ptr);
}
