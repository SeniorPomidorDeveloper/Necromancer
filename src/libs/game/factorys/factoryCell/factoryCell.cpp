#include "factoryCell.hpp"

#include <algorithm>
#include <iostream>

FactoryCell *FactoryCell::getInstance()
{
    if (instance_ == nullptr) instance_ = new FactoryCell();
    return instance_;
}

FactoryCell *FactoryCell::deleteInstance()
{
    delete instance_;
    instance_ = nullptr;
    return instance_;
}

void FactoryCell::addStandard(const CellId &id, const Cell &cell)
{
    Cell *clone = cell.getClone();
    clone->setRoom(0);
    standards_[id] = clone;
    std::set<std::string> tags = clone->getTags();
    std::for_each(tags.begin(), tags.end(), [&id, this](const std::string &tag)
    {
        tags_[tag].insert(id);
    });
}

Cell *FactoryCell::create(const CellId &id) const
{
    if (!standards_.contains(id)) return nullptr;
    return standards_.at(id)->getClone();
}

std::set<CellId> FactoryCell::getIds(const std::string &tag) const
{
    if (!tags_.contains(tag)) return std::set<CellId>();
    return tags_.at(tag);
}

FactoryCell::~FactoryCell()
{
    std::for_each(standards_.begin(), standards_.end(), [](std::pair<CellId, const Cell *> cell)
    {
        delete cell.second;
    });
}