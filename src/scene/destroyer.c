/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** destroyer
*/

#include "scene.h"

void destroy_scene(scene_t *scene)
{
    destroy_image(scene->background);
    free(scene);
}
