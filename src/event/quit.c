/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** Quit button clicked handler
*/

#include "game.h"

void handle_quit_click(void *game_ptr)
{
    game_t *game = game_ptr;
    sfRenderWindow_close(game->window);
}
