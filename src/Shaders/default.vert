#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 aTex;

out vec3 vertCol;
out vec2 vertTex;
out vec3 currentPosition;

uniform mat4 model;
uniform mat4 cameraMatrix;

void main()
{
  currentPosition = vec3(model * vec4(aPos, 1.f));
  gl_Position = cameraMatrix * vec4(currentPosition, 1.f);
  vertCol = aCol;
  vertTex = aTex;
}
