#include "levelLoader.hpp"

#include "builders/builderLevel/builderLevel.hpp"


LevelLoader::LevelLoader(const std::filesystem::path &pathMapFile = "map.json", const std::filesystem::path &pathEntitysFile = "entitys.json") : pathMapFile_(pathMapFile), pathEntitysFile_(pathEntitysFile)
{
}

Level *LevelLoader::load(const std::filesystem::path &pathDir) const
{
    if (!std::filesystem::exists(pathDir)) throw std::runtime_error("\"" + pathDir.string() + "\" directory does not exist!");
    if (!std::filesystem::is_directory(pathDir)) throw std::runtime_error("\"" + pathDir.string() + "\" is not a derrickory!");
    LevelMap *map = mapLoader_.load(pathDir / pathMapFile_);
    // LevelMap *map = entitysLoader_.load(pathDir / pathEntitysFile_, map);
    BuilderLevel::getInstance()->init();
    BuilderLevel::getInstance()->setMap(map);
    return BuilderLevel::getInstance()->build();
}
