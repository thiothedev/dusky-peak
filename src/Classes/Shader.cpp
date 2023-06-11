#include "../Headers/Shader.hpp"

// Constructor

dp::Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
  // Shaders
  const char* vertexShaderSource = dp::file::getContents(vertexPath);
  const char* fragmentShaderSource = dp::file::getContents(fragmentPath);

  // Info Log
  int success;
  char infoLog[INFO_LOG_SIZE];

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);

  // Vertex Shader Validation
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, INFO_LOG_SIZE, NULL, infoLog);
    std::cerr << "Failed to compile the vertex shader!" << std::endl;
    std::cerr << "Error: " << infoLog << std::endl;
  }

  // Fragment Shader Validation
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, INFO_LOG_SIZE, NULL, infoLog);
    std::cerr << "Failed to compile the fragment shader!" << std::endl;
    std::cerr << "Error: " << infoLog << std::endl;
  }

  // Shader Program
  this->ID = glCreateProgram();

  glAttachShader(this->ID, vertexShader);
  glAttachShader(this->ID, fragmentShader);
  glLinkProgram(this->ID);

  // Shader Program Validation
  glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(this->ID, INFO_LOG_SIZE, NULL, infoLog);
    std::cerr << "Failed to link the shader program!" << std::endl;
    std::cerr << "Error: " << infoLog << std::endl;
  }

  // Deleting the Shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

// Accessors

const GLuint dp::Shader::getID() const
{
  return this->ID;
}

// Functions

void dp::Shader::Use()
{
  glUseProgram(this->ID);
}

void dp::Shader::Delete()
{
  glDeleteShader(this->ID);
}
