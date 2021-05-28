#version 330 core

out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightDirection;
uniform sampler2D albedoTexture;

in vec2 TexCoord;
in vec3 normal;

void main()
{
    vec3 norm = normalize(normal);
    vec3 lightDir = -normalize(lightDirection);
    float lightIntensity = max(dot(norm, lightDir), 0.25f);

    vec4 col = texture(albedoTexture, TexCoord) * vec4(objectColor, 1.0) * lightIntensity;
    FragColor = col;
}