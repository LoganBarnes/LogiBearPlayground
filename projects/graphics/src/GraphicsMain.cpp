#include <iostream>
#include <exception>
#include "GraphicsConfig.hpp"
#include "Common/Driver.hpp"
#include "Common/World.hpp"
#include "GraphicsIOHandler.hpp"


/////////////////////////////////////////////
/// \brief main
/// \return
///
/// \author LogiBear
/////////////////////////////////////////////
int
main(
     int          argc, ///< number of arguments
     const char **argv  ///< array of argument strings
     )
{

  lbc::Driver::printProjectInfo(
                                graphics::PROJECT_NAME,
                                graphics::VERSION_MAJOR,
                                graphics::VERSION_MINOR,
                                graphics::VERSION_PATCH
                                );

  try
  {

    //
    // create world to handle physical updates
    // and ioHandler to interface between the
    // world and the user
    //
    lbc::World             world;
    graphics::GraphicsIOHandler ioHandler( world );

    //
    // pass world and ioHandler to driver
    // to manage update loops
    //
    lbc::Driver driver( world, ioHandler );

    //
    // run program
    //
    return driver.exec( argc, argv );

  }
  catch ( std::exception &e )
  {

    std::cerr << "ERROR: program failed: " << e.what( ) << std::endl;

    return -1;

  }



} // main
