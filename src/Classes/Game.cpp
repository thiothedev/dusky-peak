#include "../Headers/Game.hpp"

using namespace dp;

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f, -0.5f,  0.5f, 1.f, 0.f, 0.f, 0.f,  0.f, // Front
   0.5f, -0.5f,  0.5f, 0.f, 1.f, 0.f, 1.f,  0.f, // Front
   0.0f,  0.5f,  0.0f, 0.f, 0.f, 1.f, 0.5f, 1.f, // Front
   0.5f, -0.5f,  0.5f, 1.f, 1.f, 0.f, 0.f,  0.f, // Right
   0.5f, -0.5f, -0.5f, 0.f, 1.f, 1.f, 1.f,  0.f, // Right
   0.0f,  0.5f,  0.0f, 1.f, 0.f, 1.f, 0.5f, 1.f, // Right
  -0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f, 0.f,  0.f, // Back
   0.5f, -0.5f, -0.5f, 0.f, 1.f, 0.f, 1.f,  0.f, // Back
   0.0f,  0.5f,  0.0f, 0.f, 0.f, 1.f, 0.5f, 1.f, // Back
  -0.5f, -0.5f, -0.5f, 1.f, 1.f, 0.f, 0.f,  0.f, // Left
  -0.5f, -0.5f,  0.5f, 0.f, 1.f, 1.f, 1.f,  0.f, // Left
   0.0f,  0.5f,  0.0f, 1.f, 0.f, 1.f, 0.5f, 1.f, // Left
  -0.5f, -0.5f,  0.5f, 1.f, 0.f, 0.f, 0.f,  0.f, // Bottom 1
  -0.5f, -0.5f, -0.5f, 0.f, 1.f, 0.f, 0.f,  1.f, // Bottom 1
   0.5f, -0.5f,  0.5f, 0.f, 0.f, 1.f, 1.f,  0.f, // Bottom 1
   0.5f, -0.5f, -0.5f, 1.f, 1.f, 0.f, 1.f,  1.f, // Bottom 2
   0.5f, -0.5f,  0.5f, 0.f, 1.f, 1.f, 1.f,  0.f, // Bottom 2
  -0.5f, -0.5f, -0.5f, 1.f, 0.f, 1.f, 0.f,  1.f, // Bottom 2
};
GLuint indices[] = {
  0, 1, 2,
  3, 4, 5,
  6, 7, 8,
  9, 10, 11,
  12, 13, 14,
  15, 16, 17,
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
  this->bricksTexture->Delete();
  glfwTerminate();

  delete this->defaultShader;
  delete this->VAO1;
  delete this->VBO1;
  delete this->EBO1;
  delete this->camera;
  delete this->bricksTexture;
}

// Functions

bool Game::initialize()
{
  this->initializeGlfw();
  if (!this->initializeWindow()) return false;
  if (!this->initializeGlew()) return false;
  if (!this->initializeMembers()) return false;
  return true;
}

void Game::printTitle()
{
  std::cout << ENGINE_NAME << " " << ENGINE_VERSION << "\n" << std::endl;
}

void Game::run()
{
  // Main Loop
  while (!glfwWindowShouldClose(this->window))
  {
    this->update();
    this->render();
  }
}

// Accessors

const float Game::getDt() const
{
  return this->dt;
}

// Initializers

void Game::initializeGlfw()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  std::cout << "GLFW:   " << glfwGetVersionString() << std::endl;
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

  // Tests
  glEnable(GL_DEPTH_TEST);

  // OpenGL Version
  std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

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
  std::cout << "GLEW:   " << glewGetString(GLEW_VERSION) << std::endl;
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

  this->VAO1->LinkAttrib(*this->VBO1, 0, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)0);
  this->VAO1->LinkAttrib(*this->VBO1, 1, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
  this->VAO1->LinkAttrib(*this->VBO1, 2, 2, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));

  this->VAO1->Unbind();
  this->VBO1->Unbind();
  this->EBO1->Unbind();

  this->camera = new dp::Camera();
  this->camera->setConstraints(WINDOW_WIDTH, WINDOW_HEIGHT);

  this->bricksTexture = new Texture("assets/Textures/tiles.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
  this->bricksTexture->TextureUnit(*this->defaultShader, "tex0", 0);

  return true;
}

// Private Functions

void Game::updateDt()
{
  double currentTime = glfwGetTime();
  this->dt = currentTime - this->prevTime;
  this->prevTime = currentTime;
}

void Game::update()
{
  glfwPollEvents();
  this->updateDt();
  this->camera->HandleMovement(this->window, this->dt);
  this->camera->UpdateMatrices(this->window, this->defaultShader->getID());
}

void Game::render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->defaultShader->Use();
  this->bricksTexture->Bind();
  VAO1->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  glfwSwapBuffers(this->window);
}
