/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#ifndef C4011_HPP_
#define C4011_HPP_

#include <map>
#include <memory>
#include <vector>
#include "IComponent.hpp"
#include "pin.hpp"

class c4011 : public nts::IComponent
{
private:
    std::map<std::size_t, nts::Tristate> mapPin;
    std::vector<objPin::Pin> otherPin;
    const std::string crntChipName;
    const std::string crntChipType;

public:
    c4011(std::string chipName, std::string chipType) : crntChipName{chipName},
                                                        crntChipType{chipType} {};
    ~c4011() = default;
    void simulate(std::size_t tick) override {}
    nts::Tristate compute(std::size_t pin) override
    {
        if (pin == 3)
        {
            if (otherPin[0].giveValueOtherPin() == nts::TRUE && otherPin[1].giveValueOtherPin() == nts::TRUE)
                return (nts::FALSE);
            if (otherPin[0].giveValueOtherPin() == nts::UNDEFINED || otherPin[1].giveValueOtherPin() == nts::UNDEFINED)
                return (nts::UNDEFINED);
            else
                return (nts::TRUE);
        }
        if (pin == 4)
        {
            if (otherPin[4].giveValueOtherPin() == nts::TRUE && otherPin[5].giveValueOtherPin() == nts::TRUE)
                return (nts::FALSE);
            if (otherPin[4].giveValueOtherPin() == nts::UNDEFINED || otherPin[5].giveValueOtherPin() == nts::UNDEFINED)
                return (nts::UNDEFINED);
            else
                return (nts::TRUE);
        }
        if (pin == 10)
        {
            if (otherPin[6].giveValueOtherPin() == nts::TRUE && otherPin[7].giveValueOtherPin() == nts::TRUE)
                return (nts::FALSE);
            if (otherPin[6].giveValueOtherPin() == nts::UNDEFINED || otherPin[7].giveValueOtherPin() == nts::UNDEFINED)
                return (nts::UNDEFINED);
            else
                return (nts::TRUE);
        }
        if (pin == 11)
        {
            if (otherPin[10].giveValueOtherPin() == nts::TRUE && otherPin[11].giveValueOtherPin() == nts::TRUE)
                return (nts::FALSE);
            if (otherPin[10].giveValueOtherPin() == nts::UNDEFINED || otherPin[11].giveValueOtherPin() == nts::UNDEFINED)
                return (nts::UNDEFINED);
            else
                return (nts::TRUE);
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
