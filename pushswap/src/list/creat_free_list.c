/*
** EPITECH PROJECT, 2020
** p_swap
** File description:
** creat cells or free
*/

#include "p_swap.h"

List push_back_list(List li, int x)
{
    ListElement *element = malloc(sizeof(*element));
    ListElement *temp = li;

    if (element == NULL)
        exit(EXIT_FAILURE);
    element->value = x;
    element->next = NULL;
    if (is_empty_list(li))
        return element;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
    return li;
}

List push_front_list(List li, int x)
{
    ListElement *element = malloc(sizeof(*element));

    if (element == NULL)
        exit(EXIT_FAILURE);
    element->value = x;
    if (is_empty_list(li))
        element->next = NULL;
    else
        element->next = li;
    return element;
}

List free_back_list(List li)
{
    ListElement *before;
    ListElement *temp;

    if (is_empty_list(li))
        return NULL;
    if (li->next == NULL) {
        free(li);
        return NULL;
    }
    before = li;
    temp = li;
    while (temp->next != NULL) {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    free(temp);
    temp = NULL;
    return li;
}

List free_front_list(List li)
{
    ListElement *element = malloc(sizeof(*element));

    if (is_empty_list(li))
        return NULL;
    if (li->next == NULL) {
        free(li);
        return NULL;
    }
    element = li->next;
    free(li);
    return element;
}
