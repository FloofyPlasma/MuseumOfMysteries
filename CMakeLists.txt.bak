cmake_minimum_required(VERSION 3.10)

project(MuseumOfMysteries VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL EXCLUDE_FROM_ALL)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL_image EXCLUDE_FROM_ALL)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)

include_directories(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL_image
)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_options(/DWIN32 /D_WINDOWS)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
endif()

enable_testing()

add_dependencies(${PROJECT_NAME} SDL2 SDL2_image)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2/build
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL_image/build
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)