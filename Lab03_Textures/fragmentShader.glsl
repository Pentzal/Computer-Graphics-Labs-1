#version 330 core
// 3.1.3.2. Fragment Shader

// Input
in vec2 UV;

// Output
out vec3 colour;

// Uniforms
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    // Output Texture (2 Textures)
    colour = vec3(mix(texture(texture1, UV), texture(texture2, UV), 0.7));
}