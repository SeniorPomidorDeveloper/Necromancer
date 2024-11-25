cmake_minimum_required(VERSION 3.28)

project(level CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g -fsanitize=address")
set(CMAKE_POLICY_DEFAULT_CMP0069 NEW)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

add_executable(run test.cpp)

include_directories(./)
include_directories(level)

add_subdirectory(commonI)
add_subdirectory(cellElements)
add_subdirectory(cells)
add_subdirectory(level)

add_subdirectory(factorys)
add_subdirectory(builders)

target_link_libraries(run buildersM factorysM levelM cellsM cellElementsM commonIM)