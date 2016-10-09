#ifndef GraphicsGenerator_hpp
#define GraphicsGenerator_hpp


#include <memory>
#include <string>
#include <vector>


#include "GraphicsConstants.hpp"


namespace graphics
{


class GraphicsContext;
class GraphicsHandler;


///
/// \brief The GraphicsGenerator class
///
class GraphicsGenerator
{

public:

  virtual
  ~GraphicsGenerator( );

  virtual
  GraphicsHandler &generateHandler (
                                    std::string  title  = "Window",
                                    unsigned int width  = DEFAULT_VIEW_WIDTH,
                                    unsigned int height = DEFAULT_VIEW_HEIGHT
                                    ) = 0;

  virtual
  void checkEvents( ) = 0;

  void removeHandler ( GraphicsHandler &handler );

  unsigned int getNumHandlers ( );


protected:

  std::vector< std::unique_ptr< GraphicsHandler > > handlers_;


};


} // namespace graphics


#endif // GraphicsGenerator_hpp
