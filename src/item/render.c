/*
** EPITECH PROJECT, 2023
** my_rpg1
** File description:
** render
*/

#include "game.h"
#include "item.h"

static void render_item(game_t *game, item_t *item, int *prev_y,
    sfVector2f *pos)
{
    int width = sfRenderWindow_getSize(game->window).x == 1920 ? 335 : 150;
    int height = sfRenderWindow_getSize(game->window).y == 1080 ? 237 : 187;

    sfText_setPosition(item->text,
        (sfVector2f){ pos->x + width, (pos->y - height) + *prev_y });
    sfText_setString(item->text, item->name);

    sfRenderWindow_drawText(game->window, item->text, NULL);
    *prev_y += 21;
}

static void render_option(game_t *game, sfText *text, sfVector2f position)
{
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(game->window, text, NULL);
}

static void render_item_icon(game_t *game, sfVector2f map_pos)
{
    item_types_t selected = game->inventory->selected;

    int width = sfRenderWindow_getSize(game->window).x == 1920 ? 323 : 140;
    int height = sfRenderWindow_getSize(game->window).y == 1080 ? 235 : 187;

    render_option(game, game->inventory->selector_option,
        (sfVector2f){ map_pos.x + width, map_pos.y - height +
            ((selected + 1) * 21) });

    item_t *selected_item = &game->inventory->items[selected];

    if (game->inventory->selected > -1) {
        sfSprite_setPosition(selected_item->icon->sprite,
            (sfVector2f){ map_pos.x + (width == 323 ? 218 : 32),
                map_pos.y - (height == 235 ? 98 : 48) });
        sfRenderWindow_drawSprite(game->window,
            selected_item->icon->sprite, NULL);
    }
}

void render_items(void *game_ptr)
{
    game_t *game = game_ptr;

    sfVector2f map_pos =
        (sfVector2f){ game->player->x * 32, game->player->y * 32 };
    item_t *items = game->inventory->items;

    int width = sfRenderWindow_getSize(game->window).x == 1920 ? 335 : 150;
    int height = sfRenderWindow_getSize(game->window).y == 1080 ? 237 : 187;

    render_option(game, game->inventory->cancel_option,
        (sfVector2f){ map_pos.x + width,
            map_pos.y - height });
    render_item_icon(game, map_pos);

    int prev_y = 21;
    for (int i = 0; i < ITEMS_NUMBER; i++) {
        render_item(game, &items[i], &prev_y, &map_pos);
    }
}
