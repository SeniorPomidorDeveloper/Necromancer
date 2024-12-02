#ifndef I_LOADER_HPP
#define I_LOADER_HPP

#include <filesystem>

template <typename T>
class ILoader
{
    public:
        virtual T load(const std::filesystem::path &filePath) const = 0;
};

#endif // I_LOADER_HPP