#ifndef BUILDER_LEVEL_HPP
#define BUILDER_LEVEL_HPP

#include "level/level.hpp"
#include "builders/builderLevelMap/builderLevelMap.hpp"

class BuilderLevel : public IBuilder<Level>
{
    private:
        static inline BuilderLevel *instance_;
        Level *level_ = nullptr;
        bool isMapReady_ = false;

        BuilderLevel() = default;

    public:

        static BuilderLevel *getInstance();
        BuilderLevel *deleteInstance();

        BuilderLevel(const BuilderLevel &other) = delete;
        BuilderLevel(BuilderLevel &&other) = delete;

        BuilderLevel &operator=(const BuilderLevel &other) = delete;
        BuilderLevel &operator=(BuilderLevel &&other) = delete;

        void init() override;
        void setMap(LevelMap *map) ;
        // void setEntitys()...
        Level *build() override;

        bool isInitialized() const;
        bool isMapReady() const;

        virtual ~BuilderLevel() = default;
};

#endif // BUILDER_LEVEL_HPP