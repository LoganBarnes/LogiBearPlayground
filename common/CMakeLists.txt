cmake_minimum_required ( VERSION 3.0.0 )
project ( LBPlayground )

# namespace used for project
set ( PROJECT_NAMESPACE lbp )

# The version number.
set ( PROJECT_VERSION_MAJOR 1 )
set ( PROJECT_VERSION_MINOR 0 )
set ( PROJECT_VERSION_PATCH 0 )

# required before DefaultProjectLibrary.cmake
set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )

set( PROJECT_CONFIG_FILE ${SRC_DIR}/ProjectConfig.hpp.in )

find_package( PkgConfig REQUIRED   )
pkg_search_module( GLFW REQUIRED glfw3 )

# system header dirs
set(
    PROJECT_SYSTEM_INCLUDE_DIRS
    ${GLFW_INCLUDE_DIRS}
    )

# libraries to link against
set(
    TARGET_LINK_LIBS
    ${GLFW_LIBRARIES}
    )

# header dirs
set(
    PROJECT_INCLUDE_DIRS
    ${SRC_DIR}
    )

# cpp files
set(
    PROJECT_SOURCE
    ${SRC_DIR}/Driver.cpp
    ${SRC_DIR}/IOHandler.cpp
    ${SRC_DIR}/World.cpp
    )

# file with main function
set( PROJECT_MAIN ${SRC_DIR}/ExampleMain.cpp )

include( cmake/DefaultProjectLibrary.cmake )

