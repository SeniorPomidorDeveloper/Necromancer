#ifndef CELL_HPP
#define CELL_HPP

#include <cstddef>
#include <unordered_set>
#include <string>

typedef size_t Id;;

class Cell
{
    private:
        Id room_;
    
    public:
        enum Type
        {
            Wall, Door, Avallable
        };

        Cell(const Id &room);

        void setRoom(const Id &room);
        Id getRoom() const;

        virtual Type getType() const = 0;

        virtual Cell *getClone() const = 0;

        virtual bool isEmpty() const = 0;

        virtual ~Cell();
};

#endif // CELL_HPP