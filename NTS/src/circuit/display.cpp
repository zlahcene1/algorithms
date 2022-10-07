/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** if display is recieved : will display the Tick, all the input(s) value(s), output(s) value(s)
*/

#include <vector>
#include <memory>
#include "IComponent.hpp"

void display(std::vector<std::shared_ptr<nts::IComponent>> AllChipsets, int tick)
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto chip : AllChipsets)
        if (chip->giveChipsetType() == "input" 
        || chip->giveChipsetType() == "clock"
        )
            if (chip->giveValuePin() == -1)
                std::cout << "  " << chip->giveChipsetName() << ": "
                          << "U" << std::endl;
            else
                std::cout << "  " << chip->giveChipsetName()
                          << ": " << chip->giveValuePin() << std::endl;
    std::cout << "output(s):" << std::endl;
    for (auto chip : AllChipsets)
        if (chip->giveChipsetType() == "output")
            if (chip->giveValuePin() == -1)
                std::cout << "  " << chip->giveChipsetName() << ": "
                          << "U" << std::endl;
            else
                std::cout << "  " << chip->giveChipsetName()
                          << ": " << chip->giveValuePin() << std::endl;
}
