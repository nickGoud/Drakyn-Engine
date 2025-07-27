/**
 * name: opengl_manager.cpp
 * date_created: 24-07-2025
 * date_modified: 27-07-2025
 */

#include "opengl_manager.h"

#include "shaders/vertex_0.h"
#include "shaders/fragment_0.h"

#include <iostream>

#define VERTEX_GLSL shaders_vertex_0_glsl
#define FRAGMENT_GLSL shaders_fragment_0_glsl

#define INFO_SIZE 512

bool OpenGL_Manager::_compileShaders()
{
    std::cout << VERTEX_GLSL << std::endl;
    std::cout << FRAGMENT_GLSL << std::endl;

    int result;              // Symbol for errors.
    char infoLog[INFO_SIZE]; // Holds error information.

    // Build the vertex shader.
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char *vertexShaderSource = (const char *)VERTEX_GLSL;
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);

    if (!result)
    {
        glGetShaderInfoLog(vertexShader, INFO_SIZE, NULL, infoLog);
        std::cout << "Vertex shader compilation failed: " << infoLog << std::endl;
        return false;
    }
    std::cout << "Vertex shader compilation complete." << std::endl;

    // Build the fragment shader.
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char *fragmentShaderSource = (const char *)FRAGMENT_GLSL;
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);

    if (!result)
    {
        glGetShaderInfoLog(fragmentShader, INFO_SIZE, NULL, infoLog);
        std::cout << "Fragment shader compilation failed: " << infoLog << std::endl;
        return false;
    }
    std::cout << "Fragment shader compilation complete." << std::endl;

    // Attach the shaders to OpenGL.
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &result);

    if (!result)
    {
        glGetProgramInfoLog(shaderProgram, INFO_SIZE, NULL, infoLog);
        std::cout << "Shader program failed: " << infoLog << std::endl;
        return false;
    }
    std::cout << "Shader program complete." << std::endl;


    // Clean up shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return true;
}

bool OpenGL_Manager::_buildBuffers()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    return true;
}

OpenGL_Manager::OpenGL_Manager()
{
}

OpenGL_Manager::~OpenGL_Manager()
{
}

void OpenGL_Manager::init()
{
    // Set up the address for the "Vertex Buffer Object".
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Build shaders.
    if (!_compileShaders())
    {
        std::cout << "Failed to compile shaders." << std::endl;
        return;
    }
    std::cout << "Built shaders." << std::endl;

    if (!_buildBuffers())
    {
        std::cout << "Failed to build frame buffers." << std::endl;
        return;
    }
    std::cout << "Built frame buffers." << std::endl;
}

void OpenGL_Manager::draw_call()
{
    glUseProgram(shaderProgram);

    // Draw
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGL_Manager::cleanup()
{
}
