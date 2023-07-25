/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include "engine/image.h"
    #include "scene.h"
    #include "map.h"

    typedef struct player_s {
        image_t *img;
        sfVector2f position;
        sfClock *clock;
        sfVector2f last;
        sfVector2f direction;
        sfBool in_mouv;
        sfBool in_fight;
        int x;
        int y;
    } player_t;

    void create_player(void *game_ptr);
    void my_fonction_move_up(void *game_ptr, sfKeyCode code);
    void my_fonction_move_down(void *game_ptr, sfKeyCode code);
    void my_fonction_move_right(void *game_ptr, sfKeyCode code);
    void my_fonction_move_left(void *game_ptr, sfKeyCode code);
    void move_player(void *game_ptr, sfEvent event);
    void move_rect_player(sfSprite *sprite, sfIntRect *rect,
        int offset, int max_value);
    void clock_move_player(player_t *player);
    void render_player(void *game_ptr);
    void destroy_player(player_t *player);
    int check_collision_up(player_t *player, map_t *map);
    void random_encounter(char c, void *game_ptr);
    void render_png(sfRenderWindow *window, image_t *png);

#endif /* !PLAYER_H_ */
