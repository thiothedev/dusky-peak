#include "../Headers/Camera.hpp"

using namespace dp;

// Constructor

Camera::Camera()
{

}

// Accessors

void Camera::setConstraints(const unsigned int width, const unsigned int height)
{
  this->width = width;
  this->height = height;
}

// Functions

void Camera::HandleMovement(GLFWwindow* window, const float dt)
{
  float cameraSpeed = CAMERA_SPEED * dt;

  if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
  {
    this->mouseLocked = true;
  }
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
  {
    this->mouseLocked = false;
  }
  if (!this->mouseLocked)
  {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    return;
  }

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
  {
    this->position += this->orientation * cameraSpeed;
  }
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
  {
    this->position += -glm::normalize(glm::cross(this->orientation, this->up)) * cameraSpeed;
  }
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
  {
    this->position += -this->orientation * cameraSpeed;
  }
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
  {
    this->position += glm::normalize(glm::cross(this->orientation, this->up)) * cameraSpeed;
  }
  if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
  {
    this->position += this->up * cameraSpeed;
  }
  if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
  {
    this->position += -this->up * cameraSpeed;
  }

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

  double mouseX;
  double mouseY;
  glfwGetCursorPos(window, &mouseX, &mouseY);

  float rotX = CAMERA_SENSITIVITY * (float)(mouseY - (this->height / 2)) / this->height;
  float rotY = CAMERA_SENSITIVITY * (float)(mouseX - (this->width / 2)) / this->width;

  glm::vec3 newOrientation = glm::rotate(
    this->orientation,
    glm::radians(-rotX),
    glm::normalize(glm::cross(this->orientation, this->up))
  );
  if (abs(glm::angle(newOrientation, this->up) - glm::radians(90.0f)) <= glm::radians(85.0f))
  {
    this->orientation = newOrientation;
  }

  this->orientation = glm::rotate(this->orientation, glm::radians(-rotY), this->up);
  glfwSetCursorPos(window, (this->width / 2), (this->height / 2));
}

void Camera::UpdateMatrices(GLFWwindow* window, const GLuint programID)
{
  GLuint modelLoc = glGetUniformLocation(programID, "model");
  GLuint viewLoc = glGetUniformLocation(programID, "view");
  GLuint projLoc = glGetUniformLocation(programID, "proj");

  glm::mat4 model = glm::mat4(1.f);
  glm::mat4 view = glm::mat4(1.f);
  glm::mat4 proj = glm::mat4(1.f);

  view = glm::lookAt(this->position, this->position + this->orientation, this->up);
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
