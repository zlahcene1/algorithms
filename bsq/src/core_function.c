/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** core function
*/

#include "my.h"
#include "bsq.h"

void core_function(char *buf)
{
    int col = count_col(buf, '\n');
    int line = count_line(buf, '\n');
    int **array = int_array(buf, col, line);
    char **tab = str_array(buf, '\n');

    print(translator(algobox(array, buf), buf, tab), line, col);
}
