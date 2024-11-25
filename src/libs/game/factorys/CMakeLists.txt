add_subdirectory(factoryCell)

add_library(factorysM INTERFACE)

target_link_libraries(factorysM INTERFACE factoryCellM)