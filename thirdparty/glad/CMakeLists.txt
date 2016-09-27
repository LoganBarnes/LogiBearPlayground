cmake_minimum_required ( VERSION 3.0.0 )
project ( Glad )

add_library( glad SHARED src/glad.c )
target_include_directories( glad PUBLIC include )

install(
        TARGETS glad
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )
