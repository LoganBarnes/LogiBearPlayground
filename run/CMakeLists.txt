cmake_minimum_required ( VERSION 3.0.0 )
project ( testFindLib )

find_library( COMMON_LIB NAME Common
              PATHS ${CMAKE_CURRENT_SOURCE_DIR}
              PATH_SUFFIXES lib bin )

add_executable       ( testFindLib ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp )
target_link_libraries( testFindLib ${COMMON_LIB} )


