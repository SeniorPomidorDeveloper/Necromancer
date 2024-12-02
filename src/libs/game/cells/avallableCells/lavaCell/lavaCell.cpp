#include "lavaCell.hpp"

#include "cellElements/entitys/entity/entity.hpp"

LavaCell::LavaCell(const RoomId& root, const Damage &damage) : AvallableCell(root), damage_(damage)
{
}

std::set<std::string> LavaCell::getTags() const
{
    std::set<std::string> tags = AvallableCell::getTags();
    tags.insert("AttackeSlot");
    return tags;
}

bool LavaCell::giveDamage()
{
    if (slot_ == nullptr) return false;
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