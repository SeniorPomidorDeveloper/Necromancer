add_subdirectory(mapLoader)
add_subdirectory(levelLoader)

add_library(loadersM INTERFACE)

target_link_libraries(loadersM INTERFACE mapLoaderM levelLoaderM)