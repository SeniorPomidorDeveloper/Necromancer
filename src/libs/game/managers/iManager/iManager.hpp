#ifndef I_MANAGER_HPP
#define I_MANAGER_HPP


template <typename T>
class IManager
{
    public:
        virtual void addToGroup(T *element);
        virtual void removeFromGroup(T *element);
        virtual void clearGroup();
        virtual void manage();
};

#endif // I_MANAGER_HPP