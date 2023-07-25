/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** open_and_read
*/

#include "map.h"
#include "my.h"
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char **get_map(void)
{
    struct stat mk;
    int ouvert = open("assets/Maps/map.txt", O_RDONLY);
    char *buffer;
    char **buf = NULL;

    if (ouvert < 0 || stat("assets/Maps/map.txt", &mk) == -1)
        return NULL;
    buffer = malloc((sizeof(char)) * (mk.st_size + 1));
    *buffer = (char) {0};
    if (buffer == NULL) {
        return NULL;
    }
    if (read(ouvert, buffer, mk.st_size) < (mk.st_size == 0)) {
        return NULL;
    }
    buffer[mk.st_size] = '\0';
    buf = my_str_to_word_array(buffer, "\n");
    free(buffer);
    close(ouvert);
    return buf;
}
