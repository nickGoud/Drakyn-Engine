/**
 * name: opengl_manager.h
 * purpose: manage all OpenGL/GPU API operations.
 * date_created: 24-07-2025
 * date_modified: 28-07-2025
 */

#include "globals.h"

#include <string>

class OpenGL_Manager
{
private:
    // Vertex Array Object.
    // Vertex Buffer Object.
    // Element Buffer Object.
    unsigned int VBO, VAO, EBO;
    unsigned int vertexShader, fragmentShader, shaderProgram;

    bool _compileShaders();
    bool _buildBuffers();

public:
    OpenGL_Manager();
    ~OpenGL_Manager();

    void init();
    void draw_call();
    void cleanup();
};