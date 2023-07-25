/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_perso
*/

#include "game.h"
#include <stdio.h>

void my_fonction_move_up(void *game_ptr, sfKeyCode code)
{
    game_t *game = game_ptr;
    player_t *player = game->player;
    map_t *map = game->map;
    if (code == sfKeyZ) {
        player->img->rect.top = 192;
        clock_move_player(player);
        if (check_collision_up(player, map) == 1) {
            map->arr[player->y][player->x] = ' ';
            map->arr[player->y - 1][player->x] = 'P';
            player->y--;
            player->direction = (sfVector2f){0.0f, -1.5f};
            random_encounter(map->arr[player->y - 1][player->x], game);
        }
    }
}

void my_fonction_move_down(void *game_ptr, sfKeyCode code)
{
    game_t *game = game_ptr;
    player_t *player = game->player;
    map_t *map = game->map;
    if (code == sfKeyS) {
        player->img->rect.top = 0;
        clock_move_player(player);
        if (map->arr[player->y + 1][player->x] != '#') {
            map->arr[player->y][player->x] = ' ';
            map->arr[player->y + 1][player->x] = 'P';
            player->y++;
            player->direction = (sfVector2f){0.0f, 1.5f};
            random_encounter(map->arr[player->y + 1][player->x], game);
        }
    }
}

void my_fonction_move_left(void *game_ptr, sfKeyCode code)
{
    game_t *game = game_ptr;
    player_t *player = game->player;
    map_t *map = game->map;
    if (code == sfKeyQ) {
        player->img->rect.top = 64;
        clock_move_player(player);
        if (map->arr[player->y][player->x - 1] != '#') {
            map->arr[player->y][player->x] = ' ';
            map->arr[player->y][player->x - 1] = 'P';
            player->x--;
            player->direction = (sfVector2f){-1.5f, 0.0f};
            random_encounter(map->arr[player->y][player->x - 1], game);
        }
    }
}

void my_fonction_move_right(void *game_ptr, sfKeyCode code)
{
    game_t *game = game_ptr;
    player_t *player = game->player;
    map_t *map = game->map;
    if (code == sfKeyD) {
        player->img->rect.top = 128;
        clock_move_player(player);
        if (map->arr[player->y][player->x + 1] != '#') {
            map->arr[player->y][player->x] = ' ';
            map->arr[player->y][player->x + 1] = 'P';
            player->x++;
            player->direction = (sfVector2f){1.5f, 0.0f};
            random_encounter(map->arr[player->y][player->x + 1], game);
        }
    }
}

void move_player(void *game_ptr, sfEvent event)
{
    game_t *game = game_ptr;
    sfKeyCode code = event.key.code;
    if (game->player->in_mouv == sfFalse) {
        game->player->last =
            (sfVector2f){game->player->x * 32 + 16, game->player->y * 32};
        my_fonction_move_up(game, code);
        my_fonction_move_down(game, code);
        my_fonction_move_left(game, code);
        my_fonction_move_right(game, code);
    }
}
