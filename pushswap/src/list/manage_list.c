/*
** EPITECH PROJECT, 2020
** p_swap
** File description:
** all  function who manage my linked list
*/

#include "p_swap.h"

List new_list(void)
{
    return NULL;
}

Bool is_empty_list(List li)
{
    if (li == NULL)
        return true;
    return false;
}

int list_len(List li)
{
    int counter = 0;

    for (;li != NULL; counter++)
        li = li->next;
    return counter;
}

void print_list(List li)
{
    if (is_empty_list(li)) {
        my_putstr("empty list\n");
        return;
    }
    while (li != NULL) {
        my_put_nbr(li->value);
        my_putchar('\n');
        li = li->next;
    }
}
