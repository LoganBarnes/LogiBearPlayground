#ifndef GraphicsContext_hpp
#define GraphicsContext_hpp


namespace graphics
{


class GraphicsContext
{

public:

  virtual
  ~GraphicsContext( ) {}

  virtual
  void updateWindow ( ) = 0;

  virtual
  bool checkWindowShouldClose ( ) = 0;

  virtual
  void makeWindowCurrent( ) = 0;


};


} // namespace graphics


#endif // GraphicsContext_hpp
