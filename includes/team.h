/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** team
*/

#ifndef TEAM_H_
    #define TEAM_H_

    typedef struct s_poke_entity {
        int owned_status;
        int type1;
        int type2;
        int lvl;
        int max_hp;
        int hp;
        int atk;
        int def;
        int spe_atk;
        int spe_def;
        int speed;
        int id;
    } poke_entity_t;

    typedef struct s_team {
        poke_entity_t squad[6];
    } team_t;

    typedef struct s_battle_infos {
        int fighters_nb;
    } battle_infos_t;

    #define WILD_PKM 1
    #define TRAINER_PKM 1.5

    enum growth_rate {
        SLOW = 1,
        MEDIUM = 2,
        FAST = 3
    };

    static const int base_growth_rate[42] = {
        MEDIUM, // Treecko
        MEDIUM, // Grovyle
        MEDIUM, // Sceptile
        MEDIUM, // Chimchar
        MEDIUM, // Monferno
        MEDIUM, // Infernape
        MEDIUM, // Squirtle
        MEDIUM, // Wartortle
        MEDIUM, // Blastoise
        FAST,   // Clefairy
        FAST,   // Clefable
        SLOW,   // Tauros
        MEDIUM, // Rattata
        MEDIUM, // Raticate
        MEDIUM, // Pidgey
        MEDIUM, // Pidgeotto
        MEDIUM, // Pidgeot
        SLOW,   // Snorlax
        MEDIUM, // Riolu
        MEDIUM, // Lucario
        MEDIUM, // Magnemite
        MEDIUM, // Magneton
        MEDIUM, // Druddigon
        MEDIUM, // Rhyhorn
        MEDIUM, // Rhydon
        MEDIUM, // Houndour
        MEDIUM, // Houndoom
        MEDIUM, // Psyduck
        MEDIUM, // Golduck
        MEDIUM, // Hitmonchan
        MEDIUM, // Tangela
        MEDIUM, // Tangrowth
        MEDIUM, // Blitzle
        MEDIUM, // Zebstrika
        MEDIUM, // Scyther
        MEDIUM, // Wooper
        MEDIUM, // Quagsire
        SLOW,   // Onix
        MEDIUM, // Wingull
        MEDIUM, // Pelipper
        SLOW,   // Lapras
        SLOW    // Arceus
    };

    #define HP 0
    #define ATK 1
    #define DEF 2
    #define SP_ATK 3
    #define SP_DEF 4
    #define SPEED 5

    static const int base_stats[42][6] = {
        //HP|ATK|DEF|SP_ATK|SP_DEF|SPEED
        {40, 45, 35, 65, 55, 70},      // Treecko
        {50, 65, 45, 85, 65, 95},      // Grovyle
        {70, 85, 65, 105, 85, 120},    // Sceptile
        {44, 58, 44, 58, 44, 61},      // Chimchar
        {64, 78, 52, 78, 52, 81},      // Monferno
        {76, 104, 71, 104, 71, 108},   // Infernape
        {44, 48, 65, 50, 64, 43},      // Squirtle
        {59, 63, 80, 65, 80, 58},      // Wartortle
        {79, 83, 100, 85, 105, 78},    // Blastoise
        {70, 45, 48, 60, 65, 35},      // Clefairy
        {95, 70, 73, 95, 90, 60},      // Clefable
        {75, 100, 95, 40, 70, 110},    // Tauros
        {30, 56, 35, 25, 35, 72},      // Rattata
        {55, 81, 60, 50, 70, 97},      // Raticate
        {40, 45, 40, 35, 35, 56},      // Pidgey
        {63, 60, 55, 50, 50, 71},      // Pidgeotto
        {83, 80, 75, 70, 70, 101},     // Pidgeot
        {160, 110, 65, 65, 110, 30},   // Snorlax
        {40, 70, 40, 35, 40, 60},      // Riolu
        {70, 110, 70, 115, 70, 90},    // Lucario
        {25, 35, 70, 95, 55, 45},      // Magnemite
        {50, 60, 95, 120, 70, 70},     // Magneton
        {77, 120, 90, 60, 90, 48},     // Druddigon
        {80, 85, 95, 30, 30, 25},      // Rhyhorn
        {105, 130, 120, 45, 45, 40},   // Rhydon
        {45, 60, 30, 80, 50, 65},      // Houndour
        {75, 90, 50, 110, 80, 95},     // Houndoom
        {50, 52, 48, 65, 50, 55},      // Psyduck
        {80, 82, 78, 95, 80, 85},      // Golduck
        {50, 105, 79, 35, 110, 76},    // Hitmonchan
        {65, 80, 140, 40, 70, 70},     // Tangela
        {100, 125, 100, 55, 85, 50},   // Tangrowth
        {45, 60, 32, 50, 32, 76},      // Blitzle
        {75, 100, 63, 80, 63, 116},    // Zebstrika
        {70, 110, 80, 55, 80, 105},    // Scyther
        {55, 45, 45, 25, 25, 15},      // Wooper
        {75, 65, 65, 45, 45, 35},      // Quagsire
        {35, 45, 160, 30, 45, 70},     // Onix
        {40, 30, 30, 55, 30, 85},      // Wingull
        {60, 50, 100, 85, 70, 65},     // Pelipper
        {130, 85, 80, 85, 95, 60},     // Lapras
        {120, 120, 120, 120, 120, 120} // Arceus
    };

    void create_team(void *game_ptr);
    void destroy_team(team_t *team);

#endif /* !TEAM_H_ */
