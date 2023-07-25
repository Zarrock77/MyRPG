/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** compute_catch_rate
*/

#include "pokedex.h"
#include "team.h"

int compute_catch_rate(int curr_pkm, pokedex_t *dex, poke_entity_t *pkm_entity)
{
    return (
        (((3 * pkm_entity->max_hp - 2 * pkm_entity->hp) *
        (dex->infos[curr_pkm].rate * 1)) / (3 * pkm_entity->max_hp))
    );
}
