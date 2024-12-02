#include "avallableCell.hpp"

AvallableCell::AvallableCell(const RoomId &room) : Cell(room)
{
}

bool AvallableCell::setSlot(CellElement *slot)
{
    slot_ = slot;
    return true;
}

CellElement &AvallableCell::getSlot()
{
    return *slot_;
}
CellElement *AvallableCell::popSlot()
{
    CellElement *temp = slot_;
    slot_ = nullptr;
    return temp;
}
bool AvallableCell::isFree() const
{
    return slot_ == nullptr;
}

std::set<std::string> AvallableCell::getTags() const
{
    return {"Avallable"};
}

Cell *AvallableCell::getClone() const
{
    return new AvallableCell(getRoom());
}

bool AvallableCell::isEmpty() const
{
    return isFree();
}