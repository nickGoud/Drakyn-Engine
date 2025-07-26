/**
 * name: opengl_manager.h
 * purpose: manage all OpenGL/GPU API operations.
 * date_created: 24-07-2025
 * date_modified: 24-07-2025
 */

#include "globals.h"

#include "shader_manager.h"

#include <string>

class OpenGL_Manager
{
private:
    unsigned int VBO;
    unsigned int vertexShader;

    ShaderManager* pShaderManager = nullptr;

public:
    OpenGL_Manager();
    ~OpenGL_Manager();

    void init();
    void main_loop();
    void cleanup();
};