#include "builderLevelMap.hpp"

#include "level/groups/cellGroups/cellGroups.hpp"

void BuilderLevelMap::init()
{
    if (isInitialized()) std::runtime_error("The object has already been initialized before!");
    map_ = new LevelMap(1, 1);
}

BuilderLevelMap *BuilderLevelMap::getInstance()
{
    if (instance_ == nullptr) instance_ = new BuilderLevelMap;
    return instance_;
}

BuilderLevelMap *BuilderLevelMap::deleteInstance()
{
    delete instance_;
    instance_ = nullptr;
    return nullptr;
}

void BuilderLevelMap::setCells(const Matrix<CellId> &cells)
{
    if (!isInitialized()) throw std::runtime_error("The object was not initialized!");
    std::pair<size_t, size_t> size = cells.get_size();
    size_t xSize = size.first;
    size_t ySize = size.second; 
    if (map_->getSize() != size) map_->setSize(xSize, ySize);
    Matrix<Cell *>::iterator it = map_->begin();
    CellGroups *groups = CellGroups::getInstance();
    std::for_each(cells.cbegin(), cells.cend(), [&it, &groups, this](const CellId &id)
    {
        *it = FactoryCell::getInstance()->create(id);
        groups->add(id, *it);
        ++it;
    });
    isCellsReady_ = true;
}

void BuilderLevelMap::setRooms(const Matrix<RoomId> &rooms)
{
    if (!isInitialized() || !areCellsReady()) throw std::runtime_error("The cells were not created!");
    std::pair<size_t, size_t> size = rooms.get_size();
    if (map_->getSize() != size) throw std::invalid_argument("The matrix and the map have different sizes!");
    Matrix<Cell *>::iterator it = map_->begin();
    std::for_each(rooms.cbegin(), rooms.cend(), [&it, this](const RoomId &id)
    {
        (*it)->setRoom(id);
        ++it;
    });
    isRoomsReady_ = true;
}

LevelMap *BuilderLevelMap::build()
{
    bool done = isInitialized() && areCellsReady() && areRoomsReady();
    if (!done) throw std::runtime_error("The creation of the object was not completed!");
    LevelMap *tmp = map_;
    map_ = nullptr;
    isCellsReady_ = false;
    isRoomsReady_ = false;
    return tmp;
}

bool BuilderLevelMap::isInitialized() const
{
    return map_ != nullptr;
}

bool BuilderLevelMap::areCellsReady() const
{
    return isCellsReady_;
}

bool BuilderLevelMap::areRoomsReady() const
{
    return isRoomsReady_;
}