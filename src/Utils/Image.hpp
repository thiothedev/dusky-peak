#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <GL/glew.h>
#include <png.h>
#include <cstring>
#include <iostream>

namespace dp
{
  namespace image
  {
    const bool loadFromPng(const char* path, unsigned char** data, int& width, int& height);
  }
}

#endif // IMAGE_HPP
