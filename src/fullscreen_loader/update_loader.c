/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** update_loader
*/

#include "game.h"
#include "fullscreen_loader.h"

void handle_events_loading(sfRenderWindow* window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

void update_progress(LoadingData* data, float* progress, float progress_step)
{
    sfTime elapsed_time = sfClock_restart(data->clock);
    *progress += progress_step;
    sfVector2f loading_bar_size_current = {400 * *progress, 25};
    sfRectangleShape_setSize(data->loading_bar, loading_bar_size_current);
}

void draw_loading_screen(LoadingData* data)
{
    sfRenderWindow_clear(data->window, sfBlack);
    sfRenderWindow_drawRectangleShape(data->window, data->loading_bar_bg, NULL);
    sfRenderWindow_drawRectangleShape(data->window, data->loading_bar, NULL);
    sfRenderWindow_drawText(data->window, data->text, NULL);
}

void check_loader_end(game_t *game, LoadingData *data, float progress)
{
    if (progress >= 1.0f) {
        game->window = sfRenderWindow_create(
            sfVideoMode_getDesktopMode(), "Pokemon Amethyst",
            sfTitlebar | sfClose | sfFullscreen, NULL);
        sfRenderWindow_close(data->window);
    }
}
