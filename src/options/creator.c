/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** options creator
*/

#include "game.h"
#include "options.h"
#include "engine/button.h"
#include "events.h"

static void create_buttons(game_t *game)
{
    sfVector2u windowSize = sfRenderWindow_getSize(game->window);

    button_t *button_back = create_button(game->font, "< Back",
        (sfVector2f){40, 40}, handle_back_click);
    button_t *fullscreen = create_button(game->font, "Fullscreen",
        (sfVector2f){windowSize.x * 0.25f, windowSize.y * 0.45f },
        handle_fullscreen_click);
    button_t *fullsize = create_button(game->font, "1920x1080",
        (sfVector2f){ windowSize.x * 0.45f, windowSize.y * 0.45f },
        handle_fullsize_click);
    button_t *smallsize = create_button(game->font, "800x600",
        (sfVector2f){ windowSize.x * 0.65f, windowSize.y * 0.45f },
        handle_smallsize_click);

    button_t **head = &game->options->buttons;

    register_button(head, button_back);
    register_button(head, fullscreen);
    register_button(head, fullsize);
    register_button(head, smallsize);
}

static void create_option_title(game_t *game)
{
    sfVector2u window_size = sfRenderWindow_getSize(game->window);
    game->options->title = sfText_create();

    sfText_setFont(game->options->title, game->font);
    sfText_setCharacterSize(game->options->title, 30);
    sfText_setFillColor(game->options->title, sfWhite);
    sfText_setString(game->options->title, "- Options -");
    sfText_setPosition(game->options->title,
        (sfVector2f){ window_size.x * 0.455f, window_size.y * 0.14f });
}

void create_options(void *game_ptr)
{
    game_t *game = game_ptr;
    game->options = malloc(sizeof(options_t));
    game->options->buttons = NULL;
    game->options->is_visible = sfFalse;

    create_option_title(game);

    create_buttons(game);
}
