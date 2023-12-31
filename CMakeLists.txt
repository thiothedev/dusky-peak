# CMake Version
cmake_minimum_required(VERSION 3.3)

# Constants
set(PROJECT_NAME "dp")
set(OpenGL_GL_PREFERENCE LEGACY)

# Project Name
project(${PROJECT_NAME})

# C++ Standard
set(CMAKE_CXX_STANDARD 11)

# Packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(PNG REQUIRED)

# Globs
FILE(GLOB ClassSources src/Classes/*.cpp)
FILE(GLOB HeaderSources src/Headers/*.hpp)
FILE(GLOB UtilSources src/Utils/*.cpp src/Utils/*.hpp)

# Executable
add_executable(
  ${PROJECT_NAME}
  src/Main.cpp
  ${ClassSources}
  ${HeaderSources}
  ${UtilSources}
)
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} PUBLIC GL GLEW glfw glm::glm png)
