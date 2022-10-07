/*
** EPITECH PROJECT, 2020
** algbox
** File description:
** just for percent
*/

#include "my.h"
#include "bsq.h"

int smallest(int nb1, int nb2, int nb3)
{
    if (nb1 <= nb2 && nb1 <= nb3)
        return (nb1);
    if (nb2 <= nb1 && nb2 <= nb3)
        return (nb2);
    return (nb3);
}

int **algobox(int **array, char *buf)
{
    int col = count_line(buf, '\n');
    int line = count_col(buf, '\n');

    for (int x = 1; x != line; x++) {
        for (int y = 1; y != col; y++) {
            if (array[x][y] == 0) {
                array[x][y] = 0;
                continue;
            }
            else if (left >= 1 && top >= 1 && diag >= 1)
                array[x][y] += smallest(left, top, diag);
        }
    }
    return (array);
}
