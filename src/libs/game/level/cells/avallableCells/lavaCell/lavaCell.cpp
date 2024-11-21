#include "lavalCell.hpp"

LavaCell::LavaCell(const Id& root, const Damage &damage = 0) : AvallableCell(root), damage_(damage)
{
}

bool LavaCell::giveDamage(IUsingHealth *enemy)
{
    enemy->takeDamage(damage_);
}

void LavaCell::setDamage(const Damage &damage)
{
    damage_ = damage;
}

const Damage *LavaCell::getDamage()
{
    return &damage_;
}