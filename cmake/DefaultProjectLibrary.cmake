
set( INSTALL_DIR "${PROJECT_BINARY_DIR}" CACHE STRING "Location to install files" )

# paths
set( RES_PATH   ${PROJECT_SOURCE_DIR}/res        )
set( THIRDPARTY ${PROJECT_SOURCE_DIR}/thirdparty )

if ( PROJECT_CONFIG_FILE )

  configure_file (
                  ${SRC_DIR}/ProjectConfig.hpp.in
                  ${PROJECT_BINARY_DIR}/ProjectConfig.hpp
                  )

endif( ) # PROJECT_CONFIG_FILE

set ( PROJECT_INCLUDE_DIRS ${PROJECT_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})

# Create named folders for the sources within the .vcproj
# Empty name lists them directly under the .vcproj
source_group( "" FILES ${PROJECT_SOURCE} )


if ( NOT IS_ABSOLUTE ${INSTALL_DIR} )

  set( INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${INSTALL_DIR} )

endif()

set( CMAKE_INSTALL_PREFIX ${INSTALL_DIR} )
set( LIB_SUFFIX bin )


#
# glad
#
set(
    PROJECT_SYSTEM_INCLUDE_DIRS
    ${PROJECT_SYSTEM_INCLUDE_DIRS}
    ${THIRDPARTY}/glad/include
    )

set( GLAD_SOURCE ${THIRDPARTY}/glad/src/glad.c )


#
# add glfw3 variables
#
set( GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

set( BUILD_SHARED_LIBS   ON  CACHE BOOL "" FORCE )

if ( WIN32 )
  set( USE_MSVC_RUNTIME_LIBRARY_DLL ON CACHE BOOL "" FORCE )
endif()


#
# glfw
#
add_subdirectory   ( ${THIRDPARTY}/glfw )
set(
    PROJECT_SYSTEM_INCLUDE_DIRS
    ${PROJECT_SYSTEM_INCLUDE_DIRS}
    ${THIRDPARTY}/glfw/include
    )

set ( EXTRA_LIBS  ${EXTRA_LIBS}  ${GLFW_LIBRARIES} )
set ( DEP_TARGETS ${DEP_TARGETS} glfw )



# compile flags
if ( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall" )
else()
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Wcast-align -Wcast-qual"            )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2"      )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Winit-self -Wmissing-declarations -Wmissing-include-dirs"   )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wold-style-cast -Woverloaded-virtual -Wredundant-decls"     )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5" )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch-default -Wundef -Werror -Wno-unused --std=c++11"    )
endif()


# make project into library that can be used by multiple executables ( such as test classes )
add_library           ( ${PROJECT_NAME} SHARED ${PROJECT_SOURCE} ${GLAD_SOURCE} )
target_link_libraries ( ${PROJECT_NAME} ${EXTRA_LIBS} ${DEP_TARGETS}     )
add_dependencies      ( ${PROJECT_NAME} ${DEP_TARGETS}                   )

target_include_directories( ${PROJECT_NAME} SYSTEM PUBLIC ${PROJECT_SYSTEM_INCLUDE_DIRS} )
target_include_directories( ${PROJECT_NAME}        PUBLIC ${PROJECT_INCLUDE_DIRS}        )


# make executable to run
set( PROJECT_EXEC ${PROJECT_EXEC} run${PROJECT_NAME} )

add_executable        ( ${PROJECT_EXEC} ${PROJECT_MAIN} )
target_link_libraries ( ${PROJECT_EXEC} ${PROJECT_NAME} )
add_dependencies      ( ${PROJECT_EXEC} ${PROJECT_NAME} )

target_include_directories( ${PROJECT_EXEC} PUBLIC ${PROJECT_INCLUDE_DIRS} )


# Creates a folder "executables" and adds target
# project (${PROJECT_EXEC}.vcproj) under it
set_property( TARGET ${PROJECT_EXEC} PROPERTY FOLDER "executables" )

set_property( TARGET ${PROJECT_NAME} PROPERTY CMAKE_INSTALL_RPATH
              ./ )

#set_property( TARGET ${PROJECT_EXEC} PROPERTY CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE )
set_property( TARGET ${PROJECT_EXEC} PROPERTY INSTALL_RPATH
              ${CMAKE_INSTALL_PREFIX}/lib )

# Adds logic to INSTALL.vcproj to copy ${PROJECT_EXEC}.exe to destination directory
install (
         TARGETS ${PROJECT_EXEC}
         RUNTIME DESTINATION bin
         )

install(
        TARGETS ${PROJECT_EXEC} ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        )

#
# copy .dlls to same directory on windows
#
if ( WIN32 )

  add_custom_command(
                     TARGET ${PROJECT_EXEC} POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     "${PROJECT_BINARY_DIR}/libs/glfw/src/$<CONFIGURATION>/glfw3.dll"
                     $<TARGET_FILE_DIR:${PROJECT_EXEC}>
                     )

endif()
