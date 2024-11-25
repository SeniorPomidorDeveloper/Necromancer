#ifndef I_USING_ESSENCE_HPP
#define I_USING_ESSENCE_HPP

#include <cstddef>
#include "commonI/iUsingHealth/iUsingHealth.hpp"

class IAttacker
{
    public:
        virtual bool giveDamage(IUsingHealth *enemy) = 0;
        virtual void setDamage(const Damage &damage) = 0;
        virtual const Damage *getDamage() = 0;
};

#endif // I_USING_ESSENCE_HPP