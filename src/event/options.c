/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** Options button on click event handling
*/

#include "game.h"
#include "fullscreen_loader.h"

void load_fullscreen(game_t* game, const char* loading_text)
{
    sfFont* font = sfFont_createFromFile("./assets/minecraftia-regular.ttf");
    LoadingData data;
    load_data_for_loader(&data, loading_text, font);
    float progress = 0;
    float progress_step = 0.0005f;

    sfRenderWindow_destroy(game->window);
    while (sfRenderWindow_isOpen(data.window) && progress < 1.0f) {
        handle_events_loading(data.window);
        update_progress(&data, &progress, progress_step);
        draw_loading_screen(&data);
        check_loader_end(game, &data, progress);
        sfRenderWindow_display(data.window);
    }
    destroy_loader(data, font);
    float scale_x = 1920 / game->map->c1->texture_width;
    float scale_y = 1080 / game->map->c1->texture_height;
    game->map->c1->round_scale = (scale_x < scale_y) ? scale_x : scale_y;
    game->map->c2->round_scale = (scale_x < scale_y) ? scale_x : scale_y;
    create_resized_view(game);
}

void handle_fullscreen_click(void* game_ptr)
{
    game_t *game = game_ptr;

    load_fullscreen(game, "Loading fullscreen...");
}

void handle_options_click(void *game_ptr)
{
    game_t *game = game_ptr;

    game->menu->is_visible = sfFalse;
    game->options->is_visible = sfTrue;
}

void handle_fullsize_click(void *game_ptr)
{
    game_t *game = game_ptr;
    sfVideoMode desktop_mode = sfVideoMode_getDesktopMode();
    sfVector2u window_size = sfRenderWindow_getSize(game->window);
    float scale_x = 1920 / game->map->c1->texture_width;
    float scale_y = 1080 / game->map->c1->texture_height;
    game->map->c1->round_scale = (scale_x < scale_y) ? scale_x : scale_y;
    game->map->c2->round_scale = (scale_x < scale_y) ? scale_x : scale_y;

    if (window_size.x == desktop_mode.width &&
        window_size.y == desktop_mode.height) {
        sfRenderWindow_destroy(game->window);
        game->window = sfRenderWindow_create(
            game->mode, "Pokemon Amethyst",
            sfTitlebar | sfClose | sfNone , NULL);
        sfRenderWindow_setSize(game->window, (sfVector2u){1920, 1080});
    } else {
        sfRenderWindow_setSize(game->window, (sfVector2u){1920, 1080});
    }
    create_resized_view(game);
}

void handle_smallsize_click(void *game_ptr)
{
    game_t *game = game_ptr;
    sfVideoMode desktop_mode = sfVideoMode_getDesktopMode();
    sfVector2u window_size = sfRenderWindow_getSize(game->window);
    float scale_x = 800 / game->map->c1->texture_width;
    float scale_y = 600 / game->map->c1->texture_height;
    game->map->c1->round_scale = (scale_x < scale_y) ? scale_x : scale_y;
    game->map->c2->round_scale = (scale_x < scale_y) ? scale_x : scale_y;

    if (window_size.x == desktop_mode.width &&
        window_size.y == desktop_mode.height) {
        sfRenderWindow_destroy(game->window);
        game->window = sfRenderWindow_create(
            game->mode, "Pokemon Amethyst",
            sfTitlebar | sfClose | sfNone , NULL);
        sfRenderWindow_setSize(game->window, (sfVector2u){800, 600});
    } else {
        sfRenderWindow_setSize(game->window, (sfVector2u){800, 600});
    }
    create_resized_view(game);
}
