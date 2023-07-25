/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** rain
*/

#include "rain.h"
#include "game.h"

rain_t *create_rain(int nb)
{
    rain_t *rain = malloc(sizeof(rain_t));
    rain->nb = nb;
    rain->rain = malloc(sizeof(particle_t) * (nb + 1));
    return rain;
}

void init_rain(rain_t *rain)
{
    for (int i = 0; i < rain->nb; i++) {
        rain->rain[i].position.x = rand() % 800;
        rain->rain[i].position.y = -50 - rand() % 500;
        rain->rain[i].color = sfColor_fromRGB(0, 0, 255);
        rain->rain[i].speed = 1;
    }
}

void move_rain(rain_t *rain, int height, int width)
{
    for (int i = 0; i < 200; i++) {
        rain->rain[i].position.y += rain->rain[i].speed;
        if (rain->rain[i].position.y > height) {
            rain->rain[i].position.y = -50 - rand() % 500;
            rain->rain[i].position.x = rand() % width;
        }
    }
}

void show_rain(rain_t *rain, sfRenderWindow *window)
{
    for (int i = 0; i < rain->nb; i++) {
        sfRectangleShape* particle = sfRectangleShape_create();
        sfVector2f size = {2, 10};
        sfRectangleShape_setSize(particle, size);
        sfRectangleShape_setFillColor(particle, rain->rain[i].color);
        sfRectangleShape_setPosition(particle, rain->rain[i].position);
        sfRenderWindow_drawRectangleShape(window, particle, NULL);
        sfRectangleShape_destroy(particle);
    }
}
