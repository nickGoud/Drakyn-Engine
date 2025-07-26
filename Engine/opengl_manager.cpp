/**
 * name: opengl_manager.cpp
 * date_created: 24-07-2025
 * date_modified: 24-07-2025
 */

#include "opengl_manager.h"

OpenGL_Manager::OpenGL_Manager()
{
}

OpenGL_Manager::~OpenGL_Manager()
{
}

void OpenGL_Manager::init()
{
    // Build, Compile and Save shaders.
    pShaderManager = new ShaderManager();

    // Set up the address for the "Vertex Buffer Object".
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    // Build shaders.
    pShaderManager->compileShaders();
    // pShaderManager->compileShader(VERTEX_SHADER_PATH /*found in globals.h*/, eShaderType::VERTEX);
}

void OpenGL_Manager::main_loop()
{
}

void OpenGL_Manager::cleanup()
{
    delete pShaderManager;
}

