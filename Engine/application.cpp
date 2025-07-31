/**
 * Name: application.cpp
 * Date created: 20-06-2025
 * Last modified: 15-07-2025
 */

#include "application.h"

#include "glfw_callbacks.h"

#include <stdio.h>
#include <math.h>

void processInput(GLFWwindow *window);

Application::Application()
{
}

Application::~Application()
{
}

void Application::run()
{
    // Initiate and build all needed assets.
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

    // Initilize OpenGL
    pOpenGLManager = new OpenGL_Manager();
    pOpenGLManager->init();

    // Set delta
    _set_delta();
}

void Application::main_loop()
{
    float delta_tick_rate = .5; // every x seconds the fps counter will update.
    float delta_current_tick = 0.0;

    while (!glfwWindowShouldClose(pWindow))
    {
        // Update delta
        _set_delta();

        // Handle inputs devices.
        processInput(pWindow);

        // Events, Physics, Sounds, Scripts, ETC.
        // ...
        // ...

        // Graphics API draw function.
        pOpenGLManager->draw_call();

        // Stable delta reading for user.
        if (WINDOW_FRAME_COUNTER == true)
        {
            if (delta_current_tick >= delta_tick_rate)
            {
                std::string delta_str = std::to_string((int)(1.0 / delta));
                glfwSetWindowTitle(pWindow, delta_str.c_str());

                delta_current_tick = 0.0;
            }
            else
            {
                delta_current_tick += delta;
            }
        }

        // Update Graphics.
        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }
}

void Application::cleanup()
{
    delete pOpenGLManager;
    glfwTerminate();
}

void Application::_set_delta()
{
    last_time = current_time;
    current_time = glfwGetTime();
    delta = current_time - last_time;
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