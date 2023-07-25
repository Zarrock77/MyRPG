/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_strpbrk
*/
#include "my.h"
#include <stddef.h>

char *loopbrk(const char *ptr1, const char* ptr2)
{
    while (*ptr2) {
        if (*ptr1 == *ptr2)
            return (char*)ptr1;
        ptr2++;
    }
    return NULL;
}

char *my_strpbrk(const char* str1, const char* str2)
{
    const char* ptr1 = str1;
    const char* ptr2;

    while (*ptr1) {
        ptr2 = str2;
        if (loopbrk(ptr1, ptr2) != NULL)
            return loopbrk(ptr1, ptr2);
        ptr1++;
    }
    return NULL;
}
