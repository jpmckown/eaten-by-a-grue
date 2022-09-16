cmake_minimum_required(VERSION 3.22)

project(eaten_by_a_grue CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SRC_FILES
    "*.cxx"
    "mainUI/*.cxx"
    "mainUI/*.h"
    "dummys/*.cxx"
    "dummys/*.h"
    "mechanics/*.cxx"
    "mechanics/*.h"
    "places/*.cxx"
    "places/*.h"
    "things/*.cxx"
    "things/*.h"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(eaten_by_a_grue ${SRC_FILES})
target_link_libraries(eaten_by_a_grue ${SDL2_LIBRARIES})
target_include_directories(eaten_by_a_grue PUBLIC "${PROJECT_BINARY_DIR}")