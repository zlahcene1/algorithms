/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** 4069 Chipset NOT
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include <map>
#include <memory>
#include <vector>
#include "IComponent.hpp"
#include "pin.hpp"

class c4069 : public nts::IComponent
{
private:
    std::map<std::size_t, nts::Tristate> mapPin;
    std::vector<objPin::Pin> otherPin;
    const std::string crntChipName;
    const std::string crntChipType;

public:
    c4069(std::string chipName, std::string chipType) : crntChipName{chipName},
                                                        crntChipType{chipType} {
                                                        };
    ~c4069() override {}
    void simulate(std::size_t tick) override {}
    nts::Tristate compute(std::size_t pin) override {
        if (pin == 2)
        {
            if (otherPin[0].giveValueOtherPin() == nts::FALSE)
                return (nts::TRUE);
            if (otherPin[0].giveValueOtherPin() == nts::TRUE)
                return (nts::FALSE);
            else
                return (nts::UNDEFINED);
        }
        if (pin == 4)
        {
            if (otherPin[2].giveValueOtherPin() == nts::FALSE)
                return (nts::TRUE);
            if (otherPin[2].giveValueOtherPin() == nts::TRUE)
                return (nts::FALSE);
            else
                return (nts::UNDEFINED);
        }
        if (pin == 6)
        {
            if (otherPin[4].giveValueOtherPin() == nts::FALSE)
                return (nts::TRUE);
            if (otherPin[4].giveValueOtherPin() == nts::TRUE)
                return (nts::FALSE);
            else
                return (nts::UNDEFINED);
        }
        if (pin == 8)
        {
            if (otherPin[7].giveValueOtherPin() == nts::FALSE)
                return (nts::TRUE);
            if (otherPin[7].giveValueOtherPin() == nts::TRUE)
                return (nts::FALSE);
            else
                return (nts::UNDEFINED);
        }
        if (pin == 10)
        {
            if (otherPin[9].giveValueOtherPin() == nts::FALSE)
                return (nts::TRUE);
            if (otherPin[9].giveValueOtherPin() == nts::TRUE)
                return (nts::FALSE);
            else
                return (nts::UNDEFINED);
        }
        if (pin == 12)
        {
            if (otherPin[11].giveValueOtherPin() == nts::FALSE)
                return (nts::TRUE);
            if (otherPin[11].giveValueOtherPin() == nts::TRUE)
                return (nts::FALSE);
            else
                return (nts::UNDEFINED);
        }
        return (nts::UNDEFINED);
    }
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override
    {
        objPin::Pin tempMapPin{&other, otherPin};

        this->otherPin.push_back(tempMapPin);
        this->mapPin.insert({pin, nts::Tristate::UNDEFINED});
    }
    void dump() const override {}
    void setValue(int value) override final {}
    std::string giveChipsetName() override { return (crntChipName); }
    std::string giveChipsetType() override { return (crntChipType); }
    nts::Tristate giveValuePin() override final { return (nts::FALSE); }
};

#endif
