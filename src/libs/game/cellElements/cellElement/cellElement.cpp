#include "cellElement.hpp"

CellElement::CellElement(const Position& position) : position_(position)
{
    Id_ = maxId_++;
}

void CellElement::setPosition(const Position& position)
{
    position_ = position;
}

Position CellElement::getPosition() const
{
    return position_;
}

const Position &CellElement::getConstPosition() const
{
    return position_;
}

size_t CellElement::getId() const
{
    return Id_;
}