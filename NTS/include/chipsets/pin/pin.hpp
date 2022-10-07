/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#ifndef PIN_HPP
#define PIN_HPP

#include "IComponent.hpp"

namespace objPin
{
    class Pin
    {
    private:
        nts::IComponent *otherChip;
        std::size_t otherPin;

    public:
        Pin(nts::IComponent *thisComponent, std::size_t othPin)
            : otherChip{thisComponent}, otherPin{othPin} {};
        ~Pin(){};
        void setOtherPin(size_t value)
        {
            this->otherPin = value;
        }
        void setOtherChip(nts::IComponent &othcmp)
        {
            otherChip = &othcmp;
        }
        nts::Tristate giveValueOtherPin()
        {
            return (otherChip->compute(otherPin));
        }
        void printOtherChipName() { std::cout << this->otherChip->giveChipsetName() << std::endl; }
        void printOtherChipType() { std::cout << this->otherChip->giveChipsetType() << std::endl; }
    };
}

#endif