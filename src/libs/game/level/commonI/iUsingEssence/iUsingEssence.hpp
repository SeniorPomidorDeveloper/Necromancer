#ifndef I_USING_ESSENCE_HPP
#define I_USING_ESSENCE_HPP

#include <cstddef>

typedef size_t Essence;

class IUsingEssence
{
    public:
        virtual bool giveEssence(IUsingEssence *user) = 0;
        virtual Essence addEssence(const Essence &essence) = 0;
        virtual void setEssence(const Essence &essence) = 0;
        virtual Essence getEssence() = 0;
        virtual bool isEssenceEmpty() = 0;
        virtual bool isEssenceFull() = 0;
};

#endif // I_USING_ESSENCE_HPP