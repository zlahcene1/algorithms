/*
** EPITECH PROJECT, 2022
** nts
** File description:
** parse functions of instructions
*/

#include "my.hpp"

std::string giveChipsetType(std::string str)
{
    std::string first = str.substr(0, str.find(" "));
    return (first);
}

std::string giveChipsetName(std::string str)
{
    std::string temp = str;
    int end = temp.find(" ");

    temp = temp.substr(end + 1);
    return (temp);
}

std::string giveBefore(std::string str, char a)
{
    return (str.substr(0, str.find(a)));
}

std::string giveAfter(std::string str, char a)
{
    std::string temp = str;
    int end = temp.find(a);

    temp = temp.substr(end + 1);
    return (temp);
}

int givefirstPin(std::string str)
{
    return (atoi(giveAfter(giveBefore(str, ' '), ':').c_str()));
}

int giveScondPin(std::string str)
{
    return (atoi(giveAfter(giveAfter(str, ' '), ':').c_str()));
}