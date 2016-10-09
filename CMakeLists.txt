cmake_minimum_required ( VERSION 3.0.0 )
project ( LBSetup )


set( BUILD_DIR_NAME _build )

set( COMMON_PATH  ${PROJECT_SOURCE_DIR}/common     )
set( RUN_DIR      ${PROJECT_SOURCE_DIR}/run        )
set( PROJECTS_DIR ${PROJECT_SOURCE_DIR}/projects   )


set( GRAPHICS_PATH ${PROJECTS_DIR}/graphics )
set( TEST_PATH     ${PROJECTS_DIR}/test     )


include( ExternalProject )


################################################
#                    COMMON                    #
################################################
ExternalProject_Add(
                    lbCommonProj
                    PREFIX           ${PROJECT_BINARY_DIR}/common
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
                                     -DCMAKE_PREFIX_PATH:STRING=${RUN_DIR}
                                     -DCMAKE_INSTALL_PREFIX:STRING=${RUN_DIR}
                    )

ExternalProject_Add_Step(
                         graphicsProj graphicsConfigure
                         COMMAND ${CMAKE_COMMAND} -E echo "Force graphics configure"
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



