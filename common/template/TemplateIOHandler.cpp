#include "@NEW_PROJECT@IOHandler.hpp"

#include <iostream>
#include <csignal>
#include <memory>
#include <functional>
#include <random>

#include "@NEW_PROJECT@World.hpp"


namespace @NEW_PROJECT_NAMESPACE@
{


/////////////////////////////////////////////
/// \brief @NEW_PROJECT@IOHandler::@NEW_PROJECT@IOHandler
///
/// \author LogiBear
/////////////////////////////////////////////
@NEW_PROJECT@IOHandler::@NEW_PROJECT@IOHandler( @NEW_PROJECT@World &world )
  :
  lbc::IOHandler  ( world, true ) // prints info from IOHandler
  , world_        ( world )
  , exitRequested_( false )
{}



/////////////////////////////////////////////
/// \brief @NEW_PROJECT@IOHandler::~@NEW_PROJECT@IOHandler
///
/// \author LogiBear
/////////////////////////////////////////////
@NEW_PROJECT@IOHandler::~@NEW_PROJECT@IOHandler( )
{}


/////////////////////////////////////////////
/// \brief @NEW_PROJECT@IOHandler::render
/// \param alpha
///
/// \author LogiBear
/////////////////////////////////////////////
void
@NEW_PROJECT@IOHandler::showWorld( const double )
{}



/////////////////////////////////////////////
/// \brief @NEW_PROJECT@IOHandler::updateIO
///
/// \author LogiBear
/////////////////////////////////////////////
void
@NEW_PROJECT@IOHandler::updateIO( )
{

  lbc::IOHandler::updateIO( );

}



} // namespace @NEW_PROJECT_NAMESPACE@
