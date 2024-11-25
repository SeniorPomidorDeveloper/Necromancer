#include "cell.hpp"

Cell::Cell(const Id &room) : room_(room)
{
}

void Cell::setRoom(const Id &room)
{
    room_ = room;
}

Id Cell::getRoom() const
{
    return room_;
}

Cell::~Cell()
{
}