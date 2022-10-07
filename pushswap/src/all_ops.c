/*
** EPITECH PROJECT, 2020
** all ops
** File description:
** push swap
*/

#include "p_swap.h"

List sa(List li)
{
    int stock = 0;
    int stock2 = 0;

    if (li->next != NULL) {
        stock = li->value;
        li = free_front_list(li);
        stock2 = li->value;
        li = free_front_list(li);
        li = push_front_list(li, stock);
        li = push_front_list(li, stock2);
    }
    my_putstr("sa ");
    return li;
}

List sb(List li)
{
    int stock = 0;
    int stock2 = 0;

    if (li->next != NULL) {
        stock = li->value;
        li = free_front_list(li);
        stock2 = li->value;
        li = free_front_list(li);
        li = push_front_list(li, stock);
        li = push_front_list(li, stock2);

    }
    my_putstr("sb ");
    return li;
}

List ra(List l_a)
{
    int stock = l_a->value;

    l_a = free_front_list(l_a);
    l_a = push_back_list(l_a, stock);
    write(1, "ra ", 3);
    return l_a;
}

List pb(List l_a, List l_b)
{
    l_b = push_front_list(l_b, l_a->value);
    l_a = free_front_list(l_a);
    write(1, "pb ", 3);
    return l_b;
}

List pa(List l_a, List l_b)
{
    l_a = push_front_list(l_a, l_b->value);
    l_b = free_front_list(l_b);
    write(1, "pa ", 3);
    return l_a;
}
