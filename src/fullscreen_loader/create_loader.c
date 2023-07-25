/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** create_loader
*/

#include "game.h"
#include "fullscreen_loader.h"

sfRectangleShape* create_loading_bar_bg(sfRenderWindow* window)
{
    sfRectangleShape* loading_bar_bg = sfRectangleShape_create();
    sfVector2f loading_bar_size = {400, 25};
    sfRectangleShape_setSize(loading_bar_bg, loading_bar_size);
    sfVector2f loading_bar_pos = {
        (sfRenderWindow_getSize(window).x - loading_bar_size.x) / 2,
        (sfRenderWindow_getSize(window).y - loading_bar_size.y) / 2
    };
    sfRectangleShape_setPosition(loading_bar_bg, loading_bar_pos);
    sfRectangleShape_setFillColor(loading_bar_bg, sfTransparent);
    sfRectangleShape_setOutlineColor(loading_bar_bg,
    sfColor_fromRGB(200, 200, 200));
    sfRectangleShape_setOutlineThickness(loading_bar_bg, 2);

    return loading_bar_bg;
}

sfRectangleShape* create_loading_bar(sfRenderWindow* window)
{
    sfRectangleShape* loading_bar = sfRectangleShape_create();
    sfVector2f loading_bar_size = {400, 25};
    sfRectangleShape_setSize(loading_bar, loading_bar_size);
    sfVector2f loading_bar_pos = {
        (sfRenderWindow_getSize(window).x - loading_bar_size.x) / 2,
        (sfRenderWindow_getSize(window).y - loading_bar_size.y) / 2
    };
    sfRectangleShape_setPosition(loading_bar, loading_bar_pos);
    sfRectangleShape_setFillColor(loading_bar, sfWhite);

    return loading_bar;
}

sfText* create_loading_text(const char* loading_text, sfFont* font,
sfRenderWindow* window, sfRectangleShape* loading_bar)
{
    sfText* text = sfText_create();
    sfText_setString(text, loading_text);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfFloatRect text_bounds = sfText_getGlobalBounds(text);
    sfVector2f loading_bar_pos = sfRectangleShape_getPosition(loading_bar);
    sfVector2f loading_bar_size = sfRectangleShape_getSize(loading_bar);
    sfVector2f text_pos = {
        (sfRenderWindow_getSize(window).x - text_bounds.width) / 2,
        loading_bar_pos.y + loading_bar_size.y + 10
    };
    sfText_setPosition(text, text_pos);

    return text;
}

void load_data_for_loader(LoadingData *data,
const char* loading_text, sfFont *font)
{
    data->window = sfRenderWindow_create(
        sfVideoMode_getDesktopMode(), "Loading...", sfNone, NULL);
    data->loading_bar_bg = create_loading_bar_bg(data->window);
    data->loading_bar = create_loading_bar(data->window);
    data->text = create_loading_text(loading_text, font,
        data->window, data->loading_bar);
    data->clock = sfClock_create();
}
