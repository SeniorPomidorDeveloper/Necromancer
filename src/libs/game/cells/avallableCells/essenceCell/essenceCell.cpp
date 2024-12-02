#include "essenceCell.hpp"

#include <algorithm>

EssenceCell::EssenceCell(const RoomId &room, const Essence &essence) : AvallableCell(room), essence_(essence)
{
}

std::set<std::string> EssenceCell::getTags() const
{
    std::set<std::string> tags = AvallableCell::getTags();
    tags.insert("Essence");
    return tags;
}

bool EssenceCell::giveEssence(IUsingEssence *user)
{
    if (user == nullptr) return false;
    Essence lose_ess = user->addEssence(essence_);
    if (lose_ess == 0) return false;
    essence_ -= lose_ess;
    return true;
}

Essence EssenceCell::addEssence(const Essence &essence)
{
    essence_ += essence;
    return essence;
}

Essence EssenceCell::getEssence()
{
    return essence_;
}

Essence EssenceCell::spendEssence(const Essence &essence)
{
    return (essence_ >= essence) ? essence_ - essence : 0;
}

bool EssenceCell::isEssenceEmpty()
{
    return essence_ == 0;
}

bool EssenceCell::isEssenceFull()
{
    return false;
}

Cell *EssenceCell::getClone() const
{
    return new EssenceCell(getRoom(), essence_);
}