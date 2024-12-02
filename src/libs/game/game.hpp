#ifndef GAME_HPP
#define GAME_HPP

#include <map>

#include "factorys/factoryCell/factoryCell.hpp"
#include "managers/managerAllCells/managerAllCells.hpp"
#include "builders/builderLevelMap/builderLevelMap.hpp"
#include "builders/builderLevel/builderLevel.hpp"

class Game
{
    private:
        static inline Game *instance_ = nullptr;

        Game() = default;
    
    public:
        static inline FactoryCell *factoryCell = FactoryCell::getInstance();
        static inline BuilderLevelMap *builderMap = BuilderLevelMap::getInstance();
        static inline BuilderLevel *builderLevel = BuilderLevel::getInstance();
        static inline ManagerAllCells *managerCells = ManagerAllCells::getInstance();
        static inline Level *level = nullptr;

        Game(const Game &other) = delete;
        Game(Game &&other) = delete;

        static Game *getInstance();
        Game *deleteInstance();

        void makeMove();

        Game &operator=(const Game &other) = delete;
        Game &operator=(Game &&other) = delete;
};

#endif // GAME_HPP