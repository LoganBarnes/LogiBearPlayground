#ifndef World_hpp
#define World_hpp


namespace lbc
{

/////////////////////////////////////////////
/// \brief The World class
///
/// \author LogiBear
/////////////////////////////////////////////
class World
{

public:

  ///////////////////////////////////////////////////////////////
  /// \brief World
  ///////////////////////////////////////////////////////////////
  World( );


  ///////////////////////////////////////////////////////////////
  /// \brief ~World
  ///////////////////////////////////////////////////////////////
  virtual
  ~World( );


  ///////////////////////////////////////////////////////////////
  /// \brief update
  ///////////////////////////////////////////////////////////////
  virtual
  void update (
               const double worldTime, ///< update to this time
               const double timestep   ///< interval since last update
               );


  ///////////////////////////////////////////////////////////////
  /// \brief requestExit_
  ///////////////////////////////////////////////////////////////
  void
  requestExit( ) { requestExit_ = true; }

  ///////////////////////////////////////////////////////////////
  /// \brief requestingExit
  /// \return
  ///////////////////////////////////////////////////////////////
  bool
  requestingExit( ) { return requestExit_; }


private:

  bool requestExit_;

};


} // end namespace lbp


#endif // World_hpp
