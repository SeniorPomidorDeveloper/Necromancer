#include "levelMap.hpp"

LevelMap::LevelMap(const size_t width, const size_t height)
{
    if (width != 1 && height != 1) setSize(width, height);
}

void LevelMap::setSize(const size_t width, const size_t height)
{
    cells_.resize(width, height);
}

std::pair<size_t, size_t> LevelMap::getSize() const
{
    return cells_.get_size();
}

void LevelMap::setCell(const size_t x, const size_t y, Cell *cell)
{
    cells_(x, y) = cell;
}

Cell *LevelMap::getCell(const size_t x, const size_t y)
{
    return cells_(x, y);
}

Matrix<Cell *>::iterator LevelMap::begin()
{
    return cells_.begin();
}

Matrix<Cell *>::iterator LevelMap::end()
{
    return cells_.end();
}

LevelMap::~LevelMap() noexcept
{
    std::for_each(cells_.begin(), cells_.end(), [](Cell *&cell)
    {
        delete cell;
    });
}