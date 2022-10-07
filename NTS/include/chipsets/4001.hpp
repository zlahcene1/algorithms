/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include <map>
#include <memory>
#include <vector>
#include "IComponent.hpp"
#include "pin.hpp"

class c4001 : public nts::IComponent
{
private:
    std::map<std::size_t, nts::Tristate> mapPin;
    std::vector<objPin::Pin> otherPin;
    const std::string crntChipName;
    const std::string crntChipType;

public:
    c4001(std::string chipName, std::string chipType) : crntChipName{chipName},
                                                        crntChipType{chipType} {
                                                        };
    ~c4001() override {}
    void simulate(std::size_t tick) override {}
    nts::Tristate compute(std::size_t pin) override {
        if (pin == 3)
        {
            if (otherPin[0].giveValueOtherPin() == nts::FALSE && otherPin[1].giveValueOtherPin() == nts::FALSE)
                return (nts::TRUE);
            if (otherPin[0].giveValueOtherPin() == nts::UNDEFINED || otherPin[1].giveValueOtherPin() == nts::UNDEFINED)
                return (nts::UNDEFINED);
            else
                return (nts::FALSE);
        }
        if (pin == 4)
        {
            if (otherPin[4].giveValueOtherPin() == nts::FALSE && otherPin[5].giveValueOtherPin() == nts::FALSE)
                return (nts::TRUE);
            if (otherPin[4].giveValueOtherPin() == nts::UNDEFINED || otherPin[5].giveValueOtherPin() == nts::UNDEFINED)
                return (nts::UNDEFINED);
            else
                return (nts::FALSE);
        }
        if (pin == 10)
        {
            if (otherPin[6].giveValueOtherPin() == nts::FALSE && otherPin[7].giveValueOtherPin() == nts::FALSE)
                return (nts::TRUE);
            if (otherPin[6].giveValueOtherPin() == nts::UNDEFINED || otherPin[7].giveValueOtherPin() == nts::UNDEFINED)
                return (nts::UNDEFINED);
            else
                return (nts::FALSE);
        }
        if (pin == 11)
        {
            if (otherPin[10].giveValueOtherPin() == nts::FALSE && otherPin[11].giveValueOtherPin() == nts::FALSE)
                return (nts::TRUE);
            if (otherPin[10].giveValueOtherPin() == nts::UNDEFINED || otherPin[11].giveValueOtherPin() == nts::UNDEFINED)
                return (nts::UNDEFINED);
            else
                return (nts::FALSE);
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
