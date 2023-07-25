/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** event
*/

#include "game.h"

void handle_run_click(void *game_ptr)
{
    game_t *game = game_ptr;
    game->scene->is_visible = sfFalse;
    game->player->in_fight = sfFalse;
    game->map->is_visible = sfTrue;
}

void handle_attack_click(void *game_ptr)
{
    game_t *game = game_ptr;
    if (game->scene->turn % 2 == 0) {
        game->scene->turn++;
    }
}

void fight(void *game_ptr)
{
    game_t *game = game_ptr;
    int trainer_hp = game->team->squad->hp;
    int enemy_hp = game->scene->enemy->hp;
    if (enemy_hp > 0 && trainer_hp > 0) {
        all_attacks(game_ptr);
    } else {
        game->scene->is_visible = sfFalse;
        game->player->in_fight = sfFalse;
        game->map->is_visible = sfTrue;
    }
}

void all_attacks(void *game_ptr)
{
    game_t *game = game_ptr;
    int damage = 0;
    if (game->scene->turn % 2 == 1) {
        damage = game->scene->enemy->atk - game->team->squad->def;
        if (damage < 0)
            damage = 0;
        game->team->squad->hp -= damage;
        game->scene->turn++;
    }
    if (game->scene->turn % 2 == 0) {
        damage = game->team->squad->atk; - game->scene->enemy->def;
        if (damage < 0)
            damage = 0;
        game->scene->enemy->hp -= damage;
    }
}
