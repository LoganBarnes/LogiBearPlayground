#include <iostream>
#include <exception>
#include "@NEW_PROJECT@Config.hpp"
#include "Common/Driver.hpp"
#include "@NEW_PROJECT@World.hpp"
#include "@NEW_PROJECT@IOHandler.hpp"


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
                                @NEW_PROJECT_NAMESPACE@::PROJECT_NAME,
                                @NEW_PROJECT_NAMESPACE@::VERSION_MAJOR,
                                @NEW_PROJECT_NAMESPACE@::VERSION_MINOR,
                                @NEW_PROJECT_NAMESPACE@::VERSION_PATCH
                                );

  try
  {

    //
    // create world to handle physical updates
    // and ioHandler to interface between the
    // world and the user
    //
    @NEW_PROJECT_NAMESPACE@::@NEW_PROJECT@World     world;
    @NEW_PROJECT_NAMESPACE@::@NEW_PROJECT@IOHandler renderer( world );

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
