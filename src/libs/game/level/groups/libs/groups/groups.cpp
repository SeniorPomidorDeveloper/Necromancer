#include "groups.hpp"

#include <algorithm>
#include <stdexcept>

#include "group/group.cpp"

template <typename Id, typename T>
void Groups<Id, T>::add(const Id &id, const T &value)
{
    if (!groups_.contains(id)) groups_[id] = Group<T>();
    groups_[id].add(value);
}

template <typename Id, typename T>
void Groups<Id, T>::remove(const T &value)
{
    std::for_each(groups_.begin(), groups_.end(), [&value](std::pair<Id, Group<T>> group) 
    { 
        group.second.remove(value); 
    });
}

template <typename Id, typename T>
bool Groups<Id, T>::contains(const Id &id, const T &value)
{
    if (!groups_.contains(id)) return false;
    return groups_[id].contains(value);
}

template <typename Id, typename T>
void Groups<Id, T>::clear()
{
    std::for_each(groups_.begin(), groups_.end(), [](std::pair<Id, Group<T>> group) 
    { 
        group.second.clear(); 
    });
}


template <typename Id, typename T>
std::set<T> &Groups<Id, T>::operator[](const Id &id)
{
    if (!groups_.contains(id)) groups_[id] = Group<T>();
    return groups_[id].getGroup();
}

template <typename Id, typename T>
const std::set<T> &Groups<Id, T>::operator[](const Id &id) const
{
    if (!groups_.contains(id)) throw std::runtime_error("Group not found");
    return groups_.at(id).getGroup();
}