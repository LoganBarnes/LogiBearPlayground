#ifndef GraphicsIOHandler_hpp
#define GraphicsIOHandler_hpp


#include <memory>
#include <vector>
#include "Common/IOHandler.hpp"


namespace lbc
{

class World;

}


namespace graphics
{


class GraphicsGenerator;
class GraphicsHandler;


/////////////////////////////////////////////
/// \brief The GraphicsIOHandler class
///
/// \author LogiBear
/////////////////////////////////////////////
class GraphicsIOHandler : public lbc::IOHandler
{

public:

  ///////////////////////////////////////////////////////////////
  /// \brief Renderer
  ///////////////////////////////////////////////////////////////
  GraphicsIOHandler( lbc::World &world );


  ///////////////////////////////////////////////////////////////
  /// \brief ~Renderer
  ///////////////////////////////////////////////////////////////
  virtual
  ~GraphicsIOHandler( );


  ///////////////////////////////////////////////////////////////
  /// \brief render
  /// \param alpha
  ///////////////////////////////////////////////////////////////
  virtual
  void showWorld ( const double alpha );


  ///////////////////////////////////////////////////////////////
  /// \brief updateIO
  ///
  ///        Checks for keystrokes or mouse movement (or
  ///        alternate controllers) and updates output text,
  ///        images, or buffer swaps not handled by showWorld()
  ///
  ///////////////////////////////////////////////////////////////
  virtual
  void updateIO ( );


private:

  std::unique_ptr< GraphicsGenerator > upGraphicsGenerator_;

  std::vector< std::reference_wrapper< GraphicsHandler > > handlers_;


};


} // namespace graphics


#endif // GraphicsIOHandler_hpp
