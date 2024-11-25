add_subdirectory(iUsingHealth)

add_library(commonIM INTERFACE)

target_link_libraries(commonIM INTERFACE healthM)