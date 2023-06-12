#ifndef EBO_HPP
#define EBO_HPP

#include <GL/glew.h>

namespace dp
{
  class EBO
  {
    public:
      // Constructor
      EBO(GLuint indices[], GLsizeiptr size);

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

#endif // EBO_HPP
