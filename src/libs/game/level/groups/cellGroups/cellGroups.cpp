#include "cellGroups.hpp"

CellGroups *CellGroups::getInstance()
{
    if (instance_ == nullptr) instance_ = new CellGroups();
    return instance_;
}

CellGroups *CellGroups::deleteInstance()
{
    delete instance_;
    instance_ = nullptr;
    return instance_;
}