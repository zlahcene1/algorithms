/*
** EPITECH PROJECT, 2020
** bssq
** File description:
** cahr ** to int **
*/

#include "my.h"
#include "bsq.h"

int **int_array(char *buf, int col, int line)
{
    int **tab = malloc(sizeof(int *) * col + 1);
    int x = 0;
    int y = 0;
    int indice = 0;

    for (; buf[indice] != '\n'; indice++);
    indice++;
    for (; x != col; x++) {
        tab[x] = malloc(sizeof(int) * line + 1);
        for (y = 0; buf[indice] != '\n'; y++, indice++) {
            if (buf[indice] == 'o')
                tab[x][y] = 0;
            if (buf[indice] == '.')
                tab[x][y] = 1;
        }
        indice += 1;
    }
    return (tab);
}
