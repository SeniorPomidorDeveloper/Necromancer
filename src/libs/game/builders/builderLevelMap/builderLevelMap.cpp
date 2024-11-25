#include "builderLevelMap.hpp"

BuilderLevelMap::BuilderLevelMap(FactoryCell &&factoryCell)
{
    factoryCell_ = std::move(factoryCell);
}

void BuilderLevelMap::init()
{
    if (map_ != nullptr) std::runtime_error("The object has already been initialized before!");
    map_ = new LevelMap(1, 1);
}

void BuilderLevelMap::setCells(const Matrix<CellId> &cells)
{
    if (map_ == nullptr) throw std::runtime_error("The object was not initialized!");
    std::pair<size_t, size_t> size = cells.get_size();
    size_t xSize = size.first;
    size_t ySize = size.second; 
    if (map_->getSize() != size) map_->setSize(xSize, ySize);
    size_t x = 0;
    size_t y = 0;
    std::for_each(cells.cbegin(), cells.cend(), [&x, &y, &xSize, &ySize, this](const CellId &id)
    {
        map_->setCell(x++, y, factoryCell_.create(id));
        if (x == xSize) ++y;
        x %= xSize;
    });
}

LevelMap *BuilderLevelMap::build()
{
    if (map_ == nullptr) throw std::runtime_error("The object was not initialized!");
    LevelMap *tmp = map_;
    map_ = nullptr;
    return tmp;
}