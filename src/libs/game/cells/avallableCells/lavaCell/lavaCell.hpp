#ifndef LAVA_CELL_HPP
#define LAVA_CELL_HPP

#include "cells/avallableCells/avallableCell/avallableCell.hpp"
#include "cells/avallableCells/iAttackerSlotCell/iAttackerSlotCell.hpp"

class LavaCell : public AvallableCell, IAttackerSlotCell
{
    private:
        Damage damage_;

    public:
        LavaCell(const RoomId& root, const Damage &damage = 0);
        LavaCell(const LavaCell &other) = delete;
        LavaCell(LavaCell &&other) = delete;

        std::set<std::string> getTags() const override;

        void setDamage(const Damage &damage) override;
        bool giveDamage() override;
        const Damage *getDamage() override;
        Cell *getClone() const override;

        LavaCell &operator=(const LavaCell &other) = delete;
        LavaCell &operator=(LavaCell &&other) = delete;
};

#endif // LAVA_CELL_HPP