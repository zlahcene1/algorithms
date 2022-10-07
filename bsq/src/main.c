/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** main function
*/

#include "my.h"
#include "bsq.h"

int main(int ac, char **av)
{
    char *buf = NULL;

    if (ac != 2)
        return (84);
    buf = open_file(av[1]);
    if (my_strcmp(buf, "NTM\0") == 0)
        return (84);
    core_function(buf);
    return (0);
}
