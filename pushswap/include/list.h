/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** list elemen
*/

#ifndef LIST_H_
#define LIST_H_

typedef enum
{
    false,
    true
}Bool;

typedef struct ListELement
{
    int value;
    struct ListElement *next;
}ListElement, *List;

#endif
