#version 330 core

in vec3 vertCol;
in vec2 vertTex;
in vec3 vertNormal;
in vec3 currentPosition;

uniform sampler2D tex0;
uniform vec4 lightColor;
uniform vec3 lightPosition;
uniform vec3 cameraPosition;

out vec4 FragColor;

void main()
{
  vec3 normal = normalize(vertNormal);
  vec3 lightDirection = normalize(lightPosition - currentPosition);
  
  float ambient = 0.2f;
  float diffuse = max(dot(normal, lightDirection), 0.f);
  float specularLight = 0.5f;
  vec3 viewDirection = normalize(cameraPosition - currentPosition);
  vec3 reflectionDirection = reflect(-lightDirection, normal);
  float specularAmount = pow(max(dot(viewDirection, reflectionDirection), 0.f), 8);
  float specular = specularAmount * specularLight;

  FragColor = texture(tex0, vertTex) * vec4(vertCol, 1.f) * lightColor * (diffuse + ambient + specular);
}
