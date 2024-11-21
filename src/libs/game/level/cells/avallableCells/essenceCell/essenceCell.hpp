#ifndef ESSENCE_CELL_HPP
#define ESSENCE_CELL_HPP

#include "../avallableCell/avallableCell.hpp"
#include "iUsingEssence.hpp"

class EssenceCell : public AvallableCell, IUsingEssence
{
    private:
        Essence essence_;

    public:
        EssenceCell(const Id &room, const Essence &essence);
        bool giveEssence(IUsingEssence *user) override;
        Essence addEssence(const Essence &essence) override;
        void setEssence(const Essence &essence) override;
        Essence getEssence() override;
        bool isEssenceEmpty() override;
        bool isEssenceFull() override;
};

#endif // ESSENCE_CELL_HPP