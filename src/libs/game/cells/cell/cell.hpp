#ifndef CELL_HPP
#define CELL_HPP

#include <cstddef>
#include <set>
#include <string>

typedef size_t RoomId;
typedef size_t CellId;

class Cell
{
    private:
        RoomId room_;
        static inline CellId nextId_ = 0;
        CellId id_;
    
    public:
        Cell(const RoomId &room);

        void setRoom(const RoomId &room);
        RoomId getRoom() const;

        virtual std::set<std::string> getTags() const = 0;
        CellId getId() const;

        virtual Cell *getClone() const = 0;

        virtual bool isEmpty() const = 0;

        virtual ~Cell();
};

#endif // CELL_HPP