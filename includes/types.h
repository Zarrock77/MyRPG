/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** types
*/

#ifndef TYPES_H_
    #define TYPES_H_

    typedef enum {
        NORMAL_TYPE,
        FIRE_TYPE,
        WATER_TYPE,
        ELECTRIC_TYPE,
        GRASS_TYPE,
        ICE_TYPE,
        FIGHTING_TYPE,
        POISON_TYPE,
        GROUND_TYPE,
        FLYING_TYPE,
        PSYCHIC_TYPE,
        BUG_TYPE,
        ROCK_TYPE,
        GHOST_TYPE,
        DRAGON_TYPE,
        DARK_TYPE,
        STEEL_TYPE,
        FAIRY_TYPE
    } pokemon_type_t;

    static const float type_chart[18][18] = {
        { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.5, 1.0 },
        { 1.0, 0.5, 2.0, 1.0, 0.5, 0.5, 1.0, 1.0,
        1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 2.0, 1.0 },
        { 1.0, 0.5, 0.5, 2.0, 2.0, 0.5, 1.0, 1.0,
        2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0 },
        { 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0,
        0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0 },
        { 1.0, 2.0, 0.5, 2.0, 0.5, 2.0, 1.0, 2.0,
        0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 0.5, 1.0, 2.0, 1.0 },
        { 1.0, 2.0, 0.5, 1.0, 2.0, 0.5, 1.0, 1.0,
        2.0, 2.0, 1.0, 1.0, 2.0, 1.0, 2.0, 1.0, 2.0, 1.0 },
        { 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5,
        1.0, 0.5, 0.5, 0.5, 2.0, 0.0, 1.0, 2.0, 2.0, 0.5 },
        { 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
        0.5, 1.0, 2.0, 0.5, 0.5, 0.5, 1.0, 2.0, 0.0, 2.0 },
        { 1.0, 1.0, 2.0, 0.0, 2.0, 1.0, 1.0, 2.0,
        1.0, 0.5, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0 },
        { 1.0, 1.0, 1.0, 2.0, 0.5, 2.0, 2.0, 1.0,
        1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 0.5, 1.0 },
        { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
        1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 0.0, 0.5, 1.0 },
        { 1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5,
        1.0, 0.5, 2.0, 1.0, 1.0, 0.5, 1.0, 2.0, 0.5, 0.5 },
        { 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0,
        2.0, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0 },
        { 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5,
        1.0, 1.0, 2.0, 0.5, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0 },
        { 1.0, 0.5, 0.5, 0.5, 0.5, 2.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 2.0 },
        { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0,
        1.0, 1.0, 0.0, 2.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5 },
        { 1.0, 0.5, 0.5, 0.5, 2.0, 0.5, 2.0, 1.0,
        2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 0.5, 2.0 },
        { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 2.0, 2.0, 1.0 }
    };

    static const int pkm_types[42][2] = {
        {GRASS_TYPE, -1},      // Treecko
        {GRASS_TYPE, -1},      // Grovyle
        {GRASS_TYPE, -1},      // Sceptile
        {FIRE_TYPE, -1},       // Chimchar
        {FIRE_TYPE, FIGHTING_TYPE}, // Monferno
        {FIRE_TYPE, FIGHTING_TYPE}, // Infernape
        {WATER_TYPE, -1},      // Squirtle
        {WATER_TYPE, -1},      // Wartortle
        {WATER_TYPE, -1},      // Blastoise
        {FAIRY_TYPE, -1},      // Clefairy
        {FAIRY_TYPE, -1},      // Clefable
        {NORMAL_TYPE, -1},     // Tauros
        {NORMAL_TYPE, -1},     // Rattata
        {NORMAL_TYPE, -1},     // Raticate
        {FLYING_TYPE, NORMAL_TYPE}, // Pidgey
        {FLYING_TYPE, NORMAL_TYPE}, // Pidgeotto
        {FLYING_TYPE, NORMAL_TYPE}, // Pidgeot
        {NORMAL_TYPE, -1},     // Snorlax
        {FIGHTING_TYPE, -1},   // Riolu
        {FIGHTING_TYPE, STEEL_TYPE}, // Lucario
        {ELECTRIC_TYPE, STEEL_TYPE}, // Magnemite
        {ELECTRIC_TYPE, STEEL_TYPE}, // Magneton
        {DRAGON_TYPE, -1},     // Druddigon
        {GROUND_TYPE, ROCK_TYPE}, // Ryhorn
        {GROUND_TYPE, ROCK_TYPE}, // Rhydon
        {DARK_TYPE, FIRE_TYPE}, // Houndour
        {DARK_TYPE, FIRE_TYPE}, // Houndoom
        {WATER_TYPE, -1},      // Psyduck
        {WATER_TYPE, -1},      // Golduck
        {FIGHTING_TYPE, -1},   // Hitmonchan
        {GRASS_TYPE, -1},      // Tangela
        {GRASS_TYPE, -1},      // Tangrowth
        {ELECTRIC_TYPE, -1},   // Blitzle
        {ELECTRIC_TYPE, -1},   // Zebstrika
        {BUG_TYPE, FLYING_TYPE}, // Scyther
        {WATER_TYPE, GROUND_TYPE}, // Wooper
        {WATER_TYPE, GROUND_TYPE}, // Quagsire
        {ROCK_TYPE, GROUND_TYPE}, // Onix
        {FLYING_TYPE, WATER_TYPE}, // Wingull
        {FLYING_TYPE, WATER_TYPE}, // Pelipper
        {WATER_TYPE, ICE_TYPE}, // Lapras
        {NORMAL_TYPE, -1},     // Arceus
    };

#endif /* !TYPES_H_ */
