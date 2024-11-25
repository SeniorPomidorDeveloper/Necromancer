#include "lavalCell.hpp"
#include "cellElements/entitys/entity/entity.hpp"

LavaCell::LavaCell(const Id& root, const Damage &damage) : AvallableCell(root), damage_(damage)
{
}

bool LavaCell::giveDamage(IUsingHealth *enemy)
{
    return enemy->takeDamage(damage_);
}

bool LavaCell::giveDamage()
{
    if (slot_->canTakeDamage()) return static_cast<Entity *>(slot_);
    return false;
}

void LavaCell::setDamage(const Damage &damage)
{
    damage_ = damage;
}

const Damage *LavaCell::getDamage()
{
    return &damage_;
}

Cell *LavaCell::getClone() const
{
    return new LavaCell(getRoom(), damage_);
}