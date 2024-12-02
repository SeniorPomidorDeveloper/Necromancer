#include "managerAllCells.hpp"

ManagerAllCells *ManagerAllCells::getInstance()
{
    if (instance_ == nullptr) instance_ = new ManagerAllCells();
    return instance_;
}

ManagerAllCells *ManagerAllCells::deleteInstance()
{
    std::for_each(groups_.begin(), groups_.end(), [](IManagerCells *manager)
    {
        delete manager;
    });
    delete instance_;
    instance_ = nullptr;
    return instance_;
}

void ManagerAllCells::addManager(IManagerCells *manager)
{
    groups_.insert(manager);
}

void ManagerAllCells::manage() const
{
    std::for_each(groups_.begin(), groups_.end(), [](const IManagerCells *manager)
    {
        manager->manage();
    });
}