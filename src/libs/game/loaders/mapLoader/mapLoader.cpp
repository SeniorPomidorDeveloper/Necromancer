#include "mapLoader.hpp"

#include <vector>
#include <fstream>
#include <cstdio>

#include "builders/builderLevelMap/builderLevelMap.hpp"
#include "rapidjson/filereadstream.h"

void fillMatrixSize_t(const rapidjson::Value &doc, Matrix<size_t> &matrix)
{
    if (!doc.IsArray()) throw std::runtime_error("The file format does not comply with the standard!");
    rapidjson::GenericValue<rapidjson::UTF8<char>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>::ConstArray cells = doc.GetArray();
    std::pair<size_t, size_t> size = matrix.get_size();
    if (cells.Size() != size.second) throw std::runtime_error("The file format does not comply with the standard!");
    if (cells[0].Size() != size.first) throw std::runtime_error("The file format does not comply with the standard!");
    Matrix<size_t>::iterator matIt = matrix.begin();
    std::for_each(cells.begin(), cells.end(), [&matIt, &size](const rapidjson::Value &it)
    {
        std::for_each(it.Begin(), it.End(), [&matIt](const rapidjson::Value &it2)
        {
            *matIt = it2.GetUint64();
            ++matIt;
        });
    });
}

std::pair<size_t, size_t> MapLoader::loadSize(const rapidjson::Document &doc) const
{
    if (!doc.HasMember("size")) throw std::runtime_error("The file format does not comply with the standard!");
    return std::pair<size_t, size_t>(doc["size"].GetObject()["width"].GetUint64(), doc["size"].GetObject()["height"].GetUint64());
}

void MapLoader::loadCells(const rapidjson::Document &doc, Matrix<size_t> &cells) const
{
    fillMatrixSize_t(doc["cells"], cells);
    BuilderLevelMap::getInstance()->setCells(cells);
}

void MapLoader::loadRooms(const rapidjson::Document &doc, Matrix<size_t> &rooms) const
{
    fillMatrixSize_t(doc["rooms"], rooms);
    BuilderLevelMap::getInstance()->setRooms(rooms);
}

LevelMap *MapLoader::load(const std::filesystem::path &filePath) const
{
    if (!std::filesystem::exists(filePath)) throw std::runtime_error("The file \"" + filePath.string() + "\"does not exist!");
    if (!std::filesystem::is_regular_file(filePath)) throw std::runtime_error("\"" + filePath.string() + "\" is not a regular file!");
    FILE* file = std::fopen(filePath.c_str(), "rb");
    if (file == nullptr) throw std::runtime_error("The file was not opened!");
    char readBuffer[65536];
    rapidjson::FileReadStream is(file, readBuffer, sizeof(readBuffer));

    rapidjson::Document doc;
    doc.ParseStream(is);

    std::pair<size_t, size_t> size = loadSize(doc);
    Matrix<size_t> mat(size.first, size.second);

    BuilderLevelMap::getInstance()->init();
    loadCells(doc, mat);
    loadRooms(doc, mat);

    std::fclose(file);
    return BuilderLevelMap::getInstance()->build();
}