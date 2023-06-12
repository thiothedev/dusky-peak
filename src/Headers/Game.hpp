#ifndef GAME_HPP
#define GAME_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"

extern const unsigned int WINDOW_WIDTH;
extern const unsigned int WINDOW_HEIGHT;
extern const char*        WINDOW_TITLE;

// Callbacks
void framebufferSizeCallback(GLFWwindow* window, int width, int height);

namespace dp
{
  class Game
  {
    public:
      // Constructor and Destructor
      Game();
      ~Game();

      // Members
      Shader* defaultShader;
      VAO* VAO1;
      VBO* VBO1;
      EBO* EBO1;

      // Functions
      bool Initialize();
      void Run();

    private:
      GLFWwindow* window;

      // Initializers
      void initializeGlfw();
      bool initializeWindow();
      bool initializeGlew();
      bool initializeMembers();

      // Private Functions
      void update();
      void render();
  };
}

#endif // GAME_HPP
