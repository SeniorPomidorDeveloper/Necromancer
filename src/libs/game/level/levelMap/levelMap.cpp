#include "levelMap.hpp"

LevelMap::LevelMap(const size_t width, const size_t height)
{
    setSize(width, height);
}

void LevelMap::setSize(const size_t width, const size_t height)
{
    cells_.resize(width, height);
}

std::pair<size_t, size_t> LevelMap::getSize() const
{
    return cells_.get_size();
}

void LevelMap::setCell(const size_t x, const size_t y, const Cell &cell)
{
    cells_(x, y) = cell.getClone();
}

Cell *LevelMap::getCell(const size_t x, const size_t y)
{
    return cells_(x, y);
}

LevelMap::~LevelMap() noexcept
{
    std::for_each(cells_.begin(), cells_.end(), [](Cell *&cell)
    {
        delete cell;
    });
}