/*
** EPITECH PROJECT, 2020
** p_swap
** File description:
** all headerz
*/

#ifndef P_SWAP_H
#define P_SWAP_H

#include "list.h"
#include "my.h"

/*------- list manage -***--------*/

List new_list(void);
Bool is_empty_list(List li);
void print_list(List li);
List free_front_list(List li);
List free_back_list(List li);
List push_front_list(List li, int x);
List push_back_list(List li, int x);

/*------- All operations ---------*/

List sa(List li);
List ra(List l_a);
List pb(List l_a, List l_b);

#endif
