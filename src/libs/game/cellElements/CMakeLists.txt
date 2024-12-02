add_subdirectory(cellElement)
add_subdirectory(entitys)

add_library(cellElementsM INTERFACE)

target_link_libraries(cellElementsM INTERFACE entityM cellElementM)