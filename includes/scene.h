/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** scene
*/

#ifndef SCENE_H_
    #define SCENE_H_
    #include <SFML/Graphics.h>
    #include "engine.h"
    #include "team.h"

    typedef struct s_infos_block {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
    } infos_block_t;

    typedef struct s_scene {
        image_t *background;
        infos_block_t *wild_pkm_infos;
        infos_block_t *trainer_pkm_infos;
        sfView *view;
        sfBool is_visible;
        button_t *buttons;
        poke_entity_t *enemy;
        int turn;
    } scene_t;

    void create_scene(void *game_ptr);

    void set_wild_scene(void *game_ptr);
    void setup_infos(void *game_ptr, sfVector2f scale);

    void setup_infos_enemy(void *game_ptr, sfVector2f scale);
    void set_enemy_infos_pos(void *game_ptr);
    void generate_enemy(void *game_ptr, int min_lvl, int max_lvl);

    void setup_infos_trainer(void *game_ptr, sfVector2f scale);
    void set_trainer_infos_pos(void *game_ptr);

    void set_trainer_pokemon(void *game_ptr, float scale);
    void set_enemy_pokemon(void *game_ptr, float scale);

    void handle_run_click(void *game_ptr);
    void handle_attack_click(void *game_ptr);
    void all_attacks(void *game_ptr);
    void fight(void *game_ptr);

    void destroy_scene(scene_t *scene);
    void render_scene(void *game_ptr);

#endif /* !SCENE_H_ */
