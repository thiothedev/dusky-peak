#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Utils/File.hpp"

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char*        WINDOW_TITLE  = "GLFW";

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

  // Shaders
  const char* vertexShaderSource = dp::file::getContents("src/Shaders/default.vert");
  const char* fragmentShaderSource = dp::file::getContents("src/Shaders/default.frag");

  // Main Loop
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  // Terminating the Program
  glfwTerminate();
  return 0;
}
