#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

namespace dp
{
  class Camera
  {
    public:
      // Construcor
      Camera();

      glm::vec3 position;

      // Functions
      void HandleMovement();
      void UpdateMatrices();
  };
}

#endif // CAMERA_HPP
