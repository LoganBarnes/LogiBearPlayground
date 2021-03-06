#ifndef Callback_hpp
#define Callback_hpp


#include <iostream>


namespace graphics
{


class Callback
{

public:

  virtual
  ~Callback( ) {}

  /**
   * @brief handleError
   * @param error
   * @param description
   */
  virtual void
  handleError(
              int         error,
              const char *description
              )
  {

    std::cerr << "ERROR: (" << error << ") " << description << std::endl;

  }


  /**
   * @brief handleWindowSize
   * @param window
   * @param width
   * @param height
   */
  virtual void
  handleWindowSize(
                   GLFWwindow*,
                   int,
                   int
                   ) {}

  /**
   * @brief handleWindowFocus
   * @param window
   * @param focus
   */
  virtual void
  handleWindowFocus(
                    GLFWwindow*,
                    int
                    ) {}

  /**
   * @brief handleMouseButton
   * @param window
   * @param button
   * @param action
   * @param mods
   */
  virtual void
  handleMouseButton(
                    GLFWwindow*,
                    int,
                    int,
                    int
                    ) {}

  /**
   * @brief handleKey
   * @param window
   * @param key
   * @param scancode
   * @param action
   * @param mods
   */
  virtual void
  handleKey(
            GLFWwindow*,
            int,
            int,
            int,
            int
            ) {}

  /**
   * @brief handleCursorPosition
   * @param window
   * @param xpos
   * @param ypos
   */
  virtual void
  handleCursorPosition(
                       GLFWwindow*,
                       double,
                       double
                       ) {}

  /**
   * @brief handleScroll
   * @param window
   * @param xoffset
   * @param yoffset
   */
  virtual void
  handleScroll(
               GLFWwindow*,
               double,
               double
               ) {}

};


} // namespace graphics


#endif // Callback_hpp
