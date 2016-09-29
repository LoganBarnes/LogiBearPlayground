#include "IOHandler.hpp"

#include <iostream>
#include <csignal>
#include <memory>
#include <functional>
#include <random>


namespace lbc
{


namespace
{

bool signalCaught( false );

///
/// \brief signalHandler
/// \param signum
///
void
signalHandler( int signum )
{

  std::cout << "Caught signal" << std::endl;

  signalCaught = ( signum == SIGINT );

}



}


/////////////////////////////////////////////
/// \brief Renderer::Renderer
///
/// \author LogiBear
/////////////////////////////////////////////
IOHandler::IOHandler(
                     World &world,
                     bool   printInfo
                     )
  :
  world_          ( world )
  , exitRequested_( false )
{

  signal ( SIGINT, signalHandler );

  if ( printInfo )
  {

    std::cout << "Press 'CTRL + C' to exit" << std::endl;

  }

}



/////////////////////////////////////////////
/// \brief Renderer::~Renderer
///
/// \author LogiBear
/////////////////////////////////////////////
IOHandler::~IOHandler( )
{}


/////////////////////////////////////////////
/// \brief Renderer::render
/// \param alpha
///
/// \author LogiBear
/////////////////////////////////////////////
void
IOHandler::showWorld( const double )
{}



/////////////////////////////////////////////
/// \brief IOHandler::updateIO
///
/// \author LogiBear
/////////////////////////////////////////////
void
IOHandler::updateIO( )
{

  exitRequested_ |= signalCaught;

}



} // namespace lbp
