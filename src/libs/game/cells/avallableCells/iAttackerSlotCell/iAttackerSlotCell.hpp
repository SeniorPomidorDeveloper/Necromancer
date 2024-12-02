#ifndef I_ATTACKER_SLOT_CELL_HPP
#define I_ATTACKER_SLOT_CELL_HPP

#include "cells/avallableCells/avallableCell/avallableCell.hpp"
#include "commonI/iAttacker/iAttacker.hpp"

class IAttackerSlotCell : public IAttacker
{
    public:
        virtual bool giveDamage() = 0;
};

#endif // I_ATTACKER_SLOT_CELL_HPP