add_subdirectory(levelMap)
add_subdirectory(groups)

add_library(levelM level.cpp)

target_link_libraries(levelM levelMapM groupsM)