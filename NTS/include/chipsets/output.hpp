/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Output Chipset [• output: a component with a single pin used as the output of a circuit.]
*/

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <map>
#include <memory>
#include "IComponent.hpp"
#include "pin.hpp"

class output : public nts::IComponent
{
private:
    nts::Tristate valueOfPin;
    objPin::Pin otherPin;
    const std::string crntChipName;
    const std::string crntChipType;

public:
    output(std::string chipName, std::string chiptype) : otherPin{ this, 1 },
                                                         crntChipName{ chipName },
                                                         crntChipType{ chiptype },
                                                         valueOfPin{ nts::Tristate::UNDEFINED } {};
    ~output(){};
    void simulate(std::size_t tick) override {}
    nts::Tristate compute(std::size_t pin) override final
    {
        if (pin == 1)
            valueOfPin = otherPin.giveValueOtherPin();
    }
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override
    {
        if (pin != 1)
            throw std::invalid_argument("");
        this->otherPin.setOtherChip(other);
        this->otherPin.setOtherPin(otherPin);
        if (other.giveChipsetType().compare("true") == 0)
            this->valueOfPin = nts::Tristate::TRUE;
        if (other.giveChipsetType().compare("false") == 0)
            this->valueOfPin = nts::Tristate::FALSE;
    }
    void dump() const override {}
    void setValue(int value) override final {}
    std::string giveChipsetName() override
    {
        return (crntChipName);
    }
    std::string giveChipsetType() override
    {
        return (crntChipType);
    }
    nts::Tristate giveValuePin() override final
    {
        return (valueOfPin);
    }
};

#endif