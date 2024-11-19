#ifndef AVALLABLE_CELL_HPP
#define AVALLABLE_CELL_HPP

#include "../../cell/cell.hpp"
#include "../iAvallableCell/iAvallableCell.hpp"

class AvallableCell : public Cell, IAvallableCell
{
    private:
        CellElement *slot_;
        
    public:
        AvallableCell(const Id &room);

        bool setSlot(CellElement *slot) override;
        CellElement *getSlot() override;
        CellElement *popSlot() override;
        bool isFree() const override;

        Type getType() const override;
        Cell *getClone() const override;
        bool isEmpty() const override;
};

#endif // AVALLABLE_CELL_HPP