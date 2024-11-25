add_subdirectory(cell)
add_subdirectory(wallCell)
add_subdirectory(avallableCells)

add_library(cellsM INTERFACE)

target_link_libraries(cellsM INTERFACE cellM wallCellM avallableCellM)