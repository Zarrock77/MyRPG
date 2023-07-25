/*
** EPITECH PROJECT, 2023
** test
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #define POKEMONS_NB 42

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "types.h"
    #include "engine.h"

    typedef struct s_pokemon {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        int n_frames_x;
        int n_frames_y;
        int n_frames;
    } pokemon_t;

    typedef struct s_poke_info {
        sfText *name_text;
        const char *name;
        int captured;
        int rate;
        int base_xp;
        int type1;
        int type2;
    } poke_info_t;

    typedef struct s_pokedex {
        pokemon_t front[POKEMONS_NB];
        pokemon_t back[POKEMONS_NB];
        poke_info_t infos[POKEMONS_NB];
        sfSprite *ball_sprite;
        sfTexture *ball_texture;
        bool is_captured;
        sfSprite *current_sprite;
        sfText *current_name;
        sfFont *font;
        sfSprite *background;
        sfTexture *texture;
        sfBool is_active;
        int current_pokemon;
    } pokedex_t;

    void create_dex(void *game_ptr);
    void destroy_dex(pokedex_t *dex);
    void update_display(pokedex_t *dex, int current_pokemon);
    void handle_events(sfRenderWindow *window,
    int *current_pokemon, pokedex_t *dex, sfEvent event);
    void draw_sprites(sfRenderWindow *window,
    pokedex_t *dex, int current_pokemon);

#endif /* !MY_H_ */
