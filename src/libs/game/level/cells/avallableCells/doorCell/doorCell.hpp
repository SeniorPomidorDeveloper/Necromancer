#ifndef DOOR_CELL_HPP
#define DOOR_CELL_HPP

#include "../../cell/cell.hpp"
#include "../iAvallableCell/iAvallableCell.hpp"

class DoorCell : public Cell, IAvallableCell
{
    private:
        CellElement *slot_ = nullptr;
        bool opened_ = false;
    
    public:
        DoorCell(const Id &room, const bool isOpened = false);

        Type getType() const override final;

        bool isFree() const override;
        virtual void open();
        virtual void close();
        virtual bool isOpened();

        Cell *getClone() const override;

        bool isEmpty() const override;

        bool setSlot(CellElement *slot) override;
        CellElement *getSlot() override;
        CellElement *popSlot() override;
};

#endif // DOOR_CELL_HPP