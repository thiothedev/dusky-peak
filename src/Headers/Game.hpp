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
#include "Texture.hpp"

#include "../Utils/Image.hpp"
#include "../Utils/Constants.hpp"

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

      // Shaders
      Shader* defaultShader;
      Shader* lightShader;

      // Positions and Models
      glm::vec3 lightPosition = glm::vec3(0.f, 0.f, -2.f);
      glm::mat4 lightModel = glm::mat4(1.0f);
      glm::vec3 pyramidPosition = glm::vec3(0.0f, 0.0f, 0.0f);
      glm::mat4 pyramidModel = glm::mat4(1.0f);

      VAO* VAO1;
      VBO* VBO1;
      EBO* EBO1;
      VAO* VAO2;
      VBO* VBO2;
      EBO* EBO2;
      Camera* camera;
      Texture* bricksTexture;

      // Delta Time
      double prevTime = 0.f;
      float dt = 0.f;

      // Accessors
      const float getDt() const;

      // Functions
      bool initialize();
      void printTitle();
      void run();

    private:
      GLFWwindow* window;

      // Initializers
      void initializeGlfw();
      bool initializeWindow();
      bool initializeGlew();
      bool initializeShaders();
      bool initializeMembers();

      // Update Functions
      void updateDt();
      void update();

      // Render Functions
      void render();
  };
}

#endif // GAME_HPP
