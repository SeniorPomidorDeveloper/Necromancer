#include "essenceCell.hpp"

EssenceCell::EssenceCell(const Id &room, const Essence &essence) : AvallableCell(room), essence_(essence)
{
}

bool EssenceCell::giveEssence(IUsingEssence *user)
{
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

void EssenceCell::setEssence(const Essence &essence)
{
    essence_ = essence;
}

Essence EssenceCell::getEssence()
{
    return essence_;
}

bool EssenceCell::isEssenceEmpty()
{
    return essence_ == 0;
}

bool EssenceCell::isEssenceFull()
{
    return false;
}