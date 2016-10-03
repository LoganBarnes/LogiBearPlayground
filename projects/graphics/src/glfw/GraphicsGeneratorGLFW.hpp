#ifndef GraphicsGeneratorGLFW_hpp
#define GraphicsGeneratorGLFW_hpp


#include "GraphicsGenerator.hpp"


namespace graphics
{


class GraphicsHandler;
class GraphicsWindow;


class GraphicsGeneratorGLFW : public GraphicsGenerator
{

public:

  GraphicsGeneratorGLFW( );

  virtual
  ~GraphicsGeneratorGLFW( );

  virtual
  GraphicsHandler &generateHandler (
                                    std::string  title  = "Window",
                                    unsigned int width  = DEFAULT_VIEW_WIDTH,
                                    unsigned int height = DEFAULT_VIEW_HEIGHT
                                    );

  virtual
  void checkEvents ( );


private:

  bool _initGLFW ( );

  void _terminateGLFW ( );

  bool glfwInitialized_;

};


} // namespace graphics


#endif // GraphicsGeneratorGLFW_hpp
