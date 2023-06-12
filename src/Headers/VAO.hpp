#ifndef VAO_HPP
#define VAO_HPP

#include <GL/glew.h>

#include "VBO.hpp"

namespace dp
{
  class VAO
  {
    public:
      // Constructor
      VAO();

      // Accessors
      const GLuint getID() const;

      // Functions
      void LinkAttrib(dp::VBO& VBO, GLuint layout, GLuint size, GLenum type, GLsizei stride, const void* offset);
      void Bind();
      void Unbind();
      void Delete();

    private:
      GLuint ID;
  };
}

#endif // VAO_HPP
