#ifndef GraphicsHandler_hpp
#define GraphicsHandler_hpp

#include <string>
#include <unordered_map>
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
                  const int                          width   = DEFAULT_VIEW_WIDTH,
                  const int                          height  = DEFAULT_VIEW_HEIGHT
                  );

  virtual
  ~GraphicsHandler( );


//  void addProgram (
//                   std::string name,
//                   std::string vertFilePath,
//                   std::string fragFilePath
//                   );

//  void addTextureArray (
//                        std::string name,
//                        int         width,
//                        int         height,
//                        float      *array = NULL,
//                        bool        linear = false
//                        );

//  void addTextureImage (
//                        std::string name,
//                        int         width,
//                        int         height,
//                        std::string filename
//                        );

//  void updateTexture  (
//                       std::string name,
//                       int         xoffset,
//                       int         yoffset,
//                       int         width,
//                       int         height,
//                       float      *array
//                       );

//  void setTexture (
//                   std::string  name,
//                   unsigned int texture,
//                   bool         linear = false
//                   );

//  unsigned int
//  getVBO( std::string buffer )
//  { return m_buffers[ buffer ]; }


//  void addVBO (
//               std::string  buffer,
//               float       *data,
//               unsigned int size,
//               bool         dynamic = false
//               );

//  void addVAO (
//               unsigned int vbo,
//               std::string  name,
//               std::string  program,
//               bool         shared = false
//               );

//  void addVAO2 (
//                unsigned int vbo,
//                std::string  name,
//                std::string  program,
//                bool         shared = false
//                );

//  void addUVBuffer (
//                    std::string  buffer,
//                    std::string  program,
//                    std::string  attribName,
//                    float       *data,
//                    unsigned int size,
//                    bool         dynamic = false
//                    );

//  void addFramebuffer (
//                       std::string buffer,
//                       int         width,
//                       int         height,
//                       std::string texture
//                       );
//  void bindFramebuffer ( std::string name );
//  void swapFramebuffers (
//                         std::string fbo1,
//                         std::string fbo2
//                         );

  void clearViewport ( );

//  void useProgram ( std::string program );
//  void renderBuffer (
//                     std::string buffer,
//                     int         verts,
//                     uint32_t    mode
//                     );

//  void setTextureUniform (
//                          std::string program,
//                          std::string uniform,
//                          std::string texture,
//                          int         activeTex
//                          );
//  void setBoolUniform (
//                       std::string program,
//                       std::string uniform,
//                       bool        var
//                       );
//  void setIntUniform (
//                      std::string program,
//                      std::string uniform,
//                      int         value
//                      );
//  void setFloatUniform (
//                        std::string  program,
//                        std::string  uniform,
//                        const float *value,
//                        int          size
//                        );
//  void setMatrixUniform (
//                         std::string  program,
//                         std::string  uniform,
//                         const float *value,
//                         int          size
//                         );
//  void setBuffer (
//                  std::string  bufferName,
//                  float       *data,
//                  unsigned int size
//                  );

//  void swapTextures (
//                     std::string tex1,
//                     std::string tex2
//                     );

//  void setBlending ( bool blend );
//  void setCallback ( Callback *callback );

  void updateWindow ( );
  bool checkWindowShouldClose ( );
//  void setWindowShouldClose ( bool close );
//  double getTime ( );
//  void setWindowSize (
//                      int width,
//                      int height
//                      );
//  void resize (
//               int width,
//               int height
//               );

  void makeContextCurrent ( );

//  //
//  // getters
//  //
//  unsigned int
//  getTexture( std::string name ) { return m_textures[ name ]; }
//  int
//  getViewportWidth( ) { return m_viewportWidth; }
//  int
//  getViewportHeight( ) { return m_viewportHeight; }
//  GraphicsContext*
//  getContext( ) { return m_window; }


private:

//  void _terminateWindow ( );

//  static std::string _readFile ( std::string filePath );
//  static unsigned int _loadShader (
//                                   std::string vertex_path,
//                                   std::string fragment_path
//                                   );


  std::unique_ptr< GraphicsContext > upContext_;

//  std::unordered_map< std::string, unsigned int > m_programs;
//  std::unordered_map< std::string, unsigned int > m_textures;
//  std::unordered_map< std::string, unsigned int > m_buffers;
//  std::unordered_map< std::string, unsigned int > m_framebuffers;

  int viewWidth_, viewHeight_;

//  CallbackSingleton *m_input;

};


} // namespace graphics


#endif // GraphicsHandler_hpp
