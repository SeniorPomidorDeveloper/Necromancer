#include "wallCell.hpp"

#include <iostream>

WallCell::WallCell(const RoomId &room) : Cell(room)
{
}

std::set<std::string> WallCell::getTags() const
{
    return {"Wall"};
}

Cell *WallCell::getClone() const
{
    return new WallCell(getRoom());
}

bool WallCell::isEmpty() const
{
    return false;
}