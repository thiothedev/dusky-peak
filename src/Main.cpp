#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Headers/Game.hpp"

// Engine Constants
const char* ENGINE_NAME    = "Dusky Peak";
const char* ENGINE_VERSION = "0.1";

// Window Constants
const unsigned int WINDOW_WIDTH   = 800;
const unsigned int WINDOW_HEIGHT  = 600;
const char*        WINDOW_TITLE   = "GLFW";

// Other Constants
const unsigned int INFO_LOG_SIZE = 512;

// Camera Constants
const float CAMERA_FOV   = 45.f;
const float CAMERA_NEAR  = 0.1f;
const float CAMERA_FAR   = 100.f;
const float CAMERA_SPEED = 2.f;

int main()
{
  dp::Game game;
  game.PrintTitle();

  // Initializiation
  if (!game.Initialize()) {
    return 1;
  }

  game.Run();
  return 0;
}
