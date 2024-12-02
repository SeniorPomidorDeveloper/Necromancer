#ifndef MANAGER_ALL_CELLS_HPP
#define MANAGER_ALL_CELLS_HPP

#include <memory>

#include "factorys/factoryCell/factoryCell.hpp"
#include "managers/iManagerCells/iManagerCells.hpp"


class ManagerAllCells: IManager<Cell>
{
    private:
        static inline ManagerAllCells *instance_ = nullptr;

        std::set<IManagerCells *> groups_;

        ManagerAllCells() = default;

    public:
        ManagerAllCells(const ManagerAllCells &other) = delete;
        ManagerAllCells(ManagerAllCells &&other) = delete;

        static ManagerAllCells *getInstance();
        ManagerAllCells *deleteInstance();

        void addManager(IManagerCells *manager);

        void manage() const override;

        ManagerAllCells &operator=(const ManagerAllCells &other) = delete;
        ManagerAllCells &operator=(ManagerAllCells &&other) = delete;
        
        virtual ~ManagerAllCells() = default;
};

#endif // MANAGER_ALL_CELLS_HPP