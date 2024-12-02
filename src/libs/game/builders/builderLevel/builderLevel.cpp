#include "builderLevel.hpp"

BuilderLevel *BuilderLevel::getInstance()
{
    if (instance_ == nullptr) instance_ = new BuilderLevel();
    return instance_;
}

BuilderLevel *BuilderLevel::deleteInstance()
{
    delete instance_;
    instance_ = nullptr;
    return instance_;
}

void BuilderLevel::init()
{
    if (isInitialized()) throw std::runtime_error("The object was initialized!");
    level_ = new Level();
}

void BuilderLevel::setMap(LevelMap *map)
{
    if (!isInitialized()) throw std::runtime_error("The object was not initialized!");
    level_->levelMap = map;
    isMapReady_ = true;
}

// void setEntitys()...
Level *BuilderLevel::build()
{
    bool done = isInitialized() && isMapReady();
    if (!done) throw std::runtime_error("The creation of the object was not completed!");
    Level *tmp = level_;
    level_ = nullptr;
    isMapReady_ = false;
    return tmp;
}

bool BuilderLevel::isInitialized() const
{
    return level_ != nullptr;
}

bool BuilderLevel::isMapReady() const
{
    return isMapReady_;
}