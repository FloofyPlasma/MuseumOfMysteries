cmake_minimum_required(VERSION 3.10)

project(MuseumOfMysteries VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER "clang")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} include)
link_directories(${SDL2_LIBRARIES})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

link_directories(/opt/homebrew/lib)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image c++)
