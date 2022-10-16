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

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(eaten_by_a_grue ${SRC_FILES})

target_include_directories(eaten_by_a_grue PUBLIC "${PROJECT_BINARY_DIR}")

include(FetchContent)
FetchContent_Declare(SDL URL https://github.com/libsdl-org/SDL/releases/download/release-2.24.0/SDL2-2.24.0.zip)
FetchContent_MakeAvailable(SDL)

include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2main)
