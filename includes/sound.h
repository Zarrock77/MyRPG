/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** sound
*/

#ifndef SOUND_H_
    #define SOUND_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    typedef struct VolumeSlider {
        sfRectangleShape* volumeBar;
        sfCircleShape* sliderButton;
        sfMusic* music;
        int isDragging;
    } VolumeSlider;


#endif /* !SOUND_H_ */
