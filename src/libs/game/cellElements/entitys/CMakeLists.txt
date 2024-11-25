add_subdirectory(entity)

add_library(entitysM INTERFACE)

target_link_libraries(entitysM INTERFACE entityM)