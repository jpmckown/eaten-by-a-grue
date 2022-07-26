cmake_minimum_required(VERSION 3.22)

project(eaten_by_a_grue CXX)

file(GLOB SRC_FILES
    "*.cxx"
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

target_include_directories(eaten_by_a_grue PUBLIC "${PROJECT_BINARY_DIR}")