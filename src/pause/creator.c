/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** pause menu
*/

#include "game.h"
#include "engine/button.h"
#include "events.h"

static void create_title(game_t *game)
{
    sfText *title = sfText_create();

    sfText_setString(title, "- Paused -");
    sfText_setFont(title, game->font);
    sfText_setCharacterSize(title, 30);
    sfText_setFillColor(title, sfWhite);
    sfText_setPosition(title, (sfVector2f){ 880, 190 });

    game->pause->title = title;
}

static void create_pause_view(game_t *game)
{
    game->pause->view = sfView_create();

    sfVector2u windowSize = sfRenderWindow_getSize(game->window);

    sfView_setSize(game->pause->view,
        (sfVector2f){(float)windowSize.x, (float)windowSize.y});

    sfView_setCenter(game->pause->view,
        (sfVector2f){(float)windowSize.x / 2, (float)windowSize.y / 2});
}

void create_pause(void *game_ptr)
{
    game_t *game = game_ptr;
    game->pause = malloc(sizeof(pause_t));
    game->pause->buttons = NULL;
    game->pause->is_visible = sfFalse;

    create_title(game);
    create_pause_view(game);

    button_t *button_back = create_button(game->font, "< Back to menu",
        (sfVector2f){ 820, 465 }, handle_back_click);

    button_t *button_cancel = create_button(game->font, "Resume",
        (sfVector2f){ 885, 570 }, handle_cancel_click);
    button_t *button_dex = create_button(game->font, "Pokedex",
        (sfVector2f){ 875, 670 }, handle_dex_click);

    button_t **head = &game->pause->buttons;
    register_button(head, button_back);
    register_button(head, button_cancel);
    register_button(head, button_dex);
}
