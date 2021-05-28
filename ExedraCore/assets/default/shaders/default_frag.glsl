#version 330 core

out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightDirection;
uniform sampler2D albedoTexture;

in vec2 TexCoord;
in vec3 normal;

void main()
{

    vec4 texCol = texture(albedoTexture, TexCoord);
    float alpha = texCol.a;
    if (alpha < 0.1)
        discard;

    vec3 norm = normalize(normal);
    vec3 lightDir = -normalize(lightDirection);
    float lightIntensity = max(dot(norm, lightDir), 0.25f);

    vec3 col = texCol.rgb * objectColor * lightIntensity;

    FragColor = vec4(col, alpha);
}