#include "../Headers/Texture.hpp"

using namespace dp;

// Constructor

Texture::Texture(const char* image, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType)
{
  this->type = textureType;

  int width, height;
  unsigned char* data;
  dp::image::loadFromPng(image, &data, width, height);

  glGenTextures(1, &this->ID);
  glActiveTexture(slot);
  glBindTexture(this->type, this->ID);

  glTexParameteri(this->type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(this->type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexParameteri(this->type, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(this->type, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexImage2D(this->type, 0, GL_RGBA, width, height, 0, format, pixelType, data);
  glGenerateMipmap(this->type);

  glBindTexture(this->type, 0);
  delete[] data;
}

// Functions

void Texture::TextureUnit(Shader& shader, const char* uniform, GLuint unit)
{
  GLuint texLoc = glGetUniformLocation(shader.getID(), uniform);
  shader.Use();
  glUniform1i(texLoc, unit);
}

void Texture::Bind()
{
  glBindTexture(this->type, this->ID);
}

void Texture::Unbind()
{
  glBindTexture(this->type, 0);
}

void Texture::Delete()
{
  glDeleteTextures(1, &this->ID);
}
