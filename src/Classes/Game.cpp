#include "../Headers/Game.hpp"

using namespace dp;

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f,  -0.5f, 0.f, 1.f, 0.f, 0.f,
   0.0f,  -0.5f, 0.f, 0.f, 1.f, 0.f,
   0.5f,  -0.5f, 0.f, 0.f, 0.f, 1.f,
  -0.25f,  0.0f, 0.f, 1.f, 1.f, 0.f,
   0.25f,  0.0f, 0.f, 0.f, 1.f, 1.f,
   0.0f,   0.5f, 0.f, 1.f, 0.f, 1.f,
};
GLuint indices[] = {
  0, 1, 3,
  1, 2, 4,
  3, 4, 5,
};

// Callbacks
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

// Constructor and Destructor

Game::Game()
{

}

Game::~Game()
{
  this->defaultShader->Delete();
  this->VAO1->Delete();
  this->VBO1->Delete();
  this->EBO1->Delete();
  glfwTerminate();

  delete this->defaultShader;
  delete this->VAO1;
  delete this->VBO1;
  delete this->EBO1;
}

// Functions

bool Game::Initialize()
{
  this->initializeGlfw();
  if (!this->initializeWindow()) return false;
  if (!this->initializeGlew()) return false;
  if (!this->initializeMembers()) return false;
  return true;
}

void Game::Run()
{
  // Main Loop
  while (!glfwWindowShouldClose(this->window))
  {
    this->update();
    this->render();
  }
}

// Initializers

void Game::initializeGlfw()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

bool Game::initializeWindow()
{
  this->window = glfwCreateWindow(
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE,
    NULL,
    NULL
  );
  if (this->window == NULL)
  {
    std::cerr << "Failed to initialize a GLFW window!" << std::endl;
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(this->window);

  // Clear Color
  GLclampf red   = 0.0f;
  GLclampf green = 0.3f;
  GLclampf blue  = 0.3f;
  GLclampf alpha = 1.0f;
  glClearColor(red, green, blue, alpha);

  // Callbacks
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

  return true;
}

bool Game::initializeGlew()
{
  GLenum err = glewInit();
  if (err != GLEW_OK)
  {
    std::cerr << "Failed to initialize GLEW!" << std::endl;
    std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
    glfwTerminate();
    return false;
  }
  std::cout << "GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
  return true;
}

bool Game::initializeMembers()
{
  this->defaultShader = new Shader("src/Shaders/default.vert", "src/Shaders/default.frag");
  this->VAO1 = new VAO();
  this->VBO1 = new VBO(vertices, sizeof(vertices));
  this->EBO1 = new EBO(indices, sizeof(indices));

  this->VAO1->Bind();
  this->VBO1->Bind();
  this->EBO1->Bind();

  this->VAO1->LinkAttrib(*this->VBO1, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
  this->VAO1->LinkAttrib(*this->VBO1, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

  this->VAO1->Unbind();
  this->VBO1->Unbind();
  this->EBO1->Unbind();

  return true;
}

// Private Functions

void Game::update()
{
  glfwPollEvents();
}

void Game::render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  this->defaultShader->Use();
  VAO1->Bind();

  GLuint modelLoc = glGetUniformLocation(this->defaultShader->getID(), "model");
  GLuint viewLoc = glGetUniformLocation(this->defaultShader->getID(), "view");
  GLuint projLoc = glGetUniformLocation(this->defaultShader->getID(), "proj");

  glm::mat4 model = glm::mat4(1.f);
  glm::mat4 view = glm::mat4(1.f);
  glm::mat4 proj = glm::mat4(1.f);

  view = glm::translate(view, glm::vec3(0.f, 0.f, -5.f));
  proj = glm::perspective(glm::radians(CAMERA_FOV), (float)WINDOW_WIDTH / WINDOW_HEIGHT, CAMERA_NEAR, CAMERA_FAR);

  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

  glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, NULL);
  glfwSwapBuffers(this->window);
}
