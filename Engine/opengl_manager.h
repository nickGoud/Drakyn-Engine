/**
 * name: opengl_manager.h
 * purpose: manage all OpenGL/GPU API operations.
 * date_created: 24-07-2025
 * date_modified: 27-07-2025
 */

#include "globals.h"

#include <string>

class OpenGL_Manager
{
private:
    unsigned int VBO, VAO;
    unsigned int vertexShader, fragmentShader, shaderProgram;

    bool _compileShaders();
    bool _buildBuffers();

    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f}; // DELETE THIS

public:
    OpenGL_Manager();
    ~OpenGL_Manager();

    void init();
    void draw_call();
    void cleanup();
};