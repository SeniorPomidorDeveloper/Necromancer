#ifndef MAP_LOADER_HPP
#define MAP_LOADER_HPP

#include <string>

#include "rapidjson/document.h"

#include "loaders/iLoader/iLoader.hpp"
#include "level/levelMap/levelMap.hpp"


class MapLoader : public ILoader<LevelMap *>
{
    protected:
        virtual std::pair<size_t, size_t> loadSize(const rapidjson::Document &doc) const;
        virtual void loadCells(const rapidjson::Document &doc, Matrix<size_t> &cells) const;
        virtual void loadRooms(const rapidjson::Document &doc,  Matrix<size_t> &rooms) const;

    public:
        MapLoader() = default;
        MapLoader(const MapLoader &other) = delete;
        MapLoader(MapLoader &&other) = delete;

        LevelMap *load(const std::filesystem::path &filePath) const override;

        MapLoader &operator=(const MapLoader &other) = delete;
        MapLoader &operator=(MapLoader &&other) = delete;

        virtual ~MapLoader() = default;
};

#endif // MAP_LOADER_HPP