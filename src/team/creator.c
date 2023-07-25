/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** creator
*/

#include "game.h"

static int stat_formula(int base_stat, int level, int rate)
{
    return (((2 * base_stat + 31 + (252 / 4)) * level / 100) + 5) * rate;
}

static void init_stats(team_t *team, int i)
{
    team->squad[i].atk = base_stats[team->squad[i].id][ATK];
    team->squad[i].def = base_stats[team->squad[i].id][DEF];
    team->squad[i].spe_atk = base_stats[team->squad[i].id][SP_ATK];
    team->squad[i].spe_def = base_stats[team->squad[i].id][SP_DEF];
    team->squad[i].hp =
    stat_formula(base_stats[team->squad[i].id][HP],
    team->squad[i].lvl, base_growth_rate[team->squad[i].id]);
    team->squad[i].speed = base_stats[team->squad[i].id][SPEED];
    team->squad[i].max_hp = team->squad[i].hp;
}

void create_team(void *game_ptr)
{
    game_t *game = game_ptr;
    team_t *team = malloc(sizeof(team_t));

    for (int i = 0; i < 3; i++) {
        team->squad[i].id = i * 3;
        team->squad[i].lvl = 5;
        init_stats(team, i);
    }
    game->team = team;
}
