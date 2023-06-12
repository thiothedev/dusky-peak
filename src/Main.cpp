#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Headers/Game.hpp"

int main()
{
  dp::Game game;
  game.printTitle();

  if (!game.initialize()) {
    std::cerr << "Failed to initialize engine!" << std::endl;
    return 1;
  }
  game.run();

  return 0;
}
