/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** check all errors possible
*/

#include "my.h"
#include "bsq.h"

char *last_check(char *buf)
{
    int counter = count_line(buf, '\n');
    int i = 0;

    for (; buf[i] != '\n'; i++);
    i += 1;
    for (int tmp = 0; buf[i] != '\0'; i++) {
        if (buf[i] != '\n')
            tmp++;
        if (buf[i] == '\n') {
            if (tmp != counter)
                return ("NTM\0");
            tmp = 0;
        }
    }
    return (buf);
}

int take_number(char *buf)
{
    char *cpy = NULL;
    int i = 0;

    for (; buf[i] != '\n'; i++);
    cpy = malloc(sizeof(char) * i + 1);
    for (int j = 0; j < i; j++)
        cpy[j] = buf[j];
    cpy[i] = '\0';
    return (my_getnbr(cpy));
}

int check_chars(char *buf)
{
    int i = 0;

    for (;buf[i] != '\n'; i++);
    i++;
    for (; buf[i] != '\0'; i++) {
        if (buf[i] != '.' && buf[i] != 'o' && buf[i] != '\n')
            return (-1);
    }
    return (0);
}

char *check_buffer(char *buf)
{
    int i = 0;
    int stock = take_number(buf);

    if (stock != count_col(buf, '\n'))
        return ("NTM\0");
    if (check_chars(buf) == -1)
        return ("NTM\0");
    else
        return (last_check(buf));
}
