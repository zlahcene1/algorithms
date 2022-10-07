/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** main of the program
*/

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "my.hpp"
#include "IComponent.hpp"

static int wrong_input(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (giveAfter(av[1], '.') != "nts")
       return (84);
}

int main(int ac, char **av)
{
    if (wrong_input(ac, av) == 84) {
        std::cout << "usage : ./NanoTekspice [file.nts]" << std::endl;
        return (0);
    }
    instru_t *allInstructions = parser(openFile(av[1]));
    std::list<std::string> chipsets = chipsetTbToList(allInstructions);
    std::vector<std::string> links = linksTbToList(allInstructions);
    std::vector<std::shared_ptr<nts::IComponent>> AllChipsets = createComponent(chipsets, links);
    std::size_t tick = 0;
    std::string instruction = "init";
    std::vector<std::shared_ptr<nts::IComponent>> tempAllChipsets;
    std::vector<std::string> assignation;

    while (instruction != "exit")
    {
        std::cout << "> ";
        std::vector<std::string> possibleInstruction = {"simulate", "display", "loop", "exit"};
        std::cin >> instruction;
        if (std::cin.eof())
            instruction = "exit"; 
        try
        {
            if (instruction == possibleInstruction[0]) { //simulate
                tick++;
                for (auto chip : AllChipsets) //assign value
                    for (std::string instru : assignation)
                        if (giveBefore(instru, '=') == chip->giveChipsetName()) {
                            if (giveAfter(instru, '=') == "U")
                                chip->setValue(-1);
                            else
                                chip->setValue(atoi(giveAfter(instru, '=').c_str()));
                        }
                assignation.clear();
                for (auto chip : AllChipsets) //compute value
                    if (chip->giveChipsetType() == "output")
                        chip->compute(1);
            }
            else if (instruction == possibleInstruction[1]) // displays
                display(AllChipsets, tick);
            else if (instruction != possibleInstruction[3]) //assignation
                assignation.push_back(instruction); //stock the given value until a "simulate" is given 
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << "error bro" << std::endl;
        }
    }
    return 0;
}
