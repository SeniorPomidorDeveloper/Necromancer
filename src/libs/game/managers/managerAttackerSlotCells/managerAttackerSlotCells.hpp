#ifndef MANAGER_LAVA_CELLS_HPP
#define MANAGER_LAVA_CELLS_HPP

#include <set>

#include "managers/iManagerCells/iManagerCells.hpp"

class ManagerAttackerSlotCells : public IManagerCells
{
    private:
        static inline ManagerAttackerSlotCells *instance_ = nullptr;

        ManagerAttackerSlotCells() = default;

    public:
        ManagerAttackerSlotCells(const ManagerAttackerSlotCells &other) = delete;
        ManagerAttackerSlotCells(ManagerAttackerSlotCells &&other) = delete;

        static ManagerAttackerSlotCells *getInstance();
        void deletInstance();

        void manage() const override;

        std::string getTag() const override;

        ManagerAttackerSlotCells &operator=(const ManagerAttackerSlotCells &other) = delete;
        ManagerAttackerSlotCells &operator=(ManagerAttackerSlotCells &&other) = delete;
        
        virtual ~ManagerAttackerSlotCells() = default;
};

#endif // MANAGER_LAVA_CELLS_HPP