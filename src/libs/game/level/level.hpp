#ifndef LEVEL_HPP
#define LEVEL_HPP


#include <map>

#include "levelMap/levelMap.hpp"
#include "groups/cellGroups/cellGroups.hpp"

class BuilderLevel;

class Level final
{
    private:
        LevelMap *levelMap = nullptr;
        static inline CellGroups *cells = CellGroups::getInstance();
        
    public:
        friend class BuilderLevel;

        Level() = default;
        Level(const Level &other) = delete;
        Level(Level &&other) = delete;

        LevelMap &getMap();

        Level &operator=(const Level &other) = delete;
        Level &operator=(Level &&other) = delete;

        ~Level();
};

#endif // LEVEL_HPP