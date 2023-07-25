/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_
    #include <SFML/Graphics.h>
    #include "engine/image.h"

    typedef struct map_s {
        image_t *c1;
        image_t *c2;
        sfBool is_visible;
        char **arr;

    } map_t;

    sfView *create_view(sfRenderWindow *window, float scale, sfVector2f pos);
    void create_map(void *game_ptr);
    void render_c1(sfRenderWindow *window, map_t *map);
    void render_c2(sfRenderWindow *window, map_t *map);
    void destroy_map(map_t *map);

    char **get_map(void);

#endif /* !MAP_H_ */
