#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 colour;

out vec3 fragmentColour;

// 2.6.1. Shift to the right
//position.x += 0.5;

void main()
{
	// Output vertex position
	// Instantiate each vec3 individually to enable swizzling
	// Initial Positions
	gl_Position = vec4(position.x, position.y, position.z, 1.0);

	// 2.6.1. Shift to the right
	// gl_Position = vec4(position.x+0.5, position.y, position.z, 1.0);

	// 2.6.2. Flip upside-down
	// gl_Position = vec4(position.x, -position.y, position.z, 1.0);

	// 2.6.3. Swapped x/y coordinates
	// gl_Position = vec4(position.y, position.x, position.z, 1.0);

	// Output vertex colour
	fragmentColour = colour;
}