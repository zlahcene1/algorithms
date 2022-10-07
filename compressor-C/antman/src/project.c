/*
** EPITECH PROJECT, 2021
** am
** File description:
** am
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

void mini_algo(char *str)
{
    char *string = malloc(sizeof(char) * my_strlen(str) / 2);
    int j = 0;
    char n;

    for (int i = 0; i < my_strlen(str); i += 2) {
        n = ((str[i] - '0') * 10 + (str[i + 1] - '0')) + 33;
        string[j] = n + '0';
        j++;
    }
}
