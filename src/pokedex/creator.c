/*
** EPITECH PROJECT, 2023
** TEST
** File description:
** initialize_pokdex
*/

#include "pokedex.h"
#include "dex_ressources.h"
#include "game.h"

static int round_up_to_multiple_of_5(int num)
{
    if (num % 5 == 0) {
        return num;
    } else {
        return num + (5 - (num % 5));
    }
}

static void init_dex_front(pokedex_t *dex)
{
    for (int i = 0; i < POKEMONS_NB; i++) {
        dex->front[i].texture = sfTexture_createFromFile(dirs_front[i], NULL);
        dex->front[i].sprite = sfSprite_create();
        sfSprite_setTexture(dex->front[i].sprite,
        dex->front[i].texture, sfFalse);
        dex->front[i].n_frames = n_frames_front[i];
        dex->front[i].n_frames_x = 5;
        dex->front[i].n_frames_y =
        (round_up_to_multiple_of_5(dex->front[i].n_frames) / 5);
        dex->front[i].rect = get_first_frame(dex->front[i].sprite,
                        dex->front[i].n_frames_x, dex->front[i].n_frames_y);
        sfSprite_setTextureRect(dex->front[i].sprite, dex->front[i].rect);
    }
}

static void init_dex_back(pokedex_t *dex)
{
    for (int i = 0; i < POKEMONS_NB; i++) {
        dex->back[i].texture = sfTexture_createFromFile(dirs_back[i], NULL);
        dex->back[i].sprite = sfSprite_create();
        sfSprite_setTexture(dex->back[i].sprite, dex->back[i].texture, sfFalse);
        dex->back[i].n_frames = n_frames_back[i];
        dex->back[i].n_frames_x = 5;
        dex->back[i].n_frames_y =
        (round_up_to_multiple_of_5(dex->back[i].n_frames) / 5);
        dex->back[i].rect = get_first_frame(dex->back[i].sprite,
                            dex->back[i].n_frames_x, dex->back[i].n_frames_y);
        sfSprite_setTextureRect(dex->back[i].sprite, dex->back[i].rect);
    }
}

static void init_dex_info(pokedex_t *dex)
{
    dex->font = sfFont_createFromFile("./assets/font.TTF");

    for (int i = 0; i < POKEMONS_NB; i++) {
        dex->infos[i].captured = 0;
        dex->infos[i].name = name[i];
        dex->infos[i].name_text = sfText_create();
        sfText_setString(dex->infos[i].name_text, name[i]);
        sfText_setFont(dex->infos[i].name_text, dex->font);
        sfText_setColor(dex->infos[i].name_text, sfWhite);
        sfText_setCharacterSize(dex->infos[i].name_text, 20);
        sfText_setFillColor(dex->infos[i].name_text, sfWhite);
        dex->infos[i].rate = catch_rates[i];
        dex->infos[i].base_xp = base_xp_given[i];
        dex->infos[i].type1 = pkm_types[i][0];
        dex->infos[i].type2 = pkm_types[i][1];
    }
}

void create_dex(void *game_ptr)
{
    pokedex_t *dex = malloc(sizeof(pokedex_t));
    game_t *game = game_ptr;

    dex->is_captured = false;
    dex->background = sfSprite_create();
    dex->texture =
    sfTexture_createFromFile("./assets/Sprites/pokedex.png", NULL);
    sfSprite_setTexture(dex->background, dex->texture, sfFalse);
    dex->ball_sprite = sfSprite_create();
    dex->ball_texture =
    sfTexture_createFromFile("./assets/Sprites/pokeball.png", NULL);
    sfSprite_setTexture(dex->ball_sprite, dex->ball_texture, sfFalse);
    init_dex_front(dex);
    init_dex_back(dex);
    init_dex_info(dex);
    dex->is_active = sfFalse;
    dex->current_sprite = sfSprite_create();
    dex->current_pokemon = 0;
    game->dex = dex;
    update_display(game->dex, game->dex->current_pokemon);
}
