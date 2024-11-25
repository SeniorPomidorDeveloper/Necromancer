add_subdirectory(builderLevelMap)

add_library(buildersM INTERFACE)

target_link_libraries(buildersM INTERFACE builderLevelMapM)