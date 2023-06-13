#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Utils/Constants.hpp"

namespace dp
{
  class Camera
  {
    public:
      // Construcor
      Camera();

      glm::vec3 position = glm::vec3(0.f, 0.f, 0.f);

      // Functions
      void HandleMovement(GLFWwindow* window, const float dt);
      void UpdateMatrices(GLFWwindow* window, const GLuint programID);
  };
}

#endif // CAMERA_HPP
