/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** collision
*/

#include "game.h"
#include "map.h"

int check_collision_up(player_t *player, map_t *map)
{
    if (map->arr[player->y - 1][player->x] != '#' &&
        map->arr[player->y - 1][player->x] != 'J') {
        return 1;
    }
    return 0;
}
