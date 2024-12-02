#ifndef BUILDER_LEVEL_MAP_HPP
#define BUILDER_LEVEL_MAP_HPP

#include <map>

#include "builders/iBuilder/iBuilder.hpp"
#include "factorys/factoryCell/factoryCell.hpp"
#include "levelMap/levelMap.hpp"

class BuilderLevelMap : public IBuilder<LevelMap>
{
    private:
        static inline BuilderLevelMap *instance_ = nullptr;
        LevelMap *map_ = nullptr;
        Matrix<Cell *> *matrixMap_ = nullptr;

        bool isCellsReady_ = false;
        bool isRoomsReady_ = false;

        BuilderLevelMap() = default;

    public:
        static BuilderLevelMap *getInstance();
        BuilderLevelMap *deleteInstance();

        BuilderLevelMap(const BuilderLevelMap &other) = delete;
        BuilderLevelMap(BuilderLevelMap &&other) = delete ;
        
        void init() override;
        void setCells(const Matrix<CellId> &cells);
        void setRooms(const Matrix<RoomId> &rooms);
        LevelMap *build() override;

        bool isInitialized() const;
        bool areCellsReady() const;
        bool areRoomsReady() const;

        BuilderLevelMap &operator=(const BuilderLevelMap &other) = delete;
        BuilderLevelMap &operator=(BuilderLevelMap &&other) = delete;

        virtual ~BuilderLevelMap() = default;
};

#endif // BUILDER_LEVEL_MAP_HPP