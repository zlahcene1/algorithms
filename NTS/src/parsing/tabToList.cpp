/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include "my.hpp"

std::list<std::string> chipsetTbToList(instru_t *allInstructions)
{
    std::list<std::string> list;

    for (std::string x : allInstructions->chipsets)
        list.push_front(x);
    list.reverse();
    return (list);
}

std::vector<std::string> linksTbToList(instru_t *allInstructions)
{
    std::vector<std::string> links;

    for (std::string x : allInstructions->links)
        links.push_back(x);
    //vector.reverse();
    return (links);
}
