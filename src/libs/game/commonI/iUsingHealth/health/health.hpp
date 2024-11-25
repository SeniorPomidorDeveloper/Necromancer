#ifndef HEALTH_HPP
#define HEALTH_HPP

#include <cstddef>

typedef size_t HealthPoints;

class Health
{
    private:
        HealthPoints maxValue_;
        HealthPoints currentValue_;

    public:
        Health(const HealthPoints &maxValue) noexcept;
        Health(const HealthPoints &maxValue, const HealthPoints &currentValue) noexcept;

        void setMaxValue(const HealthPoints &maxValue) noexcept;
        void setCurrentValue(const HealthPoints &currentValue) noexcept;
        HealthPoints getMaxValue() const noexcept;
        HealthPoints getValue() const noexcept;

        bool isFull() const noexcept;
        bool isEmpty() const noexcept;

        Health &operator+=(const HealthPoints &health) noexcept;
        Health &operator-=(const HealthPoints &health) noexcept;

        virtual ~Health() noexcept = default;
};

#endif // HEALTH_HPP