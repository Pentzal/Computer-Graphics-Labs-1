#version 330 core
// 3.1.3.1. Vertex Shader

// Inputs
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;

// Outputs
out vec2 UV;

void main()
{
    // Output vertex position
    gl_Position = vec4(position, 1.0);

    // Output texture coordinates
    UV = uv;
}