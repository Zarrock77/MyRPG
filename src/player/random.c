/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** random
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "game.h"

int get_random(int max)
{
    static int initialized = 0;
    static unsigned int seed = 1;

    if (!initialized) {
        uintptr_t addr = (uintptr_t)&max;
        seed = (unsigned int)addr;
        initialized = 1;
    }
    seed = (seed * 1103515245 + 12345) % 2147483648;
    int random_number = seed % max;
    return random_number;
}

void random_encounter(char c, void *game_ptr)
{
    game_t *game = game_ptr;
    if (c == 'B' && get_random(100) > 70) {
        game->player->in_fight = sfTrue;
        return;
    }
    game->player->in_fight = sfFalse;
}
