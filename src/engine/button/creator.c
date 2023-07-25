/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** button
*/

#include "engine/button.h"

static sfRectangleShape *create_background(sfText *text, sfVector2f position)
{
    sfRectangleShape *background = sfRectangleShape_create();
    sfFloatRect bounds = sfText_getGlobalBounds(text);

    sfRectangleShape_setSize(background,
        (sfVector2f){ .x = bounds.width + 50, .y = 70 });

    sfRectangleShape_setOutlineThickness(background, 2.f);
    sfRectangleShape_setOutlineColor(background, sfWhite);
    sfRectangleShape_setFillColor(background, sfTransparent);
    sfRectangleShape_setPosition(background, position);

    return background;
}

static sfText *create_text(sfFont *font, char *text_string,
    sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setString(text, text_string);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text,
        (sfVector2f){ .x = pos.x + 27, .y = pos.y + 37 });
    sfText_setFillColor(text, sfWhite);

    return text;
}

button_t *create_button(sfFont *font, char *text_string, sfVector2f position,
    void (*handle_click)(void *))
{
    button_t *button = malloc(sizeof(button_t));

    button->is_visible = sfTrue;
    button->is_hovered = sfFalse;

    button->text = create_text(font, text_string, position);
    button->background = create_background(button->text, position);
    button->handle_click = handle_click;

    button->next = NULL;
    return button;
}
