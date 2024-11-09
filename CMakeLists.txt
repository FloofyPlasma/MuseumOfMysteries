cmake_minimum_required(VERSION 3.14)
project(MuseumOfMysteries)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL2_DIR "${CMAKE_SOURCE_DIR}/lib/SDL2")
set(SDL_IMAGE_DIR "${CMAKE_SOURCE_DIR}/lib/SDL_image")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Generate compile_commands.json for platforms that support them
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set up SDL2
add_subdirectory(${SDL2_DIR} SDL2-build EXCLUDE_FROM_ALL)
include_directories(${SDL2_DIR}/include)

# Set up SDL_image
add_subdirectory(${SDL_IMAGE_DIR} SDL_image-build EXCLUDE_FROM_ALL)
include_directories(${SDL_IMAGE_DIR})

file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.c")

if(NOT WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin")
endif(NOT WIN32)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main SDL2_image)

# Copy the assets folder to the build folder
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/assets"
    "${CMAKE_BINARY_DIR}/dist/assets"
)

# Hacks for Windows specifically
if(WIN32)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin")

    add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/dist/bin"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/dist/bin"
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/SDL2-build/Debug/SDL2d.dll,${CMAKE_BINARY_DIR}/SDL2-build/Release/SDL2.dll>"
        "$<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/SDL_image-build/Debug/SDL2_imaged.dll,${CMAKE_BINARY_DIR}/SDL_image-build/Release/SDL2_image.dll>"
        "${CMAKE_BINARY_DIR}/dist/bin"

        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:${PROJECT_NAME}>" # Executable file
        "${CMAKE_BINARY_DIR}/dist/bin"
    )
endif(WIN32)
