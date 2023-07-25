/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-jean-jacques.delegue
** File description:
** my_strchr
*/
#include "my.h"
#include <stddef.h>

char *my_strchr(const char *str, int c)
{
    while (*str != '\0' && *str != c)
        str++;
    if (*str == c)
        return (char*) str;
    else
        return NULL;
}
