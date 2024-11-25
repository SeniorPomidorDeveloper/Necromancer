#include "damage.hpp"

#include <utility>

Damage::Damage(const HealthPoints &value) noexcept : value_(value)
{    
}

Damage::Damage(const Damage &other) noexcept
{
    *this = other;
}

Damage::Damage(Damage &&other) noexcept
{
    *this = std::move(other);
}

HealthPoints Damage::getValue() const noexcept
{
    return value_;
}

Damage &Damage::operator=(const Damage &other) noexcept
{
    value_ = other.value_;
    return *this;
}

Damage &Damage::operator=(Damage &&other) noexcept
{
    value_ = std::move(other.value_);
    return *this;
}