#ifndef GROUP_HPP
#define GROUP_HPP

#include <set>

template <typename T>
class Group
{
    private:
        std::set<T> group_;

    public:
        Group() = default;

        virtual void add(const T &element);
        virtual void remove(const T &element);
        virtual bool contains(const T &element) const;

        std::set<T> &getGroup();
        const std::set<T> &getGroup() const;

        virtual void clear();

        virtual ~Group() = default;
};

#endif // GROUP_HPP