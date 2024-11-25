#include "doorCell.hpp"

#include <iostream>

DoorCell::DoorCell(const Id &room, const bool isOpened) : Cell(room), opened_(isOpened)
{
}

Cell::Type DoorCell::getType() const
{
    return Cell::Type::Door;
}

void DoorCell::open()
{
    opened_ = true;
}

void DoorCell::close()
{
    if (isFree()) opened_ = false;
}

bool DoorCell::isOpened()
{
    return opened_;
}

Cell *DoorCell::getClone() const
{
    return new DoorCell(getRoom());
}

bool DoorCell::isFree() const
{
    return slot_ == nullptr;
}

bool DoorCell::isEmpty() const
{
    return opened_ && isFree();
}

bool DoorCell::setSlot(CellElement *slot)
{
    if (!(isFree() && opened_)) return false;
    slot_ = slot;
    return true;
}

CellElement &DoorCell::getSlot()
{
    return *slot_;
}

CellElement *DoorCell::popSlot()
{
    CellElement *temp = slot_;
    slot_ = nullptr;
    return temp;
}