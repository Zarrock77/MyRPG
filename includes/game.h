/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** rpg
*/

#ifndef GAME_H_

    #define GAME_H_

    #include <SFML/Graphics.h>
    #include "engine.h"
    #include "intro.h"
    #include "start.h"
    #include "menu.h"
    #include "options.h"
    #include "map.h"
    #include "player.h"
    #include "pause.h"
    #include "pokedex.h"
    #include "item.h"
    #include "dialog.h"
    #include "inventory.h"
    #include "team.h"
    #include "scene.h"

    typedef struct game_s {
        sfVideoMode mode;
        sfRenderWindow *window;
        sfFont *font;
        intro_t *intro;
        image_t *professeur;
        image_t *start;
        menu_t *menu;
        options_t *options;
        pause_t *pause;
        player_t *player;
        map_t *map;
        pokedex_t *dex;
        item_t *items;
        dialog_t *dialog;
        inventory_t *inventory;
        team_t *team;
        scene_t *scene;
    } game_t;

    void create_game(game_t *game);

    void render_game(game_t *game);

    void handle_game_event(sfRenderWindow *window, game_t *game);

    void destroy_game(game_t *game);

    int get_random(int max);

#endif
