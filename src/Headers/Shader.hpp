#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>

#include "../Utils/File.hpp"

extern const unsigned int INFO_LOG_SIZE;

namespace dp
{
  class Shader
  {
    public:
      // Constructor
      Shader(const char* vertexPath, const char* fragmentPath);

      // Accessors
      const GLuint getID() const;

      // Functions
      void Use();
      void Delete();

    private:
      GLuint ID;
  };
}

#endif // SHADER_HPP
