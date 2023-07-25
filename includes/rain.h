/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** rain
*/

#ifndef RAIN_H_
    #define RAIN_H_
    #include <SFML/Graphics.h>

    typedef struct particle_s {
        sfVector2f position;
        sfColor color;
        float speed;
    } particle_t;

    typedef struct rain_s {
        particle_t *rain;
        int nb;
    } rain_t;

    rain_t *create_rain(int nb);
    void init_rain(rain_t *rain);
    void move_rain(rain_t *rain, int height, int width);
    void show_rain(rain_t *rain, sfRenderWindow *window);

#endif /* !RAIN_H_ */
