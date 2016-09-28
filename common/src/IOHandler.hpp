#ifndef IoHandler_hpp
#define IoHandler_hpp


namespace lbc
{


class World;


/////////////////////////////////////////////
/// \brief The IOHandler class
///
/// \author LogiBear
/////////////////////////////////////////////
class IOHandler
{

public:

  ///////////////////////////////////////////////////////////////
  /// \brief Renderer
  ///////////////////////////////////////////////////////////////
  IOHandler( World &world );


  ///////////////////////////////////////////////////////////////
  /// \brief ~Renderer
  ///////////////////////////////////////////////////////////////
  virtual
  ~IOHandler( );


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


  ///////////////////////////////////////////////////////////////
  /// \brief isExitRequested
  /// \return true if the user requested to exit the program
  ///////////////////////////////////////////////////////////////
  bool
  isExitRequested( ) { return exitRequested_; }


protected:

  World &world_;
  bool   exitRequested_;

};


} // namespace lbp


#endif // IoHandler_hpp
