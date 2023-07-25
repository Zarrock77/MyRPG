/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_strspn
*/
#include "my.h"

int loop(const char *str1, const char *str2, int count, int i)
{
    int len2 = my_strlen(str2);
    int flag = 0;
    for (int j = 0; j < len2; j++) {
        if (str1[i] == str2[j]) {
            count++;
            flag = 1;
            break;
        }
    }
    return flag;
}

int my_strspn(const char* str1, const char* str2)
{
    int len1 = my_strlen(str1);
    int count = 0;

    for (int i = 0; i < len1; i++) {
        int flag = 0;
        flag = loop(str1, str2, count, i);
        if (!flag)
            break;
    }
    return count;
}
