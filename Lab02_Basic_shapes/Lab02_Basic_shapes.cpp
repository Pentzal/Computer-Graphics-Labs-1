#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <common/shader.hpp>

// Function prototypes
void keyboardInput(GLFWwindow *window);

int main( void )
{
    // =========================================================================
    // Window creation - you shouldn't need to change this code
    // -------------------------------------------------------------------------
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "Lab02 Basic Shapes", NULL, NULL);
    
    if( window == NULL ){
        fprintf(stderr, "Failed to open GLFW window.\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    // -------------------------------------------------------------------------
    // End of window creation
    // =========================================================================

    // 2.1. Define a Triangle
#pragma region Initial Triangles
    //const float vertices[] = {
    //    // x     y     z
    //    -0.9f, -0.5f, 0.0f,   // triangle 1
    //    -0.1f, -0.5f, 0.0f,
    //    -0.5f,  0.5f, 0.0f,
    //     0.1f, -0.5f, 0.0f,   // 2.5. Adding another triangle
    //     0.9f, -0.5f, 0.0f,
    //     0.5f,  0.5f, 0.0f
    //};
#pragma endregion

#pragma region Rectangle with 2 Triangles
    //const float vertices[] = {
    //    // x     y     z
    //    -0.5f, -0.5f, 0.0f,   // triangle 1
    //     0.5f, -0.5f, 0.0f,
    //    -0.5f,  0.5f, 0.0f,
    //    -0.5f,  0.5f, 0.0f,   // triangle 2
    //     0.5f, -0.5f, 0.0f,
    //     0.5f,  0.5f, 0.0f
    //};
#pragma endregion

#pragma region Umbrella Corporation
    const float vertices[] = {
        // x     y     z
        -0.4f,  1.0f, 0.0f,   // north
         0.4f,  1.0f, 0.0f,
         0.0f,  0.0f, 0.0f,
         0.4f,  1.0f, 0.0f,   // north-east
         1.0f,  0.4f, 0.0f,
         0.0f,  0.0f, 0.0f,
         1.0f,  0.4f, 0.0f,   // east
         1.0f, -0.4f, 0.0f,
         0.0f,  0.0f, 0.0f,
         1.0f, -0.4f, 0.0f,   // south-east
         0.4f, -1.0f, 0.0f,
         0.0f,  0.0f, 0.0f,
         0.4f, -1.0f, 0.0f,   // south
        -0.4f, -1.0f, 0.0f,
         0.0f,  0.0f, 0.0f,
        -0.4f, -1.0f, 0.0f,   // south-west
        -1.0f, -0.4f, 0.0f,
         0.0f,  0.0f, 0.0f,
        -1.0f, -0.4f, 0.0f,   // west
        -1.0f,  0.4f, 0.0f,
         0.0f,  0.0f, 0.0f,
        -1.0f,  0.4f, 0.0f,   // north-west
        -0.4f,  1.0f, 0.0f,
         0.0f,  0.0f, 0.0f,
    };
#pragma endregion

    // 2.4. More colours
#pragma region Initial Triangles
    //const float colours[] = {
    //  // R     G     B
    //    1.0f, 0.0f, 0.0f, // Red
    //    0.0f, 1.0f, 0.0f, // Green
    //    0.0f, 0.0f, 1.0f, // Blue
    //    1.0f, 1.0f, 0.0f, // Yellow
    //    0.0f, 1.0f, 1.0f, // Cyan
    //    1.0f, 0.0f, 1.0f  // Magenta
    //};
#pragma endregion

#pragma region Umbrella Corporation
    const float colours[] = {
        // R     G     B
          1.0f, 0.0f, 0.0f, // north
          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,
          1.0f, 1.0f, 1.0f, // north-east
          1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f,
          1.0f, 0.0f, 0.0f, // east
          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,
          1.0f, 1.0f, 1.0f, // south-east
          1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f,
          1.0f, 0.0f, 0.0f, // south
          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,
          1.0f, 1.0f, 1.0f, // south-west
          1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f,
          1.0f, 0.0f, 0.0f, // west
          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,
          1.0f, 1.0f, 1.0f, // north-west
          1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f,
    };
#pragma endregion

    // 2.1.1. Vertex Array Object
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // 2.2. Shaders
    unsigned int shaderID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");
    // Use the shader program
    glUseProgram(shaderID);

    // 2.1.2. Vertex Buffer Object
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // Create colour buffer
    unsigned int colourBuffer;
    glGenBuffers(1, &colourBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_STATIC_DRAW);
    
	// Ensure we can capture keyboard inputs
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    // Render loop
	while (!glfwWindowShouldClose(window))
    {
        // Get inputs
        keyboardInput(window);
        
        // Clear the window
        glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 2.3. Draw the triangle
        // Send the VBO to the shaders
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(
            0,          // attribute
            3,          // size
            GL_FLOAT,   // type
            GL_FALSE,   // normalise or not?
            0,          // stride
            (void*)0    // offset
        );
        // Send the colour buffer to the shaders
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        // Actually Draw the Triangle(s)
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / (3 * sizeof(float)));
        glDisableVertexAttribArray(0);
        
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
    // Cleanup, remove triangle data
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderID);
    
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return 0;
}

void keyboardInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}