#ifndef I_MANAGER_HPP
#define I_MANAGER_HPP

template <typename T>
class IManager
{
    public:
        virtual void manage() const = 0;
};

#endif // I_MANAGER_HPP