/**
 * Name: main.cpp
 * Date created: 20-06-2025
 * Last modified: 20-06-2025
 */

#include "application.h"

#include <iostream>

int main()
{
    Application *app = new Application();

    try
    {
        app->run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete app;
}