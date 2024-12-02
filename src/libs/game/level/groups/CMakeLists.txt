add_subdirectory(cellGroups)

add_library(groupsM INTERFACE)

target_link_libraries(groupsM INTERFACE cellGroupsM)