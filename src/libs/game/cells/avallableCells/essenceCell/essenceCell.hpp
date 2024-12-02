#ifndef ESSENCE_CELL_HPP
#define ESSENCE_CELL_HPP

#include "cells/avallableCells/avallableCell/avallableCell.hpp"
#include "commonI/iUsingEssence/iUsingEssence.hpp"

class EssenceCell : public AvallableCell, IUsingEssence
{
    private:
        Essence essence_;

    public:
        EssenceCell(const RoomId &room, const Essence &essence);

        std::set<std::string> getTags() const override;

        bool giveEssence(IUsingEssence *user) override;
        Essence addEssence(const Essence &essence) override;
        void setEssence(const Essence &essence) override;
        Essence getEssence() override;
        Essence spendEssence(const Essence &essence) override;
        bool isEssenceEmpty() override;
        bool isEssenceFull() override;
        Cell *getClone() const override;
};

#endif // ESSENCE_CELL_HPP