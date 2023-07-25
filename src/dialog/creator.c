/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** creator
*/

#include "game.h"

static void create_text(game_t *game)
{
    game->dialog->text = sfText_create();

    sfText_setFont(game->dialog->text, game->font);
    sfText_setCharacterSize(game->dialog->text, 13);
    sfText_setFillColor(game->dialog->text, sfBlack);
}

static void create_ask_text(game_t *game)
{
    game->dialog->ask_text = sfText_create();

    sfText_setFont(game->dialog->ask_text, game->font);
    sfText_setCharacterSize(game->dialog->ask_text, 19);
    sfText_setFillColor(game->dialog->ask_text, sfWhite);
    sfText_setString(game->dialog->ask_text, "Press [T] to talk");
    sfText_setOutlineThickness(game->dialog->ask_text, 2);
    sfText_setOutlineColor(game->dialog->ask_text, sfBlack);
}

void create_dialog(void *game_ptr)
{
    game_t *game = game_ptr;

    game->dialog = malloc(sizeof(dialog_t));

    game->dialog->is_visible = sfFalse;
    game->dialog->is_asking = sfFalse;
    game->dialog->background = create_image("assets/Sprites/dialogbox.png",
        (sfVector2f){ 0, 0 }, game->window);

    sfSprite_setScale(game->dialog->background->sprite,
        (sfVector2f){ 0.29, 0.29 });

    create_ask_text(game);
    create_text(game);
}
