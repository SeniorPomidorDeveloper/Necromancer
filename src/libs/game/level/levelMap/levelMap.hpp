#ifndef LEVEL_MAP_HPP
#define LEVEL_MAP_HPP

#include "libs/matrix/paths.hpp"
#include "cells/paths.hpp"

class LevelMap final
{
    private:
        Matrix<Cell *> cells_ = Matrix<Cell *>(1, 1, nullptr);
    
    public:
        LevelMap(const size_t width, const size_t height);

        void setSize(const size_t width, const size_t height);
        std::pair<size_t, size_t> getSize() const ;

        void setCell(const size_t x, const size_t y, Cell *cell);
        Cell *getCell(const size_t x, const size_t y);

        ~LevelMap() noexcept;
};

#endif // LEVEL_MAP_HPP