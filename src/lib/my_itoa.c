/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_itoa
*/

#include <stdlib.h>

static int get_number_len(int number)
{
    int length = 0;
    while (number != 0) {
        number /= 10;
        length++;
    }
    return length;
}

char *my_itoa(int number)
{
    int length = get_number_len(number);

    char *str = (char *)malloc((length + 1) * sizeof(char));

    if (str == NULL) {
        return NULL;
    }
    int i = length - 1;

    while (number != 0) {
        str[i--] = '0' + (number % 10);
        number /= 10;
    }
    str[length] = '\0';
    return str;
}
