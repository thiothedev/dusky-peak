#ifndef GAME_HPP
#define GAME_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "Shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"
#include "Camera.hpp"

// Constants
extern const char*        ENGINE_NAME;
extern const char*        ENGINE_VERSION;
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
      Camera* camera;

      // Delta Time
      double prevTime = 0.f;
      float dt = 0.f;

      // Accessors
      const float getDt() const;

      // Functions
      bool Initialize();
      void PrintTitle();
      void Run();

    private:
      GLFWwindow* window;

      // Initializers
      void initializeGlfw();
      bool initializeWindow();
      bool initializeGlew();
      bool initializeMembers();

      // Update Functions
      void updateDt();
      void update();

      // Render Functions
      void render();
  };
}

#endif // GAME_HPP
