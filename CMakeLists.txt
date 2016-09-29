cmake_minimum_required ( VERSION 3.0.0 )
project ( LBSetup )


set( BUILD_DIR_NAME _build )

set( THIRDPARTY   ${PROJECT_SOURCE_DIR}/thirdparty )
set( COMMON_PATH  ${PROJECT_SOURCE_DIR}/common     )
set( RUN_DIR      ${PROJECT_SOURCE_DIR}/run        )
set( PROJECTS_DIR ${PROJECT_SOURCE_DIR}/projects   )


set( GRAPHICS_PATH ${PROJECTS_DIR}/graphics )
set( INT_TEST_PATH ${PROJECTS_DIR}/intTest  )
set( TEST_PATH     ${PROJECTS_DIR}/test     )


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

ExternalProject_Add_Step(
                         glfwLib glfwConfigure
                         COMMAND ${CMAKE_COMMAND} -E echo "Force glfw configure"
                         DEPENDERS configure
                         ALWAYS 1
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

ExternalProject_Add_Step(
                         gladLib gladConfigure
                         COMMAND ${CMAKE_COMMAND} -E echo "Force glad configure"
                         DEPENDERS configure
                         ALWAYS 1
                         )




################################################
#                    COMMON                    #
################################################
ExternalProject_Add(
                    lbCommonProj
                    PREFIX           ${PROJECT_BINARY_DIR}/common
                    DEPENDS          glfwLib gladLib
                    DOWNLOAD_COMMAND ""
                    UPDATE_COMMAND   ""
                    SOURCE_DIR       ${COMMON_PATH}
                    CMAKE_ARGS       -DCMAKE_INSTALL_PREFIX:STRING=${RUN_DIR}
                    )

ExternalProject_Add_Step(
                         lbCommonProj lbCommonConfigure
                         COMMAND ${CMAKE_COMMAND} -E echo "Force lbCommon configure"
                         DEPENDERS configure
                         ALWAYS 1
                         )



################################################
#                   GRAPHICS                   #
################################################
ExternalProject_Add(
                    graphicsProj
                    PREFIX           ${PROJECT_BINARY_DIR}/graphics
                    DEPENDS          lbCommonProj
                    DOWNLOAD_COMMAND ""
                    UPDATE_COMMAND   ""
                    SOURCE_DIR       ${GRAPHICS_PATH}
                    CMAKE_ARGS       -DCOMMON_PATH:STRING=${COMMON_PATH}
                                     -DCMAKE_INSTALL_PREFIX:STRING=${RUN_DIR}
                    )

ExternalProject_Add_Step(
                         graphicsProj graphicsConfigure
                         COMMAND ${CMAKE_COMMAND} -E echo "Force graphics configure"
                         DEPENDERS configure
                         ALWAYS 1
                         )



################################################
#                   INT TEST                   #
################################################
ExternalProject_Add(
                    intTestProj
                    PREFIX           ${PROJECT_BINARY_DIR}/intTest
                    DEPENDS          lbCommonProj
                    DOWNLOAD_COMMAND ""
                    UPDATE_COMMAND   ""
                    SOURCE_DIR       ${INT_TEST_PATH}
                    CMAKE_ARGS       -DCOMMON_PATH:STRING=${COMMON_PATH}
                                     -DCMAKE_INSTALL_PREFIX:STRING=${RUN_DIR}
                    )

ExternalProject_Add_Step(
                         intTestProj intTestConfigure
                         COMMAND ${CMAKE_COMMAND} -E echo "Force intTest configure"
                         DEPENDERS configure
                         ALWAYS 1
                         )




################################################
#                     TEST                     #
################################################
ExternalProject_Add(
                    testProj
                    PREFIX           ${PROJECT_BINARY_DIR}/test
                    DEPENDS          lbCommonProj
                    DOWNLOAD_COMMAND ""
                    UPDATE_COMMAND   ""
                    SOURCE_DIR       ${TEST_PATH}
                    CMAKE_ARGS       -DCOMMON_PATH:STRING=${COMMON_PATH}
                                     -DCMAKE_INSTALL_PREFIX:STRING=${RUN_DIR}
                    )

ExternalProject_Add_Step(
                         testProj testConfigure
                         COMMAND ${CMAKE_COMMAND} -E echo "Force test configure"
                         DEPENDERS configure
                         ALWAYS 1
                         )



################################################
#                 AUTO PROJECT                 #
################################################
if ( NEW_PROJECT )

  if ( NOT NEW_PROJECT_NAMESPACE )

    message( "WARNING: NEW_PROJECT_NAMESPACE not set. Using NEW_PROJECT variable" )
    set( NEW_PROJECT_NAMESPACE ${NEW_PROJECT} )

  endif()

  set( TEMPLATE_DIR ${COMMON_PATH}/template            )
  set( NEW_DIR      ${PROJECTS_DIR}/${NEW_PROJECT_NAMESPACE}_auto )

  configure_file ( ${TEMPLATE_DIR}/TemplateMain.cpp      ${NEW_DIR}/src/${NEW_PROJECT}Main.cpp      )
  configure_file ( ${TEMPLATE_DIR}/TemplateWorld.hpp     ${NEW_DIR}/src/${NEW_PROJECT}World.hpp     )
  configure_file ( ${TEMPLATE_DIR}/TemplateWorld.cpp     ${NEW_DIR}/src/${NEW_PROJECT}World.cpp     )
  configure_file ( ${TEMPLATE_DIR}/TemplateIOHandler.hpp ${NEW_DIR}/src/${NEW_PROJECT}IOHandler.hpp )
  configure_file ( ${TEMPLATE_DIR}/TemplateIOHandler.cpp ${NEW_DIR}/src/${NEW_PROJECT}IOHandler.cpp )

  file (
        COPY        ${TEMPLATE_DIR}/ProjectConfig.hpp.in
        DESTINATION ${NEW_DIR}/src
        )
  file (
        COPY        ${TEMPLATE_DIR}/CMakeLists.txt
        DESTINATION ${NEW_DIR}/
        )

endif( )



