#ifndef @NEW_PROJECT@IoHandler_hpp
#define @NEW_PROJECT@IoHandler_hpp


#include "Common/IOHandler.hpp"


namespace @NEW_PROJECT_NAMESPACE@
{


class @NEW_PROJECT@World;


/////////////////////////////////////////////
/// \brief The @NEW_PROJECT@IOHandler class
///
/// \author LogiBear
/////////////////////////////////////////////
class @NEW_PROJECT@IOHandler : public lbc::IOHandler
{

public:

  ///////////////////////////////////////////////////////////////
  /// \brief @NEW_PROJECT@IOHandler
  ///////////////////////////////////////////////////////////////
  @NEW_PROJECT@IOHandler( @NEW_PROJECT@World &world );


  ///////////////////////////////////////////////////////////////
  /// \brief ~@NEW_PROJECT@IOHandler
  ///////////////////////////////////////////////////////////////
  virtual
  ~@NEW_PROJECT@IOHandler( );


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

  @NEW_PROJECT@World &world_;
  bool exitRequested_;

};


} // namespace @NEW_PROJECT_NAMESPACE@


#endif // @NEW_PROJECT@IoHandler_hpp
