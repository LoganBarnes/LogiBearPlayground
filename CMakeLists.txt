cmake_minimum_required ( VERSION 3.0.0 )
project ( LBSetup )


set( BUILD_DIR_NAME _build )

set( THIRDPARTY   ${PROJECT_SOURCE_DIR}/thirdparty )
set( COMMON_PATH  ${PROJECT_SOURCE_DIR}/common     )
set( RUN_DIR      ${PROJECT_SOURCE_DIR}/run        )
set( PROJECTS_DIR ${PROJECT_SOURCE_DIR}/projects   )


set( GRAPHICS_PATH ${PROJECTS_DIR}/graphics )


include( ExternalProject )

################################################
#             THIRDPARTY:  GLFW                #
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
#             THIRDPARTY:   GLM               #
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
#                    COMMON                    #
################################################
ExternalProject_Add(
                    lbCommon
                    PREFIX           ${PROJECT_BINARY_DIR}/common
                    DEPENDS          glfwLib gladLib
                    DOWNLOAD_COMMAND ""
                    UPDATE_COMMAND   ""
                    SOURCE_DIR       ${COMMON_PATH}
                    CMAKE_ARGS       -DCMAKE_INSTALL_PREFIX:STRING=${RUN_DIR}
                    )




################################################
#                    COMMON                    #
################################################
ExternalProject_Add(
                    graphics
                    PREFIX           ${PROJECT_BINARY_DIR}/graphics
                    DEPENDS          lbCommon
                    DOWNLOAD_COMMAND ""
                    UPDATE_COMMAND   ""
                    SOURCE_DIR       ${GRAPHICS_PATH}
                    CMAKE_ARGS       -DCOMMON_PATH:STRING=${COMMON_PATH}
                                     -DCMAKE_INSTALL_PREFIX:STRING=${RUN_DIR}
                    )





