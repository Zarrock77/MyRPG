/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** destroyer
*/

#include "player.h"
#include "engine/image.h"

void destroy_player(player_t *player)
{
    destroy_image(player->img);
    free(player);
}
