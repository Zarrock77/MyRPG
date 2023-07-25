/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    char **my_str_to_word_array(char *str, char *lim);
    char *my_strchr(const char *str, int c);
    char *my_strdup(char const *src);
    int my_strlen(char const *str);
    char *my_strpbrk(const char* str1, const char* str2);
    int my_strspn(const char* str1, const char* str2);
    char *my_strtok(char *str, const char *delim);
    char *my_strcpy(char *dest, char const *src);
    char *my_itoa(int number);

#endif /* !MY_H_ */
