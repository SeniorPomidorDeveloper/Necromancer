#ifndef Factory_CELL_HPP
#define Factory_CELL_HPP

#include <unordered_map>

#include "cells/cell/cell.hpp"

typedef size_t CellId;

class FactoryCell
{
    private:
        std::unordered_map<CellId, const Cell *> standards_;
        
    public:
        FactoryCell();
        FactoryCell(const FactoryCell &other) = delete;
        FactoryCell(FactoryCell &&other);

        void addStandard(const CellId& id, const Cell &cell);
        Cell *create(const CellId &id) const;

        FactoryCell &operator=(const FactoryCell &other) = delete;
        FactoryCell &operator=(FactoryCell &&other);

        virtual ~FactoryCell();
};

#endif // Factory_CELL_HPP