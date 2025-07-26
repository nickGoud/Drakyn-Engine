#include "shader_manager.h"

#include <fstream>
#include <iostream>

#include "shaders/vertex_0.h"
#include "shaders/fragment_0.h"

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

bool ShaderManager::compileShader(std::string shader_path, eShaderType shaderType)
{
    std::fstream shaderFile(shader_path);
    if (!shaderFile.is_open())
    {
        std::cout << "failed to open shader file" << std::endl;
        return false;
    }

    std::cout << shader_path << std::endl;

    std::string line, shader_code;
    while(getline(shaderFile, line))
    {
        shader_code += line;
    }

    std::cout << "shader_code: " << shader_code << std::endl;
    
    return true;
}

bool ShaderManager::compileShaders()
{
    return false;
}
