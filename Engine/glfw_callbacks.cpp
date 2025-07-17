#include "glfw_callbacks.h"

void setGLFWCallbacks(GLFWwindow* window)
{
    glfwSetFramebufferSizeCallback(window, glfw_framebuffer_size_callback);
}

void glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  