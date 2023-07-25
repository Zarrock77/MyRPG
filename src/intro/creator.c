/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** creator
*/

#include "intro.h"
#include "game.h"

void center_rect_in_screen(sfRenderWindow *window, sfIntRect *rect)
{
    int screen_width = sfRenderWindow_getSize(window).x;
    int screen_height = sfRenderWindow_getSize(window).y;
    int rect_width = rect->width;
    int rect_height = rect->height;

    int x = (screen_width - rect_width) / 2;
    int y = (screen_height - rect_height) / 2;

    rect->left = x;
    rect->top = y;
}

void create_intro(void *game_ptr)
{
    game_t *game = game_ptr;
    intro_t *intro = malloc(sizeof(intro_t));
    image_t *img = create_image("assets/Sprites/intro.png",
        (sfVector2f){255, 100}, game->window);
    img->clock = sfClock_create();
    img->rect.top = 0;
    img->rect.height = 368;
    img->rect.left = 0;
    img->rect.width = 480;
    sfSprite_setTextureRect(img->sprite, img->rect);
    img->scale_rect = get_scale_rect(img->rect, game->window);
    img->round_scale_rect = get_round_scale(img->scale_rect);
    sfSprite_setScale(img->sprite,
        (sfVector2f) {img->round_scale_rect, img->round_scale_rect});
    intro->img = img;
    intro->nb = 0;
    game->intro = intro;
}

void move_rect_intro(intro_t *intro, int offset, int max_value)
{
    intro->img->rect.left = intro->img->rect.left + offset;
    if (intro->img->rect.left == max_value) {
        intro->nb++;
        intro->img->rect.top += 368;
        intro->img->rect.left = 0;
    }
    sfSprite_setTextureRect(intro->img->sprite, intro->img->rect);
}

void clock_move_intro(intro_t *intro)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(intro->img->clock)) > 50) {
        move_rect_intro(intro, 480, 7200);
        sfClock_restart(intro->img->clock);
    }
}
