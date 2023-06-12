#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Headers/Shader.hpp"
#include "Headers/VBO.hpp"
#include "Headers/EBO.hpp"
#include "Utils/File.hpp"

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char*        WINDOW_TITLE  = "GLFW";
const unsigned int INFO_LOG_SIZE = 512;

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f,  -0.5f, 0.f,
   0.0f,  -0.5f, 0.f,
   0.5f,  -0.5f, 0.f,
  -0.25f,  0.0f, 0.f,
   0.25f,  0.0f, 0.f,
   0.0f,   0.5f, 0.f,
};
GLuint indices[] = {
  0, 1, 3,
  1, 2, 4,
  3, 4, 5,
};

int main()
{
  // Initializing GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Creating the Window
  GLFWwindow* window = glfwCreateWindow(
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE,
    NULL,
    NULL
  );
  if (window == NULL)
  {
    std::cerr << "Failed to initialize a GLFW window!" << std::endl;
    glfwTerminate();
    return 1;
  }
  glfwMakeContextCurrent(window);

  // Initializing GLEW
  GLenum err = glewInit();
  if (err != GLEW_OK)
  {
    std::cerr << "Failed to initialize GLEW!" << std::endl;
    std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
    glfwTerminate();
    return 1;
  }
  std::cout << "GLEW: " << glewGetString(GLEW_VERSION) << std::endl;

  // Clear Color
  GLclampf red   = 0.f;
  GLclampf green = 0.f;
  GLclampf blue  = 0.f;
  GLclampf alpha = 0.f;
  glClearColor(red, green, blue, alpha);

  // Shader Program
  dp::Shader defaultShader("src/Shaders/default.vert", "src/Shaders/default.frag");

  // VBO
  dp::VBO VBO1(vertices, sizeof(vertices));
  dp::EBO EBO1(indices, sizeof(indices));

  // Main Loop
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  // Terminating the Program
  defaultShader.Delete();
  glfwTerminate();
  return 0;
}
