/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** main
*/

#include "game.h"

int main(void)
{
    game_t game = (game_t){ 0 };

    create_game(&game);

    render_game(&game);

    destroy_game(&game);
    return 0;
}
