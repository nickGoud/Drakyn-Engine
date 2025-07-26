/**
 * Name: application.h
 * Date created: 20-06-2025
 * Last modified: 20-06-2025
 */
#include "globals.h"

#include "opengl_manager.h"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    GLFWwindow *pWindow = nullptr;
    OpenGL_Manager* pOpenGLManager = nullptr;

    void init();
    void main_loop();
    void cleanup();
};