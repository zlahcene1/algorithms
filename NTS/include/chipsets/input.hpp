/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Input chipset [• input: a component with a single pin directly linked to the command line. Its value is initialized to undefined]
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <map>
#include <memory>
#include "IComponent.hpp"
#include "pin.hpp"

class input : public nts::IComponent {
private:
    nts::Tristate valueOfPin{nts::Tristate::UNDEFINED};
    objPin::Pin otherPin;
    const std::string crntChipName;
    const std::string crntChipType;

public:
    input(std::string chipName, std::string chipType) : otherPin{this, 1},
                                                        crntChipName{chipName},
                                                        crntChipType{chipType} {};
    ~input() = default;
    void simulate(std::size_t tick) override final{}
    nts::Tristate compute(std::size_t pin) override final
    {
        if (pin == 1)
            return (valueOfPin);
        if (pin == 0)
            return nts::Tristate::UNDEFINED;
        throw std::invalid_argument("");
    }
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override final{
        if (pin != 1)
            throw std::invalid_argument("");
        this->otherPin.setOtherChip(other);
        this->otherPin.setOtherPin(otherPin);
    }
    void dump() const override final{}
    void setValue(int value) override final
    {
        switch (value)
        {
        case (1):
            valueOfPin = nts::Tristate::TRUE;
            break;
        case (0):
            valueOfPin = nts::Tristate::FALSE;
            break;
        case (-1):
            valueOfPin = nts::Tristate::UNDEFINED;
            break;
        default:
            valueOfPin = nts::Tristate::UNDEFINED;
            break;
        }
    }
    std::string giveChipsetName() override final { return (crntChipName); }
    std::string giveChipsetType() override final { return (crntChipType); }
    nts::Tristate giveValuePin() override final { return (valueOfPin); }
};

#endif
