#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "../Utils/Constants.hpp"

namespace dp
{
  class Camera
  {
    public:
      // Constructor
      Camera();

      // Modifiers
      void setConstraints(const unsigned int width, const unsigned int height);

      // Functions
      void HandleMovement(GLFWwindow* window, const float dt);
      void UpdateMatrices(GLFWwindow* window, const GLuint programID);

    private:
      // Constraints
      unsigned int width;
	    unsigned int height;

      bool mouseLocked = false;
    
      glm::vec3 position = glm::vec3(0.f);
      glm::vec3 orientation = glm::vec3(0.f, 0.f, -1.f);
      glm::vec3 up = glm::vec3(0.f, 1.f, 0.f);
  };
}

#endif // CAMERA_HPP
