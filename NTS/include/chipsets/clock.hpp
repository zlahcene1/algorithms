/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Clock Chipset [• clock: a component that works like an input, except its value is inverted after each simulation.]
*/

#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <map>
#include <memory>
#include "IComponent.hpp"
#include "pin.hpp"

class Clock : public nts::IComponent {
private:
    nts::Tristate valueOfPin{ nts::Tristate::UNDEFINED };
    objPin::Pin otherPin;
    const std::string crntChipName;
    const std::string crntChipType;
    int tick { 0 };

public:
    Clock(std::string chipName, std::string chipType) : otherPin{this, 1}, 
                                                        crntChipName{chipName}, 
                                                        crntChipType{chipType} {};
    ~Clock() = default;
    void simulate(std::size_t tick) override final{}
    nts::Tristate compute(std::size_t pin) override final
    {
        tick++;
        if (tick == 1) {return (valueOfPin);}
        if (pin == 1) {
            if (valueOfPin == nts::Tristate::TRUE)
                return (valueOfPin = nts::Tristate::FALSE);
            else if (valueOfPin == nts::Tristate::FALSE)
                return (valueOfPin = nts::Tristate::TRUE);
            else
                return (valueOfPin = nts::Tristate::UNDEFINED);
            return (valueOfPin);
        }
        if (pin == 0)
            return nts::Tristate::UNDEFINED;
        else
            return (nts::Tristate::UNDEFINED);
        throw std::invalid_argument("");
    }
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override final {
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