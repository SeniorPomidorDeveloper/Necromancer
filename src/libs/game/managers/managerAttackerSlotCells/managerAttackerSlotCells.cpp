#include "managerAttackerSlotCells.hpp"

#include <algorithm>

#include "factorys/factoryCell/factoryCell.hpp"
#include "cells/avallableCells/lavaCell/lavaCell.hpp"
#include "level/groups/cellGroups/cellGroups.hpp"

ManagerAttackerSlotCells *ManagerAttackerSlotCells::getInstance()
{
    if (instance_ == nullptr) instance_ = new ManagerAttackerSlotCells();
    return instance_;
}

void ManagerAttackerSlotCells::deletInstance()
{
    delete instance_;
    instance_ = nullptr;
}

void ManagerAttackerSlotCells::manage() const 
{
    FactoryCell *facture = FactoryCell::getInstance();
    static std::set<CellId> ids = facture->getIds(getTag());
    static std::set<CellId>::iterator begin = ids.begin();
    static std::set<CellId>::iterator end = ids.end();
    CellGroups *groups = CellGroups::getInstance();
    std::for_each(begin, end, [&groups](const CellId &id)
    {
        std::set<Cell *> &cells = (*groups)[id];
        std::for_each(cells.begin(), cells.end(), [](Cell *cell)
        {
            static_cast<LavaCell *>(cell)->giveDamage();
        });
    });
}

std::string ManagerAttackerSlotCells::getTag() const
{
    return "AttackeSlot";
}