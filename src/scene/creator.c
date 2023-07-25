/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** creator
*/

#include "game.h"

void create_scene(void *game_ptr)
{
    game_t *game = game_ptr;
    scene_t *scene = malloc(sizeof(scene_t));
    scene->is_visible = sfFalse;
    scene->view = sfView_create();
    scene->buttons = NULL;
    scene->turn = 0;
    game->scene = scene;
}
