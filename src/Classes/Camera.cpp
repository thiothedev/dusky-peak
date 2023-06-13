#include "../Headers/Camera.hpp"

using namespace dp;

// Constructor

Camera::Camera()
{

}

// Functions

void Camera::HandleMovement(GLFWwindow* window, const float dt)
{
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
  {
    this->position += glm::vec3(0.f, 0.f, CAMERA_SPEED * dt);
  }
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
  {
    this->position += glm::vec3(CAMERA_SPEED * dt, 0.f, 0.f);
  }
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
  {
    this->position += glm::vec3(0.f, 0.f, -CAMERA_SPEED * dt);
  }
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
  {
    this->position += glm::vec3(-CAMERA_SPEED * dt, 0.f, 0.f);
  }
  if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
  {
    this->position += glm::vec3(0.f, CAMERA_SPEED * dt, 0.f);
  }
  if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
  {
    this->position += glm::vec3(0.f, -CAMERA_SPEED * dt, 0.f);
  }
}

void Camera::UpdateMatrices(GLFWwindow* window, const GLuint programID)
{
  GLuint modelLoc = glGetUniformLocation(programID, "model");
  GLuint viewLoc = glGetUniformLocation(programID, "view");
  GLuint projLoc = glGetUniformLocation(programID, "proj");

  glm::mat4 model = glm::mat4(1.f);
  glm::mat4 view = glm::mat4(1.f);
  glm::mat4 proj = glm::mat4(1.f);

  view = glm::translate(view, this->position);
  proj = glm::perspective(
    glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS ? glm::radians(CAMERA_ZOOM) : glm::radians(CAMERA_FOV),
    (float)WINDOW_WIDTH / WINDOW_HEIGHT,
    CAMERA_NEAR,
    CAMERA_FAR
  );

  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
}
