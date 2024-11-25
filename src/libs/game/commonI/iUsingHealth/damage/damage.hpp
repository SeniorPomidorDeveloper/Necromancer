#ifndef DAMAGE_HPP
#define DAMAGE_HPP

#include "commonI/iUsingHealth/health/health.hpp"

class Damage {
private:
    HealthPoints value_;

public:
    Damage(const HealthPoints &damage) noexcept;
    Damage(const Damage &other) noexcept;
    Damage(Damage &&other) noexcept;

    HealthPoints getValue() const noexcept;

    Damage &operator=(const Damage &other) noexcept;
    Damage &operator=(Damage &&other) noexcept;

    virtual ~Damage() = default;
};

#endif // DAMAGE_HPP