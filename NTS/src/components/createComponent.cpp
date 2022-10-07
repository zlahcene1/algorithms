/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include <memory>
#include <unordered_map>
#include <functional>
#include "my.hpp"
#include "IComponent.hpp"
#include "4011.hpp"
#include "4001.hpp"
#include "input.hpp"
#include "output.hpp"
#include "clock.hpp"
#include "true.hpp"
#include "false.hpp"
#include "4030.hpp"
#include "4069.hpp"
#include "4071.hpp"
#include "4081.hpp"

std::shared_ptr<nts::IComponent> declareChipset(std::string chipset)
{
    std::string typeChip = giveChipsetType(chipset);
    std::string nameChip = giveChipsetName(chipset);

    if (typeChip == "input")
        return (std::make_shared<input>(nameChip, typeChip));
    if (typeChip == "clock")
        return (std::make_shared<Clock>(nameChip, typeChip));
    if (typeChip == "true")
        return (std::make_shared<True>(nameChip, typeChip));
    if (typeChip == "false")
        return (std::make_shared<False>(nameChip, typeChip));
    if (typeChip == "output")
        return (std::make_shared<output>(nameChip, typeChip));
    if (typeChip == "4011")
        return (std::make_shared<c4011>(nameChip, typeChip));
    if (typeChip == "4001")
        return (std::make_shared<c4001>(nameChip, typeChip));
    if (typeChip == "4030")
        return (std::make_shared<c4030>(nameChip, typeChip));
    if (typeChip == "4069")
        return (std::make_shared<c4069>(nameChip, typeChip));
    if (typeChip == "4071")
        return (std::make_shared<c4071>(nameChip, typeChip));
    if (typeChip == "4081")
        return (std::make_shared<c4081>(nameChip, typeChip));
    else {
        std::cout << "chipset [" << typeChip << "] n'existe pas dans la map" << std::endl;
        exit(0);
    }
}

std::vector<std::shared_ptr<nts::IComponent>> createComponent(std::list<std::string> chipsets, std::vector<std::string> links)
{
    std::vector<std::shared_ptr<nts::IComponent>> components; //hold all initialised chipset(s)

    for (std::string chipset : chipsets)
        components.push_back(declareChipset(chipset));
    for (std::string link : links)
        for (auto firstChipset : components) {
            if (firstChipset->giveChipsetName() == giveBefore(link, ':'))
                for (auto sndChipset : components)
                    if (sndChipset->giveChipsetName() == giveBefore(giveAfter(link, ' '), ':'))
                        firstChipset->setLink(givefirstPin(link), *sndChipset, giveScondPin(link));
            if (firstChipset->giveChipsetName() == giveBefore(giveAfter(link, ' '), ':'))
                for (auto sndChipset : components)
                    if (sndChipset->giveChipsetName() == giveBefore(link, ':'))
                        firstChipset->setLink(giveScondPin(link), *sndChipset, givefirstPin(link));
        }

    return (components);
}
