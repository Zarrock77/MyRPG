/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** compute_gotten_xp
*/

#include "pokedex.h"
#include "team.h"

int compute_wild_xp(int curr_pkm, pokedex_t *dex,
poke_entity_t *pkm_entity, battle_infos_t *battle)
{
    return (
        (pkm_entity->owned_status * 1 *
        dex->infos[curr_pkm].base_xp * 1 * pkm_entity->lvl)
        /
        (7 * battle->fighters_nb)
    );
}
