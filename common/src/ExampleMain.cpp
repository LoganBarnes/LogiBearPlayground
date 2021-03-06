#include <iostream>
#include <exception>
#include "CommonConfig.hpp"
#include "Driver.hpp"
#include "World.hpp"
#include "IOHandler.hpp"


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
                                lbc::PROJECT_NAME,
                                lbc::VERSION_MAJOR,
                                lbc::VERSION_MINOR,
                                lbc::VERSION_PATCH
                                );

  try
  {

    //
    // create world to handle physical updates
    // and ioHandler to interface between the
    // world and the user
    //
    lbc::World     world;
    lbc::IOHandler renderer( world );

    //
    // pass world and ioHandler to driver
    // to manage update loops
    //
    lbc::Driver driver( world, renderer );

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
