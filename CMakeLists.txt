cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(NoMirror VERSION 1.0.0)

include(cmake/CPM.cmake)
include(cmake/get_cpm.cmake)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/GUI.cpp
    src/Keys.h
    src/GUI.h
    # Add any extra C++ source files here
)


set(IMGUI_VERSION "v1.91.5")
CPMAddPackage("gh:matcool/gd-imgui-cocos#0207a36")

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

include(cmake/nhjson.cmake)
include(cmake/discord-rpc.cmake)
include(cmake/gdr.cmake)

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

target_link_libraries(${PROJECT_NAME} imgui-cocos)

setup_geode_mod(${PROJECT_NAME})

