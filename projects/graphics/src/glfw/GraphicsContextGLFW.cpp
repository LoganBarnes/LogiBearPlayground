#include "GraphicsContextGLFW.hpp"

// THIS IS OPTIONAL AND NOT REQUIRED, ONLY USE THIS IF YOU DON'T WANT GLAD TO INCLUDE windows.h
// GLAD will include windows.h for APIENTRY if it was not previously defined.
// Make sure you have the correct definition for APIENTRY for platforms which define _WIN32 but don't use __stdcall
#ifdef _WIN32
#define APIENTRY __stdcall
#endif

// GLAD
#include "glad/glad.h"

// confirm that GLAD didn't include windows.h
#ifdef _WINDOWS_
#error windows.h was included!
#endif

#define GLFW_INCLUDE_GL_3
#include "GLFW/glfw3.h"


namespace graphics
{


GraphicsContextGLFW::GraphicsContextGLFW(
                                         const std::string          title,
                                         const int                  width,
                                         const int                  height,
                                         const GraphicsContextGLFW *pSharedContext
                                         )
  :
  GraphicsContext( )
{

  _initWindow( title, width, height, pSharedContext );
  _initGL( );

}



///
/// \brief GraphicsContextGLFW::~GraphicsContextGLFW
///
GraphicsContextGLFW::~GraphicsContextGLFW( )
{

  glfwDestroyWindow( pWindow_ );

}



///
/// \brief GraphicsContextGLFW::showBuffer
///
void
GraphicsContextGLFW::updateWindow( )
{

  glfwSwapBuffers( pWindow_ );

}



///
/// \brief GraphicsContextGLFW::checkWindowShouldClose
///
bool
GraphicsContextGLFW::checkWindowShouldClose( )
{

  return glfwWindowShouldClose( pWindow_ );

}



///
/// \brief GraphicsContextGLFW::makeWindowCurrent
///
void
GraphicsContextGLFW::makeWindowCurrent( )
{

  glfwMakeContextCurrent( pWindow_ );

}



///
/// \brief GraphicsContextGLFW::_initWindow
/// \param title
/// \param width
/// \param height
///
void
GraphicsContextGLFW::_initWindow(
                                 const std::string title,
                                 const int         width,
                                 const int         height,
                                 const GraphicsContextGLFW*
                                 )
{

  //
  // OpenGL 3.2 core profile
  //
  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3                        );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 2                        );
  glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE                  );
  glfwWindowHint( GLFW_OPENGL_PROFILE,        GLFW_OPENGL_CORE_PROFILE );


  //
  // no title means no visibility
  //
  if ( title.length( ) )
  {

    glfwWindowHint( GLFW_VISIBLE, GL_TRUE );

  }
  else
  {

    glfwWindowHint( GLFW_VISIBLE, GL_FALSE );

  }

  pWindow_ = glfwCreateWindow(
                              width,
                              height,
                              title.c_str( ),
                              0,
                              0 // pSharedContext->getWindow()
                              );

  if ( !pWindow_ )
  {

    throw( std::runtime_error( "GLFW window creation failed" ) );

  }

  /* Make the window's context current */
  glfwMakeContextCurrent( pWindow_ );

  glfwSwapInterval( 1 );

  /* set default callback functions */
//  glfwSetWindowSizeCallback ( pWindow_, CallbackSingleton::windowSizeCallback  );
//  glfwSetWindowFocusCallback( pWindow_, CallbackSingleton::windowFocusCallback );

//  glfwSetMouseButtonCallback( pWindow_, CallbackSingleton::mouseButtonCallback    );
//  glfwSetKeyCallback        ( pWindow_, CallbackSingleton::keyCallback            );
//  glfwSetCursorPosCallback  ( pWindow_, CallbackSingleton::cursorPositionCallback );
//  glfwSetScrollCallback     ( pWindow_, CallbackSingleton::scrollCallback         );

} // GraphicsContext::_initGLFW



///
/// \brief GraphicsContextGLFW::_initGL
///
void
GraphicsContextGLFW::_initGL( )
{

  if ( !gladLoadGLLoader( reinterpret_cast< GLADloadproc >( glfwGetProcAddress ) ) )
  {

    throw( std::runtime_error( "Failed to initialize OpenGL context" ) );

  }

  // Enable depth testing, so that objects are occluded based on depth instead of drawing order.
  glEnable( GL_DEPTH_TEST );

  // Move the polygons back a bit so lines are still drawn even though they are coplanar with the
  // polygons they came from, which will be drawn before them.
  glEnable( GL_POLYGON_OFFSET_LINE );
  glPolygonOffset( -1, -1 );

  // Enable back-face culling, meaning only the front side of every face is rendered.
  glEnable( GL_CULL_FACE );
  glCullFace( GL_BACK );

  // Specify that the front face is represented by vertices in counterclockwise order (this is
  // the default).
  glFrontFace( GL_CCW );

  // Specify the color used when glClear is called
  glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

} // GraphicsContextGLFW::_initGL



} // namespace graphics
