/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "p_swap.h"

int main(int ac, char **av)
{
    List l_a = new_list();
    List l_b = new_list();

    for (int i = 1; i != ac; i++)
        l_a = push_back_list(l_a, my_getnbr(av[i]));

    my_putchar('\n');
    free(l_a);
    free(l_b);
    return 0;
}
