/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** setup_scene
*/

#include "game.h"

void setup_infos(void *game_ptr, sfVector2f scale)
{
    setup_infos_enemy(game_ptr, scale);
    setup_infos_trainer(game_ptr, scale);
}

void setup_scene_buttons(void *game_ptr, float scale)
{
    game_t *game = game_ptr;

    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfVector2f pos_run = {1600, 900};
    button_t *button_run =
    create_button(game->font, "RUN", pos_run, handle_run_click);

    sfVector2f pos_attack = {1600, 800};
    button_t *button_attack =
    create_button(game->font, "ATTACK", pos_attack, handle_attack_click);

    button_t **head = &game->scene->buttons;

    register_button(head, button_run);
    register_button(head, button_attack);
}

void set_wild_scene(void *game_ptr)
{
    game_t *game = game_ptr;

    game->scene->turn = 0;
    generate_enemy(game_ptr, 3, 10);
    game->scene->background =
    create_image("assets/battle.png", (sfVector2f){0, 0}, game->window);
    game->scene->background->rect =
    get_first_frame(game->scene->background->sprite, 3, 3);
    sfSprite_setTextureRect(game->scene->background->sprite,
    game->scene->background->rect);
    game->scene->background->scale_rect =
    get_scale_rect(game->scene->background->rect, game->window);
    sfSprite_setScale(game->scene->background->sprite,
    game->scene->background->scale_rect);
    setup_infos(game_ptr, game->scene->background->scale_rect);
    setup_scene_buttons(game_ptr, game->scene->background->round_scale_rect);
}
