cmake_minimum_required ( VERSION 3.0.0 )
project ( Template )

set( COMMON_PATH "${PROJECT_SOURCE_DIR}/../../common" CACHE STRING "" )


# namespace used for project
set ( PROJECT_NAMESPACE template )

# The version number.
set ( PROJECT_VERSION_MAJOR 1 )
set ( PROJECT_VERSION_MINOR 0 )
set ( PROJECT_VERSION_PATCH 0 )

# required before DefaultProjectLibrary.cmake
set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )

set( PROJECT_CONFIG_FILE ${SRC_DIR}/ProjectConfig.hpp.in )

find_package     ( PkgConfig REQUIRED  )
pkg_search_module( GLFW REQUIRED glfw3 )

find_library( GLAD_LIB   glad   ${CMAKE_INSTALL_PREFIX}/lib )
find_library( COMMON_LIB Common ${CMAKE_INSTALL_PREFIX}/lib )

# system header dirs
set(
    PROJECT_SYSTEM_INCLUDE_DIRS
    ${GLFW_INCLUDE_DIRS}
    ${CMAKE_INSTALL_PREFIX}/include
    )

# libraries to link against
set(
    PROJECT_LINK_LIBS
    ${GLFW_LIBRARIES}
    ${GLAD_LIB}
    ${COMMON_LIB}
    )

# header dirs
set(
    PROJECT_INCLUDE_DIRS
    ${SRC_DIR}
    )

# cpp files
set(
    PROJECT_SOURCE
    ${SRC_DIR}/TemplateWorld.cpp
    ${SRC_DIR}/TemplateIOHandler.cpp
    )

# file with main function
set( PROJECT_MAIN ${SRC_DIR}/TemplateMain.cpp )

include( ${COMMON_PATH}/cmake/DefaultProjectLibrary.cmake )

