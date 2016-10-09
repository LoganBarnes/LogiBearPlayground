cmake_minimum_required ( VERSION 3.0.0 )
project ( OPGraphics )

set( COMMON_PATH "${PROJECT_SOURCE_DIR}/../../common" CACHE STRING "" )


# namespace used for project
set ( PROJECT_NAMESPACE graphics )

# The version number.
set ( PROJECT_VERSION_MAJOR 1 )
set ( PROJECT_VERSION_MINOR 0 )
set ( PROJECT_VERSION_PATCH 0 )

# required before DefaultProjectLibrary.cmake
set( SRC_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/src        )
set( THIRDPARTY ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty )

set( PROJECT_CONFIG_FILE ${SRC_DIR}/ProjectConfig.hpp.in        )
set( DLL_DEFINES_FILE    ${SRC_DIR}/common/DLLDefines.hpp.in    )

#
# add glfw3 functionality
#
set( GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

# set( BUILD_SHARED_LIBS   ON  CACHE BOOL "" FORCE )

# if ( WIN32 )
  # set( USE_MSVC_RUNTIME_LIBRARY_DLL ON CACHE BOOL "" FORCE )
# endif()

add_subdirectory   ( ${THIRDPARTY}/glfw )
include_directories( SYSTEM )

find_library( VULKAN_LIB NAME vulkan-1
              PATHS "C:\\VulkanSDK\\1.0.26.0\\Bin32" )

#
# common drivers
#
find_library( COMMON_LIB Common
              PATHS ${CMAKE_INSTALL_PREFIX}
              PATH_SUFFIXES lib bin )

# system header dirs
set(
    PROJECT_SYSTEM_INCLUDE_DIRS
    ${THIRDPARTY}/glfw/include
    ${THIRDPARTY}/include
    ${CMAKE_INSTALL_PREFIX}/include
    )


# libraries to link against
set(
    PROJECT_LINK_LIBS
    glfw
    ${VULKAN_LIB}
    ${COMMON_LIB}
    )

message( "GLFW: ${GLFW_LIBRARIES}" )

# header dirs
set(
    PROJECT_INCLUDE_DIRS
    ${SRC_DIR}
    ${SRC_DIR}/common
    ${SRC_DIR}/graphics
    ${SRC_DIR}/glfw
    )

# cpp files
set(
    PROJECT_SOURCE

    # 'Common' subclasses
    ${SRC_DIR}/GraphicsIOHandler.cpp

    )

# file with main function
set( PROJECT_MAIN ${SRC_DIR}/GraphicsMain.cpp )

add_executable( runOPGraphics ${SRC_DIR}/OPGraphics.cpp )

target_link_libraries( runOPGraphics ${PROJECT_LINK_LIBS} )

target_include_directories( runOPGraphics PUBLIC SYSTEM
                            ${PROJECT_SYSTEM_INCLUDE_DIRS} )

target_include_directories( runOPGraphics PUBLIC
                            ${PROJECT_INCLUDE_DIRS}
                            ${PROJECT_BINARY_DIR} )

install (
         TARGETS runOPGraphics
         RUNTIME DESTINATION bin
         )

# include( ${COMMON_PATH}/cmake/DefaultProjectLibrary.cmake )

