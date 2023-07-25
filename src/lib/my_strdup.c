/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-myls-jean-jacques.delegue
** File description:
** my_strdup
*/
#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest = my_strcpy(dest, src);
    return dest;
}
