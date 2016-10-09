#ifndef GraphicsHandler_hpp
#define GraphicsHandler_hpp

#include <memory>
#include "GraphicsConstants.hpp"


namespace graphics
{


class CallbackSingleton;
class Callback;
class GraphicsContext;


class GraphicsHandler
{

public:

  GraphicsHandler(
                  std::unique_ptr< GraphicsContext > &upContext,
                  const int                           width   = DEFAULT_VIEW_WIDTH,
                  const int                           height  = DEFAULT_VIEW_HEIGHT
                  );

  virtual
  ~GraphicsHandler( );

  //
  // GL calls
  //
  void clearViewport ( );


  //
  // context calls
  //
  void makeContextCurrent ( );
  void updateWindow ( );
  bool checkWindowShouldClose ( );


private:

  std::unique_ptr< GraphicsContext > upContext_;

  int viewWidth_, viewHeight_;


};


} // namespace graphics


#endif // GraphicsHandler_hpp
