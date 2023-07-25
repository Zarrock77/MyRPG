/*
** EPITECH PROJECT, 2023
** MYRPG
** File description:
** fullscreen_loader
*/

#ifndef FULLSCREEN_LOADER_H_

    #define FULLSCREEN_LOADER_H_

    #include <SFML/Graphics.h>

    typedef struct LoadingData {
        sfRenderWindow* window;
        sfRectangleShape* loading_bar_bg;
        sfRectangleShape* loading_bar;
        sfText* text;
        sfClock* clock;
    } LoadingData;

    //create_loader.c

    sfText* create_loading_text(const char* loading_text, sfFont* font,
    sfRenderWindow* window, sfRectangleShape* loading_bar);
    sfRectangleShape* create_loading_bar(sfRenderWindow* window);
    sfRectangleShape* create_loading_bar_bg(sfRenderWindow* window);
    void load_data_for_loader(LoadingData *data,
    const char* loading_text, sfFont *font);

    //update_loader.c

    void draw_loading_screen(LoadingData* data);
    void update_progress(LoadingData* data,
    float* progress, float progress_step);
    void handle_events_loading(sfRenderWindow* window);
    void check_loader_end(game_t *game, LoadingData *data, float progress);

    //destroy_loader.c

    void destroy_loader(LoadingData data, sfFont *font);

    //resize_view.c

    void create_resized_view(game_t *game);

#endif /* !FULLSCREEN_LOADER_H_ */
