/**
 * Name: application.cpp
 * Date created: 20-06-2025
 * Last modified: 15-07-2025
 */

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f}; // DELETE THIS

#include "application.h"

#include "glfw_callbacks.h"

#include <stdio.h>

void processInput(GLFWwindow *window);

Application::Application()
{
}

Application::~Application()
{
}

void Application::run()
{
    init();
    main_loop();
    cleanup();
}

void Application::init()
{
    // Initilize GLFW viewport.
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    pWindow = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "Drakyn Engine", NULL, NULL);

    if (pWindow == NULL)
    {
        printf("Failed to create GLFW window\n");
        return;
    }
    glfwMakeContextCurrent(pWindow);

    // Initilize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD\n");
        return;
    }

    setGLFWCallbacks(pWindow);
}

void Application::main_loop()
{

    while (!glfwWindowShouldClose(pWindow))
    {
        processInput(pWindow);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }
}

void Application::cleanup()
{
    glfwTerminate();
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        printf("HELLO\n");
    }
}