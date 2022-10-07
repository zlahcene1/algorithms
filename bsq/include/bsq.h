/*
** EPITECH PROJECT, 2020
** headerz
** File description:
** bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

/************** INCLUDES ********************/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*************** MACROS *********************/

#define left array[x][y - 1]
#define diag array[x - 1][y - 1]
#define top array[x - 1][y]

/************** PRINTS ********************/

char **fill_square(int **array, char *buf, char **map);
char **translator(int **array, char *buf, char **tab);
void print(char **tab, int line, int col);

/************** FUNCTIONS *****************/

void core_function(char *buf);

char *open_file(char *str);
char *check_buffer(char *buf);

char **str_array(char *buf, char c);
int **int_array(char *buf, int col, int line);
int count_col(char *buf, char c);
int count_line(char *buf, char c);

int **algobox(int **array, char *buf);

#endif
