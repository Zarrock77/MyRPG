/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_strcat
*/

char *my_strcat(const char *s1, const char *s2)
{
    size_t len_s1 = my_strlen(s1);
    size_t len_s2 = my_strlen(s2);

    char *result = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));

    if (result == NULL) {
        return NULL;
    }

    my_strcpy(result, s1);
    my_strcpy(result + len_s1, s2);
    return result;
}
