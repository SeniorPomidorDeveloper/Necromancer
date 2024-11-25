#ifndef I_USING_HEALTH_HPP
#define I_USING_HEALTH_HPP

#include <cstddef>

#include "damage/damage.hpp"

class IUsingHealth
{
    public:
        virtual void setHealth(const Health &health) = 0;
        virtual void addHealth(const HealthPoints &health) = 0;
        virtual HealthPoints getHealth() const = 0;
        virtual void spendHealth(const HealthPoints &health) = 0;
        virtual bool takeDamage(const Damage &damage) = 0;
};

#endif // I_USING_HEALTH_HPP