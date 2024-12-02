#ifndef AVALLABLE_CELL_HPP
#define AVALLABLE_CELL_HPP

#include "cells/cell/cell.hpp"
#include "cells/avallableCells/iAvallableCell/iAvallableCell.hpp"

class AvallableCell : public Cell, IAvallableCell
{
    protected:
        CellElement *slot_ = nullptr;
        
    public:
        AvallableCell(const RoomId &room);

        bool setSlot(CellElement *slot) override;
        CellElement &getSlot() override;
        CellElement *popSlot() override;
        bool isFree() const override;

        std::set<std::string> getTags() const override;
        Cell *getClone() const override;
        bool isEmpty() const override;
};

#endif // AVALLABLE_CELL_HPP