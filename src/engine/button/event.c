/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** button event
*/

#include "engine/button.h"
#include "game.h"

int on_hover(float x, float y, void *game_ptr, button_t *button)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->background);

    if (sfFloatRect_contains(&bounds, x, y)) {
        sfRectangleShape_setFillColor(button->background,
        sfColor_fromRGBA(255, 255, 255, 100));
    } else {
        sfRectangleShape_setFillColor(button->background,
        sfColor_fromRGBA(0, 0, 0, 0));
    }
    return 0;
}

int on_click(float x, float y, void *game_ptr, button_t *button)
{
    game_t *game = game_ptr;
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->background);

    if (sfFloatRect_contains(&bounds, x, y)) {
        button->handle_click(game);
        return 1;
    }

    return 0;
}

void handle_button_event(
    int (*handle_event)(float, float, void *, button_t *button),
    void *game_ptr, sfVector2f mouse, button_t *buttons)
{
    button_t *temp = buttons;
    game_t *game = game_ptr;
    sfVector2u windowSize = sfRenderWindow_getSize(game->window);
    float mouseX = mouse.x * (1920.f / windowSize.x);
    float mouseY = mouse.y * (1080.f / windowSize.y);

    while (temp != NULL) {
        if (handle_event(mouseX, mouseY, game_ptr, temp)) {
            return;
        }
        temp = temp->next;
    }
}
