#include <iostream>
#include <exception>
#include "ProjectConfig.hpp"
#include "Driver.hpp"
#include "World.hpp"
#include "Renderer.hpp"


///
/// \brief main
/// \return
///
int
main(
     int    argc,
     char **argv
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

    lbp::World    world;
    lbp::Renderer renderer( world );

    lbp::Driver driver( world, renderer );

    return driver.exec( argc, argv );

  }
  catch ( std::exception &e )
  {

    std::cerr << "ERROR: failed construction: " << e.what() << std::endl;

    return 1;

  }



} // main
