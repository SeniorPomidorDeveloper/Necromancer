#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "cellElements/cellElement/cellElement.hpp"
#include "commonI/iUsingHealth/iUsingHealth.hpp"

class Entity : public CellElement, IUsingHealth
{
    private:
        Health health_;

    public:
        Entity(const Position &position, const Health &health);

        bool canTakeDamage() const noexcept override;

        void setHealth(const Health &health) noexcept override;
        void addHealth(const HealthPoints &health) noexcept override;
        HealthPoints getHealth() const override;
        void spendHealth(const HealthPoints &health) noexcept override;
        bool takeDamage(const Damage &damage) noexcept override;

        virtual bool isLive() const noexcept;
        virtual bool isDead() const noexcept;
        virtual void die() noexcept;
};

#endif // ENTITY_HPP