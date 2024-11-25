#ifndef BUILDER_LEVEL_MAP_HPP
#define BUILDER_LEVEL_MAP_HPP

#include "builders/iBuilder/iBuilder.hpp"
#include "factorys/factoryCell/factoryCell.hpp"
#include "levelMap/levelMap.hpp"


class BuilderLevelMap : public IBuilder<LevelMap>
{
    private:
        FactoryCell factoryCell_;
        LevelMap *map_ = nullptr;

    public:
        BuilderLevelMap(FactoryCell &&factoryCell);
        BuilderLevelMap(const BuilderLevelMap &other) = delete;
        BuilderLevelMap(BuilderLevelMap &&other) = delete ;
        
        void init() override;
        void setCells(const Matrix<CellId> &cells);
        LevelMap *build() override;

        BuilderLevelMap &operator=(const BuilderLevelMap &other) = delete;
        BuilderLevelMap &operator=(BuilderLevelMap &&other) = delete;

        virtual ~BuilderLevelMap() = default;
};

#endif // BUILDER_LEVEL_MAP_HPP