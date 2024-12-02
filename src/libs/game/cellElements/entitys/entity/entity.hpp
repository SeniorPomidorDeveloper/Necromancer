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

        bool canTakeDamage() const override;

        void setHealth(const Health &health) override;
        void addHealth(const HealthPoints &health) override;
        HealthPoints getHealth() const override;
        void spendHealth(const HealthPoints &health) override;
        bool takeDamage(const Damage &damage) override;

        virtual bool isLive() const;
        virtual bool isDead() const;
        virtual void die();
};

#endif // ENTITY_HPP