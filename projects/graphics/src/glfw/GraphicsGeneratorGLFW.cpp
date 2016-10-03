#include "GraphicsGeneratorGLFW.hpp"

#include <iostream>
#include <algorithm>
#include <sstream>

#define GLFW_INCLUDE_GL_3
#include "GLFW/glfw3.h"

#include "GraphicsContextGLFW.hpp"
#include "GraphicsHandler.hpp"
//#include "CallbackSingleton.hpp"


namespace graphics
{


///
/// \brief GraphicsGeneratorGLFW::GraphicsGeneratorGLFW
///
GraphicsGeneratorGLFW::GraphicsGeneratorGLFW( )
  :
  GraphicsGenerator ( )
  , glfwInitialized_( false )
{

  if ( !_initGLFW( ) )
  {

    throw( std::runtime_error( "GLFW init failed" ) );

  }

}



///
/// \brief GraphicsGeneratorGLFW::~GraphicsGeneratorGLFW
///
GraphicsGeneratorGLFW::~GraphicsGeneratorGLFW( )
{

  _terminateGLFW( );

}



///
/// \brief GraphicsGeneratorGLFW::generateHandler
/// \param title
/// \return
///
GraphicsHandler&
GraphicsGeneratorGLFW::generateHandler(
                                       std::string  title,
                                       unsigned int width,
                                       unsigned int height
                                       )
{

  try
  {

    int iwidth  = static_cast< int >( width );
    int iheight = static_cast< int >( height );

    std::unique_ptr< GraphicsContext > context( new GraphicsContextGLFW(
                                                                        title,
                                                                        iwidth,
                                                                        iheight,
                                                                        0 ) );

    std::unique_ptr< GraphicsHandler > handler( new GraphicsHandler(
                                                                    context,
                                                                    static_cast< int >( iwidth ),
                                                                    static_cast< int >( iheight )
                                                                    ) );

    handlers_.push_back( std::move( handler ) );

  }
  catch ( const std::exception &e )
  {

    std::stringstream msg;
    msg << "Graphics handler init failed: " << e.what( );
    throw( std::runtime_error( msg.str( ) ) );

  }

  return *handlers_.back( );

} // GraphicsGeneratorGLFW::generateHandler



///
/// \brief GraphicsGeneratorGLFW::checkEvents
///
void
GraphicsGeneratorGLFW::checkEvents( )
{

  glfwPollEvents( );

}



///
/// \brief GraphicsGeneratorGLFW::_initGLFW
/// \return
///
bool
GraphicsGeneratorGLFW::_initGLFW( )
{

  //
  // set error callback before anything else to get
  // error messages from future calls
  //
//  glfwSetErrorCallback( CallbackSingleton::errorCallback );

  //
  // If we aren't already initialized then try
  // to initialized GLFW.
  //
  if ( !glfwInitialized_ && !glfwInit( ) )
  {

    //
    // init failed
    //
    return false;

  }

  std::cout << "Initialized GLFW Version: ";
  std::cout << glfwGetVersionString( ) << std::endl;


  glfwInitialized_ = true;
  return true;

} // GraphicsGeneratorGLFW::_initGLFW



///
/// \brief GraphicsGeneratorGLFW::_terminateGLFW
///
void
GraphicsGeneratorGLFW::_terminateGLFW( )
{

  if ( glfwInitialized_ )
  {

    glfwTerminate( );
    glfwInitialized_ = false;
    //
    // ready to be initialized again if necessary
    //
    std::cout << "Terminated GLFW" << std::endl;

  }

}



} // namespace graphics
