#ifndef WALL_CELL_HPP
#define WALL_CELL_HPP

#include "cells/cell/cell.hpp"

class WallCell : public Cell
{
    public:
        WallCell(const RoomId &room);

        std::set<std::string> getTags() const override;

        Cell *getClone() const override;

        bool isEmpty() const override final;
};

#endif // WALL_CELL_HPP