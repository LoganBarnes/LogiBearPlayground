#include "Driver.hpp"
#include "World.hpp"
#include "IOHandler.hpp"


#include <iostream>
#include <sstream>


namespace lbc
{


namespace
{

const double MAX_TIMESTEP_NFTR_LOOP = 0.05;

}


/////////////////////////////////////////////
/// \brief Driver::Driver
/// \param world
///
/// \author LogiBear
/////////////////////////////////////////////
Driver::Driver(
               World     &world,
               IOHandler &ioHandler
               ) noexcept
  :
  timeScale_    ( 1.0 )
  , paused_     ( false )
  , world_      ( world )
  , ioHandler_   ( ioHandler )
  , startTime_  ( 0.0 )
  , timeStep_   ( 0.1 )
  , worldTime_  ( startTime_ )
  , updateFrame_( 0 )
  , initTime_   ( std::chrono::system_clock::now( ) )
{}



/////////////////////////////////////////////
/// \brief Driver::~Driver
///
/// \author LogiBear
/////////////////////////////////////////////
Driver::~Driver( )
{}


/////////////////////////////////////////////
/// \brief Driver::exec
/// \return
///
/// \author LogiBear
/////////////////////////////////////////////
int
Driver::exec(
             int          argc, ///< number of arguments
             const char **argv  ///< array of argument strings
             )
{

  bool useDefaultLoop( true );

  for ( int i = 1; i < argc; ++i )
  {

    if ( std::string( argv[ i ] ) == "-r" )
    {

      useDefaultLoop = false;

    }
    else
    {

      std::cerr << "WARNING: Unknown argument given: " << argv[ i ] << std::endl;

    }

  }

  if ( useDefaultLoop )
  {

    _runAFAPLoop( );

  }
  else
  {

    _runNFTRLoop( );

  }

  return 0;

} // Driver::exec



/////////////////////////////////////////////
/// \brief Driver::_runAFAPLoop
///
/// \author LogiBear
/////////////////////////////////////////////
void
Driver::_runAFAPLoop( )
{

  while ( !ioHandler_.isExitRequested( ) )
  {

    if ( !paused_ )
    {

      world_.update( worldTime_, timeStep_ );
      ++updateFrame_;
      worldTime_ = updateFrame_ * timeStep_ + startTime_;

    }

    ioHandler_.showWorld( 1.0 );

    ioHandler_.updateIO( );

    ///\todo print timing info

  }

} // Driver::_runAFAPLoop



/////////////////////////////////////////////
/// \brief Driver::_runNFTRLoop
///
/// \author LogiBear
/////////////////////////////////////////////
void
Driver::_runNFTRLoop( )
{

  //
  // physics game loop:
  // http://gafferongames.com/game-physics/fix-your-timestep/
  //

  double currentTime = _getTimeSeconds( );
  double accumulator = 0.0;

  double deltaTime = timeStep_ * timeScale_;

  double newTime, frameTime, alpha;

  //
  // Loop until the user closes the window
  //
  while ( !ioHandler_.isExitRequested( ) )
  {

    if ( !paused_ )
    {

      newTime   = _getTimeSeconds( );
      frameTime = newTime - currentTime;

      if ( frameTime > MAX_TIMESTEP_NFTR_LOOP )
      {

        frameTime = MAX_TIMESTEP_NFTR_LOOP;

      }

      currentTime = newTime;

      accumulator += frameTime;

      deltaTime = timeStep_ * timeScale_;

      while ( accumulator >= deltaTime )
      {

        world_.update( worldTime_, deltaTime );

        worldTime_  += deltaTime;
        accumulator -= deltaTime;

        ///\todo print timing info

      }

    }
    else
    {

      currentTime = _getTimeSeconds( );

    }

    alpha = accumulator / deltaTime;

    ioHandler_.showWorld( alpha );

    ioHandler_.updateIO( );

    ///\todo print timing info

  }

} // Driver::_runNFTRLoop



/////////////////////////////////////////////
/// \brief Driver::_getTimeSeconds
///
/// \author LogiBear
/////////////////////////////////////////////
double
Driver::_getTimeSeconds( )
{

  //
  // current time
  //
  std::chrono::time_point< std::chrono::system_clock > timeNow;
  timeNow = std::chrono::system_clock::now( );

  //
  // time since initialization
  //
  std::chrono::duration< float > timeElapsedSecs = timeNow - initTime_;
  return timeElapsedSecs.count( );

}



/////////////////////////////////////////////
/// \brief Driver::printProjectInfo
///
/// \author LogiBear
/////////////////////////////////////////////
void
Driver::printProjectInfo(
                         std::string name,         ///<
                         std::string versionMajor, ///<
                         std::string versionMinor, ///<
                         std::string versionPatch  ///<
                         )
{

  std::stringstream info;
  info << "#  Running "
       << name << " v"
       << versionMajor << "."
       << versionMinor << "."
       << versionPatch << "  #";

  std::string borders( info.str( ).length( ), '#' );

  std::cout << borders << '\n' << info.str( ) << '\n' << borders << std::endl;

}



} // namespace lbp
