/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** False Chipset [• false: a component with a single pin that is always false.]
*/


#ifndef FALSE_HPP
#define FALSE_HPP

#include <map>
#include <memory>
#include "IComponent.hpp"
#include "pin.hpp"

class False : public nts::IComponent {
private:
    nts::Tristate valueOfPin{nts::Tristate::FALSE};
    objPin::Pin otherPin;
    const std::string crntChipName;
    const std::string crntChipType;

public:
    False(std::string chipName, std::string chipType) : otherPin{this, 1},
                                                        crntChipName{chipName},
                                                        crntChipType{chipType} {};
    ~False() = default;
    void simulate(std::size_t tick) override final{}
    nts::Tristate compute(std::size_t pin) override final
    {
        if (pin == 1)
            return (valueOfPin);
        if (pin == 0)
            return nts::Tristate::TRUE;
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
            valueOfPin = nts::Tristate::FALSE;
            break;
        case (0):
            valueOfPin = nts::Tristate::FALSE;
            break;
        case (-1):
            valueOfPin = nts::Tristate::FALSE;
            break;
        default:
            valueOfPin = nts::Tristate::FALSE;
            break;
        }
    }
    std::string giveChipsetName() override final { return (crntChipName); }
    std::string giveChipsetType() override final { return (crntChipType); }
    nts::Tristate giveValuePin() override final { return (valueOfPin); }
};

#endif


