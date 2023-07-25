/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** compute_damage
*/

#include "team.h"

int compute_damage(poke_entity_t *attacker, poke_entity_t *attacked_one)
{
    int damages = attacker->atk - attacked_one->def;
    return damages > 0 ? damages : 0;
}
