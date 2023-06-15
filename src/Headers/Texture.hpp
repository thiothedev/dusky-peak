#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>

#include "Shader.hpp"

#include "../Utils/Image.hpp"

namespace dp
{
  class Texture
  {
    public:
      // Constructor
      Texture(const char* image, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType);

      // Functions
      void TextureUnit(Shader& shader, const char* uniform, GLuint unit);
      void Bind();
      void Unbind();
      void Delete();

    private:
      GLuint ID;
      GLenum type;
  };
}

#endif // TEXTURE_HPP
