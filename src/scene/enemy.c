/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** enemy
*/

#include "game.h"

void setup_infos_enemy(void *game_ptr, sfVector2f new)
{
    game_t *game = game_ptr;
    game->scene->wild_pkm_infos = malloc(sizeof(infos_block_t));

    game->scene->wild_pkm_infos->texture =
    sfTexture_createFromFile("assets/infos_char.png", NULL);
    game->scene->wild_pkm_infos->sprite = sfSprite_create();
    sfSprite_setTexture(game->scene->wild_pkm_infos->sprite,
    game->scene->wild_pkm_infos->texture, sfFalse);
    float scale = game->scene->background->round_scale_rect;
    sfSprite_setScale(game->scene->wild_pkm_infos->sprite,
    (sfVector2f){1 / scale, 1 / scale});
    set_enemy_infos_pos(game_ptr);
    set_enemy_pokemon(game_ptr, scale);
}

void set_enemy_infos_pos(void *game_ptr)
{
    game_t *game = game_ptr;
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfVector2f position = {size.x * 0.02f, size.y * 0.02f};
    sfSprite_setPosition(game->scene->wild_pkm_infos->sprite, position);
}

static int stat_formula(int base_stat, int level, int rate)
{
    return (((2 * base_stat + 31 + (252 / 4)) * level / 100) + 5) * rate;
}

static void init_stats(poke_entity_t *enemy)
{
    enemy->atk = base_stats[enemy->id][ATK];
    enemy->def = base_stats[enemy->id][DEF];
    enemy->spe_atk = base_stats[enemy->id][SP_ATK];
    enemy->spe_def = base_stats[enemy->id][SP_DEF];
    enemy->hp = stat_formula(base_stats[enemy->id][HP],
        enemy->lvl, base_growth_rate[enemy->id]);
    enemy->speed = base_stats[enemy->id][SPEED];
    enemy->max_hp = enemy->hp;
}

void generate_enemy(void *game_ptr, int min_lvl, int max_lvl)
{
    game_t *game = game_ptr;
    poke_entity_t* enemy = (poke_entity_t *)malloc(sizeof(poke_entity_t));
    int id = get_random(41);
    int lvl = get_random(max_lvl);

    while (lvl < min_lvl) {
        lvl = get_random(max_lvl);
    }
    enemy->id = id;
    enemy->lvl = lvl;
    init_stats(enemy);
    game->scene->enemy = enemy;
}
