cmake_minimum_required ( VERSION 3.0.0 )
project ( BaseProject )

set( temp common/ )

# namespace used for project
set ( PROJECT_NAMESPACE lbp )

# The version number.
set ( PROJECT_VERSION_MAJOR 1 )
set ( PROJECT_VERSION_MINOR 0 )
set ( PROJECT_VERSION_PATCH 0 )

# required before DefaultProjectLibrary.cmake
set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${temp}src )

set( PROJECT_CONFIG_FILE ${SRC_DIR}/ProjectConfig.hpp.in )

# header dirs
set(
    PROJECT_INCLUDE_DIRS
    ${SRC_DIR}
    )

# cpp files
set(
    PROJECT_SOURCE
    ${SRC_DIR}/Driver.cpp
    ${SRC_DIR}/Renderer.cpp
    ${SRC_DIR}/World.cpp
    )

# file with main function
set( PROJECT_MAIN ${SRC_DIR}/Main.cpp )

include( ${temp}cmake/DefaultProjectLibrary.cmake )

