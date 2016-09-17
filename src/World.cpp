#include "World.hpp"


namespace lbp
{


///
/// \brief World::World
///
World::World( )
  :
  requestExit_( false )
{}


///
/// \brief World::~World
///
World::~World( )
{}



///
/// \brief World::update
///
void
World::update(
              const double worldTime, ///< update to this time
              const double            ///< interval since last update
              )
{

  if ( worldTime > 3.0 )
  {

    requestExit( );

  }

}



} // namespace lbp
