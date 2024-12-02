#ifndef I_ATTACKER_HPP
#define I_ATTACKER_HPP

#include <cstddef>
#include "commonI/iUsingHealth/iUsingHealth.hpp"

class IAttacker
{
    public:
        virtual void setDamage(const Damage &damage) = 0;
        virtual const Damage *getDamage() = 0;
};

#endif // I_ATTACKER_HPP