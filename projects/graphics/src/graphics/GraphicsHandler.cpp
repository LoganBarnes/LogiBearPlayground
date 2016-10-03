#include "GraphicsHandler.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "glad/glad.h"
#include "GraphicsContextGLFW.hpp"
// #include "CallbackSingleton.hpp"


namespace graphics
{



///
/// \brief GraphicsHandler::GraphicsHandler
/// \param width
/// \param height
///
GraphicsHandler::GraphicsHandler(
                                 std::unique_ptr< GraphicsContext > &upContext,
                                 const int                           width,
                                 const int                           height
                                 )
  :
  upContext_ ( std::move( upContext ) )
  , viewWidth_ ( width )
  , viewHeight_( height )
//  , m_input( 0 )
//  , m_initialized( false )
{

//  m_input = &CallbackSingleton::getInstance( );

}



///
/// \brief GraphicsHandler::~GraphicsHandler
///
GraphicsHandler::~GraphicsHandler( )
{

//  for ( auto it = m_programs.begin( ); it != m_programs.end( ); ++it )
//  {

//    glDeleteProgram( it->second );

//  }

//  for ( auto it = m_textures.begin( ); it != m_textures.end( ); ++it )
//  {

//    glDeleteTextures( 1, &( it->second ) );

//  }

//  for ( auto it = m_buffers.begin( ); it != m_buffers.end( ); ++it )
//  {

//    const Buffer &buffer = it->second;

//    if ( !buffer.shared )
//    {

//      glDeleteBuffers( 1, &( buffer.vbo ) );

//    }

//    glDeleteVertexArrays( 1, &( buffer.vao ) );

//  }

//  for ( auto it = m_framebuffers.begin( ); it != m_framebuffers.end( ); ++it )
//  {

//    const Buffer &buffer = it->second;
//    glDeleteFramebuffers( 1, &( buffer.vbo ) );
//    glDeleteRenderbuffers( 1, &( buffer.vao ) );

//  }

//  _terminateWindow( );

}



/////
///// \brief GraphicsHandler::addProgram
///// \param name
///// \param vertFilePath
///// \param fragFilePath
/////
//void
//GraphicsHandler::addProgram(
//                            std::string name,
//                            std::string vertFilePath,
//                            std::string fragFilePath
//                            )
//{

//  m_programs[ name ] = GraphicsHandler::_loadShader( vertFilePath, fragFilePath );

//}



/////
///// \brief GraphicsHandler::addTextureArray
///// \param name
///// \param width
///// \param height
///// \param array
///// \param linear
/////
//void
//GraphicsHandler::addTextureArray(
//                                 std::string name,
//                                 int         width,
//                                 int         height,
//                                 float      *array,
//                                 bool        linear
//                                 )
//{

//  if ( m_textures.count( name ) )
//  {

//    glDeleteTextures( 1, &( m_textures[ name ] ) );

//  }

//  GLuint texture;
//  glGenTextures( 1, &texture );
//  glBindTexture( GL_TEXTURE_2D, texture );

//  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
//  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

//  if ( linear )
//  {

//    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
//    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

//  }
//  else
//  {

//    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
//    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

//  }

//  glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_FLOAT, array );

//  m_textures[ name ] = texture;

//} // GraphicsHandler::addTextureArray



/////
///// \brief GraphicsHandler::addTextureImage
///// \param name
///// \param width
///// \param height
/////
//void
//GraphicsHandler::addTextureImage(
//                                 std::string name,
//                                 int         width,
//                                 int         height,
//                                 std::string
//                                 )
//{

//  if ( m_textures.count( name ) )
//  {

//    glDeleteTextures( 1, &( m_textures[ name ] ) );

//  }

//  GLuint texture;
//  glGenTextures( 1, &texture );
//  glBindTexture( GL_TEXTURE_2D, texture );

//  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT );
//  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT );
//  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
//  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

//  glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_FLOAT, NULL );

//  m_textures[ name ] = texture;

//} // GraphicsHandler::addTextureImage



/////
///// \brief GraphicsHandler::updateTexture
///// \param name
///// \param xoffset
///// \param yoffset
///// \param width
///// \param height
///// \param array
/////
//void
//GraphicsHandler::updateTexture(
//                               std::string name,
//                               int         xoffset,
//                               int         yoffset,
//                               int         width,
//                               int         height,
//                               float      *array
//                               )
//{

//  GLuint texture = m_textures[ name ];

//  glBindTexture( GL_TEXTURE_2D, texture );

//  glTexSubImage2D( GL_TEXTURE_2D, 0, xoffset, yoffset, width, height, GL_RGBA, GL_FLOAT, array );

//} // GraphicsHandler::addTextureArray



/////
///// \brief GraphicsHandler::setTexture
///// \param name
///// \param texture
/////
//void
//GraphicsHandler::setTexture(
//                            std::string name,
//                            GLuint      texture,
//                            bool        linear
//                            )
//{

//  m_textures[ name ] = texture;

//  glBindTexture( GL_TEXTURE_2D, texture );

//  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
//  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

//  if ( linear )
//  {

//    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
//    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

//  }
//  else
//  {

//    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
//    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

//  }

//} // GraphicsHandler::setTexture



/////
///// \brief GraphicsHandler::addBuffer
///// \param name
///// \param program
///// \param attribName
///// \param data
///// \param size
///// \param dynamic
/////
//void
//GraphicsHandler::addVBO(
//                        std::string ,
//                        GLfloat    *data,
//                        GLuint      size,
//                        bool        dynamic
//                        )
//{

////  Buffer buffer;

////  buffer.shared = false;

////  if ( m_buffers.count( name ) )
////  {

////    buffer = m_buffers[ name ];
////    glDeleteBuffers( 1, &( buffer.vbo ) );

////  }
//  GLuint vbo;
//  GLuint vao;

//  // Initialize the vertex buffer object.
//  glGenBuffers( 1, &( vbo ) );
//  glBindBuffer( GL_ARRAY_BUFFER, ( vbo ) );

//  if ( dynamic )
//  {

//    glBufferData( GL_ARRAY_BUFFER, size * sizeof( GLfloat ), data, GL_DYNAMIC_DRAW );

//  }
//  else
//  {

//    glBufferData( GL_ARRAY_BUFFER, size * sizeof( GLfloat ), data, GL_STATIC_DRAW );

//  }


//  // Unbind buffer
//  glBindBuffer( GL_ARRAY_BUFFER, 0 );

////  m_buffers[ name ] = buffer;

//} // GraphicsHandler::addBuffer



//void
//GraphicsHandler::addVAO(
//                        GLuint      vbo,
//                        std::string name,
//                        std::string program,
//                        bool        shared
//                        )
//{

////  Buffer buffer;

////  buffer.shared = shared;

////  if ( m_buffers.count( name ) )
////  {

////    buffer = m_buffers[ name ];
////    glDeleteVertexArrays( 1, &( buffer.vao ) );

////  }

////  buffer.vbo = vbo;

//  // Bind the vertex buffer object.
//  glBindBuffer( GL_ARRAY_BUFFER, ( vbo ) );


//  // Initialize the vertex array object.
//  glGenVertexArrays( 1, &( vao ) );
//  glBindVertexArray( ( vao ) );

//  int pos = glGetAttribLocation( m_programs[ program ], "uv" );

//  if ( pos < 0 )
//  {

//    std::cerr << "attrib location not found for program " << program << std::endl;

//    // Unbind buffers and return
//    glBindBuffer( GL_ARRAY_BUFFER, 0 );
//    glBindVertexArray( 0 );
//    return;

//  }

//  GLuint position = static_cast< GLuint >( pos  );

//  glEnableVertexAttribArray( position );
//  glVertexAttribPointer(
//                        position,
//                        2,        // Num coordinates per position
//                        GL_FLOAT, // Type
//                        GL_FALSE, // Normalized
//                        0,        // Stride
//                        0         // Array buffer offset
//                        );

//  // Unbind buffers.
//  glBindBuffer( GL_ARRAY_BUFFER, 0 );
//  glBindVertexArray( 0 );

//  m_buffers[ name ] = buffer;

//} // GraphicsHandler::addVAO



//void
//GraphicsHandler::addVAO2(
//                         GLuint      vbo,
//                         std::string name,
//                         std::string program,
//                         bool        shared
//                         )
//{

//  Buffer buffer;

//  shared = shared;

//  if ( m_buffers.count( name ) )
//  {

//    buffer = m_buffers[ name ];
//    glDeleteVertexArrays( 1, &( vao ) );

//  }

//  vbo = vbo;

//  // Bind the vertex buffer object.
//  glBindBuffer( GL_ARRAY_BUFFER, ( vbo ) );


//  // Initialize the vertex array object.
//  glGenVertexArrays( 1, &( vao ) );
//  glBindVertexArray( ( vao ) );

//  int pos = glGetAttribLocation( m_programs[ program ], "uv" );

//  if ( pos < 0 )
//  {

//    std::cerr << "attrib location not found for program " << program << std::endl;

//    // Unbind buffers and return
//    glBindBuffer( GL_ARRAY_BUFFER, 0 );
//    glBindVertexArray( 0 );
//    return;

//  }

//  GLuint position = static_cast< GLuint >( pos  );

//  glEnableVertexAttribArray( position );
//  glVertexAttribPointer(
//                        position,
//                        3, // Num coordinates per position
//                        GL_FLOAT, // Type
//                        GL_FALSE, // Normalized
//                        0, // Stride
//                        0 // Array buffer offset
//                        );

//  // Unbind buffers.
//  glBindBuffer( GL_ARRAY_BUFFER, 0 );
//  glBindVertexArray( 0 );

//  m_buffers[ name ] = buffer;

//} // GraphicsHandler::addVAO2



/////
///// \brief GraphicsHandler::addUVBuffer
///// \param name
///// \param program
///// \param attribName
///// \param data
///// \param size
///// \param dynamic
/////
//void
//GraphicsHandler::addUVBuffer(
//                             std::string name,
//                             std::string program,
//                             std::string attribName,
//                             GLfloat    *data,
//                             GLuint      size,
//                             bool        dynamic
//                             )
//{

//  Buffer buffer;

//  if ( m_buffers.count( name ) )
//  {
//    buffer = m_buffers[ name ];
//    glDeleteBuffers( 1, &( vbo ) );
//    glDeleteVertexArrays( 1, &( vao ) );
//  }

//  // Initialize the vertex buffer object.
//  glGenBuffers( 1, &( vbo ) );
//  glBindBuffer( GL_ARRAY_BUFFER, ( vbo ) );

//  if ( dynamic )
//  {

//    glBufferData( GL_ARRAY_BUFFER, size * sizeof( GLfloat ), data, GL_DYNAMIC_DRAW );

//  }
//  else
//  {

//    glBufferData( GL_ARRAY_BUFFER, size * sizeof( GLfloat ), data, GL_STATIC_DRAW );

//  }

//  // Initialize the vertex array object.
//  glGenVertexArrays( 1, &( vao ) );
//  glBindVertexArray( ( vao ) );

//  int pos = glGetAttribLocation( m_programs[ program ], attribName );

//  if ( pos < 0 )
//  {

//    std::cerr << "attrib location not found for program " << program << std::endl;
//    // Unbind buffers and return
//    glBindBuffer( GL_ARRAY_BUFFER, 0 );
//    glBindVertexArray( 0 );
//    return;

//  }

//  GLuint position = static_cast< GLuint >( pos );

//  glEnableVertexAttribArray( position );
//  glVertexAttribPointer(
//                        position,
//                        2,     // Num coordinates per position
//                        GL_FLOAT, // Type
//                        GL_FALSE, // Normalized
//                        sizeof( GLfloat ) * 2, // Stride
//                        NULL   // Array buffer offset
//                        );

//  // Unbind buffers.
//  glBindBuffer( GL_ARRAY_BUFFER, 0 );
//  glBindVertexArray( 0 );

//  m_buffers[ name ] = buffer;

//} // GraphicsHandler::addUVBuffer



/////
///// \brief GraphicsHandler::addFramebuffer
///// \param buffer
///// \param width
///// \param height
///// \param texture
/////
//void
//GraphicsHandler::addFramebuffer(
//                                std::string buffer,
//                                int         width,
//                                int         height,
//                                std::string texture
//                                )
//{

//  if ( m_framebuffers.count( buffer ) )
//  {

//    Buffer buf = m_framebuffers[ buffer ];
//    glDeleteFramebuffers( 1, &( buf.vbo ) );
//    glDeleteRenderbuffers( 1, &( buf.vao ) );

//  }

//  GLuint fbo;
//  glGenFramebuffers( 1, &fbo );
//  glBindFramebuffer( GL_FRAMEBUFFER, fbo );

//  GLuint rbo;
//  glGenRenderbuffers( 1, &rbo );
//  glBindRenderbuffer( GL_RENDERBUFFER, rbo );
//  glRenderbufferStorage( GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height );
//  glBindRenderbuffer( GL_RENDERBUFFER, 0 );

//  // attach a texture to FBO color attachment point
//  glFramebufferTexture2D( GL_FRAMEBUFFER,
//                         GL_COLOR_ATTACHMENT0,
//                         GL_TEXTURE_2D,
//                         m_textures[ texture ],
//                         0 );

//  // attach a renderbuffer to depth attachment point
//  glFramebufferRenderbuffer( GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rbo );

//  glBindFramebuffer( GL_FRAMEBUFFER, 0 );

//  Buffer buf;
//  buf.vbo                  = fbo;
//  buf.vao                  = rbo;
//  m_framebuffers[ buffer ] = buf;

//} // GraphicsHandler::addFramebuffer



/////
///// \brief GraphicsHandler::bindFramebuffer
///// \param name
/////
//void
//GraphicsHandler::bindFramebuffer( std::string name )
//{

//  if ( name && m_framebuffers.count( name ) )
//  {

//    glBindFramebuffer( GL_FRAMEBUFFER, m_framebuffers[ name ].vbo );

//  }
//  else
//  {

//    glBindFramebuffer( GL_FRAMEBUFFER, 0 );

//  }

//}



/////
///// \brief GraphicsHandler::swapFramebuffers
///// \param fbo1
///// \param fbo2
/////
//void
//GraphicsHandler::swapFramebuffers(
//                                  std::string fbo1,
//                                  std::string fbo2
//                                  )
//{

//  Buffer temp = m_framebuffers[ fbo1 ];

//  m_framebuffers[ fbo1 ] = m_framebuffers[ fbo2 ];
//  m_framebuffers[ fbo2 ] = temp;

//}



///
/// \brief GraphicsHandler::clearViewport
/// \param width
/// \param height
///
void
GraphicsHandler::clearViewport( )
{

  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

}



/////
///// \brief GraphicsHandler::useProgram
///// \param program
/////
//void
//GraphicsHandler::useProgram( std::string program )
//{

//  glUseProgram( m_programs[ program ] );

//}



/////
///// \brief GraphicsHandler::setTextureUniform
///// \param program
///// \param uniform
///// \param texture
///// \param activeTex
/////
//void
//GraphicsHandler::setTextureUniform(
//                                   std::string program,
//                                   std::string uniform,
//                                   std::string texture,
//                                   int         activeTex
//                                   )
//{

//  switch ( activeTex )
//  {

//  case 0:
//    glActiveTexture( GL_TEXTURE0 );
//    break;

//  case 1:
//    glActiveTexture( GL_TEXTURE1 );
//    break;

//  case 2:
//    glActiveTexture( GL_TEXTURE2 );
//    break;

//  default:
//    glActiveTexture( GL_TEXTURE3 );
//    break;

//  } // switch

//  glUniform1i( glGetUniformLocation( m_programs[ program ], uniform ), activeTex );
//  glBindTexture( GL_TEXTURE_2D, m_textures[ texture ] );

//} // GraphicsHandler::setTextureUniform



/////
///// \brief GraphicsHandler::renderBuffer
///// \param buffer
///// \param verts
///// \param mode
/////
//void
//GraphicsHandler::renderBuffer(
//                              std::string buffer,
//                              int         verts,
//                              uint32_t    mode
//                              )
//{

//  glBindVertexArray( m_buffers[ buffer ].vao );
//  glDrawArrays( mode, 0, verts );
//  glBindVertexArray( 0 );

//}



///
/// \brief GraphicsHandler::updateWindow
///
void
GraphicsHandler::updateWindow( )
{

  upContext_->updateWindow( );

}



///
/// \brief GraphicsHandler::checkWindowShouldClose
/// \return
///
bool
GraphicsHandler::checkWindowShouldClose( )
{

  return upContext_->checkWindowShouldClose( );

}



/////
///// \brief GraphicsHandler::setBuffer
///// \param bufferName
///// \param data
///// \param size
/////
//void
//GraphicsHandler::setBuffer(
//                           std::string bufferName,
//                           float      *data,
//                           GLuint      size
//                           )
//{

//  Buffer buffer = m_buffers[ bufferName ];

//  glBindBuffer( GL_ARRAY_BUFFER, vbo );
//  glBindVertexArray( vao );
//  glBufferSubData( GL_ARRAY_BUFFER, 0, size * sizeof( float ), data );

//}



/////
///// \brief GraphicsHandler::setBoolUniform
///// \param program
///// \param uniform
///// \param var
/////
//void
//GraphicsHandler::setBoolUniform(
//                                std::string program,
//                                std::string uniform,
//                                bool        var
//                                )
//{

//  glUniform1i( glGetUniformLocation( m_programs[ program ], uniform ), var );

//}



/////
///// \brief GraphicsHandler::setIntUniform
///// \param program
///// \param uniform
///// \param value
/////
//void
//GraphicsHandler::setIntUniform(
//                               std::string program,
//                               std::string uniform,
//                               int         value
//                               )
//{

//  glUniform1i( glGetUniformLocation( m_programs[ program ], uniform ), value );

//}



/////
///// \brief GraphicsHandler::setFloatUniform
///// \param program
///// \param uniform
///// \param value
/////
//void
//GraphicsHandler::setFloatUniform(
//                                 const char  *program,
//                                 const char  *uniform,
//                                 const float *value,
//                                 int          size
//                                 )
//{

//  switch ( size )
//  {

//  case 1:
//    glUniform1f( glGetUniformLocation( m_programs[ program ], uniform ), *value );
//    break;

//  case 2:
//    glUniform2fv( glGetUniformLocation( m_programs[ program ], uniform ), 1, value );
//    break;

//  case 3:
//    glUniform3fv( glGetUniformLocation( m_programs[ program ], uniform ), 1, value );
//    break;

//  case 4:
//    glUniform4fv( glGetUniformLocation( m_programs[ program ], uniform ), 1, value );
//    break;

//  default:
//    break;

//  } // switch

//} // GraphicsHandler::setFloatUniform



/////
///// \brief GraphicsHandler::setMatrixUniform
///// \param program
///// \param uniform
///// \param value
/////
//void
//GraphicsHandler::setMatrixUniform(
//                                  const char  *program,
//                                  const char  *uniform,
//                                  const float *value,
//                                  int          size
//                                  )
//{

//  int location = glGetUniformLocation( m_programs[ program ], uniform );

//  if ( location < 0 )
//  {

//    std::cerr << "Couldn't find uniform location for " << program << std::endl;

//  }

//  switch ( size )
//  {

//  case 2:
//    glUniformMatrix2fv(
//                       location,
//                       1,
//                       GL_FALSE,
//                       value
//                       );
//    break;

//  case 3:
//    glUniformMatrix3fv(
//                       location,
//                       1,
//                       GL_FALSE,
//                       value
//                       );
//    break;

//  case 4:
//    glUniformMatrix4fv(
//                       location,
//                       1,
//                       GL_FALSE,
//                       value
//                       );
//    break;

//  default:
//    break;

//  } // switch

//} // GraphicsHandler::setMatrixUniform



/////
///// \brief GraphicsHandler::swapTextures
///// \param tex1
///// \param tex2
/////
//void
//GraphicsHandler::swapTextures(
//                              std::string tex1,
//                              std::string tex2
//                              )
//{

//  GLuint temp = m_textures[ tex1 ];

//  m_textures[ tex1 ] = m_textures[ tex2 ];
//  m_textures[ tex2 ] = temp;

//}



/////
///// \brief GraphicsHandler::setBlending
///// \param blend
/////
//void
//GraphicsHandler::setBlending( bool blend )
//{

//  if ( blend )
//  {

//    glEnable( GL_BLEND );
//    glBlendEquationSeparate( GL_FUNC_ADD, GL_FUNC_ADD );
//    glBlendFuncSeparate( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO );

//  }
//  else
//  {

//    glDisable( GL_BLEND );

//  }

//} // GraphicsHandler::setBlending



/////
///// \brief GraphicsHandler::setCallback
///// \param callback
/////
//void
//GraphicsHandler::setCallback( Callback *callback )
//{

//  if ( upContext_ )
//  {

//    glfwSetWindowUserPointer( upContext_, callback );

//  }

////  m_input->setCallback( callback );

//}



/////
///// \brief GraphicsHandler::setWindowShouldClose
///// \param close
/////
//void
//GraphicsHandler::setWindowShouldClose( bool close )
//{

//  glfwSetWindowShouldClose( upContext_, static_cast< int >( close ) );

//}



/////
///// \brief GraphicsHandler::getTime
///// \return
/////
//double
//GraphicsHandler::getTime( )
//{

//  return glfwGetTime( );

//}



/////
///// \brief GraphicsHandler::setWindowSize
///// \param width
///// \param height
/////
//void
//GraphicsHandler::setWindowSize(
//                               int width,
//                               int height
//                               )
//{

//  glfwSetWindowSize( upContext_, width, height );
//  resize( width, height );

//}



/////
///// \brief GraphicsHandler::resize
///// \param width
///// \param height
/////
//void
//GraphicsHandler::resize(
//                        int width,
//                        int height
//                        )
//{

//  viewWidth_  = width;
//  viewHeight_ = height;

//}



///
/// \brief GraphicsHandler::makeContextCurrent
///
void
GraphicsHandler::makeContextCurrent( )
{

  upContext_->makeWindowCurrent( );

}



/////
///// \brief GraphicsHandler::_initGLFW
///// \param title
///// \return
/////
//bool
//GraphicsHandler::_initWindow(
//                             std::string title,
//                             GLFWwindow *sharedContext
//                             )
//{

//  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
//  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 2 );
//  glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
//  glfwWindowHint(        GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

//  // until resize is implemented
//  glfwWindowHint(             GLFW_RESIZABLE, GL_FALSE );

//  //
//  // no title means no visibility
//  //
//  if ( title.length( ) == 0 )
//  {

//    glfwWindowHint( GLFW_VISIBLE, GL_FALSE );

//  }
//  else
//  {

//    glfwWindowHint( GLFW_VISIBLE, GL_TRUE );

//  }

//  upContext_ =
//    glfwCreateWindow( viewWidth_, viewHeight_, title.c_str( ), 0, sharedContext );

//  if ( !upContext_ )
//  {

//    return false;

//  }

//  m_initialized = true;

//  /* Make the window's context current */
//  glfwMakeContextCurrent( upContext_ );

//  glfwSwapInterval( 1 );

//  /* set default callback functions */
//  glfwSetWindowSizeCallback( upContext_, CallbackSingleton::windowSizeCallback  );
//  glfwSetWindowFocusCallback( upContext_, CallbackSingleton::windowFocusCallback );

//  glfwSetMouseButtonCallback( upContext_, CallbackSingleton::mouseButtonCallback );
//  glfwSetKeyCallback( upContext_, CallbackSingleton::keyCallback );
//  glfwSetCursorPosCallback( upContext_, CallbackSingleton::cursorPositionCallback );
//  glfwSetScrollCallback( upContext_, CallbackSingleton::scrollCallback );

//  return true;

//} // GraphicsHandler::_initGLFW



/////
///// \brief GraphicsHandler::_initGLEW
///// \return
/////
//bool
//GraphicsHandler::_initGLEW( )
//{

//  glewExperimental = GL_TRUE;
//  GLenum err = glewInit( );
//  glGetError( );   // Clear errors after call to glewInit

//  if ( GLEW_OK != err )
//  {

//    // Problem: glewInit failed, something is seriously wrong.
//    std::cerr << "Error initializing glew: ";
//    std::cerr << glewGetErrorString( err ) << std::endl;
//    return false;

//  }

//  // Enable depth testing, so that objects are occluded based on depth instead of drawing order.
//  glEnable( GL_DEPTH_TEST );

//  // Move the polygons back a bit so lines are still drawn even though they are coplanar with the
//  // polygons they came from, which will be drawn before them.
//  glEnable( GL_POLYGON_OFFSET_LINE );
//  glPolygonOffset( -1, -1 );

//  // Enable back-face culling, meaning only the front side of every face is rendered.
//  glEnable( GL_CULL_FACE );
//  glCullFace( GL_BACK );

//  // Specify that the front face is represented by vertices in counterclockwise order (this is
//  // the default).
//  glFrontFace( GL_CCW );

//  // Specify the color used when glClear is called
//  glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

//  return true;

//} // GraphicsHandler::_initGLEW



/////
///// \brief GraphicsHandler::_terminateGLFW
/////        Can be called repeatedly with no adverse effects.
/////
//void
//GraphicsHandler::_terminateWindow( )
//{

//  if ( !m_initialized )
//  {

//    return;

//  }

//  if ( upContext_ )
//  {

//    glfwDestroyWindow( upContext_ );
//    upContext_ = NULL;

//  }

//  m_initialized = false;

//} // GraphicsHandler::_terminateGLFW



/////
///// \brief GraphicsHandler::_readFile
///// \param filePath
///// \return
/////
//std::string
//GraphicsHandler::_readFile( std::string filePath )
//{

//  std::string content;
//  std::ifstream fileStream( filePath, std::ios::in );

//  if ( !fileStream.is_open( ) )
//  {

//    std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
//    return "";

//  }

//  std::string line = "";

//  while ( !fileStream.eof( ) )
//  {

//    std::getline( fileStream, line );
//    content.append( line + "\n" );

//  }

//  fileStream.close( );
//  return content;

//} // GraphicsHandler::_readFile



/////
///// \brief GraphicsHandler::_loadShader
///// \param vertex_path
///// \param fragment_path
///// \return
/////
//GLuint
//GraphicsHandler::_loadShader(
//                             std::string vertex_path,
//                             std::string fragment_path
//                             )
//{

//  GLuint vertShader = glCreateShader( GL_VERTEX_SHADER );
//  GLuint fragShader = glCreateShader( GL_FRAGMENT_SHADER );

//  // Read shaders
//  std::string vertShaderStr = _readFile( vertex_path );
//  std::string fragShaderStr = _readFile( fragment_path );
//  std::string vertShaderSrc = vertShaderStr.c_str( );
//  std::string fragShaderSrc = fragShaderStr.c_str( );

//  GLint result = GL_FALSE;
//  int logLength;

//  // Compile vertex shader
//  glShaderSource( vertShader, 1, &vertShaderSrc, NULL );
//  glCompileShader( vertShader );

//  // Check vertex shader
//  glGetShaderiv( vertShader, GL_COMPILE_STATUS,  &result );
//  glGetShaderiv( vertShader, GL_INFO_LOG_LENGTH, &logLength );
//  std::vector< char > vertShaderError(
//                                      ( logLength >
//                                       1 ) ? static_cast< unsigned long >( logLength ) : 1 );
//  glGetShaderInfoLog( vertShader, logLength, NULL, &vertShaderError[ 0 ] );

//  if ( vertShaderError.size( ) > 1 )
//  {
//    std::cout << &vertShaderError[ 0 ] << std::endl;
//  }

//  // Compile fragment shader
//  glShaderSource( fragShader, 1, &fragShaderSrc, NULL );
//  glCompileShader( fragShader );

//  // Check fragment shader
//  glGetShaderiv( fragShader, GL_COMPILE_STATUS,  &result );
//  glGetShaderiv( fragShader, GL_INFO_LOG_LENGTH, &logLength );
//  std::vector< char > fragShaderError(
//                                      ( logLength >
//                                       1 ) ? static_cast< unsigned long >( logLength ) : 1 );
//  glGetShaderInfoLog( fragShader, logLength, NULL, &fragShaderError[ 0 ] );

//  if ( fragShaderError.size( ) > 1 )
//  {
//    std::cout << &fragShaderError[ 0 ] << std::endl;
//  }

//  GLuint program = glCreateProgram( );
//  glAttachShader( program, vertShader );
//  glAttachShader( program, fragShader );
//  glLinkProgram( program );

//  glGetProgramiv( program, GL_LINK_STATUS,     &result );
//  glGetProgramiv( program, GL_INFO_LOG_LENGTH, &logLength );
//  std::vector< char > programError(
//                                   ( logLength >
//                                    1 ) ? static_cast< unsigned long >( logLength ) : 1 );
//  glGetProgramInfoLog( program, logLength, NULL, &programError[ 0 ] );

//  if ( programError.size( ) > 1 )
//  {
//    std::cout << &programError[ 0 ] << std::endl;
//  }

//  glDeleteShader( vertShader );
//  glDeleteShader( fragShader );

//  return program;

//} // GraphicsHandler::_loadShader



} // namespace graphics
