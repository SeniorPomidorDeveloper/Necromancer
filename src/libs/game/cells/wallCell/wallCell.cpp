#include "wallCell.hpp"

#include <iostream>

WallCell::WallCell(const Id &room) : Cell(room)
{
}

Cell::Type WallCell::getType() const
{
    return Cell::Type::Wall;
}

Cell *WallCell::getClone() const
{
    return new WallCell(getRoom());
}

bool WallCell::isEmpty() const
{
    return false;
}