#ifndef CELL_GROUPS_HPP
#define CELL_GROUPS_HPP

#include "groups/libs/groups/paths.hpp"
#include "cells/cell/cell.hpp"

class CellGroups final : public Groups<CellId, Cell *>
{
    private:
        static inline CellGroups *instance_ = nullptr;
        CellGroups() = default;
    public:
        static CellGroups *getInstance();
        CellGroups *deleteInstance();
};

#endif // CELL_GROUPS_HPP