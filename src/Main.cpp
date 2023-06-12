#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Headers/Game.hpp"

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char*        WINDOW_TITLE  = "GLFW";
const unsigned int INFO_LOG_SIZE = 512;
const float        CAMERA_FOV    = 45.f;
const float        CAMERA_NEAR   = 0.1f;
const float        CAMERA_FAR    = 100.f;

int main()
{
  dp::Game game;
  if (!game.Initialize()) return 1;
  game.Run();

  return 0;
}
