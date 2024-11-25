#include "health.hpp"

#include <algorithm>

Health::Health(const HealthPoints &maxValue) noexcept : maxValue_(maxValue), currentValue_(maxValue)
{
}

Health::Health(const HealthPoints &maxValue, const HealthPoints &currentValue) noexcept : maxValue_(maxValue), currentValue_(currentValue) 
{
    if (currentValue_ > maxValue_) 
    {
        currentValue_ = maxValue_;
    }
}

void Health::setMaxValue(const HealthPoints &maxValue) noexcept
{
    maxValue_ = maxValue;
    if (currentValue_ > maxValue_) 
    {
        currentValue_ = maxValue_;
    }
}

void Health::setCurrentValue(const HealthPoints &currentValue) noexcept
{
    currentValue_ = currentValue;
    if (currentValue_ > maxValue_) 
    {
        currentValue_ = maxValue_;
    }
}

HealthPoints Health::getMaxValue() const noexcept
{
    return maxValue_;
}

HealthPoints Health::getValue() const noexcept
{
    return currentValue_;
}

bool Health::isFull() const noexcept
{
    return currentValue_ == maxValue_;
}

bool Health::isEmpty() const noexcept
{
    return currentValue_ == 0;
}

Health &Health::operator+=(const HealthPoints &health) noexcept
{
    currentValue_ = std::min(maxValue_, currentValue_ + health);
    return *this;
}

Health &Health::operator-=(const HealthPoints &health) noexcept
{
    if (currentValue_ < health) currentValue_ = 0;
    else currentValue_ -= health;
    return *this;
}
