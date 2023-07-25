/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** menu
*/

#include "game.h"
#include "engine/button.h"
#include "events.h"

void create_menu(void *game_ptr)
{
    game_t *game = game_ptr;
    game->menu = malloc(sizeof(menu_t));
    game->menu->buttons = NULL;
    game->menu->is_visible = sfFalse;
    game->menu->background = create_image("assets/Sprites/background.png",
        (sfVector2f){ 0, 0 }, game->window);
    sfSprite_setScale(game->menu->background->sprite, (sfVector2f){ 2, 2 });
    button_t *button_play = create_button(game->font, "Play now",
        (sfVector2f){ 880, 470 }, handle_play_click);
    button_t *button_quit = create_button(game->font, "Quit game",
        (sfVector2f){ 873, 580 }, handle_quit_click);
    button_t *button_credit = create_button(game->font, "Options",
        (sfVector2f){ 887, 685 }, handle_options_click);
    button_t **head = &game->menu->buttons;
    register_button(head, button_play);
    register_button(head, button_quit);
    register_button(head, button_credit);
}
