/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** render
*/

#include <SFML/Graphics.h>
#include "game.h"

static void render_dialog_asking(game_t *game)
{
    sfVector2f pos =
        (sfVector2f){ game->player->x * 32 - 43, game->player->y * 32 + 120 };

    sfText_setPosition(game->dialog->ask_text, pos);
    sfRenderWindow_drawText(game->window, game->dialog->ask_text, NULL);
}

static void render_dialog_message(game_t *game, sfVector2f pos, int i)
{
    sfText_setString(game->dialog->text, game->dialog->message[i]);

    sfText_setPosition(game->dialog->text,
        (sfVector2f){ pos.x + 20, pos.y + 30 + (20 * i) });
    sfRenderWindow_drawText(game->window,
        game->dialog->text, NULL);
}

void render_dialog(void *game_ptr)
{
    game_t *game = game_ptr;

    if (game->dialog->is_asking == sfTrue) {
        render_dialog_asking(game);
    } else if (game->dialog->is_visible == sfTrue) {
        sfVector2f pos =
            (sfVector2f){ game->player->x * 32 - 135,
            game->player->y * 32 + 100 };
        sfSprite_setPosition(game->dialog->background->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
            game->dialog->background->sprite, NULL);

        for (int i = 0; game->dialog->message[i] != NULL; i++) {
            render_dialog_message(game, pos, i);
        }
    }
}
