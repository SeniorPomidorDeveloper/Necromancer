#ifndef LEVEL_LOADER_HPP
#define LEVEL_LOADER_HPP

#include "loaders/mapLoader/mapLoader.hpp"
#include "level/level.hpp"

class LevelLoader : public ILoader<Level *>
{
    private:
        static inline MapLoader mapLoader_;
        // static inline EtitysLoader entitysLoader_;
        std::filesystem::path pathMapFile_ = "level";
        std::filesystem::path pathEntitysFile_ = "entitys.json";

    public:
        LevelLoader() = default;
        LevelLoader(const std::filesystem::path &pathMapFile, const std::filesystem::path &pathEntitysFile);
        LevelLoader(const LevelLoader &other) = delete;
        LevelLoader(LevelLoader &&other) = delete;

        Level *load(const std::filesystem::path &pathDir) const override;

        LevelLoader &operator=(const LevelLoader &other) = delete;
        LevelLoader &operator=(LevelLoader &&other) = delete;

        virtual ~LevelLoader() = default;
};

#endif // LEVEL_LOADER_HPP