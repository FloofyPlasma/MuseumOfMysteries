cmake_minimum_required(VERSION 3.14)
project(MuseumOfMysteries)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add SDL2 and SDL_image from the lib folder
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/lib/SDL2")
set(SDL_IMAGE_DIR "${CMAKE_SOURCE_DIR}/lib/SDL_image")

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set up SDL2
add_subdirectory(${SDL2_DIR} SDL2-build EXCLUDE_FROM_ALL)
include_directories(${SDL2_DIR}/include)

# Set up SDL_image
add_subdirectory(${SDL_IMAGE_DIR} SDL_image-build EXCLUDE_FROM_ALL)
include_directories(${SDL_IMAGE_DIR})

# Find all source files in the src folder
file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.c")

# Define the executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Link SDL2 and SDL_image
target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main SDL2_image)

# Hacks to fix VS?
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")

# Hack to copy the dlls on windowss
if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/SDL2-build/Debug/SDL2d.dll,${CMAKE_BINARY_DIR}/SDL2-build/Release/SDL2d.dll>"  # Adjust path if necessary
            "$<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/SDL_image-build/Debug/SDL2_imaged.dll,${CMAKE_BINARY_DIR}/SDL_image-build/Release/SDL2_imaged.dll>"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif (WIN32)