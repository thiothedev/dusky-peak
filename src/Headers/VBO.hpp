#ifndef VBO_HPP
#define VBO_HPP

#include <GL/glew.h>

namespace dp
{
  class VBO
  {
    public:
      // Constructor
      VBO(GLfloat indices[], GLsizeiptr size);

      // Accessors
      const GLuint getID() const;

      // Functions
      void Bind();
      void Unbind();
      void Delete();

    private:
      GLuint ID;
  };
}

#endif // VBO_HPP
