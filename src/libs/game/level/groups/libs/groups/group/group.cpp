#include "group.hpp"


template <typename T>
void Group<T>::add(const T &element)
{
    group_.insert(element);
}

template <typename T>
void Group<T>::remove(const T &element)
{
    group_.erase(element);
}

template <typename T>
bool Group<T>::contains(const T &element) const
{
    return group_.contains(element);
}

template <typename T>
void Group<T>::clear()
{
    group_.clear();
}

template <typename T>
std::set<T> &Group<T>::getGroup()
{
    return group_;
}

template <typename T>
const std::set<T> &Group<T>::getGroup() const
{
    return group_;
}