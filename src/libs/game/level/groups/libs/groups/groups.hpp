#ifndef GROUPS_HPP
#define GROUPS_HPP

#include <map>

#include "group/group.hpp"

template <typename Id, typename T>
class Groups
{
    private:
        std::map<Id, Group<T>> groups_;

    public:
        Groups() = default;

        virtual void add(const Id &id, const T &value);
        virtual void remove(const T &value);
        virtual bool contains(const Id &id, const T &value);

        virtual std::set<T> &operator[](const Id &id);
        virtual const std::set<T> &operator[](const Id &id) const;

        virtual void clear();

        virtual ~Groups() = default;
};

#endif // GROUPS_HPP