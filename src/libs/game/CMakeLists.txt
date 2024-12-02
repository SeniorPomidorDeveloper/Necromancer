cmake_minimum_required(VERSION 3.28)

project(level CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment")
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
add_subdirectory(managers)

add_subdirectory(loaders)

add_library(gameM game.cpp)

# target_link_libraries(run buildersM managersM factorysM gameM levelM cellsM commonIM)
# target_link_libraries(run managersM)

# # target_link_libraries(run buildersM factorysM levelM cellsM cellElementsM commonIM)
target_link_libraries(run gameM managersM buildersM factorysM cellsM cellElementsM commonIM levelM loadersM)