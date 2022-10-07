/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** str to word array boosted
*/

#include "my.h"
#include "bsq.h"

int count_line(char *buf, char c)
{
    int i = 0;
    int count = 0;

    for (;buf[i] != c; i += 1);
    i += 1;
    for (; buf[i] != c; i += 1)
        count += 1;
    return (count);
}

int count_col(char *buf, char c)
{
    int count = 0;
    int i = 0;

    for (; buf[i] != '\n'; i += 1);
    i += 1;
    for (; buf[i] != '\0'; i++) {
        if (buf[i] == c)
            count += 1;
    }
    return (count);
}

char **str_array(char *buf, char c)
{
    int l = 0;
    int j = 0;
    int col = count_col(buf, c);
    int line = count_line(buf, c);
    char **tab = malloc(sizeof(char *) * col + 1);

    for (; buf[l] != '\n'; l++);
    l += 1;
    for (int i = 0; i < col; i += 1) {
        j = 0;
        tab[i] = malloc(sizeof(char) + line + 1);
        for (j, l;j < line; j += 1, l += 1) {
            tab[i][j] = buf[l];
        }
        l += 1;
        tab[i][j] = '\n';
        tab[i][j + 1] = '\0';
    }
    return (tab);
}
