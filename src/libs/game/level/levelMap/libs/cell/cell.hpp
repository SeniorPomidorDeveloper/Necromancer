#ifndef CELL_HPP
#define CELL_HPP

#include <cstddef>

typedef size_t Id;

export class Cell
{
    private:
        Id room_;
    
    public:
        Cell(const Id &room);
        virtual Cell *getClone() const;
        
        void setRoom(const Id &room);
        Id getRoom() const;

        virtual bool isEmpty() const;
};

#endif // CELL_HPP