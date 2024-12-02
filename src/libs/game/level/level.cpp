#include "level.hpp"

LevelMap &Level::getMap()
{
    if (levelMap == nullptr) throw std::runtime_error("The creation of the level has not been completed!");
    return *levelMap;
}

Level::~Level()
{
    delete levelMap;
    cells->clear();
}