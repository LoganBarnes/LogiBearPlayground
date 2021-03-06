
include( GenerateExportHeader )

set( INSTALL_DIR "${PROJECT_BINARY_DIR}" CACHE STRING "Location to install files" )

# paths
set( RES_PATH   ${PROJECT_SOURCE_DIR}/res        )
set( THIRDPARTY ${PROJECT_SOURCE_DIR}/thirdparty )

if ( PROJECT_CONFIG_FILE )

  configure_file (
                  ${PROJECT_CONFIG_FILE}
                  ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.hpp
                  )

endif( ) # PROJECT_CONFIG_FILE

#
# define the dll macros for windows shared libs
#
if( MSVC )

  configure_file (
                  ${DLL_DEFINES_FILE}
                  ${PROJECT_BINARY_DIR}/DLLDefines.hpp
                  )

endif( )


set ( PROJECT_INCLUDE_DIRS ${PROJECT_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})

# Create named folders for the sources within the .vcproj
# Empty name lists them directly under the .vcproj
source_group( "" FILES ${PROJECT_SOURCE} )


# compile flags
if ( NOT MSVC )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Wcast-align -Wcast-qual"            )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2"      )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Winit-self -Wmissing-declarations -Wmissing-include-dirs"   )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wold-style-cast -Woverloaded-virtual -Wredundant-decls"     )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5" )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch-default -Wundef -Werror -Wno-unused --std=c++11"    )
endif( )


# make project into library that can be used by multiple executables ( such as test classes )
add_library           ( ${PROJECT_NAME} ${PROJECT_SOURCE}            )
target_link_libraries ( ${PROJECT_NAME} ${PROJECT_LINK_LIBS} ${DEP_TARGETS} )
set_property          ( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11     ) # c++11

#
# create the export header for windows shared libraries
#
generate_export_header( ${PROJECT_NAME}
                        BASE_NAME         ${PROJECT_NAME}
                        EXPORT_MACRO_NAME ${PROJECT_NAME}_EXPORTS
                        EXPORT_FILE_NAME  ${PROJECT_NAME}_exports.hpp
                        STATIC_DEFINE     SHARED_EXPORTS_BUILT_AS_STATIC )

if ( ${DEP_TARGETS} )
  add_dependencies ( ${PROJECT_NAME} ${DEP_TARGETS} )
endif( )

target_include_directories( ${PROJECT_NAME} SYSTEM PUBLIC ${PROJECT_SYSTEM_INCLUDE_DIRS} )
target_include_directories( ${PROJECT_NAME}        PUBLIC ${PROJECT_INCLUDE_DIRS}        )


# make executable to run
set( PROJECT_EXEC ${PROJECT_EXEC} run${PROJECT_NAME} )

add_executable        ( ${PROJECT_EXEC} ${PROJECT_MAIN} )
target_link_libraries ( ${PROJECT_EXEC} ${PROJECT_NAME} )
add_dependencies      ( ${PROJECT_EXEC} ${PROJECT_NAME} )

set_property          ( TARGET ${PROJECT_EXEC} PROPERTY CXX_STANDARD 11     ) # c++11

target_include_directories( ${PROJECT_EXEC} PUBLIC
                            ${PROJECT_INCLUDE_DIRS}
                            ${PROJECT_BINARY_DIR} )

# Creates a folder "executables" and adds target
# project (${PROJECT_EXEC}.vcproj) under it
set_property( TARGET ${PROJECT_EXEC} PROPERTY FOLDER "executables" )

set_property( TARGET ${PROJECT_NAME} PROPERTY CMAKE_INSTALL_RPATH
              ./ )

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
        ARCHIVE DESTINATION lib
        )

if ( PROJECT_INSTALL_HEADERS )

  install(
          FILES ${PROJECT_INSTALL_HEADERS}
          DESTINATION include/${PROJECT_NAME}
          )

endif()
