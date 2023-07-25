/*
** EPITECH PROJECT, 2023
** TEST
** File description:
** update_display
*/

#include "pokedex.h"

static void update_texture(pokedex_t *dex, int current_pokemon)
{
    sfSprite_setTexture(dex->current_sprite,
    dex->front[current_pokemon].texture, sfFalse);
    sfSprite_setTextureRect(dex->current_sprite,
    dex->front[current_pokemon].rect);
    sfVector2f scale = { 100.0f /
                sfSprite_getLocalBounds(dex->current_sprite).width,
                100.0f / sfSprite_getLocalBounds(dex->current_sprite).height };
    sfSprite_setScale(dex->current_sprite, scale);
    sfVector2f pos = {
        sfSprite_getPosition(dex->background).x +
        (sfSprite_getLocalBounds(dex->background).width / 2 -
        scale.y / 2) * 0.95f,
        sfSprite_getPosition(dex->background).y +
        sfSprite_getLocalBounds(dex->background).height * 0.15f
    };
    sfSprite_setPosition(dex->current_sprite, pos);
}

static void update_ball_sprite(pokedex_t *dex)
{
    sfVector2f scale = (sfVector2f){ 50.0f /
            sfSprite_getLocalBounds(dex->ball_sprite).width,
            50.0f / sfSprite_getLocalBounds(dex->ball_sprite).height };
    sfSprite_setScale(dex->ball_sprite, scale);
    sfVector2f pos = (sfVector2f){
        sfSprite_getPosition(dex->background).x +
        (sfSprite_getLocalBounds(dex->background).width -
        sfSprite_getLocalBounds(dex->ball_sprite).width) * 16.0f,
        sfSprite_getPosition(dex->background).y +
        sfSprite_getLocalBounds(dex->background).height * 0.7f
    };
    sfSprite_setPosition(dex->ball_sprite, pos);
}

static void update_is_captured(pokedex_t *dex, int id)
{
    dex->is_captured = (dex->infos[id].captured > 0) ? true : false;
}

void update_display(pokedex_t *dex, int current_pokemon)
{
    update_texture(dex, current_pokemon);
    update_ball_sprite(dex);
    update_is_captured(dex, current_pokemon);
}

void draw_sprites(sfRenderWindow *window, pokedex_t *dex, int current_pokemon)
{
    sfRenderWindow_drawSprite(window, dex->background, NULL);
    sfRenderWindow_drawSprite(window, dex->current_sprite, NULL);
    if (dex->is_captured == true) {
        sfRenderWindow_drawSprite(window, dex->ball_sprite, NULL);
    }
    sfRenderWindow_drawText(window,
    dex->infos[current_pokemon].name_text, NULL);
}
