/**
 * name: shader_manager.h
 * purpose: handle the building of fragment and vertex shaders.
 * date_created: 24-07-2025
 * date_modified: 24-07-2025
 */

#include "globals.h"
#include <string>

enum eShaderType
{
    VERTEX,
    FRAGMENT,
    COMPUTE
};

class ShaderManager
{
private:
    

public:
    ShaderManager();
    ~ShaderManager();

    // specific shaders
    bool compileShader(std::string path, eShaderType shaderType);
    // default shaders
    bool compileShaders();
};