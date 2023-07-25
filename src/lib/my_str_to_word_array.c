/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-antman-jean-jacques.delegue
** File description:
** my_str_to_word_array
*/
#include "my.h"
#include <stdlib.h>

int skip_delimiters(char *str, int i, char *lim)
{
    while (str[i] != '\0' && (my_strchr(lim, str[i])))
        i++;
    return i;
}

int skip_word(char *str, int i, char *lim)
{
    while (str[i] != '\0' && !my_strchr(lim, str[i]))
        i++;
    return i;
}

int count_word(char *str, char *lim)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        i = skip_delimiters(str, i, lim);
        if (str[i] != '\0') {
            count++;
            i = skip_word(str, i, lim);
        }
    }
    return count;
}

char **my_str_to_word_array(char *str, char *lim)
{
    int nb_word = count_word(str, lim);
    char **arr = malloc(sizeof(char *) * (nb_word + 1));
    char *dup = my_strdup(str);
    char *token = my_strtok(dup, lim);
    for (int i = 0; token != NULL; i++) {
        arr[i] = my_strdup(token);
        token = my_strtok(NULL, lim);
    }
    free(dup);
    arr[nb_word] = NULL;
    return arr;
}
