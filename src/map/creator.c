/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** map
*/

#include "map.h"
#include "game.h"

sfView *create_view(sfRenderWindow *window, float scale, sfVector2f pos)
{
    float width = sfRenderWindow_getSize(window).x;
    float height = sfRenderWindow_getSize(window).y;
    sfFloatRect rectangle = {0.f, 0.f, width / scale, height / scale};
    sfView* view = sfView_createFromRect(rectangle);
    sfView_setCenter(view, pos);
    float ratio = width / height / scale;
    sfView_zoom(view, 1.0f / ratio);
    return view;
}

static void boucle(char **map, game_t *game)
{
    int j = 0;

    for (int i = 0; map[i]; j++) {
        if (map[i][j] == 'R') {
            game->professeur->x = j;
            game->professeur->y = i;
            map[i][j] = '#';
        }
        if (map[i][j++] == '\0') {
            j = 0;
            i++;
        }
    }
}

static void init_prof(game_t *game)
{
    game->professeur =
    create_image("assets/pnj_spritesheet/professeur_chen.png",
    (sfVector2f){85 * 32 + 16, 114 * 32}, game->window);
    game->professeur->rect.top = 32;
    game->professeur->rect.left = 64;
    game->professeur->rect.height = 32;
    game->professeur->rect.width = 96;
    sfSprite_setTextureRect(game->professeur->sprite, game->professeur->rect);
    sfSprite_scale(game->professeur->sprite, (sfVector2f){ 2, 2});
}

void create_map(void *game_ptr)
{
    game_t *game = game_ptr;
    map_t *new = malloc(sizeof(map_t));
    game->professeur = malloc(sizeof(image_t));
    new->c1 =
    create_image("assets/Maps/c1.jpg",(sfVector2f){0, 0}, game->window);
    new->c2 =
    create_image("assets/Maps/c2.png", (sfVector2f){0, 0}, game->window);
    new->arr = get_map();
    init_prof(game);
    new->c1->view = create_view(game->window, new->c1->round_scale,
        (sfVector2f){game->player->x * 32 + 16, game->player->y * 32});
    new->c2->view = create_view(game->window, new->c2->round_scale,
        (sfVector2f){game->player->x * 32 + 16, game->player->y * 32});
    new->is_visible = sfFalse;
    game->map = new;
}
