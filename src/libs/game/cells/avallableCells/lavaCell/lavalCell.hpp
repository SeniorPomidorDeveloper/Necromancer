#ifndef LAVA_CELL_HPP
#define LAVA_CELL_HPP

#include "../avallableCell/avallableCell.hpp"
#include "commonI/iAttacker/iAttacker.hpp"

class LavaCell : public AvallableCell, IAttacker
{
    private:
        Damage damage_;
        bool giveDamage(IUsingHealth *enemy) override;

    public:
        LavaCell(const Id& root, const Damage &damage = 0);
        void setDamage(const Damage &damage) override;
        bool giveDamage();
        const Damage *getDamage() override;
        Cell *getClone() const override;
};

#endif // LAVA_CELL_HPP