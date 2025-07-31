/**
 * Name: application.h
 * Date created: 20-06-2025
 * Last modified: 20-06-2025
 */
#include "globals.h"

#include "opengl_manager.h"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

#define WINDOW_FRAME_COUNTER true

class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    GLFWwindow *pWindow = nullptr;
    OpenGL_Manager* pOpenGLManager = nullptr;

    float current_time = 0.0, last_time = 0.0;

    void init();
    void main_loop();
    void cleanup();

    void _set_delta();
};