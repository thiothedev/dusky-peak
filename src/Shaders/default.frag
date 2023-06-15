#version 330 core

in vec3 vertCol;
in vec2 vertTex;
in vec3 vertNormal;
in vec3 currentPosition;

uniform sampler2D tex0;
uniform vec4 lightColor;
uniform vec3 lightPosition;

out vec4 FragColor;

void main()
{
  vec3 normal = normalize(vertNormal);
  vec3 lightDirection = normalize(lightPosition - currentPosition);
  
  float diffuse = max(dot(normal, lightDirection), 0.f);

  FragColor = texture(tex0, vertTex) * vec4(vertCol, 1.f) * lightColor * diffuse;
}
