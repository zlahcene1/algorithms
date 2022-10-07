/*
** EPITECH PROJECT, 2021
** GIANTMANT
** File description:
** main function
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac != 3) {
        my_putstr("FAILURE\n");
        return (84);
    }
    open_file(av[1]);
    return (0);
}
