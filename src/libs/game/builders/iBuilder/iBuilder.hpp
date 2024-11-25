#ifndef I_BUILDER_HPP
#define I_BUILDER_HPP

template <typename T>
class IBuilder
{
    public:
        virtual void init() = 0;
        virtual T *build() = 0;
};

#endif // I_BUILDER_HPP