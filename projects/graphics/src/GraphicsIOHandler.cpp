#include "GraphicsIOHandler.hpp"


namespace graphics
{


/////////////////////////////////////////////
/// \brief Renderer::Renderer
///
/// \author LogiBear
/////////////////////////////////////////////
GraphicsIOHandler::GraphicsIOHandler( lbc::World &world )
  :
  lbc::IOHandler( world )
{}



/////////////////////////////////////////////
/// \brief Renderer::~Renderer
///
/// \author LogiBear
/////////////////////////////////////////////
GraphicsIOHandler::~GraphicsIOHandler( )
{}


/////////////////////////////////////////////
/// \brief Renderer::render
/// \param alpha
///
/// \author LogiBear
/////////////////////////////////////////////
void
GraphicsIOHandler::showWorld( const double )
{}



/////////////////////////////////////////////
/// \brief GraphicsIOHandler::updateIO
///
/// \author LogiBear
/////////////////////////////////////////////
void
GraphicsIOHandler::updateIO( )
{

  lbc::IOHandler::updateIO( );

}


} // namespace lbp
