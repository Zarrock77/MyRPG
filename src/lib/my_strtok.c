/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_strtok
*/
#include "my.h"
#include <stddef.h>

char *my_strtok(char *str, const char *delim)
{
    static char *last = NULL;
    char *token = NULL;
    if (str == NULL)
        str = last;
    if (*str == '\0') {
        return NULL;
    }
    str += my_strspn(str, delim);
    if (*str == '\0')
        return NULL;
    token = str;
    str = my_strpbrk(token, delim);
    if (str != NULL) {
        *str = '\0';
        last = str + 1;
    } else {
        last = token + my_strlen(token);
    }
    return token;
}
