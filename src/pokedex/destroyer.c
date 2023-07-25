/*
** EPITECH PROJECT, 2023
** TEST
** File description:
** destroy_ressources
*/

#include "pokedex.h"

static void destroy_front_sprites(pokedex_t *dex)
{
    for (int i = 0; i < POKEMONS_NB; i++) {
        sfSprite_destroy(dex->front[i].sprite);
        sfTexture_destroy(dex->front[i].texture);
    }
}

static void destroy_back_sprites(pokedex_t *dex)
{
    for (int i = 0; i < POKEMONS_NB; i++) {
        sfSprite_destroy(dex->back[i].sprite);
        sfTexture_destroy(dex->back[i].texture);
    }
}

static void destroy_dex_info(pokedex_t *dex)
{
    for (int i = 0; i < POKEMONS_NB; i++) {
        sfText_destroy(dex->infos[i].name_text);
    }
}

void destroy_dex(pokedex_t *dex)
{
    destroy_front_sprites(dex);
    destroy_back_sprites(dex);
    destroy_dex_info(dex);
    sfSprite_destroy(dex->current_sprite);
    sfSprite_destroy(dex->background);
    sfTexture_destroy(dex->texture);
    sfSprite_destroy(dex->ball_sprite);
    sfTexture_destroy(dex->ball_texture);
    sfFont_destroy(dex->font);
    free(dex);
}
