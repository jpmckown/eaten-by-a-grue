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

# This insures that SDL2 output libraries are copied to the build output folder too
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(eaten_by_a_grue ${SRC_FILES})

target_include_directories(eaten_by_a_grue PUBLIC "${PROJECT_BINARY_DIR}")

# Fetch SDL and make it available to the project
include(FetchContent)
FetchContent_Declare(SDL URL https://github.com/libsdl-org/SDL/releases/download/release-2.24.0/SDL2-2.24.0.zip)
FetchContent_MakeAvailable(SDL)

# Set the include directories to find SDL.h
include_directories(${SDL2_INCLUDE_DIRS})

# Add the libraries to the project (through much pain discovered that not only is SDL2 needed but SDL2main as well)
# It appears that including different aspects of SDL requires adding the libraries for them as well.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2main)
