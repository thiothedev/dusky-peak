#include "../Headers/Game.hpp"

using namespace dp;

glm::vec3 calculateNormal(const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& v3) {
  glm::vec3 edge1 = v2 - v1;
  glm::vec3 edge2 = v3 - v1;
  return glm::normalize(glm::cross(edge1, edge2));
}

glm::vec3 faceNormalFront = calculateNormal(
  glm::vec3(-0.5f, -0.5f, 0.5f),
  glm::vec3(0.5f, -0.5f, 0.5f),
  glm::vec3(0.0f, 0.5f, 0.0f)
);
glm::vec3 faceNormalRight = calculateNormal(
  glm::vec3(0.5f, -0.5f, 0.5f),
  glm::vec3(0.5f, -0.5f, -0.5f),
  glm::vec3(0.0f, 0.5f, 0.0f)
);
glm::vec3 faceNormalBack = calculateNormal(
  glm::vec3(0.5f, -0.5f, -0.5f),
  glm::vec3(-0.5f, -0.5f, -0.5f),
  glm::vec3(0.0f, 0.5f, 0.0f)
);
glm::vec3 faceNormalLeft = calculateNormal(
  glm::vec3(-0.5f, -0.5f, -0.5f),
  glm::vec3(-0.5f, -0.5f, 0.5f),
  glm::vec3(0.0f, 0.5f, 0.0f)
);
glm::vec3 faceNormalBottom1 = calculateNormal(
  glm::vec3(-0.5f, -0.5f, 0.5f),
  glm::vec3(-0.5f, -0.5f, -0.5f),
  glm::vec3(0.5f, -0.5f, 0.5f)
);
glm::vec3 faceNormalBottom2 = calculateNormal(
  glm::vec3(0.5f, -0.5f, -0.5f),
  glm::vec3(0.5f, -0.5f, 0.5f),
  glm::vec3(-0.5f, -0.5f, -0.5f)
);

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f, -0.5f,  0.5f, 1.f, 0.f, 0.f, 0.f,  0.f, faceNormalFront.x, faceNormalFront.y, faceNormalFront.z, // Front
   0.5f, -0.5f,  0.5f, 0.f, 1.f, 0.f, 1.f,  0.f, faceNormalFront.x, faceNormalFront.y, faceNormalFront.z, // Front
   0.0f,  0.5f,  0.0f, 0.f, 0.f, 1.f, 0.5f, 1.f, faceNormalFront.x, faceNormalFront.y, faceNormalFront.z, // Front
   0.5f, -0.5f,  0.5f, 1.f, 1.f, 0.f, 0.f,  0.f, faceNormalRight.x, faceNormalRight.y, faceNormalRight.z, // Right
   0.5f, -0.5f, -0.5f, 0.f, 1.f, 1.f, 1.f,  0.f, faceNormalRight.x, faceNormalRight.y, faceNormalRight.z, // Right
   0.0f,  0.5f,  0.0f, 1.f, 0.f, 1.f, 0.5f, 1.f, faceNormalRight.x, faceNormalRight.y, faceNormalRight.z, // Right
  -0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f, 0.f,  0.f, faceNormalBack.x,  faceNormalBack.y,  faceNormalBack.z, // Back
   0.5f, -0.5f, -0.5f, 0.f, 1.f, 0.f, 1.f,  0.f, faceNormalBack.x,  faceNormalBack.y,  faceNormalBack.z, // Back
   0.0f,  0.5f,  0.0f, 0.f, 0.f, 1.f, 0.5f, 1.f, faceNormalBack.x,  faceNormalBack.y,  faceNormalBack.z, // Back
  -0.5f, -0.5f, -0.5f, 1.f, 1.f, 0.f, 0.f,  0.f, faceNormalLeft.x,  faceNormalLeft.y,  faceNormalLeft.z, // Left
  -0.5f, -0.5f,  0.5f, 0.f, 1.f, 1.f, 1.f,  0.f, faceNormalLeft.x,  faceNormalLeft.y,  faceNormalLeft.z, // Left
   0.0f,  0.5f,  0.0f, 1.f, 0.f, 1.f, 0.5f, 1.f, faceNormalLeft.x,  faceNormalLeft.y,  faceNormalLeft.z, // Left
  -0.5f, -0.5f,  0.5f, 1.f, 0.f, 0.f, 0.f,  0.f, faceNormalFront.x, faceNormalFront.y, faceNormalFront.z, // Bottom 1
  -0.5f, -0.5f, -0.5f, 0.f, 1.f, 0.f, 0.f,  1.f, faceNormalFront.x, faceNormalFront.y, faceNormalFront.z, // Bottom 1
   0.5f, -0.5f,  0.5f, 0.f, 0.f, 1.f, 1.f,  0.f, faceNormalFront.x, faceNormalFront.y, faceNormalFront.z, // Bottom 1
   0.5f, -0.5f, -0.5f, 1.f, 1.f, 0.f, 1.f,  1.f, faceNormalFront.x, faceNormalFront.y, faceNormalFront.z, // Bottom 2
   0.5f, -0.5f,  0.5f, 0.f, 1.f, 1.f, 1.f,  0.f, faceNormalFront.x, faceNormalFront.y, faceNormalFront.z, // Bottom 2
  -0.5f, -0.5f, -0.5f, 1.f, 0.f, 1.f, 0.f,  1.f, faceNormalFront.x, faceNormalFront.y, faceNormalFront.z, // Bottom 2
};
GLuint indices[] = {
  0, 1, 2,
  3, 4, 5,
  6, 7, 8,
  9, 10, 11,
  12, 13, 14,
  15, 16, 17,
};
GLfloat lightVertices[] = {
  -0.25f, -0.25f,  0.25f,
   0.25f, -0.25f,  0.25f,
  -0.25f, -0.25f, -0.25,
   0.25f, -0.25f, -0.25,
  -0.25f,  0.25f,  0.25f,
   0.25f,  0.25f,  0.25f,
  -0.25f,  0.25f, -0.25,
   0.25f,  0.25f, -0.25,
};
GLuint lightIndices[] = {
  0, 1, 4, // Front
  5, 4, 1, // Front
  1, 3, 5, // Right
  7, 5, 3, // Right
  3, 2, 7, // Back
  6, 7, 2, // Back
  2, 6, 0, // Left
  4, 6, 0, // Left
  4, 6, 5, // Top
  7, 6, 5, // Top
  3, 2, 1, // Bottom
  0, 1, 2, // Bottom
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
  this->lightShader->Delete();

  this->VAO1->Delete();
  this->EBO1->Delete();
  this->VBO1->Delete();

  this->VAO2->Delete();
  this->VBO2->Delete();
  this->EBO2->Delete();

  this->bricksTexture->Delete();

  delete this->defaultShader;
  delete this->lightShader;

  delete this->VAO1;
  delete this->VBO1;
  delete this->EBO1;

  delete this->VAO2;
  delete this->VBO2;
  delete this->EBO2;

  delete this->bricksTexture;
  delete this->camera;

  glfwDestroyWindow(window);
  glfwTerminate();
}

