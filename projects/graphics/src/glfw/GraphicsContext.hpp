#ifndef GraphicsContext_hpp
#define GraphicsContext_hpp


namespace graphics
{


///
/// \brief The GraphicsContext class
///
class GraphicsContext
{

public:

  virtual
  ~GraphicsContext( ) {}

  ///
  /// \brief updateWindow
  ///
  virtual
  void updateWindow ( ) = 0;

  ///
  /// \brief checkWindowShouldClose
  /// \return
  ///
  virtual
  bool checkWindowShouldClose ( ) = 0;

  ///
  /// \brief makeWindowCurrent
  ///
  virtual
  void makeWindowCurrent( ) = 0;


};


} // namespace graphics


#endif // GraphicsContext_hpp
