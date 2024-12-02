#include "game.hpp"

Game *Game::getInstance()
{
    if(instance_ == nullptr) instance_ = new Game();
    return instance_;
}

Game *Game::deleteInstance()
{
    factoryCell = factoryCell->deleteInstance();
    builderMap = builderMap->deleteInstance();
    builderLevel = builderLevel->deleteInstance();
    managerCells = managerCells->deleteInstance();
    delete level;
    CellGroups::getInstance()->deleteInstance();
    level = nullptr;
    delete instance_;
    instance_ = nullptr;
    return instance_;
}

void Game::makeMove()
{
    managerCells->manage();
}