// Functions

bool Game::initialize()
{
  this->initializeGlfw();
  if (!this->initializeWindow()) return false;
  if (!this->initializeGlew()) return false;
  if (!this->initializeShaders()) return false;
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

bool Game::initializeShaders()
{
  this->defaultShader = new Shader("src/Shaders/default.vert", "src/Shaders/default.frag");
  this->lightShader = new Shader("src/Shaders/light.vert", "src/Shaders/light.frag");
  
  return true;
}

bool Game::initializeMembers()
{
  this->VAO1 = new VAO();
  this->VBO1 = new VBO(vertices, sizeof(vertices));
  this->EBO1 = new EBO(indices, sizeof(indices));

  this->VAO1->Bind();
  this->VBO1->Bind();
  this->EBO1->Bind();

  this->VAO1->LinkAttrib(*this->VBO1, 0, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)0);
  this->VAO1->LinkAttrib(*this->VBO1, 1, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
  this->VAO1->LinkAttrib(*this->VBO1, 2, 2, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
  this->VAO1->LinkAttrib(*this->VBO1, 3, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(8 * sizeof(GLfloat)));

  this->VAO1->Unbind();
  this->VBO1->Unbind();
  this->EBO1->Unbind();

  this->VAO2 = new VAO();
  this->VBO2 = new VBO(lightVertices, sizeof(lightVertices));
  this->EBO2 = new EBO(lightIndices, sizeof(lightIndices));

  this->VAO2->Bind();
  this->VBO2->Bind();
  this->EBO2->Bind();

  this->VAO2->LinkAttrib(*this->VBO2, 0, 3, GL_FLOAT, 0, (void*)0);

  this->VAO2->Unbind();
  this->VBO2->Unbind();
  this->EBO2->Unbind();

  this->camera = new dp::Camera();
  this->camera->setConstraints(WINDOW_WIDTH, WINDOW_HEIGHT);

  this->bricksTexture = new Texture("assets/Textures/tiles.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
  this->bricksTexture->TextureUnit(*this->defaultShader, "tex0", 0);

  this->lightModel = glm::translate(this->lightModel, this->lightPosition);
  this->pyramidModel = glm::translate(this->pyramidModel, this->pyramidPosition);

  glm::vec4 lightColor = glm::vec4(1.f, 0.f, 0.f, 1.f);

  this->lightShader->Use();
  glUniformMatrix4fv(glGetUniformLocation(this->lightShader->getID(), "model"), 1, GL_FALSE, glm::value_ptr(this->lightModel));
  glUniform4f(glGetUniformLocation(this->lightShader->getID(), "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
  this->defaultShader->Use();
  glUniformMatrix4fv(glGetUniformLocation(this->defaultShader->getID(), "model"), 1, GL_FALSE, glm::value_ptr(this->pyramidModel));
  glUniform4f(glGetUniformLocation(this->defaultShader->getID(), "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
  glUniform3f(glGetUniformLocation(this->defaultShader->getID(), "lightPosition"), lightPosition.x, lightPosition.y, lightPosition.z);

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

  this->bricksTexture->Bind();

  this->defaultShader->Use();
  this->camera->UseMatrix(this->defaultShader->getID(), "cameraMatrix");
  VAO1->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  
  this->lightShader->Use();
  this->camera->UseMatrix(this->lightShader->getID(), "cameraMatrix");
  VAO2->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);

  glfwSwapBuffers(this->window);
}
