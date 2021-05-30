#version 330 core
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec2 vertexUV;

uniform mat4 ModelMatrix;
uniform mat4 ViewProjectionMatrix;

out vec3 normal;
out vec2 TexCoord;

void main()
{
    gl_Position = ViewProjectionMatrix * ModelMatrix * vec4(vertexPosition, 1.0);

    normal = mat3(transpose(inverse(ModelMatrix))) * vertexNormal;
    TexCoord = vertexUV;
}