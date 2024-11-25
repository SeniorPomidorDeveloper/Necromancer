#ifndef I_AVALLABLE_CELL_HPP
#define I_AVALLABLE_CELL_HPP

#include "cellElements/cellElement/cellElement.hpp"

class IAvallableCell
{
    public:
        virtual bool setSlot(CellElement *slot) = 0;
        virtual CellElement &getSlot() = 0;
        virtual CellElement *popSlot() = 0;
        virtual bool isFree() const = 0;
};

#endif // I_AVALLABLE_CELL_HPP