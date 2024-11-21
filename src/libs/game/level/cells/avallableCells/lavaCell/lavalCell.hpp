#ifndef LAVA_CELL_HPP
#define LAVA_CELL_HPP

#include "avallableCell/avallableCell.hpp"
#include "iAttacker.hpp"

class LavaCell : public AvallableCell, IAttacker
{
    private:
        Damage damage_;

    public:
        LavaCell(const Id& root, const Damage &damage = 0);
        bool giveDamage(IUsingHealth *enemy) override;
        void setDamage(const Damage &damage) override;
        const Damage *getDamage() override;
};

#endif // LAVA_CELL_HPP