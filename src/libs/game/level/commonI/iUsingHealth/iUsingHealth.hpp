#ifndef I_USING_HEALTH_HPP
#define I_USING_HEALTH_HPP

#include <cstddef>

typedef size_t Damage;

typedef size_t Health;

class IUsingHealth
{
    public:
        virtual void setHealth(const Health &health) = 0;
        virtual void addHealth(const Health &health) = 0;
        virtual bool takeDamage(const Damage &damage) = 0;
};

#endif // I_USING_HEALTH_HPP