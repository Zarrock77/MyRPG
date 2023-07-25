/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** destroyer
*/

#include "map.h"
#include <stdlib.h>

void destroy_map(map_t *map)
{
    for (int i = 0; map->arr[i] != NULL; i++) {
        free(map->arr[i]);
    }
    free(map->arr);
    destroy_image(map->c1);
    destroy_image(map->c2);
    free(map);
}
