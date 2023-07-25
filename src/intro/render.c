/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** render
*/

#include "game.h"

void render_intro(void *game_ptr)
{
    game_t *game = game_ptr;
    sfRenderWindow_drawSprite(game->window, game->intro->img->sprite, NULL);
    if (game->intro->nb != 12)
        clock_move_intro(game->intro);
    if (game->intro->nb >= 12)
        game->intro->img->is_visible = sfFalse;
}
