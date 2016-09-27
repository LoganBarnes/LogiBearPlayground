#include <iostream>
#include <exception>
#include "ProjectConfig.hpp"
#include "Driver.hpp"
#include "World.hpp"
#include "Renderer.hpp"


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

  lbp::Driver::printProjectInfo(
                                lbp::PROJECT_NAME,
                                lbp::VERSION_MAJOR,
                                lbp::VERSION_MINOR,
                                lbp::VERSION_PATCH
                                );

  try
  {

    /// \todo Create a vector of all worlds/renderers
    ///       and pass that to the driver instead. It
    ///       will allow the driver to toggle through
    ///       different project implementations
    lbp::World    world;
    lbp::Renderer renderer( world );

    lbp::Driver driver( world, renderer );

    return driver.exec( argc, argv );

  }
  catch ( std::exception &e )
  {

    std::cerr << "ERROR: failed construction: " << e.what() << std::endl;

    return -1;

  }



} // main
