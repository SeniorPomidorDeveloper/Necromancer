add_subdirectory(cell)
add_subdirectory(wallCell)
add_subdirectory(avallableCells)

target_link_libraries(cellM wallCellM avallableCellM)