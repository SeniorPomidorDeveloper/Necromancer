#include "factoryCell.hpp"

#include <algorithm>

FactoryCell::FactoryCell()
{
}

FactoryCell::FactoryCell(FactoryCell &&other)
{
    *this = std::move(other);
}

void FactoryCell::addStandard(const CellId &id, const Cell &cell)
{
    standards_[id] = cell.getClone();
}

Cell *FactoryCell::create(const CellId &id) const
{
    return standards_.at(id)->getClone();
}

FactoryCell &FactoryCell::operator=(FactoryCell &&other)
{
    standards_ = std::move(other.standards_);
    return *this;
}

FactoryCell::~FactoryCell()
{
    std::for_each(standards_.begin(), standards_.end(), [](std::pair<CellId, const Cell *> cell)
    {
        delete cell.second;
    });
}