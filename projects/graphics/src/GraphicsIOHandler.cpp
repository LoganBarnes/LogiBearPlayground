#include "GraphicsIOHandler.hpp"

#include <sstream>
#include <iostream>

#include "GraphicsGeneratorGLFW.hpp"
#include "GraphicsHandler.hpp"


namespace graphics
{


/////////////////////////////////////////////
/// \brief Renderer::Renderer
///
/// \author LogiBear
/////////////////////////////////////////////
GraphicsIOHandler::GraphicsIOHandler( lbc::World &world )
  :
  lbc::IOHandler( world, false )
  , upGraphicsGenerator_( new GraphicsGeneratorGLFW( ) )
{

  try
  {

    handlers_.push_back( upGraphicsGenerator_->generateHandler( "Main" ) );

  }
  catch ( const std::exception &e )
  {

    std::stringstream msg;
    msg << "Failed to init GraphicsIOHandler: " << e.what( );
    throw( std::runtime_error( msg.str( ) ) );

  }

//  std::cout << "Press 'ESC' to exit" << std::endl;

}



/////////////////////////////////////////////
/// \brief Renderer::~Renderer
///
/// \author LogiBear
/////////////////////////////////////////////
GraphicsIOHandler::~GraphicsIOHandler( )
{

  handlers_.clear( );

}



/////////////////////////////////////////////
/// \brief Renderer::render
/// \param alpha
///
/// \author LogiBear
/////////////////////////////////////////////
void
GraphicsIOHandler::showWorld( const double )
{

  //
  // iterate through all contexts and render scene
  //
  for ( auto iter = handlers_.begin( ); iter != handlers_.end( ); ++iter )
  {

    GraphicsHandler &handler = *iter;

    handler.makeContextCurrent( );
    handler.clearViewport( );

    //
    // render
    //

    handler.updateWindow( );

  }

}



/////////////////////////////////////////////
/// \brief GraphicsIOHandler::updateIO
///
/// \author LogiBear
/////////////////////////////////////////////
void
GraphicsIOHandler::updateIO( )
{

  //
  // check input events and close requests
  //
  upGraphicsGenerator_->checkEvents( );

  //
  // iterate through all contexts and check for close requests
  //
  for ( auto iter = handlers_.begin( ); iter != handlers_.end( ); ++iter )
  {

    GraphicsHandler &handler = *iter;

    exitRequested_ |= handler.checkWindowShouldClose( );

  }

}



} // namespace lbp
