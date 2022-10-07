/*
** EPITECH PROJECT, 2020
** skj
** File description:
** fgd
*/

#include <stddef.h>

char *my_strcpy_n(char *dest, char const *src, int n)
{
    int i = 0;

    for (i, n; src[i] != '\0'; i++, n++) {
        dest[i] = src[n];
    }
    dest[i] = '\0';
    return (dest);
}

int search(char *str, char const *to_find, int j)
{
    for (int i = 0; to_find[i] != '\0'; i++, j++) {
        if (str[j] != to_find[i])
            return (-1);
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int tmp = 0;

    for (int i = 0; str[i] != '\0';i++) {
        if (str[i] == to_find[0]) {
            tmp = search(str, to_find, i);
            if (tmp == 0) {
                return (my_strcpy_n(str, str, i));
            }
        }
    }
    return (NULL);
}
