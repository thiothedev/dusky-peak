#include "../Headers/EBO.hpp"

using namespace dp;

// Constructor

EBO::EBO(GLuint indices[], GLsizeiptr size)
{
  glGenBuffers(1, &this->ID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Accessors

const GLuint EBO::getID() const
{
  return this->ID;
}

// Functions

void EBO::Bind()
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
}

void EBO::Unbind()
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
  glDeleteBuffers(1, &this->ID);
}
