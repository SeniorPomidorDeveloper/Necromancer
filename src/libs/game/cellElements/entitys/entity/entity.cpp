#include "entity.hpp"

Entity::Entity(const Position &position, const Health &health) : CellElement(position), health_(health)
{
}

bool Entity::canTakeDamage() const
{
    return true;
}

void Entity::setHealth(const Health &health)
{
    health_ = health;
}

void Entity::addHealth(const HealthPoints &health)
{
    health_ += health;
}
HealthPoints Entity::getHealth() const
{
    return health_.getValue();
}

void Entity::spendHealth(const HealthPoints &health)
{
    health_ -= health;
}

bool Entity::takeDamage(const Damage &damage)
{
    spendHealth(damage.getValue());
}

bool Entity::isLive() const
{
    return !health_.isEmpty();
}

bool Entity::isDead() const
{
    return health_.isEmpty();
}

void Entity::die()
{
    health_.setCurrentValue(0);
}