#include "Image.hpp"

const bool dp::image::loadFromPng(const char* path, unsigned char** data, int& width, int& height)
{
  png_image image;
  memset(&image, 0, sizeof(image));
  image.version = PNG_IMAGE_VERSION;

  if (!png_image_begin_read_from_file(&image, path)) {
    std::cerr << "Failed to begin reading PNG: " << path << std::endl;
    return false;
  }

  image.format = PNG_FORMAT_RGBA;
  *data = new unsigned char[PNG_IMAGE_SIZE(image)];

  if (!png_image_finish_read(&image, nullptr, *data, 0, nullptr)) {
    std::cerr << "Failed to finish reading PNG: " << path << std::endl;
    delete[] *data;
    return false;
  }

  width = image.width;
  height = image.height;
  
  return true;
}
