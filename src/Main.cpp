#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Headers/Game.hpp"

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char*        WINDOW_TITLE  = "GLFW";
const unsigned int INFO_LOG_SIZE = 512;

int main()
{
  dp::Game game;
  if (!game.Initialize()) return 1;
  game.Run();

  return 0;
}
