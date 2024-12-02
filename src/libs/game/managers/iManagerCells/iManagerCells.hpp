#ifndef I_MANAGER_CELLS_HPP
#define I_MANAGER_CELLS_HPP

#include <cstddef>
#include <set>

#include "cells/cell/cell.hpp"
#include "managers/iManager/iManager.hpp"

typedef size_t GroupId;

class IManagerCells : public IManager<Cell>
{
    public:
        virtual std::string getTag() const = 0;
        virtual ~IManagerCells() = default;
};

#endif // I_MANAGER_CELLS_HPP