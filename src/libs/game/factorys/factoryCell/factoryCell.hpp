#ifndef Factory_CELL_HPP
#define Factory_CELL_HPP

#include <unordered_map>

#include "cells/cell/cell.hpp"

typedef size_t CellId;

class FactoryCell
{
    private:
        static inline FactoryCell *instance_ = nullptr;
        std::unordered_map<CellId, const Cell *> standards_;
        std::unordered_map<std::string, std::set<CellId>> tags_;

        FactoryCell() = default;
        
    public:
        static FactoryCell *getInstance();
        FactoryCell *deleteInstance();

        FactoryCell(const FactoryCell &other) = delete;
        FactoryCell(FactoryCell &&other) = delete;

        void addStandard(const CellId& id, const Cell &cell);
        Cell *create(const CellId &id) const;

        std::set<CellId> getIds(const std::string &tag) const;

        FactoryCell &operator=(const FactoryCell &other) = delete;
        FactoryCell &operator=(FactoryCell &&other) = delete;

        virtual ~FactoryCell();
};

#endif // Factory_CELL_HPP