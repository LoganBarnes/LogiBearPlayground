#ifndef GraphicsContextGLFW_hpp
#define GraphicsContextGLFW_hpp


#include <string>
#include "GraphicsContext.hpp"
#include "GraphicsConstants.hpp"


struct GLFWwindow;
typedef GLFWwindow GLFWwindow;


namespace graphics
{


///
/// \brief The GraphicsContextGLFW class
///
class GraphicsContextGLFW : public GraphicsContext
{

public:

  GraphicsContextGLFW(
                      const std::string          title          = "GLFW Window",
                      const int                  width          = DEFAULT_VIEW_WIDTH,
                      const int                  height         = DEFAULT_VIEW_HEIGHT,
                      const GraphicsContextGLFW *pSharedContext = 0
                      );

  virtual
  ~GraphicsContextGLFW( );


  virtual
  void updateWindow ( );

  virtual
  bool checkWindowShouldClose ( );

  virtual
  void makeWindowCurrent ( );


private:

  void _initWindow (
                    const std::string          title,
                    const int                  width,
                    const int                  height,
                    const GraphicsContextGLFW *pSharedContext
                    );

  void _initGL ( );


  GLFWwindow *pWindow_;


};


} // namespace graphics


#endif // GraphicsContextGLFW_hpp
