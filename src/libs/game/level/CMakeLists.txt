add_subdirectory(levelMap)

add_library(levelM INTERFACE)

target_link_libraries(levelM INTERFACE levelMapM)