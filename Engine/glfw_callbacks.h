#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void setGLFWCallbacks(GLFWwindow* window);

void glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height);  
void glfw_process_input(GLFWwindow* window);
