#include "cell.hpp"

Cell::Cell(const RoomId &room) : room_(room)
{
    id_ = nextId_++;
}

CellId Cell::getId() const
{
    return id_;
}

void Cell::setRoom(const RoomId &room)
{
    room_ = room;
}

RoomId Cell::getRoom() const
{
    return room_;
}

Cell::~Cell()
{
}