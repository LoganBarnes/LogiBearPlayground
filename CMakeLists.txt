cmake_minimum_required ( VERSION 3.0.0 )
project ( LBSetup )


set( BUILD_DIR_NAME _build )

set( COMMON_PATH ${PROJECT_SOURCE_DIR}/common     )
set( THIRDPARTY  ${PROJECT_SOURCE_DIR}/thirdparty )
set( RUN_DIR     ${PROJECT_SOURCE_DIR}/run        )


include( ExternalProject )

################################################
##                    GLFW                    ##
################################################
ExternalProject_Add(
                    glfwLib
                    PREFIX           ${THIRDPARTY}/_build/glfw
                    DOWNLOAD_COMMAND ""
                    UPDATE_COMMAND   ""
                    SOURCE_DIR       ${THIRDPARTY}/glfw
                    CMAKE_ARGS       -DGLFW_BUILD_DOCS:BOOL=OFF
                                     -DGLFW_BUILD_TESTS:BOOL=OFF
                                     -DGLFW_BUILD_EXAMPLES:BOOL=OFF
                                     -DBUILD_SHARED_LIBS:BOOL=ON
                                     -DUSE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=ON
                                     -DCMAKE_INSTALL_PREFIX:STRING=${RUN_DIR}
                    )




###############################################
##                    GLM                    ##
###############################################
ExternalProject_Add(
                    gladLib
                    PREFIX           ${THIRDPARTY}/_build/glad
                    DOWNLOAD_COMMAND ""
                    UPDATE_COMMAND   ""
                    SOURCE_DIR       ${THIRDPARTY}/glad
                    CMAKE_ARGS       -DCMAKE_INSTALL_PREFIX:STRING=${RUN_DIR}
                    )



################################################
##                   COMMON                   ##
################################################
ExternalProject_Add(
                    LBCommon
                    PREFIX          ${PROJECT_BINARY_DIR}/common
                    DEPENDS          glfwLib gladLib
                    DOWNLOAD_COMMAND ""
                    UPDATE_COMMAND   ""
                    SOURCE_DIR       ${COMMON_PATH}
                    CMAKE_ARGS       -DCMAKE_INSTALL_PREFIX:STRING=${RUN_DIR}
                    )

