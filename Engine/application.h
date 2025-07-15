/**
 * Name: application.h
 * Date created: 20-06-2025
 * Last modified: 20-06-2025
 */

class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    void init();
    void main_loop();
    void cleanup();
};