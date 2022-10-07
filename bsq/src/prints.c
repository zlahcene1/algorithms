/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** all prints
*/

#include "my.h"
#include "bsq.h"
#include "struct_coord.h"

struct c init_struct(void)
{
    struct c c;

    c.x = 0;
    c.y = 0;
    c.stock = 0;
    return (c);
}

struct c scanner(char *buf, int **array)
{
    struct c my_struct = init_struct();
    int i = 0;

    for (; buf[i] != '\n'; i++);
    i++;
    for (int x = 0; buf[i] != '\0'; x++, i++) {
        for (int y = 0; buf[i] != '\n'; i++, y++) {
            if (array[x][y] > my_struct.stock) {
                my_struct.stock = array[x][y];
                my_struct.x = x;
                my_struct.y = y;
            }
        }
    }
    return (my_struct);
}

char **translator(int **array, char *buf, char **tab)
{
    struct c c = scanner(buf, array);

    for (int x = c.stock; x > 0; x--, c.x--) {
        for (int y = c.y; y != (c.y - c.stock); y--) {
            tab[c.x][y] = 'x';
        }
    }
    free(array);
    free(buf);
    return (tab);
}

void print(char **tab, int line, int col)
{
    for (int x = 0; x < col; x++) {
        write(1, tab[x], line);
        my_putchar('\n');
    }
    free(tab);
}
