#ifndef IC_
#define IC_

#include <iostream>

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent
    {
    public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual void dump() const = 0;
        virtual void setValue(int value) = 0;
        //PERSONAL ADD:
        virtual std::string giveChipsetName() = 0;
        virtual std::string giveChipsetType() = 0;
        virtual nts::Tristate giveValuePin() = 0;
    };
}

#endif
