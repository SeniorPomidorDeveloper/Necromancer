#ifndef CELL_ELEMENT_HPP
#define CELL_ELEMENT_HPP

#include <utility>
#include <cstddef>

typedef std::pair<size_t, size_t> Position;

class CellElement
{
    private:
        Position position_;
        static inline size_t maxId_ = 0;
        size_t Id_;

    public:
        CellElement(const Position& position);
        void setPosition(const Position& position);
        Position getPosition() const;
        const Position &getConstPosition() const;

        virtual bool canTakeDamage() const;
        size_t getId() const;

        virtual ~CellElement() = default;
};

#endif // CELL_ELEMENT_HPP