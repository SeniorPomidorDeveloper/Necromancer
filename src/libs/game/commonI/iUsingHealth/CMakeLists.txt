add_subdirectory(health)
add_subdirectory(damage)

add_library(iUsingHealthM INTERFACE)

target_link_libraries(iUsingHealthM INTERFACE healthM damageM)